#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    freopen("quyhoachdong.inp","r",stdin);
    freopen("quyhoachdong.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,m;
    while (cin >> a >> b >> c >> m){
        if (a==0 || b==0 || c==0 || m<=2 || m>a+b+c){
            cout << "Yes";
        }
        else cout << "No";
        cout << "\n";
    }
    return 0;
}
