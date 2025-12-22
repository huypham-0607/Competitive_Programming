#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int c=0;
        for (int i=1 ;i<=n; i++){
            int a,b;
            cin >> a >> b;
            if (a>b) c++;
        }
        cout << c << "\n";
    }
    return 0;
}
