//Vladislav Vitamer
   #include <linux/kernel.h>
   #include <linux/sched.h>
   #include <linux/module.h>
   // #include <stdlib.h>
   #include <linux/mm.h>



  bool print_range(struct task_struct* ts);
  static int pid_arg =1;
  static char* va_string;

  struct vm_area_struct *vma;
  unsigned long vm_space =0;
  struct vma_iterator iter;

  long start_bound=0xffffffffffff;
  long end_bound=0;

  module_param(pid_arg, int, 0);
  MODULE_PARM_DESC(pid_arg, "The PID of the process whose information you'd like to see");
  module_param(va_string, charp, 0444);
  MODULE_PARM_DESC(va_string, "The virtual address we want to check on");

  bool print_range(struct task_struct* ts){
     struct task_struct *task = ts;
   printk(KERN_INFO "Entered loop in part3");
   struct mm_struct *mm = get_task_mm(task);
mmap_read_lock(mm);

   VMA_ITERATOR(iter,task->mm,0);
  for_each_vma(iter,vma){
   if(vma->vm_start < start_bound) {start_bound=vma->vm_start;}
   if(vma->vm_end > end_bound) {end_bound=vma->vm_end;}
   printk(KERN_INFO "heres a vma: start %lx      end %lx\n",   vma->vm_start,   vma->vm_end);

   
  }
  mmap_read_unlock(mm);
  long range = end_bound-start_bound;
  printk(KERN_INFO "\nRange from %lx to %lx, with a total size of %lx",start_bound,end_bound,range);

  long query =0;
  bool err = kstrtol(va_string,0,&query);
  if(err){
   printk(KERN_INFO "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!\nError in string to integer conversion\n\n");
  }


  if(!(query > end_bound) && !(query < start_bound)){
   return true;
  }else{
   return false;
  }
   
}

  int init_module(void)
  {

        printk(KERN_INFO "Entering VA STATUS!\n");

   struct task_struct *iter;
   short found = 0;
bool query_in_range=0;
   for_each_process(iter){
      if(iter->pid==pid_arg){
    printk(KERN_INFO "\n======================\n\nWE FOUND HIM\n\n======================\n");

         
         query_in_range = print_range(iter);
         found=1;
      }
 
      if(query_in_range){
      printk(KERN_INFO "\n\n The address is in the range of the vma\n\n");
         
      }else{
      printk(KERN_INFO "\n\n The address is not in the range of the vma\n\n");
      }
   }



   return 0;
   }
   
   void cleanup_module(void)
   {
   printk(KERN_INFO "End VA STATUS\n");
   }



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vladislav Vitmaer");
MODULE_DESCRIPTION("Process information report");
