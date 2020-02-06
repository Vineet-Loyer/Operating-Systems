/*QUESTION
SESSION: CPU Scheduling
Q. 4: Bogar Birthday Party - Day 2
QUESTION DESCRIPTION

Bogar a student of TAMIL Siddha College On his birthday took his n Friends (F1, F2, F3. Fn) to Naturopathy hotel for a treat. The waiter noted the order of F1, F2, F3. Fn as O1, O2, O3. On respectively.

Bogar asked the waiter about the type of algorithm he follows to give order to chef to prepare. Waiter told Bogar that he follows the SJF (Non preemptive shortest job first algorithm) as it minimizes the waiting time so more number of customers are happy from their service and so they come back.

Print the waiting time, time at which chef starts to prepare the order (Preparation start time) (service time) and time in which the order completes (turnaround time) for each one of them.

Print the average waiting and average turnaround time. Assume F1 gets the menu first and orders first then F2 and so on Therefore the time at which the order is given to the waiter (Arrival time) changes for each friend.

Input: The first line contains the Number of friend/s. The next n line contains the Friend name, order give time(Burst Time) and time taken by chef to cook that order for F1, F2, F3. Fn. (Arrival Time=0)


Output: - The first n lines should print input values, waiting time and Time in which the order completes (Turn Around time) for each friend in each line. Print average waiting and average turnaround time in next two lines respectively
TEST CASE 1

INPUT
4
eLabTeam
eThinkTeam
eCurriculaTeam
eVerifyTeam
3 6 4 2
0 0 0 0
OUTPUT
Sorting Depend on Burst Time
eVerifyTeam 2 0
eLabTeam 3 0
eCurriculaTeam 4 0
eThinkTeam 6 0
Waiting Time
Time Taken for eVerifyTeam=0
Time Taken for eLabTeam=2
Time Taken for eCurriculaTeam=5
Time Taken for eThinkTeam=9
Average Waiting Time=4.000000
TurnAround Time
Time Taken for eVerifyTeam=2
Time Taken for eLabTeam=5
Time Taken for eCurriculaTeam=9
Time Taken for eThinkTeam=15
Average TurnAround Time=7.750000

CODE:

*/
#include <iostream>
using namespace std;
int main() 
{
	int size;
    cin>>size;
    string name[size];
    for(int i=0;i<size;i++)
      cin>>name[i];
    int bt[size];
    for(int i=0;i<size;i++)
      cin>>bt[i];
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<size-i-1;j++)
      {
        if(bt[j]>bt[j+1])
        {
          string value=name[j];
          name[j]=name[j+1];
          name[j+1]=value;
          int loc=bt[j];
          bt[j]=bt[j+1];
          bt[j+1]=loc;
        }
      }
    }
    cout<<"Sorting Depend on Burst Time\n";
    for(int i=0;i<size;i++)
    {
      cout<<name[i]<<" "<<bt[i]<<" 0\n";
    }
    int wait[size],ta[size];
    float avgw=0.0,avgta=0.0;
    wait[0]=0;
    cout<<"Waiting Time\n";
    for(int i=1;i<size;i++)
    { 
      wait[i]=wait[i-1]+bt[i-1];
      cout<<"Time Taken for "<<name[i-1]<<"="<<wait[i-1]<<endl;
      avgw+=wait[i];
    }
    cout<<"Time Taken for "<<name[size-1]<<"="<<wait[size-1]<<endl;
    cout<<"Average Waiting Time="<<fixed<<setprecision(6)<<(float)avgw/(float)size<<endl;
    cout<<"TurnAround Time\n";
    for(int i=0;i<size;i++)
    {
      ta[i]=wait[i]+bt[i];
      cout<<"Time Taken for "<<name[i]<<"="<<ta[i]<<endl;
      avgta+=ta[i];
    }
    cout<<"Average TurnAround Time="<<fixed<<setprecision(6)<<(float)avgta/(float)size<<endl;
	return 0;
}