#include <iostream>

using namespace std;

int t,n;

int main()
{
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        if (n%2==0){
            cout << "YES" << endl;
            for (int j=0; j<n; j++){
                if (j%2 == 0){
                    cout << "-1 ";
                }
                else cout <<"1 ";
            }
        }
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
