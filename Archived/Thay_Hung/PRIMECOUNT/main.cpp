#include <bits/stdc++.h>
#define lim 31622
#define lowlim = 177
#define upper (int)1e9;
using namespace std;


bitset<1000000010> bs;
vector<int> prime;
int l,r,t;

int nextnum(int p, int x){
    return x-(x%p)+p;
}

void init(){
    //int smax = lowlim+1;
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (int i=2; i<=lim; i++){
        if (bs[i]){
            for (int j=i*i; j<=lim; j+=i){
                bs[j] = 0;
            }
            prime.push_back(i);
        }
    }
}

int getans(int l, int r){
    if (r>lim){
        l = max(l,lim+1);
        for (auto x:prime){
            if (x*x>r) break;
            //cout << nextnum(x,l) << " " << x <<endl;
            for (int i=max(nextnum(x,l),x*x); i<=r; i+=x){
                bs[i] = 0;
                //cout << i << endl;
            }
        }
    }
    int c=0;
    for (int i=l; i<=r; i++){
        //cout << i << " " << bs[i] << " " << c << endl;
        if (bs[i]) c++;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    init();

    /*for (int i=0; i<10000; i++){
        cout << bs[i] << " ";
    }
    cout << endl;*/

    while (t--){
        cin >> l >> r;
        cout << getans(l,r) << "\n";
    }

    /*for (int i=0; i<10000; i++){
        cout << bs[i] << " ";
    }
    cout << endl;*/

    return 0;
}
