#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Worker thread function to start calculation
void *start_calculation(void *arg) {
    // Get the named pipe from the argument
    char *named_pipe = (char *)arg;
    int fd;

    while (1) {
        // Open the named pipe for reading
        fd = open(named_pipe, O_RDONLY);
        if (fd == -1) {
            perror("Error opening named pipe");
            continue;
        }

        // Enter critical section (lock)
        pthread_mutex_lock(&mutex);

        // Exit critical section (unlock)
        pthread_mutex_unlock(&mutex);

        // Enter critical section (lock)
        pthread_mutex_lock(&mutex);

        // Identify the worker type
        char worker_type[20];
        read(fd, worker_type, sizeof(worker_type));
        printf("%s", worker_type);

        // Read and display input1, operation, input2, and result
        char buffer[256];
        ssize_t bytes_read;

        for (int i = 0; i < 4; ++i) {
            bytes_read = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_read <= 0) {
                break;
            }
            buffer[bytes_read] = '\0';

            if (i == 0) {
                // First line, directly print the input
                printf("%s", buffer);
            } else {
                // Subsequent lines, print with an indentation
                printf("\n %s", buffer);
            }
        }

        printf("\n");

        // Close the named pipe
        close(fd);

        // Exit critical section (unlock)
        pthread_mutex_unlock(&mutex);

        // Enter critical section (lock)
        pthread_mutex_lock(&mutex);
        printf("Waiting A Worker Calculation...\n");
        // Exit critical section (unlock)
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t thread_adder, thread_subtractor, thread_multiplier, thread_divider;

    // Enter critical section (lock)
    pthread_mutex_lock(&mutex);
    printf("Waiting A Worker Calculation...\n");
    // Exit critical section (unlock)
    pthread_mutex_unlock(&mutex);

    // Create threads for each worker
    pthread_create(&thread_adder, NULL, start_calculation, "adder_pipe");
    pthread_create(&thread_subtractor, NULL, start_calculation, "subtractor_pipe");
    pthread_create(&thread_multiplier, NULL, start_calculation, "multiplier_pipe");
    pthread_create(&thread_divider, NULL, start_calculation, "divider_pipe");

    // Wait for threads to finish (Note: This won't happen in this example since threads run indefinitely)
    pthread_join(thread_adder, NULL);
    pthread_join(thread_subtractor, NULL);
    pthread_join(thread_multiplier, NULL);
    pthread_join(thread_divider, NULL);

    return 0;
}

