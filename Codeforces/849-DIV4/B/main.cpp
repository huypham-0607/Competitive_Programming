#include <bits/stdc++.h>

using namespace std;

int t,n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        int x=0;
        int y=0;
        bool v=false;
        for (int i=0; i<n; i++){
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            if (s[i] == 'R') x++;
            if (s[i] == 'L') x--;
            if (x==1 && y==1) v=true;
        }
        if (v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
