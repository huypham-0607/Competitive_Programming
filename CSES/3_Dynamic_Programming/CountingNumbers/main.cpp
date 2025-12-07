#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

unsigned long long level[20],a,b;
unsigned long long ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    level[0] = 1;
    for (int i=1; i<=18; i++){
        level[i] = level[i-1]*9;
    }
    cin >> a >> b;
    if (b == 1000000000000000000) b--;
    unsigned long long total = 0;
    unsigned long long t = 0;
    unsigned long long lvla = 0;
    while (a!=0){
        unsigned long long unit = a%10;
        a/=10;
        lvla++;
        if (unit == a%10) t=0;
        t+=unit*level[lvla-1];
        if (unit > a%10) t-=level[lvla-1];
    }
    //cout << t << " ";
    total+=t;
    //ans-=t;
    t = 0;
    unsigned long long lvlb = 0;
    while (b!=0){
        unsigned long long unit = b%10;
        b/=10;
        lvlb++;
        if (unit == b%10) t=0;
        t+=(9-unit)*level[lvlb-1];
        if (unit < b%10) t-=level[lvlb-1];
    }
    //cout << t << " ";
    //ans-=t;
    total+=t;
    for (unsigned long long i=lvla; i<=lvlb; i++){
        ans+=level[i];
    }
    ans-=total;
    cout << ans;
    return 0;
}
