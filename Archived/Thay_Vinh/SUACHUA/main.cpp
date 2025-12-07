#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

stack <char> s;
int n,m,i,j;
char c;
string st,st1;

int main()
{
    freopen("SUACHUA.INP","r",stdin);
    freopen("SUACHUA.OUT","w",stdout);
    cin >> n >> m;
    st="";
    for (int i=0; i<n; i++){
        cin >> c;
        st[i] = c;
    }

    for (int k=0; k<m; k++){
        i=0;
        for (j=0; j<n;j++){
            cin >>c;
            st1[j]=c;
        }
        j=0;
        while (i<n){

            s.push(st[i]);
            while (!s.empty() && s.top() == st1[j]){
                s.pop();
                j++;
            }
            i++;
        }
        if (s.empty()){
            cout << "Y"<< endl;
        }
        else cout << "N" << endl;

        while (!s.empty()){
            s.pop();
        }
    }
    return 0;
}
