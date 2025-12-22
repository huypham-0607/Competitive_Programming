#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 1e9+7;

int test;
int n,x;
int pre[maxn];
int a[maxn];

int check(int mask, int pos){
    int res = 0;
    int prev = 0;
    for (int i=1; i<=n; i++){
        int cur = (pre[i]^pre[prev]);
        if (pos == 1){
            if ((x&pos)){
                if (!(cur&mask)){
                    res++;
                    prev = i;
                }
            }
            else {
                if (!(cur&mask) && !(cur&pos)){
                    res++;
                    prev = i;
                }
            }
        }
//        cout << i << ": " << (cur&mask) << " " << (cur&pos)
        else if (!(cur&mask) && !(cur&pos)){
            res++;
            prev = i;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    while (test--){
        cin >> n >> x;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            pre[i] = (pre[i-1]^a[i]);
        }
        int ans = 0;
        int mask = 0;
        for (int i=30; i>=0; i--){
            int pos = (1<<i);
            if (pos == 1){
                if (!(x&pos)){
                    if ((pre[n]&pos)){
                        continue;
                    }
                }
                ans = max(ans,check(mask,pos));
            }
            else if (!(x&pos)){
                if ((pre[n]&pos)){
//                    cout << "meow" << endl;
                    break;
                }
                mask+=pos;
            }
            else{
                if ((pre[n]&pos)) continue;
                else{
//                    cout << "{" << i << "}" << endl;
                    ans = max(ans,check(mask,pos));
                }
            }
        }
        if (!ans){
            cout << -1 << endl;
        }
        else cout << ans << endl;
    }

    return 0;
}
