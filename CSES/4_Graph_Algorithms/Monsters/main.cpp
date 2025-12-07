#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iis pair<ii,string>
#define fi first
#define se second
#define INF 1e9
using namespace std;


int a[1010][1010],b[1010][1010];
bool visit[1010][1010];
int di[4] = {0,1,0,-1},
    dj[4] = {1,0,-1,0};
string dir[4] = {"R","D","L","U"};
int m,n,si,sj;
vector<ii> v;

bool valid(int i, int j){
    return (i>0 && i<=n && j>0 && j<=m);
}

bool border(int i, int j){
    return (i==0 || i==n || j==0 || j==m);
}

void BFS(int a[1010][1010],int si, int sj){

    queue<iii> q;
    q.push({{si,sj},0});
    while (!q.empty()){
        int i = q.front().fi.fi;
        int j = q.front().fi.se;
        int t = q.front().se;
        //cout << i << " " << j << " " << t<< endl;
        q.pop();
        for (int x=0; x<4; x++){
            int newi = i+di[x];
            int newj = j+dj[x];
            if (valid(newi,newj) && a[newi][newj] > t+1){
                a[newi][newj] = t+1;
                q.push({{newi,newj},t+1});
            }
        }
    }
}

string BFS2(){
    queue<iis> q;
    q.push({{si,sj},""});
    while (!q.empty()){
        int i = q.front().fi.fi;
        int j = q.front().fi.se;
        string t = q.front().se;
        visit[i][j] = true;
        q.pop();
        if (border(i,j)){
            return t;
        }
        for (int x=0; x<4; x++){
            int newi = i+di[x];
            int newj = j+dj[x];
            if (valid(newi,newj) && !visit[newi][newj] && a[newi][newj]!=-1 && a[newi][newj] < b[newi][newj]){
                string tnew=t+dir[x];
                q.push({{newi,newj},tnew});
            }
        }
    }
    return "X";
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++){
            if (s[j-1] == '#'){
                a[i][j] = -1;
                b[i][j] = -1;
            }
            else{
                a[i][j] = INF;
                b[i][j] = INF;
            }
            if (s[j-1] == 'A'){
                a[i][j] = 0;
                si = i;
                sj = j;
            }
            if (s[j-1] == 'M'){
                b[i][j] = 0;
                v.push_back({i,j});
            }
        }
    }
    //BFS(a,si,sj);
    /*cout << "meow" << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i][j] == INF) cout << "." << " ";
            else if (a[i][j] == -1) cout << "#" << " ";
            else cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (b[i][j] == INF) cout << "." << " ";
            else if (b[i][j] == -1) cout << "#" << " ";
            else cout << b[i][j] << " ";
        }
        cout << endl;
    }*/
    BFS(a,si,sj);
    for (auto in:v){
        //cout << "meow" << endl;
        BFS(b,in.fi,in.se);
    }
    //cout << "woof" << endl;
    string s = BFS2();
    if (s == "X"){
        cout << "NO";
    }
    else {
        cout << "YES" << "\n";
        cout << s.size() << "\n";
        cout << s;
    }
    return 0;
}
