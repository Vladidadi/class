#include "list-forming2.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
    char threads[512];
    
    for(int i=0; i<64 ;i++){
        sprintf(threads,"%d",i);
        // threads=i;
        for(int j=0;j<1000;j=j*200){
            // K=j;
            form_list(2,((char**)&threads));
        }
          
    }
    return 0;

}