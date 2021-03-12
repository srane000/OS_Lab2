#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
int a=10, b=25, fq=0, fr=0;
    
fq=fork(); // fork a child - call it Process Q
    
if(fq==0) { // Child successfully forked
   a=a+b; // print values of a, b, and process_id
   printf("1 A = %d\n1 B = %d\n1 PID = %d\n", a, b, getpid()); // 1
        
   fr=fork(); // fork another child - call it Process R
   printf("fr = %d\n", fr);
        
if(fr!=0) {
  b=b+15; // print values of a, b, and process_id
  printf("2 A = %d\n2 B = %d\n2 PID = %d\n", a, b, getpid()); // 2
}
else {
    a=20+(a*b); // print values of a, b, and process_id
    printf("3 A = %d\n3 B = %d\n3 PID = %d\n", a, b, getpid()); // 3
}
        
}
else {
    b=a+b-5; // print values of a, b, and process_id
   printf("4 A = %d\n4 B = %d\n4 PID = %d\n", a, b, getpid()); // 4
}

return 0;
}


