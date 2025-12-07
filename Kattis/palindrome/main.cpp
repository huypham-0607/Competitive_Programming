#include <bits/stdc++.h>
#define UP(s) (s.size()/2 + s.size()%2)
//#define LOW(s) (s.size()/2)-1
using namespace std;
string s1,s2;
bool v;
int m,n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    for (int k=0; k<m; k++){
        cin >> n >> s1;
        s2 = s1.substr(s1.size()/2,s1.size()/2+s1.size()%2);
        for (unsigned long long i =0; i<s2.size()/2;i++){
            swap(s2[i], s2[s2.size()-1-i]);
        }
        //cout << s2<< endl;

        v=true;

        if (s1[1] == 'A' && s2[1] == 'B') v=false;
        if (s1.size()%2 !=1 && s1[s2.size()-1] == 'B' && s2[s2.size()-1] == 'A') v=false;
        if (v) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }
    return 0;
}
