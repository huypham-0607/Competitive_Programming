/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
int n,m;
int p1[6010],p2[6010];
string s,t;

//KMP
void KMP(string s,int *pi){
    pi[0] = 0;
    for (int i=1; i<(int) s.size(); i++){
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if (s[i]==s[j]) pi[i] = j+1;
        else pi[i] = 0;
    }
}

//Solve
pair<int,pii> get(string s, string t, bool rev){
    pair<int,pii> res = {0,{0,0}};
    for (int i=0; i<=n; i++){
        string s1,s2,t1,t2;
        s1 = s.substr(0,i); s2 = s.substr(i);
        t1 = t; t2 = t;
        reverse(s1.begin(),s1.end());
        reverse(t2.begin(),t2.end());
        KMP(s1+"#"+t2,p1);
        KMP(s2+"#"+t1,p2);
//        if (i == 7){
//            string rawr1 = s1+"#"+t2;
//            string rawr2 = s2+"#"+t1;
//            cout << s1+"#"+t2 << endl;
//            cout << s2+"#"+t1 << endl;
//            for (int i=0; i<(int)rawr1.size(); i++){
//                cout << p1[i] << " ";
//            }
//            cout << endl;
//            for (int i=0; i<(int)rawr2.size(); i++){
//                cout << p2[i] << " ";
//            }
//            cout << endl;
//        }
        for (int j=0; j<=m; j++){
            res = max(res,{p1[i+m-j]+p2[n-i+j],
                            {i-p1[i+m-j],
                            (rev)? m-(j+p1[i+m-j]): j-p2[n-i+j]}});
        }
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> s >> t;
    n = (int) s.size();
    m = (int) t.size();
    pair<int,pii> ans = get(s,t,0);
    reverse(t.begin(),t.end());
    ans = max(ans,get(s,t,1));
    cout << ans.fi << endl << ans.se.fi << " " << ans.se.se;
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
