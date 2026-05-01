//Vladislav Vitamer
   #include <linux/kernel.h>
   #include <linux/sched.h>
   #include <linux/module.h>
   #include <linux/mm.h>

   void print_range(struct task_struct* ts);
  static int pid_arg =1;

  struct vm_area_struct *vma;
  unsigned long vm_space =0;
  struct vma_iterator iter;

  long start_bound=0xffffffffffff;
  long end_bound=0;

  module_param(pid_arg, int, 0);
MODULE_PARM_DESC(pid_arg, "The PID of the process whose information you'd like to see");

  void print_range(struct task_struct* ts){
     struct task_struct *task = ts;
   printk(KERN_INFO "Entered loop in part3");
   struct mm_struct *mm = get_task_mm(task);
mmap_read_lock(mm);
      //  char *print_state;
   VMA_ITERATOR(iter,task->mm,0);
  for_each_vma(iter,vma){
   if(vma->vm_start < start_bound) {start_bound=vma->vm_start;}
   if(vma->vm_end > end_bound) {end_bound=vma->vm_end;}
   printk(KERN_INFO "heres a vma: start %lx      end %lx\n",   vma->vm_start,   vma->vm_end);


  }
  mmap_read_unlock(mm);
  long range = end_bound-start_bound;
  printk(KERN_ALERT "\nRange from %lx to %lx, with a total size of %lx",start_bound,end_bound,range);

}

  int init_module(void)
  {

        printk(KERN_INFO "Printing vmas!\n");

   struct task_struct *iter;
   short found = 0;

   for_each_process(iter){
      if(iter->pid==pid_arg){
    printk(KERN_INFO "\n======================\n\nWE FOUND HIM\n\n======================\n");

         print_range(iter);
         found=1;
      }


   }



   return 0;
   }
   
   void cleanup_module(void)
   {
   printk(KERN_INFO "End Printing Other\n");
   }



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vladislav Vitmaer");
MODULE_DESCRIPTION("Process information report");
