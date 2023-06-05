// Code for Bankers Algorithm for Deadlock Avoidance

#include <stdio.h>
#include <stdlib.h>

void BankersAlgo(int n, int m, int *alloc, int *max, int *avail, int *need)
{
  int i, j, k, flag, count = 0, *work, *finish, *safeSeq;
  work = (int *)malloc(m * sizeof(int));
  finish = (int *)malloc(n * sizeof(int));
  safeSeq = (int *)malloc(n * sizeof(int));
  for (i = 0; i < m; i++)
    work[i] = avail[i];
  for (i = 0; i < n; i++)
    finish[i] = 0;
  while (count < n)
  {
    flag = 0;
    for (i = 0; i < n; i++)
    {
      if (finish[i] == 0)
      {
        for (j = 0; j < m; j++)
        {
          if (need[i * m + j] > work[j])
            break;
        }
        if (j == m)
        {
          for (k = 0; k < m; k++)
            work[k] += alloc[i * m + k];
          finish[i] = 1;
          safeSeq[count++] = i;
          flag = 1;
        }
      }
    }
    if (flag == 0)
    {
      printf("System is in unsafe state\n");
      return;
    }
  }
  printf("System is in safe state\n");
  printf("Safe sequence is: ");
  for (i = 0; i < n; i++)
    printf("%d ", safeSeq[i]);
  printf("\n");
}

int main()
{
  int n, m, i, j;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  printf("Enter number of resources: ");
  scanf("%d", &m);
  int *alloc, *max, *avail, *need;
  alloc = (int *)malloc(n * m * sizeof(int));
  max = (int *)malloc(n * m * sizeof(int));
  avail = (int *)malloc(m * sizeof(int));
  need = (int *)malloc(n * m * sizeof(int));
  printf("Enter allocation matrix:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &alloc[i * m + j]);
  printf("Enter max matrix:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &max[i * m + j]);
  printf("Enter available matrix:\n");
  for (i = 0; i < m; i++)
    scanf("%d", &avail[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      need[i * m + j] = max[i * m + j] - alloc[i * m + j];
  BankersAlgo(n, m, alloc, max, avail, need);
  return 0;
}