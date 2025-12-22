#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const int INF = 1e9+7;

int n;
int a[N];
vector<int> v;

int main(){
    cin >> n;
    n*=2;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int ans = INF;

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            v.clear();
            for (int idx=0; idx<n; idx++){
                if (idx!=i && idx!=j) v.push_back(a[idx]);
            }
            sort(v.begin(),v.end());

            int t = 0;
            for (int idx=0; idx<n-2; idx+=2){
                t += v[idx+1] - v[idx];
            }
            ans = min(ans,t);
        }
    }

    cout << ans;

    return 0;
}
