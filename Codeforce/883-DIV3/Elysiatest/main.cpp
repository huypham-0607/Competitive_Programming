#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

int n,q,id;
int a[10000];

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<n; i++){
        cin >> a[i];
    }
    while (q--){
        cin >> id;
        if (id==3){
            int t=0,l,r;
            cin >> l >> r;
            for (int i=l; i<=r; i++){
                t+=a[i];
            }
            cout << t << "\n";

        }
        else{
            int l,r,x;
            cin >> l >> r >> x;
            for (int i=l; i<=r; i++){
                if (id==1){
                    a[i]+=x;
                }
                else a[i]=x;
            }
        }
    }
    for (int i=24; i<=64; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int j=0; j<5; j++){
        cin >> id;
        if (id==3){
            int t=0,l,r;
            cin >> l >> r;
            for (int i=l; i<=r; i++){
                t+=a[i];
            }
            cout << t << "\n";

        }
        else{
            int l,r,x;
            cin >> l >> r >> x;
            for (int i=l; i<=r; i++){
                if (id==1){
                    a[i]+=x;
                }
                else a[i]=x;
            }
        }
    }
    return 0;
}
