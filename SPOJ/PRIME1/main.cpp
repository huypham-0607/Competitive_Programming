#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define uplim 1000000000
#define lim 31622
#define lowlim 177

using namespace std;

bitset<uplim> bs;
vector<int> prime;
int t;

int nextnum(int x, int i){
    return (i*((x-1)/i)+i);
}

void sieve(){
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (int i=2; i<=lowlim; i++){
        if (bs[i]){
            for (int j = i*i; j<=lim; j+=i){
                bs[j] = 0;
            }
        }
    }
    /*for (int i=0; i<=100; i++){
        cout << bs[i] << " ";
    }*/
    for (int i=0; i<=lim; i++){
        if(bs[i]){
            prime.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cin >> t;
    while (t--){
        int l,r;
        cin >> l >> r;
        for (auto i:prime){
            for (int j=max(i*i,nextnum(l,i)); j<=r; j+=i){
                bs[j] = 0;
            }
            //cout << i << " ";
        }
        for (int i=l; i<=r; i++){
            if (bs[i]) cout << i << "\n";
        }
        cout << "\n";
    }
    return 0;
}
