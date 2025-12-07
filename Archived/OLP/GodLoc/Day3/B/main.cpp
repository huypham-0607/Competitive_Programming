#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 2e9;

int test;
int n,m;

int IT[maxn*4];
vector<int> a[maxn];
set<int> st;

void update(int idx, int l, int r, int x, int y){
    if (r < x || l > y) return;
    if (x <= l && r <= y){
        IT[idx] = 1;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,x,y);
    update(idx*2+1,mid+1,r,x,y);
    if (IT[idx*2] && IT[idx*2+1]) IT[idx] = 1;
}

int query(int idx, int l, int r, int x, int y){
    int res = 0;
    if (r < x || l > y) return 0;
//    cout << idx << " " << l << " " << r << " " << x << " " << y << " " << IT[idx] <<  endl;
    if (l <= x && y <= r) res = max(res,IT[idx]);
    if (x <= l && r <= y){
        return max(res,IT[idx]);
    }
    int mid = (l+r)/2;
    return max({res,query(idx*2,l,mid,x,y),query(idx*2+1,mid+1,r,x,y)});
}

void BFS(int start){
    queue<pii> q;
    stack<int> s;
    update(1,1,n,start,start);
    q.push({start,start});
    while (!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
//        cout << "-" << x << " " << y << "-" << endl;
        q.pop();

        auto itr = st.lower_bound(x);
        int u = *itr;
        while (u<=y){
//            cout << "{" << u << "}" << endl;
            for (int i=0; i<int(a[u].size())-1; i++){
                int l = a[u][i]+1;
                int r = a[u][i+1]-1;
                if (l > r) continue;
//                cout << l << " " << r << endl;
                if (!query(1,1,n,l,r)){
                    update(1,1,n,l,r);
                    q.push({l,r});
                }
            }
            s.push(u);
//            st.erase(u);
            itr++;
            u = *itr;
        }
        while (!s.empty()){
            st.erase(s.top());
            s.pop();
        }
    }
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> m;

    for (int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i=1; i<=n; i++){
        a[i].push_back(0);
        a[i].push_back(n+1);
        sort(a[i].begin(),a[i].end());
        st.insert(i);
    }
    st.insert(INF);
    st.insert(0);
    int c = -1;
    for (int i=1; i<=n; i++){
//        cout << query(1,1,n,i,i) << endl;
//        for (int i=1; i<=4*n; i++){
//            cout << IT[i] << " ";
//        }
//        cout << endl;
        if (!query(1,1,n,i,i)){
            BFS(i);
            ++c;
        }
    }
    cout << c;
    return 0;
}
