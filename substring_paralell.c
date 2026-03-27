#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// #include <stdio.h>
// #include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sched.h>
#include <stdint.h>

#define MAX 1024

int total = 0;
int n1,n2;
char *s1,*s2;
FILE *fp;

int readf(FILE *fp)
{
	if((fp=fopen("strings.txt", "r"))==NULL){
		printf("ERROR: can't open string.txt!\n");
		return 0;
	}
	s1=(char *)malloc(sizeof(char)*MAX);
	if(s1==NULL){
		printf("ERROR: Out of memory!\n");
		return -1;
	}
	s2=(char *)malloc(sizeof(char)*MAX);
	if(s2==NULL){
		printf("ERROR: Out of memory\n");
		return -1;
	}
	/*read s1 s2 from the file*/
	s1=fgets(s1, MAX, fp);
	s2=fgets(s2, MAX, fp);
	n1=strlen(s1)-1;  /*length of s1*/
	n2=strlen(s2)-1; /*length of s2*/
	
	if(s1==NULL || s2==NULL || n1<n2)  /*when error exit*/
		return -1;
}
// void * substring_worker_thread( void *arg)
// {
void* num_substring_thread(void* arg)
{
	// int i,j,k;
	int count;
	int* i;
    i=((int* )arg);
	int j=n2;
    int* return_val;
	for (int k=0;k<j;k++){
        if(*(s1+*i+k)!=*(s2+k)){
			break;
		}else{
			count++;
		}
	}
	if (count==n2){
		return_val= (int*)1;
	}else{
		return_val= (int*)0;
	}
    return return_val;
	// for (i = 0; i <= (n1-n2); i++){   
	// 	count=0;
	// 	for(j = i,k = 0; k < n2; j++,k++){  /*search for the next string of size of n2*/  
	// 		if (*(s1+j)!=*(s2+k)){
	// 			break;
	// 		}
	// 		else
	// 			count++;
	// 		if(count==n2)    
	// 			total++;		/*find a substring in this step*/                          
	// 	}
	// }
	
	// return total;
}


int main(int argc, char *argv[])
{
	int num_threads,i;
	int total=0;
    readf(fp);


    int NUM_PROCS;//number of CPU
    int* cpu_array = NULL;

    // struct Node  *tmp,*next;
    // struct timeval starttime, endtime;

    // if(argc == 1){
    //     printf("ERROR: please provide an input arg (the number of threads)\n");
    //     exit(1);
    // }

    // num_threads = atoi(argv[1]); //read num_threads from user
	num_threads = n1;
    pthread_t substring_worker[num_threads];
    NUM_PROCS = sysconf(_SC_NPROCESSORS_CONF);//get number of CPU
    if( NUM_PROCS > 0)
    {
        cpu_array = (int *)malloc(NUM_PROCS*sizeof(int));
        if( cpu_array == NULL )
        {
            printf("Allocation failed!\n");
            exit(0);
        }
        else
        {
            for( i = 0; i < NUM_PROCS; i++)
               cpu_array[i] = i;
        }

    }

    // pthread_mutex_init(&mutex_lock, NULL);//RWLOCK

    // List = (struct list *)malloc(sizeof(struct list));
    // if( NULL == List )
    // {
    //    printf("End here\n");
    //    exit(0);	
    // }
    // List->header = List->tail = NULL;

    // gettimeofday(&starttime,NULL); //ge//t program start time
    for( i = 0; i < num_threads; i++ )
    {
        pthread_create(&(substring_worker[i]), NULL, (void *) num_substring_thread, &i); 
    }
		void* worker_return;
        int* substring_found;
    for( i = 0; i < num_threads; i++ )
    {

        if(substring_worker[i] != 0)
        {
            pthread_join(substring_worker[i],&worker_return);
        }
        substring_found=(int*)worker_return;
		total+=*substring_found;
    }


    // gettimeofday(&endtime,NULL); //get the finish time

    // if( List->header != NULL )
    // {
    //     next = tmp = List->header;
    //     while( tmp != NULL )
    //     {  
    //        next = tmp->next;
    //        free(tmp);
    //        tmp = next;
    //     }            
    // }

    if( cpu_array!= NULL)
       free(cpu_array);
	   printf("\n\nTotal: %d substring occurances\n",total);
    /* calculate program runtime */
    // printf("Total run time is %ld microseconds.\n", (endtime.tv_sec-starttime.tv_sec) * 1000000+(endtime.tv_usec-starttime.tv_usec));
    return 0; 






	// int count=0;
 
	// readf(fp);
	// pthread_create(&(substring_worker[i]), NULL, (void *) num_substring_thread, &cpu_array[i%NUM_PROCS]); 
	// count = num_substring();
 	// printf("The number of substrings is: %d\n", count);
	// return 1;
	
}











