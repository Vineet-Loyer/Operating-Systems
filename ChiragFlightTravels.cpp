/*
CPU Scheduling
Q. 5: Chirag Flight Travel
QUESTION DESCRIPTION

Semester break has started and Chirag is going home from College . He is taking flight from Chennai to Delhi. After entering the Airport, he was asked to directly go to the counter of boarding pass and without following the queue.

He was Told that The Airline staff follows the SJF (Shortest Job First) algorithm and first process the request of the person who came with the lowest baggage weight as it is easy to process and the waiting time reduces. Chirag is a programmer and wanted to gift a program to the airline which shows the service time (time at which that person will reach the counter), waiting time (service time -arrival time) for each person in the queue and turnaround time (total time from arrival till person gets boarding pass). Also, Calculate average waiting and average turnaround time.

Input: The first line contains the Number of Passengers n. The next n line contains service time.

Output: - The first n lines should print input values, Gnatt Chart for waiting time, Average waiting time, Gnatt Chart for Turn around time, Average turn around time.
TEST CASE 1

INPUT
4
5 9 7 3
OUTPUT
Gnatt Chart for Waiting time=3 8 15 
Average WT=6
Gnatt Chart for Turn Around Time=3 8 15 24 
Average TAT=50
P4 3 0 3
P1 5 3 8
P3 7 8 15
P2 9 15 24
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct process
{
  int bt,ser,trn,pid;
}p[20];

struct process temp;
int main()
{
  int burst[100];
  int n;
  cin>>n;
  for(int i=0;i<n;i++){cin>>burst[i];}
  for(int i=0;i<n+1;i++)
  {
    p[i].pid=i+1;
	p[i].bt=burst[i];
  }
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
		if(p[i].bt > p[j].bt)
        {
          temp=p[i];
          p[i]=p[j];
          p[j]=temp;
        }
    }
  }
  p[0].ser=0;
  for(i=1;i<n;i++){
    p[i].ser=p[i-1].ser+p[i-1].bt;}
  for(i=0;i<n;i++)
  {
    p[i].trn=p[i].ser+p[i].bt;
  }
  int sum=0,sum1=0;
  for(i=0;i<n;i++)
  {
	sum+=p[i].ser;
    sum1+=p[i].trn;
  }
  float avg=int(sum/n);
  float avg1=int(sum1/n);
 cout<<"Gnatt Chart for Waiting time=";
  for(i=1;i<n;i++)
    cout<<p[i].ser<<" ";
  cout<<endl;
  cout<<"Average WT="<<avg;
  cout<<endl;
  cout<<"Gnatt Chart for Turn Around Time=";
   for(i=0;i<n;i++)
    cout<<p[i].trn<<" ";
  cout<<endl;
  cout<<"Average TAT="<<sum1;
  cout<<endl;
  for(i=0;i<n;i++)
  {
    cout<<"P"<<p[i].pid<<" "<<p[i].bt<<" "<<p[i].ser<<" "<<p[i].trn<<endl;
  }
  return 0;
}