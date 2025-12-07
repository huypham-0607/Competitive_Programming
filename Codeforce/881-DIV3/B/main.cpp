#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int t,n;
ll a[200100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        ll sum=0;
        ll totalc = 0;
        ll c=0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if (a[i] == 0) continue;
            if (a[i] < 0){
                if (c==0){
                    c=1;
                }
                sum-=a[i];
            }
            else{
                sum+=a[i];
                totalc+=c;
                c=0;
            }
        }
        if (c==1) totalc++;
        cout << sum << " " << totalc << "\n";
    }
    return 0;
}
