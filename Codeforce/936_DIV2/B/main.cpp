#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e9+7;

int test;
int n,k;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    while (test--){
        cin >> n >> k;
        int ans = 0;
        int t =0;
        int total = 0;
        int cnt = 0;
        int cntans = 0;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            t = t+a[i];
            if (t>=INF){
                t=t%INF;
                cnt++;
            }
            else if (t<0){
                t = t+INF;
                cnt--;
                if (cnt <0){
                    t = 0;
                    cnt = 0;
                }
            }
//            cout << ans <<  " " << cntans << " " << t << " " << cnt << endl;
            total = total+a[i];
            if (total>=INF) total = total%INF;
            if (total<0) total+=INF;
            if ((cnt > cntans) || (cntans == cnt && t > ans)){
                cntans = cnt;
                ans = t;
            }
        }
//        cout << endl;
        for (int i=1; i<=k; i++){
            total = (total+ans)%INF;
            ans = ans*2%INF;
        }
//        cout << t << endl;
        cout << total << endl;
    }

    return 0;
}
