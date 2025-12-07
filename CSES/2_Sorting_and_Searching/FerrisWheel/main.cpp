#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,x;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i=1; i<=n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    int i=0;
    int j=n-1;
    while (i<=j){
        if (i!=j){
            if (v[i] + v[j]<=x){
                ++i;
            }
        }
        ++cnt;
        --j;
    }
    cout << cnt;
    return 0;
}
