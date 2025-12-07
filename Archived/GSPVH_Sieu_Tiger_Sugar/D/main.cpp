#include <bits/stdc++.h>
#define int unsigned long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxsieve = 10000060;
const int divi = 998244353;
const int maxn = 1e14;

bitset<maxsieve> bs;
vector<int> prime,ans,ans2;

void sieve(){
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (int i=2; i*i<=10000000; i++){
        if (bs[i]){
            for (int j=i*i; j<=10000000; j+=i){
                bs[j] = 0;
            }
        }
    }
    for (int i=2; i<=10000000; i++){
        if (bs[i]) prime.push_back(i);
    }
}



signed main(){
    //freopen("primelcm.INP","r",stdin);
    //freopen("primelcm.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int x:prime){
        pq.push({x*x,x});
    }

    int cur = 1;
    ans.push_back(1);
    ans2.push_back(1);
    while (!pq.empty()){
        int x = pq.top().fi;
        int snt = pq.top().se;
        pq.pop();
        cur = (cur*snt)%divi;
        ans.push_back(x);
        ans2.push_back(cur);
        if (x <= maxn / snt) pq.push({x*snt,snt});
    }
    /*cout << "\n";
    cout << ans[670125] << "\n";
    cout << ans2.size() << "\n";
    for (int i = 50; i<100; i++){
        cout << ans2[i] << " ";
    }*/
    int t;
    int n;
    cin >> t;
    while (t--){
        cin >> n;
        cout << ans2[(upper_bound(ans.begin(),ans.end(),n) - ans.begin()) -1] << " ";
    }
    return 0;
}
