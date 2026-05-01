#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd272d446, "__fentry__" },
	{ 0xf296206e, "pgdir_shift" },
	{ 0xb1ad3f2f, "boot_cpu_data" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x095159b2, "physical_mask" },
	{ 0x1bdf2bc8, "sme_me_mask" },
	{ 0xf296206e, "ptrs_per_p4d" },
	{ 0x6f8082dd, "pv_ops" },
	{ 0xd272d446, "BUG_func" },
	{ 0xbd03ed67, "page_offset_base" },
	{ 0x82fd7238, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0xe8213e80, "_printk" },
	{ 0xbf2c538b, "get_task_mm" },
	{ 0x73c05ac1, "__tracepoint_mmap_lock_start_locking" },
	{ 0xa59da3c0, "down_read" },
	{ 0x73c05ac1, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x1f55c5b2, "kstrtoll" },
	{ 0x73c05ac1, "__tracepoint_mmap_lock_released" },
	{ 0xa59da3c0, "up_read" },
	{ 0x2287b539, "__mmap_lock_do_trace_start_locking" },
	{ 0x2287b539, "__mmap_lock_do_trace_released" },
	{ 0xaedbc175, "__mmap_lock_do_trace_acquire_returned" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x0d428105, "init_task" },
	{ 0x0040afbe, "param_ops_charp" },
	{ 0x0040afbe, "param_ops_int" },
	{ 0xbebe66ff, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0xf296206e,
	0xb1ad3f2f,
	0xd272d446,
	0x095159b2,
	0x1bdf2bc8,
	0xf296206e,
	0x6f8082dd,
	0xd272d446,
	0xbd03ed67,
	0x82fd7238,
	0xbd03ed67,
	0xe8213e80,
	0xbf2c538b,
	0x73c05ac1,
	0xa59da3c0,
	0x73c05ac1,
	0x1f55c5b2,
	0x73c05ac1,
	0xa59da3c0,
	0x2287b539,
	0x2287b539,
	0xaedbc175,
	0xd272d446,
	0x0d428105,
	0x0040afbe,
	0x0040afbe,
	0xbebe66ff,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__fentry__\0"
	"pgdir_shift\0"
	"boot_cpu_data\0"
	"__x86_return_thunk\0"
	"physical_mask\0"
	"sme_me_mask\0"
	"ptrs_per_p4d\0"
	"pv_ops\0"
	"BUG_func\0"
	"page_offset_base\0"
	"__ubsan_handle_shift_out_of_bounds\0"
	"__ref_stack_chk_guard\0"
	"_printk\0"
	"get_task_mm\0"
	"__tracepoint_mmap_lock_start_locking\0"
	"down_read\0"
	"__tracepoint_mmap_lock_acquire_returned\0"
	"kstrtoll\0"
	"__tracepoint_mmap_lock_released\0"
	"up_read\0"
	"__mmap_lock_do_trace_start_locking\0"
	"__mmap_lock_do_trace_released\0"
	"__mmap_lock_do_trace_acquire_returned\0"
	"__stack_chk_fail\0"
	"init_task\0"
	"param_ops_charp\0"
	"param_ops_int\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7D08F21A83F8F1E54F17A54");
