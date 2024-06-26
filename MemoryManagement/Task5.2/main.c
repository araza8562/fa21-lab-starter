#include "header.h"

int main()
{
  // Declare a pointer to an integer array
  int *array;

  // Seed the random number generator
  srand(time(0));

  // Allocate memory for the array
  array = MALLOC(SIZE, integer);

  // Initialize the array with random values
  initialize_memory(array, SIZE);

  // Display the original array
  printf("Original array:\n");
  show_memory(array, SIZE);

  // Reallocate memory for the array to double its size
  array = REALLOC(array, integer, 2 * SIZE);

  // Initialize the additional elements in the array
  initialize_memory(array, 2 * SIZE);

  // Display the resized array
  printf("\nResized array:\n");
  show_memory(array, 2 * SIZE);

  // Free the allocated memory
  free(array);

  return EXIT_SUCCESS;
}