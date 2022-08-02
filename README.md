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
- Description: The  memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
- Parameter: `void *s` - 
- Parameter: `int c` -
- Parameter: `size_t n` -
- Return value: 
- Prototype:
```c
void *memset(void *s, int c, size_t n)
```

- memset example:
```c
#include <unistd.h>

int	main(void){
	int id = fork();
	if (id == 0)
		printf("Hello, child process id: %d\n", id);
	else
		printf("Hello, parent process id: %d\n", id);
	return 0;
}
```
