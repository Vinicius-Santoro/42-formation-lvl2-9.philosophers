# 42-formation-lvl2-9.philosophers
Project 9: Philosophers - Eighth project for the formation of software engineers at school 42 São Paulo.

- This project is about the basics of threading a process. How to create threads and use mutexes.

## Necessary concepts

### What is a processor?
- 

### What is the core?
- 

### What are processes?
- 

### What are threads?
- 

## Extern functions
We can use some extern functions. Follows a description of each of them.

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
#include <unistd.h>

int	main(void)
{
	printf("Hello world!");
	return 0;
}
```
#### output
```
Teste do printf
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
