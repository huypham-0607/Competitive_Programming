#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first
#define se second

using namespace std;

int n,m,h;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        vector<iii> data;
        cin >> n >> m >> h;
        for (int i=0; i<n; i++){
            int x;
            vector<int> v;
            for (int i=0; i<m; i++){
                cin >> x;
                v.push_back(x);
            }
            sort(v.begin(),v.end());
            int t=0, c=0, p=0;
            for(auto x:v){
                t+=x;
                if (t<=h){
                    c++;
                    p+=t;
                }
                else break;
            }
            data.push_back({{-c,p},i});
        }
        sort(data.begin(),data.end());
        for (int i=0; i<n; i++){
            if (data[i].se == 0){
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}
