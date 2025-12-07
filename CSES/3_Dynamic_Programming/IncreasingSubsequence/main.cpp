#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 100010

using namespace std;

int n,x;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        int pos = upper_bound(dp.begin(),dp.end(),x) - dp.begin();

    }
    return 0;
}