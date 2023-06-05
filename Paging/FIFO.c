// Code for FIFO Page Replacement Algorithm in C Programming Language

#include <stdio.h>
#include <stdlib.h>

void FIFO(int *pages, int n, int capacity)
{
  int i, j;
  int page_faults = 0;

  int *frame = (int *)malloc(capacity * sizeof(int));
  for (i = 0; i < capacity; i++)
  {
    frame[i] = -1;
  }

  int frame_index = 0;
  for (i = 0; i < n; i++)
  {
    int found = 0;
    for (j = 0; j < capacity; j++)
    {
      if (frame[j] == pages[i])
      {
        found = 1;
        break;
      }
    }
    if (found == 0)
    {
      frame[frame_index] = pages[i];
      frame_index = (frame_index + 1) % capacity;
      page_faults++;
    }
  }

  printf("Page Hits: %d\n", n - page_faults);
  printf("Page Faults: %d\n", page_faults);
  printf("Page Hit Rate: %f\n", (float)(n - page_faults) / n);
  printf("Page Fault Rate: %f\n", (float)page_faults / n);
}

int main()
{
  int n;
  printf("Enter the number of pages: ");
  scanf("%d", &n);

  int *pages = (int *)malloc(n * sizeof(int));

  int i;
  for (i = 0; i < n; i++)
  {
    printf("Enter the page number: ");
    scanf("%d", &pages[i]);
  }

  int capacity;
  printf("Enter the capacity of the frame: ");
  scanf("%d", &capacity);

  FIFO(pages, n, capacity);

  return 0;
}