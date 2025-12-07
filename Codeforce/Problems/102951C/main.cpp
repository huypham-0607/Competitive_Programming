#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int test;
int n;
int pos[N];
int a[N],b[N];

//IT
int IT[N*4];

void update(int idx, int l, int r, int pos, int val){
    if (pos < l || pos > r) return;
    if (l == r){
        IT[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,pos,val);
    update(idx*2+1,mid+1,r,pos,val);
    IT[idx] = max(IT[idx*2],IT[idx*2+1]);
}

int get(int idx, int l, int r, int x, int y){
    if (y<l || x>r) return 0;
    if (x<=l && r<=y) return IT[idx];
    int mid = (l+r)/2;
    return max(get(idx*2,l,mid,x,y),get(idx*2+1,mid+1,r,x,y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
        pos[b[i]] = i;
    }
    for (int i=1; i<=n; i++){
        int prev = 0;
        int idx = pos[a[i]];
        if (idx>1) prev = get(1,1,n,1,idx-1);
        update(1,1,n,idx,prev+1);
    }
    cout << get(1,1,n,1,n);
    return 0;
}
