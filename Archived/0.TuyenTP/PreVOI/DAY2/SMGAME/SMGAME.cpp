#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "SMGAME"

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
int a[N],b[N];

/*Inititalization*/
void Init(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
}

/*Subtask1*/
bool CheckSub1(){
    return true;
}

int vis[N];

void DFS(int u){
    vis[u] = true;
    if (!vis[(u+n-1)%n] && b[(u+n-1)%n] == 2) DFS((u+n-1)%n);
    if (!vis[(u+1)%n] && b[(u+1)%n] == 2) DFS((u+1)%n);
}

void SolveSub1(){
    for (int i=0; i<n; i++){
        if (a[i] == 2){
            if (b[i] == 1){
                cout << -1 << endl;
                return;
            }
            if (!vis[i]) DFS(i);
        }
    }
    for (int i=0; i<n; i++){
        if (a[i] == 1 && b[i] == 2 && !vis[i]){
            cout << -1 << endl;
            return;
        }
    }

    int cnt = 0;
    for (int i=0; i<n; i++){
        if (a[i] == 1){
            if (b[i] == 2 && vis[i]) ++cnt;
        }
    }
//    for (int i=0; i<n; i++){
//        cout << vis[i] << endl;
//    }
    cout << cnt << endl;
}

/*Subtask2*/
bool CheckSub2(){
    return false;
}

void SolveSub2(){

}

/*Subtask3*/
bool CheckSub3(){
    return false;
}

void SolveSub3(){

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
