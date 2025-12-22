#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int temp;
    string s1,s2;
    for (int i=1; i<=n; i++){
        cin >> temp >> s1;
        s2 = s1;
        reverse(s2.begin(),s2.end());
        if (s1<=s2){
            cout << s1 << endl;
        }
        else{
            cout << s2+s1 << endl;
        }
    }
    return 0;
}
