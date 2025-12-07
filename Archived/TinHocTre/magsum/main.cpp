#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define f first
#define s second
#define solucian hobbies_of_nghiaaa
#define all(a) begin(a),end(a)
#define pb push_back
#define mp make_pair
#define ll long long
#define db double
#define ull unsigned long long
#define BIT(i)  (1LL<<(i))
#define sz(a) (int)a.size()
#define len(a) (int)a.length()
#define endl "\n"
#define forw(ooo,kkk,ooooo) for(int ooo=(int)kkk;ooo<=(int)ooooo;ooo++)
#define ford(ooo,kkk,ooooo) for(int ooo=(int)kkk;ooo>=(int)ooooo;ooo--)
/*
3
2 2 4
*/
int n;
const int N = 3e5;
int a[N+1];
int id[N+1];
ll prefix[N+1];
struct DSU{
    int l,r,root;
    bool oke=false;
    DSU(){}
    DSU(int i):l(i),r(i),root(i),oke(false){}
};
DSU dsu[N+1];
bool cmp(int u,int v)
{
    return a[u]<a[v];
}
ll ans = 0;
int findset(int u)
{
    return dsu[u].root==u?u:dsu[u].root=findset(dsu[u].root);
}
void hopthe(int i,int j,int k)
{
    i=findset(i);
    j=findset(j);
    if (dsu[i].r-dsu[i].l>dsu[j].r-dsu[j].l)
    {
        forw(z,k,dsu[j].r)
        {
            int l=dsu[i].l,r;
            if (z==k) r=k-1;
            else r=k;
            while(l<r)
            {
                int mid = (l+r)>>1;
                if (prefix[z]-prefix[mid-1]<2LL*a[k])
                    r=mid;
                else l=mid+1;
            }
            if (l>r||prefix[z]-prefix[l-1]>=2LL*a[k]) continue;
            if (z==k&&r<k)
                ans+=k-r;
            else if (z!=k&&r<=k)
                ans+=k-r+1;
        }
    }
    else{
        forw(z,dsu[i].l,k)
        {
            int l=k,r=dsu[j].r;
            if (z==k) l=k+1;
            while(l<r)
            {
                int mid = ((l+r)>>1)+1;
                if (prefix[mid]-prefix[z-1]<2LL*a[k])
                    l=mid;
                else r=mid-1;
            }
            if (l>r||prefix[l]-prefix[z-1]>=2LL*a[k]) continue;
            if ((z==k&&l>k))
                ans+=l-k;
            else if ((z!=k&&l>=k))
                ans+=l-k+1;
        }
        swap(i,j);
    }
    dsu[j].root=i;
    dsu[i].l=min(dsu[i].l,dsu[j].l);
    dsu[i].r=max(dsu[i].r,dsu[j].r);
}
void solve3()
{
    ford(i,n,1)
    {
        int l=1,r=i;
        while(l<r){
            int mid = (l+r)>>1;
            if(prefix[i]-prefix[mid-1]<2LL*a[i])
                r=mid;
            else l=mid+1;
        }
        ans+=(i-r+1);
    }
    cout<<ans << endl;
}
void solve2()
{
    cin>>n;
    bool kt = true;
    forw(i,1,n){
        cin>>a[i];
        if (i>1) kt&=(a[i]>=a[i-1]);
        id[i]=i;
        prefix[i]=prefix[i-1]+a[i];
    }
    if (kt){
        solve3();
        return ;
    }
    ans = 0;
    forw(i,1,n)

    {
        ll dem = 0;
        int MAX=0;
        forw(j,i,n){
            MAX=max(MAX,a[j]);
            dem+=a[j];
            if (2LL*MAX>dem)
                ans++;
    }
    }
    cout<<ans << endl;
}
void solve()
{
    ans=0;
//    cin>>n;

    forw(i,1,n){
//        cin>>a[i];

        id[i]=i;
//        prefix[i]=prefix[i-1]+a[i];
    }

    forw(i,1,n) dsu[i]=DSU(i);
    sort(id+1,id+n+1,cmp);
    forw(j,1,n){
        int i = id[j];
        dsu[i].oke=true;
        ans+=1;
        if (i>1&&dsu[i-1].oke==true) hopthe(i-1,i,i);
        if (i<n&&dsu[i+1].oke==true) hopthe(i,i+1,i);
    }
    cout<<ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve2();
        solve();
    return 0;
}
