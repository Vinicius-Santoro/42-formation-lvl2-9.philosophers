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

#### Useful links

- [developing](#developing)
- [developing](#developing)
- [developing](#developing)

## Necessary concepts

#### Processor
- asd
#### Core
- asd
#### Processes
- asd
#### Threads
- asd

## Extern functions

#### memset
- Description: The  memset() function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`.
- Parameter: `void *s` - 
- Parameter: `int c` -
- Parameter: `size_t n` -
- Return value: 
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

int	main(void)
{
	printf("Hello world!");
	return 0;
}
```
#### output
```
Hello world!
````
<h1></h1>
