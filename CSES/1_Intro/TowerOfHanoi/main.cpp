#include <bits/stdc++.h>

using namespace std;

int c,n;

int last(int x,int y){
    return 6-x-y;
}

void recursioncount(int n, int s, int e){
    c++;
    if (n==1){
        //cout << s << " " << e << endl;
    }
    else {
        recursioncount(n-1,s,last(s,e));
        //cout << s << " " << e << endl;
        recursioncount(n-1,last(s,e),e);
    }
}

void recursion(int n, int s, int e){
    //c++;
    if (n==1){
        cout << s << " " << e << endl;
    }
    else {
        recursion(n-1,s,last(s,e));
        cout << s << " " << e << endl;
        recursion(n-1,last(s,e),e);
    }
}


int main()
{
    cin >> n;
    recursioncount(n,1,3);
    cout << c << endl;
    recursion(n,1,3);
    return 0;
}
