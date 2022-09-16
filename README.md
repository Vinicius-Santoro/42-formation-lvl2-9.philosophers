# 42-formation-lvl2-9.philosophers
Project 9: Philosophers - Eighth project for the formation of software engineers at school 42 São Paulo.

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

- [memset](#memset)
- [malloc](#malloc)
- [free](#free)
- [write](#write)
- [usleep](#usleep)
- [gettimeofday](#gettimeofday)
- [pthread_join](#pthread_join)
- [pthread_create](#pthread_create)
- [pthread_detach](#pthread_detach)
- [pthread_mutex_init](#pthread_mutex_init)
- [pthread_mutex_lock](#pthread_mutex_lock)
- [pthread_mutex_unlock](#pthread_mutex_unlock)
- [pthread_mutex_destroy](#pthread_mutex_destroy)

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

## Extern functions

#### memset
- Description: The  memset() function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`.
- Parameter: `void *s` - string to be filled.
- Parameter: `int c` - character that will be input.
- Parameter: `size_t n` - number of bytes to be input.
- Prototype:

```c
void	*memset(void *s, int c, size_t n)
```

- memset example:
```c
#include <stdio.h>
/*
Memset library
*/
#include <string.h>

#define  BUF_SIZE  20
 
int main(void)
{
   char buffer[BUF_SIZE + 1];
   char *string;
 
   memset(buffer, 0, sizeof(buffer));
   string = (char *) memset(buffer,'A', 10);
   printf("\nBuffer contents 1: %s\n", string);
   memset(buffer+10, 'B', 10);
   printf("\nBuffer contents 2: %s\n", buffer);
}
 
```
#### output
```
Buffer contents 1: AAAAAAAAAA
Buffer contents 2: AAAAAAAAAABBBBBBBBBB
````
<h1></h1>

#### malloc
- Description: The malloc() function allocates size bytes and returns a pointer to the allocated memory. The memory is not initialized. If size is 0, then malloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().
- Parameter: `size_t size` - 
- Return value: pointer to the allocated memory.
- Prototype:
```c
void	*malloc(size_t size)
```

- malloc example:
```c
#include <unistd.h>
/*
Malloc library.
*/
#include <stdlib.h>

int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int *ptr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i)
            ptr[i] = i + 1;

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) 
            printf("%d ", ptr[i]);
    }
 
    return 0;
}
```
<h1></h1>

#### free
- Description: The free() function deallocates the memory previously allocated by a call to calloc, malloc, or realloc.
- Parameter: `void *ptr` - pointer to be deallocated.
- Prototype:
```c
void    free(void *ptr)
```

- free example:
```c
#include <stdio.h>
/*
Free library
*/
#include <stdlib.h>
 
int main()
{
  
    // This pointer ptr will hold the
    // base address of the block created
    int *ptr;
    int n;
  
    // Get the number of elements for the array
    printf("Enter number of Elements: ");
    scanf("%d", &n);
  
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
  
    // Check if the memory has been successfully
    // allocated by calloc() or not
    if (ptr == NULL) {
        printf("Memory not allocated \n");
        exit(0);
    }
    // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (int i = 0; i < n; ++i)
            ptr[i] = i + 1;

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int i = 0; i < n; ++i) 
            printf("%d ", ptr[i]);
    
    free(ptr);
    printf("\nMalloc Memory Successfully freed.");
  
    return 0;
}
```
<h1></h1>

#### write
- Description:  Writes cnt bytes from buf to the file associated with fd.
- Parameter: `int fd` - file descriptor.
- Parameter: `void* buf` -  buffer to write data.
- Parameter: `size_t nbyte` - length of buffer
- Return: If successful, return the number of bytes actually written to the fd. Else, return 0 on reaching end of file, or return -1 on error.
- Prototype:

```c
size_t write (int fd, void* buf, size_t nbyte)
```

- write example:
```c
/*
Write library
*/
#include <unistd.h>

int	main(void)
{
	char *name = "Vinicius";
	write(1, name, sizeof(*name * sizeof(char)));
	return (0);
} 
```
#### output
```
Vinicius
````

<h1></h1>

#### usleep
- Description: suspend execution for microsecond intervals.
- Parameter: `useconds_t usec` - microseconds.
- Return: 0 on success, -1 on error.
- Prototype: 

```c
int	usleep(useconds_t usec);
```

-  example:
```c
#include <stdio.h>
/*
Usleep library
*/
#include <unistd.h>

int main(void)
{
    unsigned int mSeconds;
    int returnCode;

	/*
	getting microseconds
	*/
    printf("Insert the microseconds: ");
    scanf("%d", &mSeconds);

    printf("The value insered is: %d\n", mSeconds);

	/*
	usleep function.
	*/
    returnCode = usleep(mSeconds);
    if(!returnCode)
        printf("Sucess execution!\nExit code: %d\n", returnCode);
    else
        printf("Failure execution!\nExit code: %d\n", returnCode);
    return (0);
}
```
<h1></h1>

#### gettimeofday
- Description: can get the time.
- Parameter: `int fd` - file descriptor.
- Return: 0 on success, -1 on error.
- Prototype:
```c
 int gettimeofday(struct timeval *tv, struct timezone *tz)
```

-  example:
```c
#include <stdio.h>

/*
Gettimeofday library
*/
#include <sys/time.h>

int main(void)
{
    struct timeval	tv;
    struct timezone	tz;
    long int        second_and_microsecond_for_milisecond;

    gettimeofday(&tv,&tz);

second_and_microsecond_for_milisecond = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
printf("Seconds since 1/1/1970.......: %lu\n",tv.tv_sec);
printf("Microseconds.................: %ld\n",tv.tv_usec);
printf("Seconds for Miliseconds:.....: %ld\n", (tv.tv_sec * 1000));
printf("Microseconds for Miliseconds.: %ld\n", (tv.tv_usec / 1000));
printf("Sec and Microsec for Milisec.: %ld", second_and_microsecond_for_milisecond);
return (0);
}
```

#### output
```
Seconds since 01/01/1970.......: 1663294030
Microseconds.................: 601024
Seconds for Miliseconds:.....: 1663294030000
Microseconds for Miliseconds.: 601
Sec and Microsec for Milisec.: 1663294030601
````

<h1></h1>

#### 
- Description: 
- Parameter: `int fd` - file descriptor.
- Return: 
- Prototype:

```c

```

-  example:
```c
/*
library
*/
#include <>

int	main(void)
{

	return (0);
} 
```






