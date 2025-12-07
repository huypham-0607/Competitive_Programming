#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "CYCLE"

using namespace std;

const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,m,k;
vector<int> p;
vector<int> q;

void Init(){
    p.clear();
    q.clear();
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        --x;
        p.push_back(x);
    }
    sort(all(p));
    for (int i=1; i<=k; i++){
        int x; cin >> x;
        --x;
        q.push_back(x);
    }
    sort(all(q));
}

namespace Sub4{
    bool CheckSub(){ return true; }

    vector<int> cstp, cstq;

    void process(vector<int>& event, int orgcur, int orgchange, int orgpos, vector<int>& dp){
        int pos=orgpos, change = orgchange, cur = orgcur;
        int idx = 0;
        for (int i=pos; i<pos+n; i++){
            dp[i] = min(dp[i],cur);

            while (idx!=(int)event.size() && event[idx] == i){
                change+=2;
                ++idx;
            }
            cur+=change;
        }
    }

    void SolveSub(){
        cstp.clear();
        cstq.clear();
        cstp.resize(n*2+10,INF);
        cstq.resize(n*2+10,INF);
        for (int i=0; i<m-1; i++){
            p.push_back(p[i]+n);
        }
        for (int i=0; i<k-1; i++){
            q.push_back(q[i]+n);
        }
        vector<int> event;
        for (int i=0; i<m; i++){
            int pos = p[i];
            int change = 1;
            int cur = 0;
            for (int tmp=1; tmp<m; tmp++){
                event.push_back(p[i+tmp]-tmp);
                cur+=p[i+tmp]-(pos+tmp);
                change-=1;
            }
            process(event,cur,change,pos,cstp);
            event.clear();
        }
        for (int i=0; i<k; i++){
            int pos = q[i];
            int change = 1;
            int cur = 0;
            for (int tmp=1; tmp<k; tmp++){
                event.push_back(q[i+tmp]-tmp);
                cur+=q[i+tmp]-(pos+tmp);
                change-=1;
            }
            process(event,cur,change,pos,cstq);
            event.clear();
        }
        for (int i=n; i<n*2; i++){
            cstp[i%n] = min(cstp[i%n],cstp[i]);
            cstq[i%n] = min(cstq[i%n],cstq[i]);
        }
        int ans = INF;
        for (int i=0; i<n; i++){
            for (int idx=i+m; idx<i+m+n; idx++){
                int j = idx;
                if ((j+k)>=n && (j+k)-n > i) break;
                else ans = min(ans,cstp[i] + cstq[j%n]);
//                cout << i << " " << j << endl;
            }
        }

//        cout << endl;
//        for (int i=0; i<n; i++){
//            cout << cstp[i] << " " << cstq[i] << endl;
//        }
        cout << ans << endl;
    }
}

signed main(){
    freopen(NAME ".inp","r",stdin);
    freopen(NAME ".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ntest;
    cin >> ntest;
    for (int itest=1; itest<=ntest; itest++){
        Init();
        if (Sub4::CheckSub()) Sub4::SolveSub();
    }


    return 0;
}
