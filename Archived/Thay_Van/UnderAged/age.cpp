#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 256
#define Beanstalk Beanstalk is the best waifu why cuz shes professional.
#define Iloveyourmom vector<vector<bool>>
using namespace std;

int n,m,s1,s2;
vector<int> a[lim];
Iloveyourmom bronya(20*n+6,vector<bool> (n+9,0));
Iloveyourmom seele(20*n+6,vector<bool> (n+9,0));

int bfs(int s1, int s2){
    bronya[0][s1] = true;
    seele[0][s2] = true;
    for (int i=0; i<20*n; i++){
        for (int j=1; j<=n; j++){
            if (bronya[i][j]){
                for (auto v:a[j]){
                    bronya[i+1][v] = true;
                }
            }
        }
        for (int j=1; j<=n; j++){
            if (seele[i][j]){
                for (auto v:a[j]){
                    seele[i+1][v] = true;
                    if (bronya[i+1][v]){
                        return i+1;
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    freopen("AGE.INP","r",stdin);
    freopen("AGE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s1 >> s2;
    while (m--){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    cout << bfs(s1,s2);
    return 0;
}
