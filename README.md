# 42-formation-lvl2-9.philosophers
Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo.

- This project is about the basics of threading a process. How to create threads and use mutexes.

## Sumary

#### Necessary concepts

Some necessary concepts to develop this project.

- [What is the processor?](#processor)
- [What is the core?](#core)
- [What are processes?](#processes)
- [What are threads?](#threads)

#### Extern functions

We can use some extern functions. Follows a description of each of them.

- [memset](readmes/extern_functions.md)
- [malloc](readmes/extern_functions.md)
- [free](readmes/extern_functions.md)
- [write](readmes/extern_functions.md)
- [usleep](readmes/extern_functions.md)
- [gettimeofday](readmes/extern_functions.md)
- [pthread_join](readmes/extern_functions.md)
- [pthread_create](readmes/extern_functions.md)
- [pthread_detach](readmes/extern_functions.md)
- [pthread_mutex_init](readmes/extern_functions.md)
- [pthread_mutex_lock](readmes/extern_functions.md)
- [pthread_mutex_unlock](readmes/extern_functions.md)
- [pthread_mutex_destroy](readmes/extern_functions.md)

#### Useful links:

- [Short introduction to threads (pthreads)](https://youtu.be/d9s_d28yJq0)
- [Difference between processes and threads](https://youtu.be/IKG1P4rgm54)


## Necessary concepts

#### Processor
- A processor is an integrated electronic circuit that performs the calculations that run a computer. A processor performs arithmetical, logical, input/output (I/O) and other basic instructions that are passed from an operating system (OS). Most other processes are dependent on the operations of a processor.

#### Core
- A processor core is a processing unit that reads instructions to perform specific actions. Instructions are chained together so that, when run in real-time, they make up your computer experience. Literally, everything you do on your computer has to be processed by your processor.

#### Processes
- A process is an instance of a program running in a computer. It is close in meaning to task , a term used in some operating systems. In UNIX and some other operating systems, a process is started when a program is initiated (either by a user entering a shell command or by another program). Like a task, a process is a running program with which a particular set of data is associated so that the process can be kept track of. An application that is being shared by multiple users will generally have one process at some stage of execution for each user.
- A process can initiate a subprocess, which is a called a child process (and the initiating process is sometimes referred to as its parent ). A child process is a replica of the parent process and shares some of its resources, but cannot exist if the parent is terminated.
- Processes can exchange information or synchronize their operation through several methods of interprocess communication ( IPC ).

#### Threads
- Threads refer to the highest level of code executed by a processor, so with many threads, your CPU can handle several tasks at the same time. All CPUs have active threads, and every process performed on your computer has at least a single thread.
- The number of threads you have depends on the number of cores in your CPU. Each CPU core can have two threads. So a processor with two cores will have four threads. A processor with eight cores will have 16 threads.
- Threads are important to the function of your computer because they determine how many tasks your computer can perform at any given time.

## how the project works
