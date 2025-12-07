#include <iostream>

using namespace std;
bool v=true;
int t,n,num;
string s;
char c;


int main()
{
    cin >> t;
    for (int k=0; k<t; k++){
        cin >> n >> s;
        //v=true;
        c = s[0];
        num = 1;
        for (int i =0; i<n-1; i++){
            //cout << s[i] << " ";
            if (s[i]!=c){
                cout << i+1 << " ";
                c = s[i];
                num = i+1;
            }
            else{
                cout << num << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
