#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int number1, number2, result;
    char operation;

    // Create named pipe
    mkfifo("divider_pipe", 0666);

    // Worker operations (you can adapt this for other worker programs)
    while (1) {
        // Prompt for input 1
        printf("Input 1: ");
        scanf("%d", &number1);

        // Prompt for input 2
        printf("Input 2: ");
        scanf("%d", &number2);

        // Set the operation for division
        operation = '/';

        // Check for division by zero
        if (number2 == 0) {
            printf("Error: Division by zero\n");
            continue;
        }

        // Calculate the result
        result = number1 / number2;
        printf("Result: %d\n", result);

        // Open the named pipe for writing
        int fd = open("divider_pipe", O_WRONLY);
        if (fd == -1) {
            perror("Error opening named pipe");
            continue;
        }

        // Send worker type (Divider) to the named pipe
        dprintf(fd, "Divider\n");

        // Send input1, operation, input2, and result to the named pipe
        dprintf(fd, "%d\n%c\n%d\n%d\n", number1, operation, number2, result);
        
        // Close the named pipe
        close(fd);
    }

    return 0;
}

