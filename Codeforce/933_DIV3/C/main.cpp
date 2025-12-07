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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        string s;
        int cnt = 0;
        cin >> s;
        for (int i=0; i<n-2; i++){
            if (s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e') ++cnt;
            if (s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p'){
                ++cnt;
                i+=2;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
