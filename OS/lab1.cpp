#include <bits/stdc++.h>
#define fr(i,x,y) for (int i = x; i < y; i++) 
#define vl vector<int>
using namespace std;

void show(vector<int> &v) {
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main(void)
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vl at(n);
    vl bt(n);

    cout << "Enter arrival time: ";
    fr(i,0,n) cin >> at[i];
    
    cout << "Enter burst time: ";
    fr(i,0,n) cin >> bt[i];

    //completion time
    vl ct(n);

    ct[0] = at[0] + bt[0];

    fr(i,1,n) {
        ct[i] = ct[i-1] > at[i] ? ct[i-1]+bt[i] : ct[i] = at[i] + bt[i]; 
    }
    
    //turnaround time
    
    vl tt(n);
    fr(i,0,n) {
        tt[i] = ct[i] - at[i];
    }

    //waiting time
    vl wt(n);
    fr(i,0,n) {
        wt[i] = ct[i] - bt[i] - at[i];
    }

    //response time
    vl rt(n);
    fr(i,0,n) rt[i] = wt[i];
    
    //display;

    cout << "Completion time: ";
    show(ct);

    cout << "Waiting time: ";
    show(wt);

    cout << "Turnaround time: ";
    show(tt);

    cout << "Response Time: ";
    show(rt);
}