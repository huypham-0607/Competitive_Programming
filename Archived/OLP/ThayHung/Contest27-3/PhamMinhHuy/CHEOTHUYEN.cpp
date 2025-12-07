#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "CHEOTHUYEN"

using namespace std;

/*Constants*/
const int N = 2e5+5e4+10;
const int INF = 1e9;
const long long LLINF = 1e18+3;

/*Global Variables*/
int test;
int n;
int x[N],y[N];

/*Inititalization*/
void Init(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
}

/*Subtask1*/
bool CheckSub1(){
    if (n<=5000) return true;
    return false;
}

//BFS
vector<int> adj[N];
int dist[N];

void BFS(int s){
    for (int i=1; i<=n; i++){
        dist[i] = -1;
    }
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto v:adj[u]){
            if (dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
}

void SolveSub1(){

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (x[i] > x[j] && y[i] > y[j]) adj[i].push_back(j);
            if (x[i] < x[j] && y[i] < y[j]) adj[i].push_back(j);
        }
    }
    for (int i=1; i<=n; i++){
        BFS(i);
        int res = 0;
        for(int i=1; i<=n; i++){
            res+=dist[i];
        }
        cout << res << endl;
    }

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
int main(){
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
