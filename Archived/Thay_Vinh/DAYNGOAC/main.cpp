#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
string st;
int n;

bool solve(string st){
    stack<char> s;
    s.push('0');
    for (unsigned long long i=0; i<st.length();i++){
        if (st[i]=='(' || st[i]=='{' || st[i]=='[')
            s.push(st[i]);
        else
            if (char(int(st[i])-1) == s.top() || char(int(st[i])-2) == s.top())
                s.pop();
        else return false;
    }
    if (s.top() == '0'){
        return true;
    }
    else return false;
}


int main()
{
    freopen("DAYNGOAC.INP","r",stdin);
    freopen("DAYNGOAC.OUT","w",stdout);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> st;
        if (solve(st))
            cout << "TRUE" << endl;
        else cout <<"FALSE"<<endl;
    }
    return 0;
}
