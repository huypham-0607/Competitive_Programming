/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,qr,cnt;
vector<pii> v;
priority_queue<piii,vector<piii>,greater<piii>> query;
map<int,int> mp;
set<int> st;
int ans[N];

//Fenwick Tree
int BIT[N*2];

void update(int idx, int val){
    while (idx<=cnt){
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int get(int idx){
    int sum = 0;
    while (idx>0){
        sum+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

int getpref(int l,int r){
    if (l == 1){
        return get(r);
    }
    else return get(r) - get(l-1);
}

/*Solution*/
void solve(){
    cin >> n >> qr;

    for (int i=1; i<=n; i++){
        int h,w;
        cin >> w >> h;
        v.push_back({h,-w});
        mp[w] = 0;
    }
    sort(v.begin(),v.end());
    for (int i=1; i<=qr; i++){
        int h,w;
        cin >> w >> h;
        query.push({{h,w},i});
        mp[w] = 0;
    }
    cnt = 0;
    for (auto it=mp.begin(); it!=mp.end(); it++){
        mp[it->fi] = ++cnt;
    }
    queue<int> q,q2;

    v.push_back({LLINF,0});
    for (int i=0; i<(long long)(v.size()); i++){
        int h = v[i].fi;
        int w = -v[i].se;
        int id = mp[w];

//        cout << h << " " << w << " " << id << endl;

        if (i && v[i].fi!=v[i-1].fi){
            while (!q.empty()){
                int orgid = q.front();

                auto it = st.lower_bound(orgid);
                if (it!=st.begin()){
                    --it;
                    int id2 = (*it);
                    update(id2,-1);
                    if (!getpref(id2,id2)){
                        st.erase(id2);
                    }
                }
                q2.push(orgid);
                q.pop();
            }
            while (!q2.empty()){
                st.insert(q2.front());
                update(q2.front(),1);
                q2.pop();
            }
        }
        q.push(id);

//        cout << get(cnt) << endl;

        while (!query.empty() && query.top().fi.fi < h){
            int w = query.top().fi.se;
            int idx = query.top().se;
            int id2 = mp[w];
            ans[idx] = getpref(id2,cnt);
            query.pop();
        }
    }
//    for(auto it = st.begin(); it!=st.end(); it++){
//        cout << *it << " ";
//    }
//    cout << endl;
    for (int i=1; i<=qr; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
