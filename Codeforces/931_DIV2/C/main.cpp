#include <bits/stdc++.h>
//#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        int x,y,meow;
        cin >> n >> m;
        cout << "? " << 1 << " " << 1 << endl;
        cin >> meow;
        cout.flush();
        int sum = meow+2;
        cout << "? " << n << " " << 1 << endl;
        cin >> meow;
        cout.flush();
        int sub1 = n-1-meow;
        cout << "? " << 1 << " " << m << endl;
        cin >> meow;
        cout.flush();
        int sub2 = -m+1+meow;
//        cout << sum + sub2 << endl;
        if (sum+sub2<2){
            x = (sum+sub1)/2;
            y = sum-x;
            cout << "! " << x << " " << y << endl;
//            cout << sum << " " << sub1 << " " << sub2 << " ";
            cout.flush();
            continue;
        }
        x = (sum+sub2)/2;
        y = sum-x;
//        cout << sum << " " << x << " " << y << endl;
        if (y < 1){
            x = (sum+sub1)/2;
            y = sum-x;
            cout << "! " << x << " " << y << endl;
//            cout << sum << " " << sub1 << " " << sub2 << " ";
            cout.flush();
            continue;
        }
        int diff = x-1;
        cout << "? " << 1 << " " << y << endl;
        cin >> meow;
        cout.flush();
        if (meow == diff){
            cout << "! " << x << " " << y << endl;
            cout.flush();
        }
        else{
            x = (sum+sub1)/2;
            y = sum-x;
            cout << "! " << x << " " << y << endl;
//            cout << sum << " " << sub1 << " " << sub2 << " ";
            cout.flush();
        }
    }
    return 0;
}
