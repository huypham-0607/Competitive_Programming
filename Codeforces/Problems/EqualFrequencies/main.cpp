#include <bits/stdc++.h>

using namespace std;

int a[26];



int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--){
        int a[26];
        cin >> n >> s;
        for (int i=0; i<n; i++){
            a[s[i] - 'A']++;
        }


    }
    return 0;
}
