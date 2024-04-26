#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sched.h>
#include<time.h>

int main(){
 int blok_S = 0;
printf("wright block size  = ");
 scanf("%d" , &blok_S);
 int f_C = 0;
 printf("wright fork count = ");
 scanf("%d" , &f_C);
 int n = f_C * blok_S;
 int sum = 0;
 
 pid_t x = 0;
 int* arr = (int*)mmap(0,4096,PROT_READ | PROT_WRITE,MAP_ANONYMOUS | MAP_SHARED,-1,0);
 int* arr1 = (int*)mmap(0,4096,PROT_READ | PROT_WRITE,MAP_ANONYMOUS | MAP_SHARED,-1,0);

 for (size_t i = 0; i < blok_S * f_C; i++)
 { 
   scanf("%d", &arr[i] );
 }
  
    for(int i = 0 ; i < f_C; i++){
          x = fork();
          if( x == 0 ){
            for (int g = i * blok_S; g < (i+1) * blok_S; g++)
               arr1[0]+=arr[g]; 
              exit(NULL);
         } 
    }
    
    printf("sum = %d\n" , arr1[0]);
}  




   






