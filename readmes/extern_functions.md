### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;


## Extern functions

- [memset](#memset)
- [malloc](#malloc)
- [free](#free)
- [write](#write)
- [usleep](#usleep)
- [gettimeofday](#gettimeofday)
- [pthread_create](#pthread_create)
- [pthread_join](#pthread_join)
- [pthread_detach](#pthread_detach)
- [pthread_mutex_init](#pthread_mutex_init)
- [pthread_mutex_lock](#pthread_mutex_lock)
- [pthread_mutex_unlock](#pthread_mutex_unlock)
- [pthread_mutex_destroy](#pthread_mutex_destroy)

<h1></h1>

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
- Parameter: `struct timeval *tv` - struct with number of seconds and microseconds since the Epoch.
- Parameter: `struct timezone *tz` - struct with timezone.
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
```

<h1></h1>

#### pthread_create
- Description: create a new thread
- Parameter: `pthread_t *restrict thread` - thread.
- Parameter: `const pthread_attr_t *restrict attr` - points to a pthread_attr_t structure whose contents are used at thread creation time to determine attributes for the new thread.
- Parameter: `void *(*start_routine)(void *)` - routine function.
- Parameter: `void *restrict arg)` - sole argument of routine function.
- Return:  On success, pthread_create() returns 0; on error, it returns an error number, and the contents of *thread are undefined.
- Prototype:

```c
int pthread_create(pthread_t *restrict thread,
                   const pthread_attr_t *restrict attr,
                   void *(*start_routine)(void *),
                   void *restrict arg);
```

-  example:
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
Pthread_create Library
*/
#include <pthread.h>

void	*routine()
{
	printf("Hello from thread\n");
	sleep(3);
	printf("Ending thread\n");
}

int	main()
{
	pthread_t thread[2];
	int i;

	for(i = 0; i < 2; i++)
		pthread_create(thread + i, NULL, &routine, NULL);
	for(i = 0; i < 2; i++)
		pthread_join(thread[i], NULL);

	return(0);
}
```
#### output
```
Hello from thread
Hello from thread
Ending thread
Ending thread
```

<h1></h1>

#### pthread_join
- Description: waits for the thread specified by thread to terminate. 
- Parameter: `pthread_t thread` - thread.
- Parameter: `void **retval` - if retval is not NULL, then pthread_join() copies the exit status of the target thread (i.e., the value that the target thread supplied to pthread_exit(3)) into the location pointed to by
retval.  If the target thread was canceled, then PTHREAD_CANCELED is placed in the location pointed to by retval.
- Prototype:
```c
int pthread_join(pthread_t thread, void **retval);
```
-  example:
```c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
Pthread_join Library
*/
#include <pthread.h>

void* roll_dice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    printf("Thread result: %p\n", result);
    return (void*) result;
}

int main(void)
{
    int *res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
        return 1;
    /*
    retval != NULL
        copies the exit status of the target threa into the location pointed
        to by retval.
    */
    if (pthread_join(th, (void**) &res) != 0)
        return 2;
    printf("Main res: %p\n", res);
    printf("Result: %d\n", *res);
    free(res);
    return 0;
}
```

#### output
```
Thread result: 0x7f9860000b60
Main res: 0x7f9860000b60
Result: 6
```

<h1></h1>

#### pthread_mutex_init 
- Description: Creates a mutex, referenced by mutex, with attributes specified by attr. If attr is NULL, the default mutex attribute (NONRECURSIVE) is used.
- Parameter: `pthread_mutex_t *restrict mutex` - mutex.
- Parameter: `const pthread_mutexattr_t *restrict attr` - attribute.
- Return: If successful, pthread_mutex_init() returns 0, and the state of the mutex becomes initialized and unlocked. If unsuccessful, pthread_mutex_init() returns -1.

- Prototype:
```c
int pthread_mutex_init(pthread_mutex_t *restrict mutex,
                       const pthread_mutexattr_t *restrict attr);
```

#### pthread_mutex_lock
- Description: Locks a mutex object, which identifies a mutex. If the mutex is already locked by another thread, the thread waits for the mutex to become available. The thread that has locked a mutex becomes its current owner and remains the owner until the same thread has unlocked it. When the mutex has the attribute of recursive, the use of the lock may be different. When this kind of mutex is locked multiple times by the same thread, then a count is incremented and no waiting thread is posted. The owning thread must call pthread_mutex_unlock() the same number of times to decrement the count to zero.
- Parameter: `pthread_mutex_t *mutex` - mutex.
- Return: If successful, pthread_mutex_lock() returns 0. If unsuccessful, pthread_mutex_lock() returns -1.
- Prototype:
```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
```

#### pthread_mutex_unlock
- Description: Releases a mutex object. If one or more threads are waiting to lock the mutex, pthread_mutex_unlock() causes one of those threads to return from pthread_mutex_lock() with the mutex object acquired. If no threads are waiting for the mutex, the mutex unlocks with no current owner. When the mutex has the attribute of recursive the use of the lock may be different. When this kind of mutex is locked multiple times by the same thread, then unlock will decrement the count and no waiting thread is posted to continue running with the lock. If the count is decremented to zero, then the mutex is released and if any thread is waiting for it is posted.
- Parameter: `pthread_mutex_t *mutex` - mutex.
- Return: If successful, pthread_mutex_unlock() returns 0. If unsuccessful, pthread_mutex_unlock() returns -1
- Prototype:
```c
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

#### pthread_mutex_destroy
- Description: Deletes a mutex object, which identifies a mutex. Mutexes are used to protect shared resources. mutex is set to an invalid value, but can be reinitialized using pthread_mutex_init().
- Parameter: `pthread_mutex_t *mutex` - mutex.
- Return: If successful, pthread_mutex_destroy() returns 0. If unsuccessful, pthread_mutex_destroy() returns -1.
- Prototype:
```c
int pthread_mutex_destroy(pthread_mutex_t *mutex) 
```

-  example:
```c
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine()
{
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        /*
        Critical section
        If mutex are not applied, it may cause a race condition where the values
        of variables may be unpredictable and vary depending on the timings of
        context switches of the processes or threads. 
        */
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(void)
{
    pthread_t th[4];
    int i;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < 4; i++)
    {
        if (pthread_create(th + i, NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
        printf("Thread %d has started\n", i);
    }
    for (i = 0; i < 4; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
            return 2;
        printf("Thread %d has finished execution\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}
```

#### output with synchronization techniques (mutex)
```
Thread 0 has started
Thread 1 has started
Thread 2 has started
Thread 3 has started
Thread 0 has finished execution
Thread 1 has finished execution
Thread 2 has finished execution
Thread 3 has finished execution
Number of mails: 40000000
```

#### output without synchronization techniques (mutex), causing a race condition
```
Thread 0 has started
Thread 1 has started
Thread 2 has started
Thread 3 has started
Thread 0 has finished execution
Thread 1 has finished execution
Thread 2 has finished execution
Thread 3 has finished execution
Number of mails: 14530673
```







