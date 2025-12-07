#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        int x;
        v.clear();
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int a = v[0];
        int b = v[n-1];
        int c = v[1];
        int d = v[n-2];
        cout << abs(a-b)+abs(b-c)+abs(c-d)+abs(d-a) << endl;
    }
    return 0;
}
