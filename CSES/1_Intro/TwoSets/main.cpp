#include <bits/stdc++.h>

using namespace std;

int n,c,i;
unsigned long long t;
bool a[1000001];

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++){
        t+=i;
    }
    if (t%2){
        cout << "NO";
    }
    else {
        cout << "YES" << endl;
        t=t/2;
        i=n;
        c=0;
        while (t){
            //cout << t << " and " << i << " ";
            if (i<=t){
                t-=i;
                a[i] = true;
                c++;
            }
            i--;
        }
        cout << c << endl;
        for (i=1; i<=n; i++){
            if (a[i]) cout << i << " ";
        }
        cout << endl << n-c << endl;
        for (i=1; i<=n; i++){
            if(!a[i]) cout << i << " ";
        }

    }
    return 0;
}
