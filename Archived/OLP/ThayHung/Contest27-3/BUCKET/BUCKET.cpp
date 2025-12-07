#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "BUCKET"

using namespace std;

/*Constants*/
const int N = 3e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int test;
int n;
pii a[N];

/*Inititalization*/
void Init(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
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

/*Subtask5*/
bool CheckSub5(){
    return true;
}

void SolveSub5(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    priority_queue<int> caplist;
    int res = 0;
    for (int i=1; i<=n; i++){
        if (a[i].fi < a[i].se){
            pq.push({a[i].fi,INF});
            ++res;
        }
        pq.push({a[i].se,a[i].fi});
    }
    caplist.push(0);
    int capless = 0;
    while (!pq.empty()){
        int val = pq.top().fi;
        int cap = pq.top().se;

//        cout << val << " " << cap << " " << endl;

        pq.pop();

//        cout << caplist.top() << " " << capless << endl;

        if (cap == INF){
            if (capless == 0){
                if (caplist.top()<=capless){
                    cout << -1;
                    return;
                }
                else{
                    ++res;
                    pq.push({caplist.top(),INF});
                    caplist.pop();
                }
            }
            else --capless;
        }
        else{
            if (val <= cap){
                caplist.push(cap);
            }
            else ++capless;
        }
    }
    cout << n-res;
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
    if (CheckSub5()) return SolveSub5(),0;


    return 0;
}
