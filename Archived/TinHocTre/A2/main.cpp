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
#define forw(i,j,z) for(int i=(int)j;i<=(int)z;i++)
#define ford(i,j,z) for(int i=(int)j;i>=(int)z;i--)

void Sieve(){
    bs.flip();
    bs[0] = bs[1] = 0;
    for (int i=3; i*i<1e7;i+=2){
       if (bs[i]){
            for(ll j=(ll )i*i;j<=1e7;j+=(i<<1))
                bs[j]=0;
       }
    }
    prime.push_back(0);
    int cnt = 0;
    int i = 2;
    while (cnt<250001){
        if (bs[i]){
            prime.push_back(i);
            ++cnt;
        }
        ++i;
    }
}


void solve()
{

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
