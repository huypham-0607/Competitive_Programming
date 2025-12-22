#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int primemax = 3170;
const int maxn = 1e7;
vector<int> prime;
int t,x,y;

void sieve(){
    bitset<maxn+10> bs;
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (int i=2; i*i<=maxn; i++){
        if (bs[i]){
            for (int j = i*i; j<=maxn; j+=i){
                bs[j] = 0;
            }
        }
    }
    for (int i=2; i<=maxn; i++){
        if (bs[i]) prime.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cin >> t;
    while (t--){
        cin >> x >> y;
        if (y<=3) cout << -1 << "\n";
        else{
        x = max(4,x);
        if (x!=y){
            x+=(x%2);
            cout << 2 << " " << x-2 << "\n";
        }
        else{
            for (auto p:prime){
                if (p>=x) break;
                if ((x-p)%p == 0){
                    cout << p << " " << x-p << "\n";
                    x = 0;
                    break;
                }
            }
            if (x!=0) cout << -1 << "\n";
        }
        }
    }
    return 0;
}
