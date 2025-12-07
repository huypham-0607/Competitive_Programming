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
int n,k;
priority_queue<int> l;
priority_queue<int,vector<int>,greater<int>> r;
map<int,int> mpl,mpr;
int a[maxn];
vector<int> v;

void updatel(int x){
    --mpl[x];
    if (!mpl[x]){
        mpl.erase(x);
    }
    while (!l.empty() && mpl.find(l.top()) == mpl.end()){
        l.pop();
    }
}

void updater(int x){
    --mpr[x];
    if (!mpr[x]){
        mpr.erase(x);
    }
    while (!r.empty() && mpr.find(r.top()) == mpr.end()){
        r.pop();
    }
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        if (i<=k) v.push_back(x);
        a[i] = x;
    }
    sort(v.begin(),v.end());
    int med = v[(k-1)/2];
    for (int i=(k-1)/2; i>=0; i--){
        l.push(v[i]);
        ++mpl[v[i]];
    }
    for (int i=(k-1)/2+1; i<k; i++){
        r.push(v[i]);
        ++mpr[v[i]];
    }
    cout << med << endl;
//    cout << l.top() << " " << r.top() << endl;
    for (int i=k+1; i<=n; i++){
        int x = a[i-k];
        int y = a[i];
        if (x <= med){
            updatel(x);
            if (y <= med){
                ++mpl[y];
                l.push(y);
            }
            else{
                ++mpr[y];
                r.push(y);
                ++mpl[r.top()];
                l.push(r.top());
                updater(r.top());
            }
        }
        else{
            updater(x);
            if (y > med){
                ++mpr[y];
                r.push(y);
            }
            else{
                ++mpl[y];
                l.push(y);
                ++mpr[l.top()];
                r.push(l.top());
                updatel(l.top());
            }
        }
        med = l.top();
        cout << med << endl;
//        cout << l.top() << " " << r.top() << " " << x << " " << y << endl;
    }
    return 0;
}
