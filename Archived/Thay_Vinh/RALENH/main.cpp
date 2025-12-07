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
    freopen("RALENH.INP","r",stdin);
    freopen("RALENH.OUT","w",stdout);
    cin >> n >> m;
    st="12345";

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
            cout << "Yes"<< endl;
        }
        else cout << "No" << endl;

        while (!s.empty()){
            s.pop();
        }
    }
    return 0;
}
