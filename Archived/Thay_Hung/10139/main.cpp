#include <bits/stdc++.h>
#define lim 31622
#define lowlim 177
#define fi first
#define se second
using namespace std;

bool a[lim+10];
vector <int> prime;
int n,m;
void sieve(){
    memset(a,1,sizeof(a));
    a[0]=false;
    a[1]=false;
    for (int i=2; i<=lowlim; i++){
        for (int j=i*i; j<=lim; j+=i){
            a[j] = false;
        }
    }
    for (int i=2; i<=lim; i++){
        if (a[i]){
            prime.push_back(i);
        }
    }
}

int main()
{
    //freopen("10139.INP","r",stdin);
    //freopen("10139.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    while(cin >> n >> m){
        //if (n==0) break;
        //if (n==0) n=1;
        if (m==0){
            cout << m << " does not divide " << n << "!" << "\n";
            continue;
        }
        vector <pair<int,int>> pf;
        int savem = m;
        for (auto i:prime){
            int c=0;
            while(m%i==0){
                c++;
                m/=i;
            }
            if (c){
                pf.push_back({i,c});
            }
        }
        if (m!=1) pf.push_back({m,1});
        bool v=true;
        for (auto in:pf){
            int num = in.fi;
            int c=0;
            for (int i=num; i<=n; i*=num){
                c+=n/i;
            }
            //cout << c << " " << in.se << endl;
            if (c<in.se){
                v=false;
                break;
            }
        }
        if (v) cout << savem << " divides " << n << "!" << "\n";
        else cout << savem << " does not divide " << n << "!" << "\n";
    }
    return 0;
}
