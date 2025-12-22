/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int LG = 21;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
pii SOS_and[(1<<LG)+10];
int SOS_or[(1<<LG)+10];

pii Update(pii u, pii x){
    if (x.fi > u.fi){
        u.se = u.fi;
        u.fi = x.fi;
    }
    else if (x.fi > u.se){
        u.se = x.fi;
    }

    if (x.se > u.fi){
        u.se = u.fi;
        u.fi = x.se;
    }
    else if (x.se > u.se){
        u.se = x.se;
    }
    return u;
}

/*Solution*/
void solve(){
    cin >> n;

    for (int i=0; i<(1<<LG); i++){
        SOS_or[i] = INF;
    }

    for (int i=1; i<=n; i++){
        int x; cin >> x;
        SOS_and[x] = Update(SOS_and[x],make_pair(i,0));
        SOS_or[x] = min(SOS_or[x],i);
    }

    for (int i=0; i<LG; i++){
        for (int mask=0; mask<(1<<LG); mask++){
            if (!(mask&(1<<i))) SOS_and[mask] = Update(SOS_and[mask],SOS_and[mask^(1<<i)]);
        }
    }

    for (int i=0; i<LG; i++){
        for (int mask=0; mask<(1<<LG); mask++){
            if (!(mask&(1<<i))) SOS_or[mask] = min(SOS_or[mask],SOS_or[mask^(1<<i)]);
        }
    }

//    for (int i=0; i<(1<<LG); i++){
//        cout << SOS_and[i].fi << " " << SOS_and[i].se << " " << SOS_or[i] << endl;
//    }

    int ans = 0;

    for (int mask=0; mask<(1<<LG); mask++){
        int tmpmask = 0;
        for (int idx=LG-1; idx>=0; idx--){
            if (mask&(1<<idx)) continue;
            int newmask = (tmpmask^(1<<idx));
            if (SOS_or[newmask] < SOS_and[mask].se){
                tmpmask = newmask;
            }
        }

        if (SOS_or[tmpmask] < SOS_and[mask].se){
            ans = max(ans,tmpmask|mask);
        }
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
