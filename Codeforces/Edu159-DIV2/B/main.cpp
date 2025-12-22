#include <bits/stdc++.h>
#define endl "\n"
#define int unsigned long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,p,l,t,test;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n >> p >> l >> t;
//        cout << n << " " << p << " " << l << " " << t << "\n";
        int totaldays = 0;
        int cur = 0;
        int taskcnt = (n-1)/7+1;
        int fulldays = taskcnt/2;
        int fulldayval = l+t+t;
        if (fulldays){
            if (fulldays*fulldayval >= p){
                int res = p/(fulldayval);
                if ((p%(fulldayval))) res++;
//                cout << res << " ";
                cout << n-res << "\n";
                continue;
            }
            else{
                totaldays+=fulldays;
                cur+=fulldays*fulldayval;
            }
        }
//        cout << cur << " ";
        if (taskcnt%2){
            if (cur+l+t>=p){
                cout << n-(totaldays+1) << "\n";
                continue;
            }
            else{
                cur+=l+t;
                totaldays++;
            }
        }
        int rest = n - fulldays;
        if (taskcnt%2) rest--;
        int remainpoints = p-cur;
//        cout << "meow " << fulldays << " " << cur << " ";
        totaldays+= ((remainpoints%l == 0)? remainpoints/l : remainpoints/l+1);
        cout << n-totaldays << "\n";
    }
    return 0;
}
