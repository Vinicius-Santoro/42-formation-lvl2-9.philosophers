/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:58:03 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/15 16:58:03 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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