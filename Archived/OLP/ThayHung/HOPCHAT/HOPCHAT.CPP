#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "HOPCHAT"

using namespace std;

const int maxn = 1e5+10;
const int INF = 1e9+7;

//Global Variables

int test;
int n,k;
int a[maxn];

//Inititalization

void Init(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
}

//Subtask1

bool CheckSub1(){
    return true;
}

vector<int> v;

void SolveSub1(){
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            v.push_back((a[i]^a[j]));
        }
    }
    sort(v.begin(),v.end());
    cout << v[k-1];
}

//Subtask2

bool CheckSub2(){
    return false;
}

void SolveSub2(){

}

//Subtask3

bool CheckSub3(){
    return false;
}

void SolveSub3(){

}

//Subtask4

bool CheckSub4(){
    return false;
}

void SolveSub4(){

}



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
