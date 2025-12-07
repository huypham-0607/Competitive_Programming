#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define INF 1e9*2
using namespace std;

int n;
double d,h;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> d >> h;
        vector<double> v;
        for (int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        v.push_back(INF);
        double ans=0;
        for (int i=0; i<n; i++){
            double tam = v[i+1] - v[i];
            double trueheight = min(tam,h);
            tam = 1;
            double truebase = d*(tam-trueheight/h);
            ans+=(d+truebase)*trueheight/2;
            //cout << trueheight << " ";
        }
        //cout << endl;
        cout << setprecision(9) <<ans << "\n";
    }
    return 0;
}
