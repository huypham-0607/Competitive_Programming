#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e17+7;

int test;
int n,k;
int w[22];
pii dp[(1<<20)+3];


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i=0; i<n; i++){
        cin >> w[i];
    }

    for (int mask=0; mask<(1<<n); mask++){
        dp[mask] = {INF,INF};
    }

   dp[0] = {1,0};

    for (int mask=0; mask<(1<<n); mask++){
        for (int idx=0; idx<n; idx++){
            if (!(mask&(1<<idx))){
                int rides = dp[mask].fi;
                int weight = dp[mask].se;

                if (weight+w[idx]>k){
                    rides++;
                    weight=w[idx];
                }
                else weight+=w[idx];

                dp[(mask^(1<<idx))] = min(dp[(mask^(1<<idx))],make_pair(rides,weight));
            }
        }
    }

    cout << dp[(1<<n)-1].fi;

    return 0;
}
