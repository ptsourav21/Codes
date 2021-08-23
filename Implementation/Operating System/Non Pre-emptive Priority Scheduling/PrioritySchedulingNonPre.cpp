/* Implemented By Purnendu Talukder
Ahsanullah University Of Science and Technology
Department: CSE       Batch: 41*/

#include<iostream>

using namespace std;

struct fcfs{
    int p, at, ct, tt, wt, pr;

};


int main(){
    int i, n, j, tl[10];
    float avg=0.0, sum1 =0.0, sum2 =0.0;
    struct fcfs ar[10], temp;
    cout<<"Enter total number of processes: ";
    cin>>n;
    cout<<"\nEnter id, arrival times, cpu times, priority: "<<endl;
    for(i=0; i<n; i++)
    {
        cin>>ar[i].p;
        cin>>ar[i].at;
        cin>> ar[i].ct;
        cin>>ar[i].pr;
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(ar[j].at>ar[j+1].at)
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    //timline

    tl[0]=ar[0].at;
    for(i=0; i<n-1; i++)
    {
        for(j=1; j<n+1; j++)
        {
            if(ar[j].pr>ar[j+1].pr)
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    for(i=1; i<n+1; i++)
    {
        tl[i]=tl[i-1] + ar[i-1].ct;
    }

    //wt
    for(i=0; i<n; i++)
    {
        if(ar[i].at!= 0)
        {
        ar[i].wt=tl[i]-ar[i].at;
        }
        else
            ar[0].wt=0;
    }
    //tt
    for(i=0; i<n; i++)
    {

        ar[i].tt=ar[i].wt+ar[i].ct;

    }

    cout<<endl;
    cout<<"Process\tWaiting time\tTurnaroun time\t"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<ar[i].p<<"\t\t"<<ar[i].wt<<"\t\t"<<ar[i].tt<<"\t\t"<<ar[i].pr;
        cout<<endl;
    }

    for(i=0; i<n; i++)
    {
        sum1+=ar[i].wt;
        sum2+=ar[i].tt;
    }
    avg=sum1/(float)n;
    cout<<"Average CPU time: "<<avg<<endl;
    avg=sum2/(float)n;
    cout<<"Average Turnaround time: "<<avg<<endl;
}

