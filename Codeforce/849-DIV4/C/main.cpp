#include <bits/stdc++.h>

using namespace std;

int t,n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n >> s;
        while ((s[0] == '0' && s[s.size()-1] == '1') || (s[0] == '1' && s[s.size()-1] == '0')){
            n-=2;
            s = s.substr(1,n);
        }
        cout << n << endl;
    }
    return 0;
}
