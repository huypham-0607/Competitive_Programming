#include <bits/stdc++.h>
#define endl "\n"
#define int unsigned long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;
const int lg = 60;

int n,test;
vector<int> v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        v.clear();
        int cnt = 0;
        for (int i=lg; i>=0; i--){
            int meow = 1;
            meow = (meow << i);
//            cout << n << " " << meow << " " << i << endl;
            if ((n&meow)){
                ++cnt;
                if (cnt == 1){
                    for (int j=1; j<=i; j++){
                        v.push_back(j);
                    }
                }
                else{
                    v.push_back(i+1);
                }
            }
            if (i == 0) break;
        }
        cout << v.size() << endl;
        for (auto x:v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
