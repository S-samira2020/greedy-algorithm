#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

struct Item{
    string name;
    int w, v;
};

bool comp(Item i1, Item i2){
    return i1.v*1.0/i1.w > i2.v*1.0/i2.w;
}

double frac_knapsack(int W, Item items[], int n){
    sort(items, items+n, comp);
//    cout << "\nafter sorting" <<endl;
//    for (int i=0;i<n;i++)
//        cout << items[i].name <<
//        " " << items[i].v*1.0/items[i].w
//        << items[i].v << " " << items[i].w << endl;
//    cout << endl;

    double w = W, profit = 0;/// curr capacity
    int i=0;
    while (w>0.01){
        int vi = items[i].v;
        int wi = items[i].w;
        double xi = min(1.0, w/wi);
//        cout << items[i].name << " "
//            << xi << " " << vi << " "
//            << wi << " " << wi*xi << " " << vi*xi << endl;
///  Taking gold-dust 8.0 kg -- 2000.0 taka
        printf("Taking %s %.1f kg -- %.1f taka\n",
               items[i].name.c_str(), xi*wi, xi*vi);
        i++;
        w = w - xi*wi;

        profit = profit + xi*vi;

    }
    return profit;
}

int main(){
    int W, n;
    cin >> W >> n;
    Item items[n];
    for (int i=0;i<n;i++){
        cin >> items[i].name >> items[i].v >> items[i].w;
    }

    cout << frac_knapsack(W, items, n);
}

/**
15
4
silver-dust 300 4
gold-dust 2000 8
salt 80 10
sugar 89 10
*/
