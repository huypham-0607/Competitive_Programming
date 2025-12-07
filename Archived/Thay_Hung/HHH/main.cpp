#include <bits/stdc++.h>
#define lim 10000000
#define lowlim 3162

using namespace std;

int l,r;
unsigned long long ans[lim+10];

void make(){
    for (int i=2; i<=lowlim; i++){
        ans[i*i]+=i;
        for (int j=i*i+i; j<=lim; j+=i){
            ans[j]+=i+j/i;
        }
    }
}

int main()
{
    freopen("HHH.INP","r",stdin);
    freopen("HHH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=0; i<=lim; i++){
        ans[i] = 1;
    }
    ans[1] = 0;
    make();
    cin >> l >> r;
    unsigned long long res=0;
    for (unsigned long long i=l; i<=r; i++){
        if (i>ans[i]){
            res+=(i-ans[i]);
        }
        else{
            res+=(ans[i]-i);
        }
    }
    cout << res;
    return 0;
}
