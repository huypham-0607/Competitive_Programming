#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

ll t,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        ll sum = n;
        while (n>1){
            if (n%2==1) n--;
            n = n/2;
            sum+=n;
        }
        cout << sum << "\n";
    }
    return 0;
}
