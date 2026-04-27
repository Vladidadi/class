//Vladislav Vitamer
  #include <linux/kernel.h>
  #include <linux/sched.h>
  #include <linux/module.h>
 
  static int pid_arg =1;

  module_param(pid_arg, int, 0);
MODULE_PARM_DESC(pid_arg, "The PID of the process whose information you'd like to see");

  void print_loop(struct task_struct* ts){
     struct task_struct *task;
   printk(KERN_INFO "Entered loop in part3");

       char *print_state;
  for(task=ts;task!=&init_task;task=task->parent)

   {
   switch(task->__state){
    case 0:
    print_state=    "TASK_RUNNING"   ;
    break;
    case 1:
    print_state= "TASK_INTERRUPTIBLE" ;
    break;
    default:
    print_state="error";
   }
   printk(KERN_INFO "heres a task named %s with PID [%d] whose state is %s\n",task->comm , task->pid,print_state);
   }
}

  int init_module(void)
  {

        printk(KERN_INFO "Printing Other!\n");

   struct task_struct *iter;
   short found = 0;

   for_each_process(iter){
      if(iter->pid==pid_arg){
   //  printk(KERN_INFO "\n======================\n\nWE FOUND HIM\n\n======================\n");

         print_loop(iter);
         found=1;
      }
      if(!found){
   //  printk(KERN_INFO "walking thru the task_struct looking for %d, we found %s with PID [%d]\n",pid_arg,iter->comm , iter->pid);
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
