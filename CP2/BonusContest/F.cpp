    /*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
    #include <bits/stdc++.h>

    #define TEXT ""

    using namespace std;

    #define pb push_back
    #define endl "\n"
    #define ffor(i, a, b) for(int i = a; i <= (b); ++i)
    #define rfor(i, a, b) for(int i = a; i >= (b); --i)
    #define frep(i, a, b) for(int i = a; i < (b); ++i)
    #define rrep(i, a, b) for(int i = a; i > (b); --i)
    #define all(x) (x).begin(),(x).end()
    #define fi first
    #define se second

    typedef int int2;
    #define int long long

    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pii;
    typedef pair<ll,ll> pll;
    typedef pair<double,double> pdd;

    mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

    const int N = 1e6+10;
    const int LG = 20;
    const int INF = 1e9+7;
    const int MD = 1e9+7; //998244353;
    const long long LLINF = 1e18+3;

    //Starts here

    int n,m;
    int st[LG][2*N];
    int jump[2*N];

    void solve(){
        cin >> n >> m;
        vector<pii> v;
        for (int i=1; i<=m; i++){
            int l,r; cin >> l >> r;
            if (r < l) {
                r+=n;
            }
            v.push_back({l,r});
        }
        sort(all(v));

        int l = 1;
        int idx = 0;
        for (int i=1; i<=2*n; i++){
            int r = 0;
            while (idx != m && v[idx].fi == i) {
                r = max(r,v[idx].se);
                ++idx;
            }
            
            l = max(l,i);
            for (int pos=l; pos<=r; pos++){
                jump[pos] = i;    
            }
            l = max(l,r+1);
        }

        // for (int i=1; i<=2*n; i++){
        //     cout << jump[i] << " ";
        // }
        // cout << endl;

        for (int i=1; i<=2*n; i++) {
            st[0][i] = (jump[i] == 0) ? i : jump[i]-1;
            for (int lg=1; lg<LG;lg++){
                int v = st[lg-1][i];
                st[lg][i] = st[lg-1][v];
            }
        }

        // for (int i=1; i<=2*n; i++){
        //     for (int lg=0; lg<LG; lg++){
        //         cout << st[lg][i] << " ";
        //     }
        //     cout << endl;
        // }

        int ans = INF;

        for (int i=n; i<=2*n; i++){
            int e = i-n;
            int cnt = 0;
            int cur = i;
            for (int lg=LG-1; lg>=0; lg--){
                if (st[lg][cur] > e) {
                    cnt += (1<<lg);
                    cur = st[lg][cur];
                }
            }
            if (st[0][cur] <= e) {
                ans = min(ans,cnt+1);
            }
        }

        if (ans == INF) {
            cout << "impossible" << endl;
        }
        else {
            cout << ans << endl;
        }
    }

    /*Driver Code*/
    signed main(){
        cin.tie(0) -> sync_with_stdio(0);
        if (fopen(TEXT".inp","r")){
            freopen(TEXT".inp","r",stdin);
            freopen(TEXT".out","w",stdout);
        }

        int testCount = 1;
    //    cin >> testCount;
        while (testCount--){
            solve();
        }

        return 0;
    }

