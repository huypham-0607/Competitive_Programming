#include "bits/stdc++.h"
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define endl '\n'
#define f first
#define mp make_pair
#define s second
using namespace std;

const int M = 1e9 + 7, N = 500005;

void add(int &x, int y){
    x = (x + y) % M;
    while(x < 0) x += M;
}

struct BIT{
    vector <int> ft;
    int n;
    BIT(int N){ft = vector<int>(N + 5, 0); n = N;}
    void update(int x, int v){while(x <= n) add(ft[x], v), x += (x & -x);}
    int query(int x){
        if(x <= 0) return 0;
        return x > 0 ? (ft[x] + query(x-(x & -x))) % M : 0;
    }
};

int n;
string str;
int dp[N];

BIT even(N + 5), odd(N + 5);
vector <int> g[N];

signed main()
{
    fast;
    cin >> n >> str;
    str = "  " + str;
    dp[1] = 1;
    odd.update(1, 1);
    vector <int> bs;
    for(int i = 2; i <= n + 1; i++) if(str[i] == 'B') bs.push_back(i);
    reverse(bs.begin(), bs.end());
    int lastR = -1;
    for(int i = 2; i <= n + 1; i++){
        for(int j : g[i]){
            if(j & 1) odd.update(j, -dp[j]);
            else even.update(j, -dp[j]);
        }
        if(str[i] == 'R'){
            lastR = i;
            if(!bs.size()) continue;
            int front = bs.back();
            int dist = front - i + 1;
            if(2 * dist + i - 1 < N) g[2 * dist + i - 1].push_back(i - 1);
            continue;
        }
        if(str[i] == 'X') add(dp[i], dp[i - 1]);
        //query form prev R
        int mxIdx = max(0, i - 2 * (i - lastR));
        if(i & 1){
            int x = (odd.query(i) - odd.query(mxIdx - 1) + M) % M;
            add(dp[i], x);
            odd.update(i, dp[i]);
        }
        else{
            int x = (even.query(i) - even.query(mxIdx - 1) + M) % M;
            add(dp[i], x);
            even.update(i, dp[i]);
        }
        if(bs.size()){
            int front = bs.back();
            if(front == i) bs.pop_back();
            int dist = front - i + 1;
            if(2 * dist + i - 1 < N) g[2 * dist + i - 1].push_back(i - 1);
        }
    }
    cout << dp[n + 1] << endl;
}
