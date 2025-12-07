#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

#define NAME "SCHEDULE"

using namespace std;

const int maxn = 1e5+10;
const int INF = 1e9+7;

//Global Variables
int test;
int n,m;
int t[maxn],s[maxn],e[maxn];

//Inititalization
void Init(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> t[i] >> s[i] >> e[i];
    }
}

//Subtask1
bool CheckSub1(){
    bool res = true;
    for (int i=1; i<=n; i++){
        if (s[i]!=e[i]) res = false;
    }
    return res;
}

map<int,int> mp;

void SolveSub1(){
    int mx = 0;
    for (int i=1; i<=n; i++){
        mp[s[i]]+=t[i];
        mx = max(mx,mp[s[i]]);
    }
    cout << mx;
}

//Subtask2
bool CheckSub2(){
    return false;
}

void SolveSub2(){

}

//Subtask3
bool CheckSub3(){

    return false;
}

void SolveSub3(){

}

//Subtask4
bool CheckSub4(){
    return true;
}

vector<piii> v;
priority_queue<pii,vector<pii>,greater<pii>> pq;
int task;

int BsearchCheck(int val){
    while (!pq.empty()) pq.pop();
    int done = 0;

    int pos = 0;
    int cur = 0;
//    if (val == 3) cout << "{" << 3 << "}" << endl;
    for (int meow=0; meow<=n; meow++){
        int i = v[meow].se;
//        if (val == 3) cout << " " << v[meow].fi.fi << " " << v[meow].fi.se << " " << v[meow].se << " " << cur << endl;

        cur+=val*(ed-s[i]);
        while (!pq)
        while (!pq.empty() && pq.top().se<=cur){
            int ed = pq.top().fi;
            int w = pq.top().se;

            pq.pop();

            cur+=val*(ed-pos);
            cur-=w;

//            if (val == 3)cout << cur << " " << pos << " " << ed << " " << w << endl;

            if (cur<0) return false;
            pos = ed;
        }
        if (pq.empty()){
            cur = 0;
            pos = s[i]-1;
        }
        pq.push({e[i],t[i]});
    }
    return true;
}

void SolveSub4(){
    for (int i=1; i<=n; i++){
        task+=t[i];
        v.push_back({{s[i],e[i]},i});
    }
    v.push_back({{INF,INF},0});
    s[0] = INF;
    e[0] = INF;
    t[0] = 0;
    sort(v.begin(),v.end());

    int ans = 0, l=1, r=100000000000000010;

    while (l<=r){
        int mid = (l+r)/2;
//        cout << l << " " << r << " " << mid << " " << ans << endl;
        if (!BsearchCheck(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
//    cout << BsearchCheck(3) << endl;
    cout << ans+1 << endl;
}

//Driver Code
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub1()) return SolveSub1(),0;
    if (CheckSub2()) return SolveSub2(),0;
    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;

    return 0;
}
