#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 300010

using namespace std;

ll a[lim],b[lim],pre[lim],add[lim];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=0; i<n-1; i++){
        //cout << i << endl;
        if (a[i] < a[i+1]){
            b[i+3]+=a[i+1]-a[i];
        }
        else if (a[i] > a[i+1]){
            if (b[i] > a[i]-a[i+1]){
                b[i+3] += b[i] - (a[i]-a[i+1]);
            }
            else{
                pre[i]+= (a[i]-a[i+1])-b[i];
            }
        }
    }
    /*for (int i=0; i<n+2; i++){
        cout << pre[i] << " ";
    }*/
    //cout << endl;
    for (int i=n+1; i>=0; i--){
        if (i/3>0){
            pre[i-3]+=pre[i];
        }
        b[i]+=pre[i];
    }
    /*for (int i=0; i<n+2; i++){
        cout << b[i] << " ";
    }*/

    ll t = b[0] + b[1] + b[2];
    if (t>a[0]) cout << "No";
    else {
        cout << "Yes" << endl;
        ll rem = a[0]-t;
        for (int i=0; i<n+2; i++){
            if (i%3 == 0){
                b[i]+=rem;
            }
            cout << b[i] << " ";
        }
    }
    return 0;
}
