#include <bits/stdc++.h>

using namespace std;

int n,c,req[100],avail[100],ams[100],ps[100],aml[100],pl[100],pos;
bool check(int t){
    //cout << endl;
    int total = 0,cst,sum,mn,sumlow;
    for (int i=0; i<n; i++){
        sum = req[i]*t-avail[i];
        mn = ((sum-1)/aml[i] +1)*pl[i];
        //cout << sum << " " <<mn << endl;
        for (int j=sum/aml[i]; j>=0; j--){
            sumlow = sum - aml[i]*j;
            cst = j*pl[i] + ((sumlow-1)/ams[i]+1)*ps[i];
            mn = min(mn,cst);
            //cout << mn << " " <<sumlow<<" " << cst << " " << j << endl;
        }
        //cout << endl;
        total+=mn;
    }
    //cout << total << endl<<endl;
    if (total>c) return false;
    else return true;
}

int bs (int l,int r){
    //cout << l << " " << r << endl;
    if (l==r) return l;
    int mid = (l+r)/2;
    //cout << mid+1 << endl;
    if (!check(mid+1)) return bs(l,mid);
    return bs(mid+1,r);
}

int main()
{
    freopen("SINHNHAT.INP","r",stdin);
    freopen("SINHNHAT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    //cout << c << endl;
    for (int i=0; i<n; i++){
        cin >> req[i] >> avail[i] >> ams[i] >> ps[i] >> aml[i] >> pl[i];
    }

    if (c==0) cout << 0;
    else{
        pos = bs(1,100000);
        cout << pos;
    }
    return 0;
}
