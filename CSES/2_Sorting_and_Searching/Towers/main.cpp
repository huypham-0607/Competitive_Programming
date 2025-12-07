#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    cin >> x;
    v.push_back(x);
    int cnt = 1;
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        int pos = upper_bound(v.begin(),v.end(),x) - v.begin();
        if (cnt == pos){
            ++cnt;
            v.push_back(x);
        }
        else v[pos] = x;
    }
    cout << cnt;
    return 0;
}
