#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

// Thread function for pthread_join demo
void* thread_function(void* arg) {
    printf("Thread is running...\n");
    return NULL;
}

int main() {
    pid_t pid;

    // 1. fork()
    pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process (PID: %d)\n", getpid());

        // 2. exec() demo (replace child with "ls -l")
        printf("Child executing ls command using exec...\n");
        execlp("ls", "ls", "-l", NULL);

        // If exec fails
        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent Process (PID: %d), Child PID: %d\n", getpid(), pid);

        // 3. wait()
        wait(NULL);
        printf("Parent resumes after child finishes.\n");

        // 4. ps demo
        printf("Displaying process list using system(ps)...\n");
        system("ps -aux");

        // 5. pthread_join demo
        pthread_t t1;
        pthread_create(&t1, NULL, thread_function, NULL);
        pthread_join(t1, NULL);
        printf("Thread finished execution.\n");
    }

    return 0;
}