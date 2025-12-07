#include <bits/stdc++.h>
#define limit 500000
using namespace std;

int a[limit], t[limit];
int n,q;

int mid(int l, int r){
    return (l+r)/2;
}

void Build(int l, int r, int pos){
    if (l == r){
        t[pos] = a[l];
    }
    else{
        Build(l,mid(l,r),pos*2);
        Build(mid(l,r)+1,r,pos*2+1);
        t[pos] = t[pos*2] + t[pos*2+1];
    }
}

void Update(int l, int r, int pos, int x, int v){
    if (l<=x && x<=r){
        if (l==r){
            t[pos] = v;
        }
        else{
            Update(l,mid(l,r),pos*2,x,v);
            Update(mid(l,r)+1,r,pos*2+1,x,v);
            t[pos] = t[pos*2] + t[pos*2+1];
        }
    }
}

int Sum(int l, int r, int pos, int i, int j){
    if (!())
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    Build(1,n,1);
    for (int i=1; i<=7; i++){
        cout << t[i] << " ";
    }
    return 0;
}
