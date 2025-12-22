#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

bool check[1001000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i=2; i<=1000; i++){
        int num = i*i, t = i*i+i+1;
        while (t<=1000000){
            //if (check[t]) cout << i << " UwU" << "\n";
            check[t] = true;
            num*=i;
            t+=num;
        }
    }
    int t;
    cin >> t;
    while (t--){
            int n;
        cin >> n;
        if (check[n]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
