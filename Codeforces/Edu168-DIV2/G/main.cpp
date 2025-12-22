#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 200005

using namespace std;

int a[lim],
    tree[lim*4],
    lazy[lim*4];
int n,q;

//lazy

void build(int i, int s, int e){
    if(s==e){
        tree[i] = a[s];
        return;
    }
    int mid = (s+e)/2;
    build(i*2,s,mid);
    build(i*2+1,mid+1,e);
    tree[i] = tree[i*2] + tree[i*2+1];
    return;

}

void update(int i, int s, int e, int us, int ue, int x){
    if (lazy[i]!=0){
        tree[i]+=(e-s+1)*lazy[i];
        if (s!=e){
            lazy[i*2]+=lazy[i];
            lazy[i*2+1]+=lazy[i];
        }
    }
    lazy[i] = 0;

    if (s>e ||e < us || ue < s){
        return;
    }
    if (us <= s && e <= ue){
        tree[i] += (e-s+1)*x;
        if (s!=e){
            lazy[i*2]+=x;
            lazy[i*2+1]+=x;
        }
        return;
    }

    int mid = (s+e)/2;
    update(i*2,s,mid,us,ue,x);
    update(i*2+1,mid+1,e,us,ue,x);
    tree[i] = tree[i*2] + tree[i*2+1];
}

int getint(int i, int s, int e, int us, int ue){
    if (lazy[i]!=0){
        tree[i]+=(e-s+1)*lazy[i];
        if (s!=e){
            lazy[i*2]+=lazy[i];
            lazy[i*2+1]+=lazy[i];
        }
    }
    lazy[i] = 0;
    if (s>e || e < us || ue < s){
        return 0;
    }
    if (us <= s && e <= ue){
        return tree[i];
    }

    int mid = (s+e)/2;
    return getint(i*2,s,mid,us,ue) + getint(i*2+1,mid+1,e,us,ue);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    //cout << "meow" << "\n";
    build(1,1,n);
    /*for(int i=1; i<=6*n; i++){
        cout << tree[i] << " ";
    }*/
    while (q--){
        int id = 1;
        if (id==1){
            int x = 1;
            int l,r;
            cin >> l >> r;
            update(1,1,n,l,r,x);
        }
        else{
            int x;
            cin >> x;
            cout << getint(1,1,n,x,x) << "\n";
        }
    }
    for (int i=1; i<=n; i++){
        cout << getint(1,1,n,i,i) << endl;
    }


    return 0;
}

