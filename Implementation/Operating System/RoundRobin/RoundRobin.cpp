/* Implemented By Purnendu Talukder
Ahsanullah University Of Science and Technology
Department: CSE       Batch: 41*/

#include<iostream>

using namespace std;

int main()
{
    int i, j, n, q_t, count, temp, ex=0, p[100], at[100], ct[100], rem_ct[100], tat[100], wt[100];
    float atat, awt;

    cout<<"Enter process number: ";
    cin>>n;

    cout<<"Enter Process sequence, Arrival time, Cpu time:\n";
    for(i=0; i<n;i++)
    {
        cin>>p[i];
        cin>>at[i];
        cin>>ct[i];
        rem_ct[i]=ct[i];
    }
    cout<<"Enter quantum time:";
    cin>>q_t;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1; j++)
        {
            if(at[j]>at[j+1])
            {
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                temp=ct[j];
                ct[j]=ct[j+1];
                ct[j+1]=temp;

                temp=rem_ct[j];
                rem_ct[j]=rem_ct[j+1];
                rem_ct[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }

    }

    while(true)
    {
        for(i=0, count=0; i<n; i++)
        {
            temp=q_t;
            if(rem_ct[i]==0)
            {
                count++;
                continue;
            }
            if(rem_ct[i]>q_t)
            {
                rem_ct[i]=rem_ct[i]-q_t;
            }
            else
            if(rem_ct[i]>=0){
                temp=rem_ct[i];
                rem_ct[i]=0;
            }
            ex+=temp;
            tat[i]=ex-at[i];
        }
        if(n==count)
        {
            break;
        }
    }
    cout<<"\nProcess\tArrival Time\t CPU time\t Turnaround Time\t Waiting Time\n";
    for(i=0; i<n; i++){
        atat+=tat[i];
        wt[i]=tat[i]-ct[i];
        awt+=wt[i];
        cout<<"P["<<p[i]<<"]\t\t"<<at[i]<<"\t\t"<<ct[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
    }
    atat=atat/n;
    awt=awt/n;
    cout<<"Averaqe turnaround time: "<<atat<<endl;
    cout<<"Average waiting time: "<<awt<<endl;
}
