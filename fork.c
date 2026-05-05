#include <stdio.h> 
#include <unistd.h> 
int main() { 
    pid_t pid; 
    pid = fork(); 
    if (pid < 0) { 
        printf("Fork failed\n"); 
    } 
    else if (pid == 0) { 
        printf("Child Process\n"); 
        printf("Child PID: %d\n", getpid()); 
    } 
    else { 
        printf("Parent Process\n"); 
        printf("Parent PID: %d\n", getpid()); 
        printf("Child PID: %d\n", pid); 
    } 
    return 0;
}