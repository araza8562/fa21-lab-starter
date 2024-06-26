#include "header.h"

// Only in this file you can directly call malloc, realloc, etc.
#undef malloc
#undef realloc

void *alloc(size_t size)
{

  void *mempool;

  mempool = malloc(size);

  if (mempool != NULL)
    return mempool;

  else
  {
    printf("Out of memory");
    exit(EXIT_FAILURE);
  }
}

void *R_alloc(int *ptr, size_t size)
{

  void *mempool;

  mempool = realloc(ptr, size);

  if (mempool != NULL)
    return mempool;

  else
  {
    printf("Out of memory");
    exit(EXIT_FAILURE);
  }
}

// Definition for initialize_memory
// Function to initialize the array with random values
void initialize_memory(int *array, int n)
{
  // If the array is at its initial size, initialize all elements
  if ((n - SIZE) == 0)
  {
    for (int i = 0; i < n; i++)
    {
      array[i] = rand() % 10; // Assign a random value between 0 and 9
    }
  }
  // If the array size has been increased by 5, initialize the additional elements
  else if ((n - SIZE) == 5)
  {
    for (int i = 5; i < n; i++)
    {
      array[i] = rand() % 10; // Assign a random value between 0 and 9
    }
  }
}

// Function to display the contents of the array
void show_memory(int *array, int n)
{
  // If the array is at its initial size, display all elements
  if ((n - SIZE) == 0)
  {
    for (int i = 0; i < n; i++)
    {
      printf("%d ", array[i]);
    }
  }
  // If the array size has been increased by 5, display all elements
  else if ((n - SIZE) == 5)
  {
    for (int i = 0; i < n; i++)
    {
      printf("%d ", array[i]);
    }
  }
  printf("\n"); // Add a newline for better output formatting
}
