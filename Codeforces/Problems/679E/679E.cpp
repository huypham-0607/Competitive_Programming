    /*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
    #include <bits/stdc++.h>

    #define TEXT "679E"

    using namespace std;

    #define pb push_back
    #define endl "\n"
    #define all(x) (x).begin(),(x).end()
    #define lb lower_bound
    #define ub upper_bound
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

    const int N = 1e5+10;
    const int INF = 1e9+7;
    const int MD = 1e9+7; //998244353;
    const long long LLINF = 1e18+3;

    //Starts here

    int pw[12];

    // val1: maximum true value;
    // val2: second maximum true value;
    // rem: minimum remainder of value pw[lvl] - val;
    // lvl: power degree of val1;

    struct Node{
        int val1,val2,rem,lvl; 
        Node(){
            val1 = -1;
            val2 = -1;
            rem = -1;
            lvl = -1;
        }
    };

    int n,q;
    Node IT[4*N];
    int lazyAdd[4*N];
    int lazyVal[4*N],lazyRem[4*N],lazyLvl[4*N];

    void applySet(int idx, int val, int rem, int lvl) {
        IT[idx].val1 = val;
        IT[idx].val2 = -LLINF;
        IT[idx].rem = rem;
        IT[idx].lvl = lvl;

        lazyAdd[idx] = 0;
        lazyVal[idx] = val;
        lazyRem[idx] = rem;
        lazyLvl[idx] = lvl;
    }

    void applyAdd(int idx, int val) {
        IT[idx].val1 += val;
        if (IT[idx].val2 != -LLINF) IT[idx].val2 += val;
        IT[idx].rem -= val;

        lazyAdd[idx] += val;
    }

    void propagate(int idx){
        if (lazyVal[idx]!=-1) {
            int val = lazyVal[idx];
            int rem = lazyRem[idx];
            int lvl = lazyLvl[idx];

            applySet(idx*2,val,rem,lvl);
            applySet(idx*2+1,val,rem,lvl);
        }
        lazyVal[idx] = -1;
        lazyRem[idx] = -1;
        lazyLvl[idx] = -1;

        if (lazyAdd[idx]!=0) {
            int val = lazyAdd[idx];
            
            //Update idx*2
            applyAdd(idx*2,val);

            //Update idx*2+1
            applyAdd(idx*2+1,val);
        }
        //Reset idx
        lazyAdd[idx] = 0;
    }

    void comb(Node& i, Node l, Node r){
        //Combine func
        if (l.val1 < r.val1) swap(l,r);

        i.val1 = l.val1;
        if (l.val1 == r.val1) {
            i.val2 = max(l.val2,r.val2);
        } else {
            i.val2 = max(l.val2,r.val1);
        }
        i.rem = min(l.rem,r.rem);
        i.lvl = max(l.lvl,r.lvl);
    }

    void build(int idx, int l, int r, int a[]){
        lazyAdd[idx] = 0;
        lazyVal[idx] = -1;
        lazyRem[idx] = -1;
        lazyLvl[idx] = -1;
        if (l==r){
            IT[idx].val1 = a[l];
            IT[idx].val2 = -LLINF;
            IT[idx].lvl = 0;
            while (pw[IT[idx].lvl] < IT[idx].val1) ++IT[idx].lvl;
            IT[idx].rem = pw[IT[idx].lvl] - IT[idx].val1;
            if (IT[idx].rem == 0) cout << l << endl; 
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid,a);
        build(idx*2+1,mid+1,r,a);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void init(int _n, int a[]) {
        n = _n;
        build(1,1,n,a);
    }

    void updateAdd(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            applyAdd(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updateAdd(idx*2,l,mid,x,y,val);
        updateAdd(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void updatePop(int idx, int l, int r, int x, int y) {
        // cerr << idx << " " << l << " " << r << " " << IT[idx].val2 << endl;
        if (y < l || r < x || IT[idx].rem >= 0) return;
        if (x <= l && r <= y && IT[idx].val2 < 0) {
            IT[idx].val2 = -LLINF;
            while (pw[IT[idx].lvl] < IT[idx].val1) ++IT[idx].lvl;
            IT[idx].rem = pw[IT[idx].lvl] - IT[idx].val1;

            lazyAdd[idx] = 0;
            lazyVal[idx] = IT[idx].val1;
            lazyRem[idx] = IT[idx].rem;
            lazyLvl[idx] = IT[idx].lvl;

            return;
        }
        // cerr << "Passed" << endl;

        propagate(idx);

        int mid = (l+r)/2;
        updatePop(idx*2,l,mid,x,y);
        updatePop(idx*2+1,mid+1,r,x,y);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void updateSet(int idx, int l, int r, int x, int y, int val) {
        if (y < l || r < x) return;
        if (x <= l && r <= y) {
            IT[idx].val1 = val;
            IT[idx].val2 = -LLINF;
            IT[idx].lvl = 0;
            while (pw[IT[idx].lvl] < IT[idx].val1) ++IT[idx].lvl;
            IT[idx].rem = pw[IT[idx].lvl] - IT[idx].val1;

            lazyAdd[idx] = 0;
            lazyVal[idx] = val;
            lazyLvl[idx] = IT[idx].lvl;
            lazyRem[idx] = IT[idx].rem;
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updateSet(idx*2,l,mid,x,y,val);
        updateSet(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x){
        if (x < l || r < x) return 0;
        if (l==r){
            return IT[idx].val1;
        }

        propagate(idx);

        int mid = (l+r)/2;
        return max(getVal(idx*2,l,mid,x),getVal(idx*2+1,mid+1,r,x));
    }

    int a[N];

    void solve(){
        cin >> n >> q;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }

        init(n,a);

        while (q--){
            int id,l,r,x;
            cin >> id;
            if (id == 1) {
                cin >> x;
                int res = getVal(1,1,n,x);
                cout << res << endl;
            }
            if (id == 2) {
                cin >> l >> r >> x;
                updateSet(1,1,n,l,r,x);
                // for (int i=1; i<=n; i++) {
                //     cout << getVal(1,1,n,i) << " ";
                // }
                // cout << endl;
            }
            if (id == 3) {
                cin >> l >> r >> x;
                int cnt = 0;
                do {
                    // cout << "Rem: " << IT[1].rem << endl;
                    updateAdd(1,1,n,l,r,x);
                    // cout << "Rem after Add: " << IT[1].rem << endl;
                    updatePop(1,1,n,l,r);
                    // ++cnt;
                    // if (cnt > 100){
                    //     cout << "What?" << endl;
                    //     break;
                    // }
                } while (IT[1].rem == 0); 
                // cout << "Rem: " << IT[1].rem << endl;
                // for (int i=1; i<=n; i++) {
                //     cout << getVal(1,1,n,i) << " ";
                // }
                // cout << endl;
            }
        }
    }

    /*Driver Code*/
    signed main(){
        // cin.tie(0) -> sync_with_stdio(0);
        if (fopen(TEXT".inp","r")){
            freopen(TEXT".inp","r",stdin);
            freopen(TEXT".out","w",stdout);
        }

        pw[0] = 1;
        for (int i=1; i<12; i++){
            pw[i] = pw[i-1]*42;
        }

        int testCount = 1;
    //    cin >> testCount;
        while (testCount--){
            solve();
        }

        return 0;
    }