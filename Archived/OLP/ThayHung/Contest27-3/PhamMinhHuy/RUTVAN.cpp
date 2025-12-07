#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "RUTVAN"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9;
const long long LLINF = 1e18+3;

/*Global Variables*/
int test;
int n,m,limn,limm;
vector<int> a,b;

/*Inititalization*/
void Init(){
    cin >> limn >> limm >> n >> m;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i=1; i<=m; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
}

/*Subtask1*/
bool CheckSub1(){
    return false;
}

void SolveSub1(){

}

/*Subtask2*/
bool CheckSub2(){
    return false;
}

void SolveSub2(){

}

/*Subtask3*/
bool CheckSub3(){
    return true;
}

void SolveSub3(){
    a.push_back(limn);
    b.push_back(limm);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int vercnt = n;
    int horcnt = m;
    int prev = 0;
    vector<int> hor,ver;
    for (auto i:b){
        ver.push_back(i-prev);
        prev = i;
    }
    prev = 0;
    for (auto i:a){
        hor.push_back(i-prev);
        prev = i;
    }
    sort(ver.begin(),ver.end());
    sort(hor.begin(),hor.end());
//    cout << "meow" << endl;
//    for (auto i:ver){
//        cout << i << " ";
//    }
//    cout << endl;
//    for (auto i:hor){
//        cout << i << " ";
//    }
//    cout << endl;
    int res = 0;
    res+=ver[0]*vercnt;
    res+=hor[0]*horcnt;
    int i = 1;
    int j = 1;
    while (i<=m || j<=n){
        if (j>n){
            res+=ver[i]*vercnt;
            horcnt--;
            ++i;
        }
        else if (i>m){
            res+=hor[j]*horcnt;
            vercnt--;
            ++j;
        }
        else if (ver[i]<hor[j]){
            res+=ver[i]*vercnt;
            horcnt--;
            ++i;
        }
        else{
            res+=hor[j]*horcnt;
            vercnt--;
            ++j;
        }
    }
    cout << res;
}

/*Subtask4*/
bool CheckSub4(){
    return false;
}

void SolveSub4(){

}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub1()) return SolveSub1(),0;
    if (CheckSub2()) return SolveSub2(),0;
    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;


    return 0;
}

