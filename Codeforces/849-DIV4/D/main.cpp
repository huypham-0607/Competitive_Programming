#include <bits/stdc++.h>

using namespace std;

int t,n,a[26],l[100000],r[100000],ans;
string s;

int num(char x){
    return x-'a';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--){
        for (int i=0; i<n; i++){
            l[i] = 0;
            r[i] = 0;
        }
        cin >> n >> s;
        int c=0;
        for (int i=0; i<n; i++){
            if ((a[num(s[i])]) == 0) c++;
            a[num(s[i])]++;
            l[i] = c;
        }
        for (int i=0; i<n; i++){
            a[num(s[i])]--;
            if ((a[num(s[i])]) == 0) c--;
            r[i] =c;
        }
        ans = l[0]+r[0];
        for (int i=1; i<n-1; i++){
            ans = (ans < l[i]+r[i])? l[i] + r[i] : ans;
        }
        cout << ans << endl;
    }
    return 0;
}
