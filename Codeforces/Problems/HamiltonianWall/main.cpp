#include <iostream>

using namespace std;

int t,m,num,nxt;
string a,b;
bool v;


int check(char x, char y){
    if (x == 'B'){
        if (y == 'B') return 2;
        else return 1;
    }
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int k=0; k<t; k++){
        cin >> m;
        cin >> a >> b;
        num = check(a[0],b[0]);
        v = true;
        for (long long unsigned i=1; i<a.size(); i++){
            nxt = check(a[i],b[i]);
            if (nxt == 2){
                if (num!=2){
                    num = (num+1)%2;
                }
            }
            else{
                if (num == 2){
                    num = nxt;
                }
                else if (num != nxt){
                    v = false;
                    break;
                }
            }
        }
        if (v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
