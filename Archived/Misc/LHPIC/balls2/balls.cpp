#include <iostream>

using namespace std;

/*Global Variables*/
int n,q;
int a[200010];

/*Solution*/
void Solve(){
    cin >> n >> q;

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int i=1; i<=q; i++){
        int id,x; cin >> id;

        if (id == 1){
            cin >> x;
            ++n;
            a[n] = x;
        }

        if (id == 2){
            --n;
        }

        if (id == 3){
            cin >> x;
            cout << a[x] << "\n";
        }
    }
}

/*Driver Code*/
signed main(){

    Solve();

    return 0;
}
