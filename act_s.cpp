#include<bits/stdc++.h>
using namespace std;
#define N 6

struct A
{
    int s, f;

};
bool comp(A a1, A a2)
{
    return (a1.f>a2.f);
}
void activity_selection(A as[], int n)
{
    sort(as,as+n,comp);

    int i=0;
    cout << "(" <<as[i].s<< ", " <<as[i].f << ")\n";
    for(int j=1;j<n;j++)
    {
        if(as[j].s>=as[i].f)
        {
            cout<< "(" <<as[j].s << ", " << as[j].f << ") \n";
            i = j;
        }
    }
}

int main()
{
    A as[N];
    for(int i=0;i<=N-1;i++)
    {


        cin >> as[i].s >> as[i].f;
    }
    activity_selection(as,N);
    return 0;
}
