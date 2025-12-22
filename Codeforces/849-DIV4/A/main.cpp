#include <bits/stdc++.h>

using namespace std;

string c,cf = "codeforces";
int t;

int main()
{
    cin >> t;
    while (t--){
        cin >> c;
        if (cf.find(c)!=string::npos) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
