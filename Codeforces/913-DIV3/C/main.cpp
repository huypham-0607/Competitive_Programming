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
int a[100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        string s;
        cin >> n;
        cin >> s;
        for (int i=0; i<=30; i++){
            a[i] = 0;
        }
        for (int i=0; i<n; i++){
            a[s[i]-'a']++;
        }
        int mx = 0;
        for (int i=0; i<=25; i++){
            mx = max(mx,a[i]);
        }
        cout << max(mx-(n-mx),n%2) << endl;
    }
    return 0;
}
