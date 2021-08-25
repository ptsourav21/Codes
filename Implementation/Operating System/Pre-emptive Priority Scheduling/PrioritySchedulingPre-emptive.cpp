#include<bits/stdc++.h>
using namespace std;

struct process {
    int p, at, ct, pr, start_time, completion_time, tt, wt, response_time;
};

int main() {

    int n;
    struct process p[100];
    float atat, awt, avg_response_time, cpu_utilisation, throughput;
    int total_tt= 0, total_wt = 0, total_response_time = 0, total_idle_time = 0;
    int ct_rem[100], is_completed[100], m;
    int current_time = 0, completed = 0, prev = 0, flag = 0, time[100], k = 0, cnt = 0, id[100];

    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;

    cout<<"Enter arrival time of process: \n";
    for(int i = 0; i < n; i++) {
        cin>>p[i].at;
        p[i].p = i+1;
    }

    cout<<"Enter burst time of the process: \n";
    for(int i=0; i<n; i++){
        cin>>p[i].ct;
        ct_rem[i] = p[i].ct;
    }

    cout<<"Enter priority of the process: \n";
    for(int i=0; i<n; i++){
        cin>>p[i].pr;
    }
    cout<<"\n\n";



    while(completed != n) {
        int idx = -1;
        int mx = 100000;
        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && is_completed[i] == 0) {
                if(p[i].pr < mx) {
                    mx = p[i].pr;
                    idx = i;
                    id[cnt] = idx;

                }
                if(p[i].pr == mx) {
                    if(p[i].at < p[idx].at) {
                        mx = p[i].pr;
                        idx = i;
                        id[cnt] = idx;
                    }
                }
            }
        }

        if(idx != id[cnt-1])
        {
           time[k] = cnt;
           id[k] = idx;
           k++;
        }
        m = k;

        if(idx != -1) {
            if(ct_rem[idx] == p[idx].ct) {
                p[idx].start_time = current_time;
                //cout<<p[idx].start_time<<" ";
            }
            ct_rem[idx] -= 1;
            current_time++;
            prev = current_time;
            cnt++;

            if(ct_rem[idx] == 0) {
                time[m] = cnt;
                id[m] = idx;
                m++;
                p[idx].completion_time = current_time;
                p[idx].tt = p[idx].completion_time - p[idx].at;
                p[idx].wt = p[idx].tt - p[idx].ct;

                total_tt += p[idx].tt;
                total_wt += p[idx].wt;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
             cnt++;
        }
    }

    cout<<"\nGantt Chart\n";
    for(int i=0; i<m-1; i++)
    {
        int a;
        a = id[i];
        cout <<"|   "<<"P"<< p[a].p << "   ";
    }
    cout <<"|   ";

    cout<<"\n";
    for(int i=0; i<m; i++)
    {
        cout << time[i] << "\t  ";
    }

    cout<<"\n\n";


    atat = (float) total_tt / n;
    awt = (float) total_wt / n;

    cout<<endl<<endl;

    for(int i=0; i<n; i++){
        cout<<"Process: "<<p[i].p<<"  AT: "<<p[i].at<<"  BT: "<<p[i].ct<<"  CT: "<<p[i].completion_time<<"  TAT: "<<p[i].tt<<"  WT: "<<p[i].wt<<"\n\n";
    }

    cout<<"Average Turnaround Time = "<<atat<<endl;
    cout<<"Average Waiting Time = "<<awt<<endl;
}
