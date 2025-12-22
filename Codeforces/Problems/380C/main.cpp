#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second

using namespace std;

const int maxn = 4e6+100;

int cnt[maxn],rb[maxn],lb[maxn];
string s;

void build(int i,int l, int r){
    if (r == l){
        cnt[i] = 0;
        if (s[l-1] == '('){
            rb[i] = 1;
            lb[i] = 0;
        }
        else{
            lb[i] = 1;
            rb[i] = 0;
        }
    }
    else{
        int mid = (l+r)/2;
        int u = i*2;
        int v = i*2+1;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        int tam = min(rb[u],lb[v]);
        cnt[i] = cnt[u]+cnt[v]+tam;
        lb[i] = lb[u]+lb[v]-tam;
        rb[i] = rb[v]+rb[u]-tam;
    }
    //cout << l << " " << r << " | " << cnt[i] << " " << rb[i] << " " << lb[i] << "\n";
}

iii query(int i, int l, int r, int ql, int qr){
    if (r < ql || l > qr) return {0,{0,0}};

    if (r <= qr && l >= ql) return {cnt[i],{rb[i],lb[i]}};

    int mid = (l+r)/2;
    int t=0;
    iii in1 = query(i*2,l,mid,ql,qr);
    iii in2 = query(i*2+1,mid+1,r,ql,qr);
    int tam = min(in1.se.fi,in2.se.se);
    t+= in1.fi + in2.fi + tam;
    return {t,{in1.se.fi+in2.se.fi-tam,in1.se.se+in2.se.se-tam}};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> s;
    n = s.size();
    //cout << n;
    cin >> m;
    build(1,1,n);
    while (m--){
        int x,y;
        cin >> x >> y;
        cout << query(1,1,n,x,y).fi*2 << "\n";
    }
    return 0;
}
