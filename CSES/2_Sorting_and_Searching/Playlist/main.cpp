#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int n,ans;
map<int,int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans = 0;
    int bot = 0;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        bot = max(mp[x],bot);
        mp[x] = i;
        ans = max(ans,i-bot);
    }
    cout << ans;
    return 0;
}
