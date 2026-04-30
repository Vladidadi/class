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
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0xe8213e80, "_printk" },
	{ 0xbf2c538b, "get_task_mm" },
	{ 0x73c05ac1, "__tracepoint_mmap_lock_start_locking" },
	{ 0xa59da3c0, "down_read" },
	{ 0x73c05ac1, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x0ca0353a, "mas_find" },
	{ 0x73c05ac1, "__tracepoint_mmap_lock_released" },
	{ 0xa59da3c0, "up_read" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xaedbc175, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x2287b539, "__mmap_lock_do_trace_start_locking" },
	{ 0x2287b539, "__mmap_lock_do_trace_released" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x0d428105, "init_task" },
	{ 0x0040afbe, "param_ops_int" },
	{ 0xbebe66ff, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0xbd03ed67,
	0xe8213e80,
	0xbf2c538b,
	0x73c05ac1,
	0xa59da3c0,
	0x73c05ac1,
	0x0ca0353a,
	0x73c05ac1,
	0xa59da3c0,
	0xd272d446,
	0xaedbc175,
	0x2287b539,
	0x2287b539,
	0xd272d446,
	0x0d428105,
	0x0040afbe,
	0xbebe66ff,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__fentry__\0"
	"__ref_stack_chk_guard\0"
	"_printk\0"
	"get_task_mm\0"
	"__tracepoint_mmap_lock_start_locking\0"
	"down_read\0"
	"__tracepoint_mmap_lock_acquire_returned\0"
	"mas_find\0"
	"__tracepoint_mmap_lock_released\0"
	"up_read\0"
	"__x86_return_thunk\0"
	"__mmap_lock_do_trace_acquire_returned\0"
	"__mmap_lock_do_trace_start_locking\0"
	"__mmap_lock_do_trace_released\0"
	"__stack_chk_fail\0"
	"init_task\0"
	"param_ops_int\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "24FDA79FFB0917CFEECD4CF");
