1. Write a program ​processes.c​, and let the parent process produce two child processes.
One prints out"I am first child, my pid is: "PID,and the other prints out "I am second child, my pid is: " PID.
Guarantee that the parent terminates after the children terminate (Note,you need to wait for two child processes here). Use the getpid() function to retrieve the PID.

2. Consider the parent process as P.The program consists of fork() system call statements placed at different points in the code to create new processes Q and R. The program also shows three variables: a,b,and pid - with the print out of these variables occurring from various processes. Show the values of pid, a, and b printed by the processes P, Q, and R.

int​ a=​10​, b=​25​, fq=​0​, fr=​0 
fq=fork() ​// fork a child - call it Process Q
if​(fq==​0​){ // Child successfully forked  
a=a+b print values of a, b, ​and​ process_id  
fr=fork() ​// fork another child - call it Process R​ 
if​(fr!=​0​){    
b=b+​15​ //print values of a, b, and process_id  
}
​else​ {    
a=(a*b)+​20​
//print values of a, b, and process_id  }
}​
else​{  
b=a+b​-5​;  
//print values of a, b, ​and​ process_id
}
