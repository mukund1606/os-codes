// Code for Priority Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

void PriorityScheduling(int n, int *burst, int *priority)
{
  int i, j, *wt, *tat, *p, *pos, temp;
  float avgwt = 0, avgtat = 0;
  wt = (int *)malloc(n * sizeof(int));
  tat = (int *)malloc(n * sizeof(int));
  p = (int *)malloc(n * sizeof(int));
  pos = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
  {
    p[i] = priority[i];
    pos[i] = i;
  }
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (p[j] > p[j + 1])
      {
        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
        temp = pos[j];
        pos[j] = pos[j + 1];
        pos[j + 1] = temp;
      }
    }
  }
  wt[0] = 0;
  for (i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + burst[pos[i - 1]];
    avgwt += wt[i];
  }
  for (i = 0; i < n; i++)
  {
    tat[i] = wt[i] + burst[pos[i]];
    avgtat += tat[i];
  }
  printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++)
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pos[i], burst[pos[i]], priority[pos[i]], wt[i], tat[i]);
  printf("Average waiting time: %f\n", avgwt / n);
  printf("Average turnaround time: %f\n", avgtat / n);
}

int main()
{
  int n, i, *burst, *priority;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  burst = (int *)malloc(n * sizeof(int));
  priority = (int *)malloc(n * sizeof(int));
  printf("Enter burst time and priority for each process:\n");
  for (i = 0; i < n; i++)
    scanf("%d%d", &burst[i], &priority[i]);
  PriorityScheduling(n, burst, priority);
  return 0;
}
