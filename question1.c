#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int child1, child2, status;
    
    //check if fork fails
child1 = fork();
if(child1 < 0) {
  perror("fork for child1");
return -1;
}
// if child process returns 0, return process identifier in parent process
if(child1 == 0) {
  
//process id of child process is returned in parent process
printf("I am first child, my pid is: %d\n", getpid());
}

else{
//does the same routine for the second child  
  child2 = fork();
if(child2 < 0){
   perror("fork for child2");
   return -1;
}        
        
if(child2 == 0){

   printf("I am second child, my pid is: %d\n", getpid());
}
}

//Parent process terminates only if child terminates which it does
int waitpid = wait(&status);

while (waitpid > 0) {

if (waitpid < 0) {
   perror("wait");
return -1;
}
waitpid = wait(&status);
}
   
return 0;
}

