#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int a[51];
int n,k,t=0;
string s,p;
//queue<char> q;

int vt(char c){
    return int(c)-65-(int(c) / 97*6);
}

int main()
{
    freopen("HVC.INP","r",stdin);
    freopen("HVC.OUT","w",stdout);
    queue<char> q;
    fill_n(a,52,0);
    cin >> n >> k >> s >> p;
    for (int i=0; i<n; i++){
        a[vt(s[i])]++;
    }
    for (int i=0; i<k; i++){
        q.push(p[i]);
        if (a[vt(p[i])] == 0){
            while (q.front() != p[i]){
                a[vt(q.front())]++;
                q.pop();
            }
            q.pop();
        }
        else a[vt(p[i])]--;

        if (q.size() == n){
            t++;
            a[vt(q.front())]++;
            q.pop();
        }
    }

    cout << t;
    return 0;
}
