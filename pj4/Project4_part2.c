//Vladislav Vitamer
   #include <linux/kernel.h>
   #include <linux/sched.h>
   #include <linux/module.h>
   // #include <stdlib.h>
   #include <linux/mm.h>



   int offset_fetcher(long addy, struct mm_struct *mm);
   int find_in_range(struct task_struct* ts);
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
  MODULE_PARM_DESC(   va_string, "The virtual address we want to check on");
   
   
   int offset_fetcher(long addy, struct mm_struct *mm){
      if((mm ))
{

  long unsigned int vmpage;
      int i=0;
      pgd_t *pgd ;//=pgd_offset(mm,addy);
      p4d_t *p4d;//=p4d_offset(pgd,addy);
      pud_t *pud;//=pud_offset(p4d,addy);
      pmd_t *pmd;//=pmd_offset(pud,addy);
      pte_t *pte;//=pte_offset_kernel(pmd,addy);

      while(vma){
         for (vmpage=vma->vm_start,i=1;vmpage < vma->vm_end;vmpage += PAGE_SIZE,i++){
             pgd=pgd_offset(mm,addy);
      if (pgd_none(*pgd) || pgd_bad(*pgd)){
         return 0;
      }
      p4d=p4d_offset(pgd,addy);
      if (p4d_none(*p4d) || p4d_bad(*p4d)){
         return 0;
      }
        pud=pud_offset(p4d,addy);
      if (pud_none(*pud) || pud_bad(*pud)){
         return 0;
         }
            pmd=pmd_offset(pud,addy);
      if (pmd_none(*pmd) || pmd_bad(*pmd)){

    return 0;
         }
            return pte_present(*pte);
   }
         }
      }
      return 0;
     
}


  int find_in_range(struct task_struct* ts){
     struct task_struct *task = ts;
   printk(KERN_INFO "Entered loop in part3");
   struct mm_struct *mm = get_task_mm(task);
mmap_read_lock(mm);

//    VMA_ITERATOR(iter,task->mm,0);
//   for_each_vma(iter,vma){
//    if(vma->vm_start < start_bound) {start_bound=vma->vm_start;}
//    if(vma->vm_end > end_bound) {end_bound=vma->vm_end;}
//    printk(KERN_INFO "heres a vma: start %lx      end %lx\n",   vma->vm_start,   vma->vm_end);

   
//   }
//   long range = end_bound-start_bound;
//   printk(KERN_INFO "\nRange from %lx to %lx, with a total size of %lx",start_bound,end_bound,range);

  long query =0;
  bool err = kstrtol(va_string,0,&query);
  if(err){
   printk(KERN_INFO "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!\nError in string to integer conversion\n\n");
  }


  int present=offset_fetcher(query,mm);
  mmap_read_unlock(mm);
  printk(KERN_INFO "\n\nPresent status of page: %d\n",present);
   return present;
}

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

   // print_range(iter);

  }
  mmap_read_unlock(mm);
  long range = end_bound-start_bound;
  printk(KERN_INFO "\nRange from %lx to %lx, with a total size of %lx",start_bound,end_bound,range);
//   for(task=ts;task!=&init_task;task=task->parent)

//    {
//    switch(task->__state){
//     case 0:
//     print_state=    "TASK_RUNNING"   ;
//     break;
//     case 1:
//     print_state= "TASK_INTERRUPTIBLE" ;
//     break;
//     default:
//     print_state="error";
//    }
//    printk(KERN_INFO "heres a task named %s with PID [%d] whose state is %s\n",task->comm , task->pid,print_state);
//    break;   
// }

   
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

         
         query_in_range = find_in_range(iter);
    
         
         found=1;
      }
 
 
   }

        if(query_in_range){
      printk(KERN_INFO "\n\n The address is in the range of the vma\n\n");
         
      }else{
      printk(KERN_INFO "\n\n The address is not in the range of the vma\n\n");
      }



   return 0;
   }
   
   void cleanup_module(void)
   {
      //    VMA_ITERATOR(iter,task->mm,0);
//   for_each_vma(iter,vma){
//    if(vma->vm_start < start_bound) {start_bound=vma->vm_start;}
//    if(vma->vm_end > end_bound) {end_bound=vma->vm_end;}
//    printk(KERN_INFO "heres a vma: start %lx      end %lx\n",   vma->vm_start,   vma->vm_end);

   
   printk(KERN_INFO "End VA STATUS\n");
   }



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vladislav Vitmaer");
MODULE_DESCRIPTION("Process information report");
