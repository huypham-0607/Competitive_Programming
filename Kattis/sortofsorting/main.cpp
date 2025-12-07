#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string a[200];
pair <string,int> b [200];

int main()
{
    freopen("sortofsorting.INP","r",stdin);
    freopen("sortofsorting.OUT","w",stdout);
    cin>>n;
    cin.ignore(256,'\n');
    while (n!=0){
        for (int i=0; i!=n; i++){
            getline(cin,a[i]);
            b[i].first = a[i].substr(0,2);
            b[i].second = i;
        }

        sort(b,b+n);

        for (int i=0; i!=n; i++){
            cout << a[b[i].second] << endl;
        }
        cout <<endl;
        cin>>n;
        cin.ignore(256,'\n');
    }
    return 0;
}
