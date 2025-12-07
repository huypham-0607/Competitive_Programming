#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5 + 5;

bool marked[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("camera.inp","r",stdin);
    freopen("camera.out","w",stdout);
    int n,k,r,t;
    cin >> n >> k >> r >> t;
    for (int i = 1; i <= k; i++){
        int tm;
        cin >> tm;
        marked[tm] = 1;
    }
    int cur = 0;
    int res = 0;
    vector<int> v;
    for (int i = 1; i < r; i++) cur += marked[i];
    for (int j = r; j <= n; j++){
        if (marked[j]) cur++;
        int i = j;
        while(i >= j - r + 1 && cur < t){
            if (marked[i] == 0){
                v.push_back(i);
                marked[i] = 1;
                cur++;
                res++;
            }
            i--;
        }
        if (marked[j - r + 1] == 1) cur--;
    }
    cout << res << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
