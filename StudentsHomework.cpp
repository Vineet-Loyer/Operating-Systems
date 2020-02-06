/* Ques: Students HomeWork
QUESTION DESCRIPTION

Student Karthi is assigned with several homework from various subject by his Teachers.
He is also insisted to complete the homework based on their Priority.
You are asked to calculate average turnaround time and average waiting time.
Note:'1' Should be considered as the highest priority.
Input : 1st line number of process
2nd line burst time of each process
3rd line Priority of each process

TEST CASE 1

INPUT
5
8 7 1 2 4
5 4 1 2 3
OUTPUT
average turn around=9
average waiting time=5

CODE:
*/

#include<iostream>
 
using namespace std;
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    //Enter Total Number of Process:
    cin>>n;
 
    //Enter Burst Time and Priority
    
    for(i=0;i<n;i++)
    {
        //cout<<"\nP["<<i+1<<"]\n";
        //cout<<"Burst Time:";
        cin>>bt[i];
        //cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    
    
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        
    }
 
    avg_tat=total/n;     //average turnaround time
    
    cout<<"\naverage turn around="<<avg_tat;
    cout<<"\naverage waiting time="<<avg_wt;
 
    return 0;
}