// Code for SRTF Scheduler in C Programming Language

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

void SRTF(struct process *p, int n)
{
  int i, j;
  int total_waiting_time = 0;
  int total_turnaround_time = 0;

  for (i = 0; i < n; i++)
  {
    if (i == 0)
    {
      p[i].waiting_time = 0;
    }
    else
    {
      p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }
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

  SRTF(p, n);

  return 0;
}
