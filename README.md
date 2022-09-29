# 42-formation-lvl2-9.philosophers
Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo.

- This project is about the basics of threading a process. How to create threads and use mutexes.

## Sumary

#### Necessary concepts

Some necessary concepts to develop this project.

- [What is the processor?](#processor)
- [What is the core?](#core)
- [What are threads?](#threads)
- [What are processes?](#processes)
- [Difference between processes and threads](#threads_x_processes)

#### Extern functions

We can use some extern functions. Follows a description of each of them.

- [memset](readmes/extern_functions.md)
- [malloc](readmes/extern_functions.md)
- [free](readmes/extern_functions.md)
- [write](readmes/extern_functions.md)
- [usleep](readmes/extern_functions.md)
- [gettimeofday](readmes/extern_functions.md)
- [pthread_create](readmes/extern_functions.md)
- [pthread_join](readmes/extern_functions.md)
- [pthread_detach](readmes/extern_functions.md)
- [pthread_mutex_init](readmes/extern_functions.md)
- [pthread_mutex_lock](readmes/extern_functions.md)
- [pthread_mutex_unlock](readmes/extern_functions.md)
- [pthread_mutex_destroy](readmes/extern_functions.md)

#### Useful links:

- [Short introduction to threads (pthreads)](https://youtu.be/d9s_d28yJq0)
- [Difference between processes and threads](https://youtu.be/IKG1P4rgm54)
- [What is a mutex in C?](https://youtu.be/oq29KUy29iQ)
- [Multithreading in C](https://www.geeksforgeeks.org/multithreading-c-2/)
- [Mutex lock for Linux Thread Synchronization](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/#:~:text=A%20Mutex%20is%20a%20lock,the%20locked%20region%20of%20code.)


#### How the project works

- [Dining philosophers problem](#philosophers)

## Necessary concepts

#### Processor
- A processor is an integrated electronic circuit that performs the calculations that run a computer. A processor performs arithmetical, logical, input/output (I/O) and other basic instructions that are passed from an operating system (OS). Most other processes are dependent on the operations of a processor.

#### Core
- A processor core is a processing unit that reads instructions to perform specific actions. Instructions are chained together so that, when run in real-time, they make up your computer experience. Literally, everything you do on your computer has to be processed by your processor.

#### Threads
- Threads refer to the highest level of code executed by a processor, so with many threads, your CPU can handle several tasks at the same time. All CPUs have active threads, and every process performed on your computer has at least a single thread.
- The number of threads you have depends on the number of cores in your CPU. Each CPU core can have two threads. So a processor with two cores will have four threads. A processor with eight cores will have 16 threads.
- Threads are important to the function of your computer because they determine how many tasks your computer can perform at any given time.

#### Processes
- A process is an instance of a program running in a computer. It is close in meaning to task , a term used in some operating systems. In UNIX and some other operating systems, a process is started when a program is initiated (either by a user entering a shell command or by another program). Like a task, a process is a running program with which a particular set of data is associated so that the process can be kept track of. An application that is being shared by multiple users will generally have one process at some stage of execution for each user.
- A process can initiate a subprocess, which is a called a child process (and the initiating process is sometimes referred to as its parent ). A child process is a replica of the parent process and shares some of its resources, but cannot exist if the parent is terminated.
- Processes can exchange information or synchronize their operation through several methods of interprocess communication ( IPC ).

#### Threads_X_Processes

- The biggest difference is threads share memory.

#### Threads example: 
```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void* routine()
{
    x += 5;
    sleep(2);
    printf("Value of x: %d\n", x);
    printf("Process ID: %d\n", getpid());
}

void* routine2()
{
    sleep(2);
    printf("Value of x: %d\n", x);
    printf("Process ID: %d\n", getpid());
}

int main(void)
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL))
        return 1;
    if (pthread_create(&t2, NULL, &routine2, NULL))
        return 2;
    if (pthread_join(t1, NULL))
        return 3;
    if (pthread_join(t2, NULL))
        return 3;
    return 0;
}
```
#### output
```
Value of x: 7
Process ID: 416
Value of x: 7
Process ID: 416
```

<h1></h1>

#### Processes example: 
```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    int x = 2;
    int pid = fork();
    if (pid == -1)
        return 1;
    
    if (pid == 0)
        x++;
    sleep(2);
    printf("Value of x: %d\n", x);
    if (pid != 0)
        wait(NULL);
    return 0;
}
```
#### output
```
Value of x: 2
Value of x: 3
Process ID: 466
Process ID: 467
````

## How the project works

#### Philosophers

