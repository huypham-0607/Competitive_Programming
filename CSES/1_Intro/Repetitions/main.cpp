#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin >> s;
    s=s+"0";
    char c='1';
    int mx =0,l=0;
    for (unsigned long long i =0; i<s.size(); i++){
        if (c!=s[i]){
            mx = max(mx,l);
            l=1;
            c=s[i];
        }
        else{
            l++;
        }
    }
    cout << mx;
    return 0;
}
