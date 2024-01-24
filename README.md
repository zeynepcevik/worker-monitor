# Worker Monitor 
### Abstract
The project focuses on developing a multi-threaded system in the Linux environment to perform basic arithmetic operations concurrently. The system comprises four worker programs (adder, subtractor, multiplier, and divider) and a worker monitor. Each worker program operates independently in its dedicated terminal, continually accepting user input for numerical calculations. 
The worker monitor observes and displays the operations performed by each worker in real-time by listening to them through separate named pipes. The implementation utilizes pthread mutex locks to ensure that only one worker can access the critical section at any given time, allowing seamless coordination among the threads.


