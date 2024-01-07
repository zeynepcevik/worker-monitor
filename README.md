# Worker Monitor
### Abstract
The project focuses on developing a multi-threaded system in the Linux environment to perform basic arithmetic operations concurrently. The system comprises four worker programs (adder, subtractor, multiplier, and divider) and a worker monitor. Each worker program operates independently in its dedicated terminal, continually accepting user input for numerical calculations. 
The worker monitor observes and displays the operations performed by each worker in real-time by listening to them through separate named pipes. The implementation utilizes pthread mutex locks to ensure that only one worker can access the critical section at any given time, allowing seamless coordination among the threads.

### Things Done During the Project

#### Worker Programs (adder.c, subtractor.c, multiplier.c, divider.c):
• Creating Named Pipes: With each worker program, a named pipe (FIFO) was created for communication with the worker monitor.
• User Input: Continuously requests two numbers and an operation (addition, subtraction, multiplication or division) from the user.
• Calculation: Performs the corresponding calculation based on the user input.
• Named Pipe Write: The worker type, input values and result are sent to the named pipe.

#### Worker Monitor (worker_monitor.c or WM):
• Initialising Named Pipes: Each named pipe is opened for communication with worker programmes.
• Thread Creation: Threads are created for each worker type (adder, subtractor, multiplier, divider).
• Thread Function (start_calculation): Opens the named pipe associated with the worker type.
• A mutex is used to provide exclusive access to the critical section.
• The worker type is defined, input values are read and displayed and the named pipe is closed.
• By releasing the mutex, other threads are allowed to enter the critical section.

#### Main Function:
• Start named pipes and threads are created.
• The mutex is used to display "Waiting for a Worker Calculation..." before any calculation starts and after each calculation finishes.
• Threads are expected to finish.

#### Thread Synchronisation (Mutex):
• A mutex is used to provide exclusive access to shared resources (such as console output) and to prevent race conditions.
• The mutex is locked before entering the critical section and unlocked when exiting.

### Success Criteria:

#### Worker Programs (Adder, Subtractor, Multiplier, Divider):
• Successfully executed on separate terminals.
• Continuously request numerical input from users.
• Arithmetic operations (addition, subtraction, multiplication, division) are performed on user inputs.
• The result of each operation is displayed as output on the relevant terminal.

#### Worker Monitor:
• Executes successfully on the terminal dedicated to it.
• To synchronise access to critical sections, pthread mutex locks are used.
• Real-time monitoring of worker operations is provided through separate pipes.
• Detailed information about each operation is displayed, including worker type, input values, operation performed and result.
• By allowing only one worker to access the critical section at a time, conflicts are avoided and orderly execution is ensured.

#### General System:
• Appropriate communication between processes is shown through named pipes.
• Ensures thread safety and prevents race conditions by effectively enforcing mutex locks.
• Efficient coordination between worker schedules is demonstrated with the worker monitor displaying synchronised information.
• Operates continuously until manually terminated, providing a permanent monitoring mechanism.

