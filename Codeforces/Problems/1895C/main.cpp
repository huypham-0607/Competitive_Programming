#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
vector<pair<int,string>> v;
map<pii,int> mp;

int cal(string s){
    int t=0;
    while (s!=""){
        t+=(s[0] - '0');
        s = s.substr(1);
    }
    return t;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        //cout << cal(s) << endl;
        int meow = s.size();
        mp[{meow,cal(s)}]++;
        v.push_back({-meow,s});
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(auto in:v){
        string s = in.se;
        int meow = s.size();
        int t = cal(s);
        ans+=mp[{s.size(),t}];
        int t2;
        for (int i=1; i<(s.size()+1)/2; i++){
            t2 = (t - cal(s.substr(0,i)))*2 - t;
            ans+=mp[{(s.size()-i)-i,t2}];
            t2 = (cal(s.substr(0,s.size()-i))*2)-t;
            ans+=mp[{(s.size()-i)-i,t2}];
        }
    }
    cout << ans;
    return 0;
}
