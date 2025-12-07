#include <bits/stdc++.h>
#define lim 1000000
#define div 1000000007
using namespace std;

int t1[1000010],t2[1000010];



int add(int x, int y){
    return (x+y)%div;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    t1[0] = 0;
    t2[0] = 0;
    t1[1] = 1;
    t2[1] = 1;
    for (int i=2; i<=lim; i++){
        t1[i] = add(add(t1[i-1],t1[i-1]),add(t1[i-1],t1[i-1]));
        //cout << t1[i] << " ";
        t1[i] = add(t1[i],t2[i-1]);
        //cout << t1[i] << " ";
        t2[i] = add(add(t2[i-1],t2[i-1]),t1[i-1]);
        //cout << t2[i] << "\n";
    }
    int t;
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        cout << add(t1[x],t2[x]) << endl;
    }

    /*for (int i=0; i<100; i++){
        cout << t1[i] << " " << t2[i] << "\n";
    }
    cout << add(1,1);*/
    return 0;
}
