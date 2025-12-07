/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int n,m;

//BIGNUM
class BigNum{
public:
    string num;
    BigNum(int x=0){
        while (x!=0){
            num.push_back(char(48+x%10));
            x/=10;
        }
    }

    string Add(string a, string b){
        if (b.size() > a.size()) swap(a,b);
        int n = a.size();
        int m = b.size();
        string res = "";
        int remain = 0,cur;
        for (int i=0; i<=n; i++){
            cur = remain;
            if (i<n) cur+=a[i]-'0';
            if (i<m) cur+=b[i]-'0';
            res.push_back(char(48+cur%10));
            remain = cur/10;
        }
        while (res.back()=='0') res.pop_back();
        return res;
    }

    string Sub(string a, string b){
        while (a.size()<b.size()) a.push_back('0');
        int n = a.size();
        int m = b.size();
        string res = "";
        int remain = 0,cur;
        for (int i=0; i<=n; i++){
            cur = -remain;
            if (i<n) cur+=a[i]-'0';
            if (i<m) cur-=b[i]-'0';
            if (cur<0){
                remain=1;
                cur+=10;
            }
            else remain = 0;
            res.push_back(char(48+cur%10));
        }
        while (res.back()=='0') res.pop_back();
        return res;
    }

    string Mul(string a, string b){
        if (a.size()<b.size()) swap(a,b);
        int n = a.size();
        int m = b.size();
        string res = "";
        for (int i=0; i<n+m; i++){
            res.push_back('0');
        }
        int remain = 0,cur;
        for (int i=0; i<n; i++){
            remain = 0;
            for (int j=0; j<=m; j++){
                cur = remain;
                cur += res[i+j]-'0';
                if (j<m) cur+=(a[i]-'0')*(b[j]-'0');
                res[i+j] = char(48+cur%10);
                remain = cur/10;
            }
        }
        while (res.back()=='0') res.pop_back();
        return res;
    }

    BigNum operator+(BigNum const &b){
        BigNum res;
        res.num = Add(num,b.num);
        return res;
    }

    BigNum operator-(BigNum const &b){
        BigNum res;
        res.num = Sub(num,b.num);
        return res;
    }

    BigNum operator*(BigNum const &b){
        BigNum res;
        res.num = Mul(num,b.num);
        return res;
    }
};

string Div2(string a){
    int cur = 0;
    int n = a.size();
    for (int i=0; i<n; i++){
        cur = a[i]-'0';
        if (i!=0 && cur%2==1) a[i-1] = char(48+(a[i-1]-48)+5);
        a[i] = char(48+cur/2);
    }
    while (a.back() == '0') a.pop_back();
    return a;
}

BigNum GetSum(int x){
    BigNum tmp(x);
    tmp = tmp*(tmp+BigNum(1));
    tmp.num = Div2(tmp.num);
    return tmp;
}

bool comp(BigNum a,BigNum b){
    if (b.num.size() > a.num.size()) return true;
    int n = a.num.size();
    for (int i=1; i<=n; i++){
        if (b.num[i]>a.num[i]) return true;
        if (b.num[i]<a.num[i]) return false;
    }
    return true;
}

pair<BigNum,int> Binsearch1(){
    BigNum rawr = GetSum(m)*BigNum(n)+GetSum(n-1)*BigNum(m*m);
    BigNum org = rawr;
//    cout << rawr.num << endl;
    rawr.num = Div2(rawr.num);
    int ans = 0;
    int l = 1;
    int r = m;
    while (l<=r){
        int mid = (l+r)/2;
        BigNum tmp = GetSum(mid)*BigNum(n)+GetSum(n-1)*BigNum(mid*m);
        if (comp(tmp,rawr)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
//    cout << rawr.num << endl;
    if (comp(rawr-(GetSum(ans)*BigNum(n)+GetSum(n-1)*BigNum(ans*m)),(GetSum(ans+1)*BigNum(n)+GetSum(n-1)*BigNum((ans+1)*m))-rawr)){
//        cout << (GetSum(ans)*BigNum(n)).num << " " << (GetSum(n-1)*BigNum(ans*m)).num << " " << (rawr-(GetSum(ans)*BigNum(n)+GetSum(n-1)*BigNum(ans*m))).num << endl;
        return make_pair(org-(GetSum(ans)*BigNum(n)+GetSum(n-1)*BigNum(ans*m))*(BigNum(2)),ans);
    }
    else return make_pair((GetSum(ans+1)*BigNum(n)+GetSum(n-1)*BigNum((ans+1)*m))*BigNum(2)-org,ans+1);
}

pair<BigNum,int> Binsearch1(){
    BigNum rawr = GetSum(m)*BigNum(n)+GetSum(n-1)*BigNum(m*m);
    BigNum org = rawr;
    cout << rawr.num << endl;
    rawr.num = Div2(rawr.num);
    int ans = 0;
    int l = 1;
    int r = n;
    while (l<=r){
        int mid = (l+r)/2;
        BigNum tmp = GetSum(m)*BigNum(mid)+GetSum(mid-1)*BigNum(m*m);
        if (comp(tmp,rawr)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << rawr.num << endl;
    if (comp(rawr-(GetSum(ans)*BigNum(n)+GetSum(n-1)*BigNum(ans*m)),(GetSum(ans+1)*BigNum(n)+GetSum(n-1)*BigNum((ans+1)*m))-rawr)){
        cout << (GetSum(ans)*BigNum(n)).num << " " << (GetSum(n-1)*BigNum(ans*m)).num << " " << (rawr-(GetSum(ans)*BigNum(n)+GetSum(n-1)*BigNum(ans*m))).num << endl;
        return make_pair(org-(GetSum(ans)*BigNum(n)+GetSum(n-1)*BigNum(ans*m))*(BigNum(2)),ans);
    }
    else return make_pair((GetSum(ans+1)*BigNum(n)+GetSum(n-1)*BigNum((ans+1)*m))*BigNum(2)-org,ans+1);
}

/*Solution*/
void solve(){
    cin >> n >> m;
//    BigNum a(n),b(m);
//    BigNum tmp(0);
//    cout << a.num << " " << b.num << endl;
//    tmp = a+b; cout << tmp.num << endl;
//    tmp = a-b; cout << tmp.num << endl;
//    tmp = a*b; cout << tmp.num << endl;
//    cout << Div2(a.num) << endl;
//    cout << Div2(b.num) << endl;
    pair<BigNum,int> ans1 = Binsearch1();
    cout << ans1.fi.num << " " << ans1.se << endl;
    for (int i=1; i<=20; i++){
        cout << GetSum(i).num << " ";
    }
    cout << endl;
    BigNum rawr = GetSum(6)-GetSum(3);
    cout << GetSum(6).num << endl;
    cout << GetSum(3).num << endl;
    cout << rawr.num << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
