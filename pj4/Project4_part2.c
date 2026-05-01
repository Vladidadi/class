// Vladislav Vitamer
#include <linux/kernel.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/mm.h>

static int pid_arg = 1;
static char *va_string;

module_param(pid_arg, int, 0);
MODULE_PARM_DESC(pid_arg, "PID to inspect");
module_param(va_string, charp, 0444);
MODULE_PARM_DESC(va_string, "Virtual address to test (example: 0x7fff...)");

static int find_in_range(struct task_struct *task)
{
	struct mm_struct *mm;
	struct vm_area_struct *vma;
	unsigned long query = 0;
	int err;
	int in_vma_range = 0;

	if (!va_string) {
		pr_info("va_string not set\n");
		return 0;
	}

	err = kstrtoul(va_string, 0, &query);
	if (err) {
		pr_info("invalid va_string: %s (err=%d)\n", va_string, err);
		return 0;
	}

	mm = get_task_mm(task);
	if (!mm) {
		pr_info("task %d has no userspace mm\n", task->pid);
		return 0;
	}

	mmap_read_lock(mm);
	vma = find_vma(mm, query);
	if (vma && query >= vma->vm_start && query < vma->vm_end)
		in_vma_range = 1;
	mmap_read_unlock(mm);
	mmput(mm);

	pr_info("pid=%d va=%lx in_vma_range=%d\n", task->pid, query, in_vma_range);
	return in_vma_range;
}

int init_module(void)
{
	struct task_struct *iter;
	int found = 0;
	int query_in_range = 0;

	pr_info("Entering VA VMA checker\n");

	for_each_process(iter) {
		if (iter->pid == pid_arg) {
			found = 1;
			query_in_range = find_in_range(iter);
			break;
		}
	}

	if (!found) {
		pr_info("PID %d not found\n", pid_arg);
		return 0;
	}

	if (query_in_range)
		pr_info("The address is in the range of a VMA\n");
	else
		pr_info("The address is NOT in the range of a VMA\n");

	return 0;
}

void cleanup_module(void)
{
	pr_info("End VA VMA checker\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vladislav Vitmaer");
MODULE_DESCRIPTION("Check whether virtual address belongs to a process VMA");
