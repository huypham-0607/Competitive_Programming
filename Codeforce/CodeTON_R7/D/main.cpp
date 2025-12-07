#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 2e9;

int n,q,test;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n >> q;
        int cnt = 0;
        priority_queue<int,vector<int>,greater<int>> low;
        priority_queue<int> high;
        int t=0;
        int left,right;
        a[0] = 1;
        a[n+1] = 1;
        low.push(n+1);
        high.push(0);
        for (int i=1; i<=n; i++){
            cin >> a[i];
            if (a[i] == 1){
                ++cnt;
                low.push(i);
                high.push(i);
            }
            t+=a[i];
            left = (low.top()-1)*2+1;
            right = (n-high.top())*2+1;
        }
        int op;
        while (q--){
            cin >> op;
            if (op == 1){
                int x;
                cin >> x;
                int verify,val;
                verify = x%2;
                if (cnt%2) verify = (verify+1)%2;
                if (!verify){
                    val = t;
                }
                else val = t-min(left,right);
                if (x<=val) cout << "YES" << endl;
                else cout << "NO" << endl;
//                cout << val << endl;
            }
            else{
                int pos,val;
                cin >> pos >> val;
                t+=(val-a[pos]);
                if (val == 1 && a[pos]!=val){
                    ++cnt;
                    low.push(pos);
                    high.push(pos);
                }
                else if (val == 2 && a[pos]!=val){
                    --cnt;
                }
                a[pos] = val;
                while (a[low.top()] == 2){
                    low.pop();
                }
                while (a[high.top()] == 2){
                    high.pop();
                }
                left = (low.top()-1)*2+1;
                right = (n-high.top())*2+1;
            }
        }
    }
    return 0;
}
