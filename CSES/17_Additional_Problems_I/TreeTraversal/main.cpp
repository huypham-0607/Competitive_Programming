#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int in[N];
int ID[N];
int pre[N];
stack<int> s;
vector<int> a[N];
int n;

void DFS(int u){
    for (auto v:a[u]){
        DFS(v);
    }
    cout << u << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> pre[i];
        ID[pre[i]] = i;
    }
    for (int i=1; i<=n; i++){
        cin >> in[i];
    }
    for (int i=1; i<=n+1; i++){
        int u = in[i];
//        cout << u << ": " << endl;
        int id = ID[u];
        int prev = 0;
        while (!s.empty() && id<ID[s.top()]){
            if (prev!=0){
                a[s.top()].push_back(prev);
            }
//            cout << s.top() << " ";
            prev = s.top();
            s.pop();
        }
//        cout << endl;
        s.push(u);
        if (prev!=0 && u!=0) a[u].push_back(prev);
    }
    DFS(pre[1]);
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << i << ": ";
//        for (auto x:a[i]){
//            cout << x << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
