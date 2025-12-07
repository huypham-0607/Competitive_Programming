#include <bits/stdc++.h>
#define limit 3000000000
#define lowlim 65536
#define INF 10000000000
//#define int long long
#define ll long long
#define listlim 1000000
using namespace std;

bitset <limit> bs;
vector<ll> prime;
//int a[listlim];
ll l,r;

ll nextnum(ll pos, ll mul){
    return mul*((pos-1)/mul)+mul;
}

void InitSieve(){
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (ll i=2; i<=256; i++){
        if (bs[i]){
            for (ll j=i*i; j<=lowlim; j+=i){
                bs[j] = 0;
            }
        }
    }
    for (ll i=1; i<=lowlim; i++){
        if (bs[i]){
            prime.push_back(i);
        }
    }
}

int main()
{
    freopen("10140.INP","r",stdin);
    freopen("10140.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    InitSieve();
    while (cin >> l >> r){
        if (!l && !r){
            break;
        }
        ll mindist = INF;
        ll maxdist = 0;
        ll minl,minr,maxl,maxr;
        ll c = 0;
        ll pre;
        for (auto i:prime){
            for (ll j=max(nextnum(l,i),i*i); j<=r; j+=i){
                bs[j] = 0;
            }
        }
        for (ll i=l; i<=r; i++){
            if (bs[i]){
                c++;
                if (c>1){
                    if (i-pre<mindist){
                        mindist = i-pre;
                        minl = pre;
                        minr = i;
                    }
                    if (i-pre>maxdist){
                        maxdist = i-pre;
                        maxl = pre;
                        maxr = i;
                    }
                }
                pre = i;
            }
        }
        if (c<=1) cout << "There are no adjacent primes." << "\n";
        else cout << minl << "," << minr << " are closest, " << maxl << "," << maxr << " are most distant." << "\n";

    }
    return 0;
}
