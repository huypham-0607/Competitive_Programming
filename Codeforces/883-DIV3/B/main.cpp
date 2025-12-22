#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

char a[15];

bool check(char c){
    if (a[1] == c && a[2] == c && a[3] == c) return true;
    else if (a[4] == c && a[5] == c && a[6] == c) return true;
    else if (a[7] == c && a[8] == c && a[9] == c) return true;
    else if (a[1] == c && a[4] == c && a[7] == c) return true;
    else if (a[2] == c && a[5] == c && a[8] == c) return true;
    else if (a[3] == c && a[6] == c && a[9] == c) return true;
    else if (a[1] == c && a[5] == c && a[9] == c) return true;
    else if (a[3] == c && a[5] == c && a[7] == c) return true;
    else return false;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        for (int i=1; i<=9; i++){
            cin >> a[i];
        }
        if (check('+')) cout << '+' << "\n";
        else if (check('X')) cout << 'X' << "\n";
        else if (check('O')) cout << 'O' << "\n";
        else cout << "DRAW" << "\n";
    }
    return 0;
}
