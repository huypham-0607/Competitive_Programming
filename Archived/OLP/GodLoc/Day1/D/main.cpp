#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n;
deque<piii> mn,mx;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }

    for (int i=1; i<=n; i++){
        int pos;
        if (dq1.empty()) pos = 1;
        else pos = dq1.back().se.fi+1;
        while (!dq1.empty() && dq1.back().fi<a[i]){
            dq1.pop();
            if (dq1.empty()) pos = 1;
            else pos = dq1.back().se.fi+1;
        }
        dq1.push_back({a[i],{pos,i});
        if (dq2.empty()) pos = 1;
        else pos = dq2.back().se.fi+1;
        while (!dq2.empty() && dq2.back().fi>b[i]){
            dq2.pop();
            if (dq2.empty()) pos = 1;
            else pos = dq2.back().se.fi+1;
        }
        dq2.push_back({b[i],{pos,i});

        while (dq1.front()>dq2.front()){
            dq1.pop_front();
        }
        while (dq1.front()>dq2.front()){
            dq2.pop_front();
        }
        if (dq1.top() == dq2.top())
    }
    return 0;
}
