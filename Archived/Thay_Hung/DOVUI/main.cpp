#include <bits/stdc++.h>

using namespace std;

int a,b,t=0;

int cost(int a,int lvl,int c){
    if (c<3) c++;
    else c+=2;
    if (a>99*lvl){
        return lvl*99*c+cost(a-lvl*99,lvl*100,c);
    }
    else return a*c;
}
int main()
{
    freopen("DOVUI.INP","r",stdin);
    freopen("DOVUI.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;

    if (a>200){
        a-=200;
        t+=100;
    }
    else{
        t+=a/2;
        a=0;
    }

    if (a>29700){
        a-=29700;
        t+=9900;
    }
    else{
        t+=a/3;
        a=0;
    }

    if (a>4950000){
        a-=4950000;
        t+=(990000+a/7);
        a=0;
    }
    else{
        t+=a/5;
        a=0;
    }

    int l=0, r=t/2,mid;
    while (l<=r){
        mid = (l+r)/2;
        //cout << l << " "<< mid << " "<< r <<" "<<(cost(t-mid-1,1,1)+2-cost(mid-1,1,1)+2)<< endl;
        if ((cost(t-mid-1,1,1)+2-cost(mid-1,1,1)-2) == b) break;
        else if ((cost(t-mid-1,1,1)+2-cost(mid-1,1,1)-2) > b) l = mid+1;
        else r = mid-1;
    }
    cout << cost(mid-1,1,1)+2;
    return 0;
}
