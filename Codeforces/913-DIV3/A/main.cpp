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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int ch = s[0]-'a';
        int num = s[1]-'1';
        for (int i=0; i<8; i++){
            if (i == ch) continue;
            cout << char(int('a')+i) << s[1] << endl;
        }
        for (int i=0; i<8; i++){
            if (i == num) continue;
            cout << s[0] << char(int('1')+i) << endl;
        }
    }
    return 0;
}
