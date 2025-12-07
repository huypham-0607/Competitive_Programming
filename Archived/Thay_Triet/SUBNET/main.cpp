#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int m,n,x,t=0;
unsigned long long v=0,sm,snm;
string s;
stringstream ss;

unsigned long long solve(string s){
    stringstream ss;
    unsigned long long x=0,y=0;
    int j;
    char f;
    ss << s;
    for (j=0; j<4; j++){
        ss >> x>>f;
        //cout << x << " ";
        y=(y << 8) | x;
    }
    ss.clear();
    return(y);
}

int main()
{
    freopen("SUBNET.INP","r",stdin);
    freopen("SUBNET.OUT","w",stdout);

    cin >> m >> n >> s;
    snm=0;
    for (int i=0; i<32; i++){
        snm = (snm << 1);
        if (i<m)
            snm = snm | 1;
    }
    sm = solve(s);
    pair<unsigned long long,string> a[n];
    for (int i=0; i<n; i++){
        cin >> a[i].second;
        a[i].first = solve(a[i].second);
    }

    sort(a,a+n);

    //for (int i=0; i<n; i++){
    //    cout << a[i].second << endl;
    //}
    //cout << endl;
    //cout << snm << endl;
    for (int i=0; i<n; i++){
        //v = solve(a[i]) & snm;
        //cout << v <<" "<< sm<<" "<<endl;
        if ((a[i].first & snm) == sm){
            cout <<a[i].second<<endl;
            t++;
        }
        //cout << endl;
    }
    if (t==0)
        cout << 0;

    return 0;
}
