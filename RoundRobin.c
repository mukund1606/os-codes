// Code for Round Robin Scheduler in C Programming Language

#include <stdio.h>
#include <stdlib.h>

struct process
{
  int pid;
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turnaround_time;
};

void RoundRobin(struct process *p, int n, int quantum)
{
  int i, j;
  int total_waiting_time = 0;
  int total_turnaround_time = 0;

  int *remaining_burst_time = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
  {
    remaining_burst_time[i] = p[i].burst_time;
  }

  int current_time = 0;
  while (1)
  {
    int done = 1;
    for (i = 0; i < n; i++)
    {
      if (remaining_burst_time[i] > 0)
      {
        done = 0;
        if (remaining_burst_time[i] > quantum)
        {
          current_time += quantum;
          remaining_burst_time[i] -= quantum;
        }
        else
        {
          current_time += remaining_burst_time[i];
          p[i].waiting_time = current_time - p[i].burst_time;
          remaining_burst_time[i] = 0;
        }
      }
    }
    if (done == 1)
    {
      break;
    }
  }

  for (i = 0; i < n; i++)
  {
    p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    total_waiting_time += p[i].waiting_time;
    total_turnaround_time += p[i].turnaround_time;
  }

  printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
  }

  printf("Average Waiting Time: %f\n", (float)total_waiting_time / n);
  printf("Average Turnaround Time: %f\n", (float)total_turnaround_time / n);
}

int main()
{
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct process *p = (struct process *)malloc(n * sizeof(struct process));

  int i;
  for (i = 0; i < n; i++)
  {
    printf("Enter the arrival time of process %d: ", i + 1);
    scanf("%d", &p[i].arrival_time);
    printf("Enter the burst time of process %d: ", i + 1);
    scanf("%d", &p[i].burst_time);
    p[i].pid = i + 1;
  }

  int quantum;
  printf("Enter the time quantum: ");
  scanf("%d", &quantum);

  RoundRobin(p, n, quantum);

  return 0;
}