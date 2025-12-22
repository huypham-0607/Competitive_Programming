#include <iostream>

using namespace std;

int t,n;
bool lcheck;
string s;

int main()
{
    cin >> t;
    for (int k=0; k<t; k++){
        cin >> n >> s;
        s += "0";
        lcheck = false;
        for (int i=0; i<n; i++){
            if (s[i] == 'L'){
                lcheck =  true;
                if (s[i+1] == 'R'){
                    cout << i+1;
                    break;
                }
                if (s[i+1] == '0'){
                    if (s[0] == 'R') cout << "0";
                    else cout << "-1";
                    break;
                }
            }
        }
        if (!lcheck) cout << "-1";
        cout << endl;
    }
    return 0;
}
