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
string s,e;
map<string,int> mp;
queue<pair<string,int>> q;

void GetNext(string s, int val){
    string s1,s2,s3;
    if (s.size()>0){
        for (int i=0; i<(int)s.size(); i++){
            s1 = s.substr(0,i);
            s2 = s.substr(i+1,(int)s.size()-(i+1));
            s3 = s1+s2;
        }
    }
    if (s.size()<n){

    }
}

void BFS(string s){
    mp[s] = 0;
    q.push({s,0});
    while (!q.empty()){
        string s = q.front().fi;
        int val = q.front().se;

        q.pop();

        GetNext(s,val);
    }
}



/*Solution*/
void solve(){
    cin >> s >> e;
    int n = max(s.size(),e.size());
    BFS(s);
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

