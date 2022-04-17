#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct A{
    int i;
    int s, f;

};
bool comp(A a1, A a2)
{
    return a1.f < a2.f;
}
void activity_selection(int s[],int f[],int n)
{
    A as[n];
    for(int i=0;i<n;i++)
    {
        as[i].i = i;
        as[i].s = s[i];
        as[i].f = f[i];
    }
    sort(as, as+n, comp);
    vector<A> sol;
    sol.push_back(as[0]);
    int k = 0;
    for(int m=1;m<n;m++)
    {
        if(as[m].s >= as[k].f)
        {
            sol.push_back(as[m]);
            k = m;
        }
    }
    for(A a: sol)
        cout << a.i << " " << a.s << " " << a.f << endl;
}

struct p
    {
        char name;
        int s, f;
    };

void activity_selection2(A as[], int n)
{
    sort(as, as+n, comp);
    vector<A> sol;
    sol.push_back(as[0]);
    int k = 0;
    for(int m=1;m<n;m++)
    {
        if(as[m].s >= as[k].f)
        {
            sol.push_back(as[m]);
            k = m;
        }

}
    for(A a: sol)
        cout << a.i << " " << a.s << " " << a.f << endl;
}

int main()
{
    int n;
    cin >> n;
    A passengers[n];
    for(int i=0;i<n;i++)
    {
        char c;
        int start, interval;
        cin >> c;
        cin >> start >> interval;
        passengers[i] .i = c;
        passengers[i].s = start;
        passengers[i].f =start+interval;
    }
    activity_selection2(passengers, n);
}


