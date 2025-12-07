/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n, pos1;
int a[N];
vector<pii> ans;
priority_queue<int,vector<int>,greater<int>> minheap;
priority_queue<int> maxheap;


void do0(){
    for (int i=1; i<=n; i++){
        if (a[i] == 0) maxheap.push(i);
    }
    for (int i=1; i<=n; i++){
        if (maxheap.empty()) break;
        if (maxheap.top()<i) break;
        if (a[i] == 0) continue;
        if (a[i] == 1){
            ans.push_back({maxheap.top(),i});
            a[i] = 0;
            a[maxheap.top()] = 1;
            pos1 = maxheap.top();
            maxheap.pop();
        }
        else{
            ans.push_back({pos1,i});
            a[i] = 1;
            a[pos1] = 2;
            ans.push_back({maxheap.top(),i});
            a[i] = 0;
            a[maxheap.top()] = 1;
            pos1 = maxheap.top();
            maxheap.pop();
        }
    }
}

void do2(){
    for (int i=1; i<=n; i++){
        if (a[i] == 2) minheap.push(i);
    }
    for (int i=n; i>0; i--){
        if (minheap.empty()) break;
        if (minheap.top()>i) break;
        if (a[i] == 2) continue;
        if (a[i] == 1){
            ans.push_back({minheap.top(),i});
            a[i] = 2;
            a[minheap.top()] = 1;
            pos1 = minheap.top();
            minheap.pop();
        }
        else{
            ans.push_back({pos1,i});
            a[i] = 1;
            a[pos1] = 0;
            ans.push_back({minheap.top(),i});
            a[i] = 2;
            a[minheap.top()] = 1;
            pos1 = minheap.top();
            minheap.pop();
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    int cnt0 = 0, cnt2 = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i] == 0) cnt0++;
        if (a[i] == 2) cnt2++;
        if (a[i] == 1) pos1 = i;
    }
    if (cnt0>n/2){
        do2();
        do0();
    }
    else{
        do0();
        do2();
    }
    cout << ans.size() << endl;
    for (auto in:ans){
        cout << in.fi << " " << in.se << endl;
    }
    ans.clear();
    while (!minheap.empty()) minheap.pop();
    while (!maxheap.empty()) maxheap.pop();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
