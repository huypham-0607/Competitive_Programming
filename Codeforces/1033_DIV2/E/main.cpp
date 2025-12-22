/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#include <windows.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,kkk;
int a[N];
int org;

pair<int,pii> red(int cnt, int k, int val, int x){
    int res = 0;
    int delta = min(cnt%k,x);

    res += val*delta;
    x-=delta;
    cnt-=delta;

    if (x){
        int a = x/k;
        int b = x%k;

        int s = val-a;

        res += (s*a + a*(a-1)/2)*k;
        cnt -= k*a;
        val -= a;

        if (b){
            --val;
            res += val*b;
            cnt -= b;
        }
    }

    return {res,{cnt,val}};
}


pair<int,pii> inc(int cnt, int k, int val, int x){
    int res = 0;
    int delta = min(cnt%k,x);

    res += val*delta + kkk*delta;
    x-=delta;
    cnt-=delta;

    if (x){
        int a = x/k;
        int b = x%k;

        int s = val+1;

        res += (s*a + a*(a-1)/2)*k + kkk*k*a;
        cnt -= k*a;
        val += a;

        if (b){
            ++val;
            res += val*b + kkk*b;
            cnt -= b;
        }
    }

    return {res,{cnt,val}};
}

pii check(int x){
    int l = 1;
    int r = 1;
    int vall = a[l]+1-1;
    int valr = a[n-r+1]+1;
    int cntl = a[l+1] - a[l];
    int cntr = a[n-r+1] - a[n-r];

    int res = 0;

    int cnt = 0;


    while (x > 0){
//        cout << vall << " " << valr << " " << cntl << " " << cntr << endl;
        int delta = min({cntl,cntr,x});

        x-=delta;
        pair<int,pii> tmpl = inc(cntl,l,vall,delta);
        pair<int,pii> tmpr = red(cntr,r,valr,delta);
        res+=tmpl.fi;
        res-=tmpr.fi;
        cntl = tmpl.se.fi;
        cntr = tmpr.se.fi;
        vall = tmpl.se.se;
        valr = tmpr.se.se;

        while (l<n && cntl == 0){
            ++l;
//            vall = a[l];
            cntl = abs(a[l+1] - a[l])*l;
        }
        while (r<n && cntr == 0){
            ++r;
//            valr = a[n-r+1]+1;
            cntr = abs(a[n-r+1] - a[n-r])*r;
        }

//        cout << x << " " << vall << " " << valr <<  " " << cntl << " " << cntr << endl;
//        cout << org+res << endl;
//        Sleep(1);
    }

//    cout << "value " << vall << " " << valr << " " << kkk << endl;

    return {res,vall-valr+kkk};
}

/*Solution*/
void solve(){
    cin >> n >> kkk;
    int t = 0;
    org = 0;
    a[0] = INF;
    a[n] = INF;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        t+=a[i];
        org += a[i]*(a[i]+1)/2;
    }

    sort(a+1,a+n+1);

    int low = t/n;
    if (t%n) ++t;

    int lim = 0;

    for (int i=1; i<=n; i++){
        if (a[i] > low) lim+=a[i]-low;
    }

    int l = 1, r = lim;
    int ans = org;
    int anspos = 0;
    while (l<=r){
        int mid = (l+r)/2;
//        cout << "mid " << mid << endl;
        pii tmp = check(mid);
//        cout << tmp.fi << endl;
        tmp.fi+=org;

//        cout << "result " << mid << " " << tmp.fi << " " << tmp.se << endl;

        if (tmp.se<0){
            ans = tmp.fi;
            anspos = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

//    if (anspos<lim){
//        pii tmp = check(anspos+1);
//        tmp.fi+=org;
//        if (ans>tmp.fi){
//            ans = tmp.fi;
//            ++anspos;
//        }
//    }

    cout << ans << endl;
//    cout << org << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
