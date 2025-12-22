#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,t;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        v.push_back(0);
        int l=0, r=INF;
        for (int i=1; i<=n; i++){
            int a,x;
            cin >> a >> x;
            if (a == 1){
                l = max(l,x);
            }
            if (a == 2){
                r = min(r,x);
            }
            if (a == 3){
                v.push_back(x);
            }
        }
        v.push_back(INF);
        sort(v.begin(),v.end());
        int i = 0, j = v.size()-1;
        while (v[i] < l) i++;
        while (v[j] > r) j--;
//        cout << l << " " << r << " " << i << " " << j << endl;
        cout << max(0,r-l+1)-max(0,(j-i+1)) << endl;
    }
    return 0;
}
