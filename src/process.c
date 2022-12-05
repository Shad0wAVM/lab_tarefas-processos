/*
 * process.c - simple example demonstrating the creation of threads
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>


/* global value */
int g_value = 0;

void* thr_func(void* ptr) {
    g_value = 1;
    return NULL;
}

int main() {
    int p_id = fork();
    if (p_id == -1) {
        fprintf(stderr, "error creating thread.\n");
        return -1;
    }

    if (p_id == 0){
        thr_func(NULL);
    } else{
        g_value = 2;
    }
    
    if(p_id > 0 && wait(&p_id) == -1) {
        fprintf(stderr, "error joining thred.\n");
        return -1;
    }
    sleep(2);
    printf("value = %d\n", g_value);
    return 0;
}
