#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

pair <float,int> a[10];
int n,m;
float r,t,d,x,mx;


int fktr(int n){
    int t=1;
    for (int i=1; i<=n; i++){
        t*=i;
    }
    return t;
}

void hv(){
    int i=n-1,j=n;
    while (a[i].second > a[i+1].second){
        i--;
    }
    while (a[j].second < a[i].second){
        j--;
    }
    a[i].swap(a[j]);
    for (int k=1; k<=(n-i)/2;k++){
        a[i+k].swap(a[n-k+1]);
    }
}

float di(float r1,float r2){
    return sqrt((r1+r2)*(r1+r2)-abs((r1-r2)*(r1-r2)));
}

int main()
{
    freopen("XEPVONG.INP","r",stdin);
    freopen("XEPVONG.OUT","w",stdout);
    cin >> n;
    m=fktr(n);
    //printf("%.2f",mx);
    a[0].first = 0; a[0].second = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i].first;
        //cout << a[i].first << " ";
        a[i].second=i;
    }
    //cout << endl;
    mx = numeric_limits<float>::max();
    for (int i=0; i<m; i++){
        t=0;
        for (int j=1; j<=n; j++){
            x=di(a[j].first, a[j-1].first);
            //cout << x << " "<< a[j].first <<" ";
            r=(a[j].first > a[j-1].first)? a[j].first : a[j-1].first;
            d= (x>r) ? x : r;
            t+=d;
            //cout << t << endl;
        }
        t+=a[n].first;
        //cout << t << endl;
        //printf("%.2f",mx);
        //cout << endl;
        mx = (t < mx) ? t : mx;
        hv();
    }

    printf("%.3f",mx);
    return 0;
}
