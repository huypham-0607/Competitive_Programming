#include <iostream>
#include <algorithm>

using namespace std;

/*Global Variables*/
int q;
int a[100010],tmp[100010],nen[100010];
bool check[100010];

/*Solution*/
void Solve(){

    cin >> q;
    for (int i=0; i<q; i++){
        cin >> a[i];
        tmp[i] = a[i];
    }
    sort(tmp,tmp+q);

    int n = 0;
    int pre = 0;
    for (int i=0; i<q; i++){
        if (tmp[i]!=pre){
            nen[n] = tmp[i];
            ++n;
        }
        pre = tmp[i];
    }

    int cnt = 0;
    for (int i=0; i<q; i++){
        int pos = lower_bound(nen,nen+n,a[i]) - nen;
        if (!check[pos]) ++cnt;
        check[pos] = true;

        cout << cnt << " ";
    }
}

/*Driver Code*/
int main(){

    Solve();

    return 0;
}
