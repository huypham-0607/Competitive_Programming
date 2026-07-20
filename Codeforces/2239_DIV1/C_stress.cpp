/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "C"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(ll l, ll r){
    return uniform_int_distribution<ll> (l,r) (mt);
}

void Gen(){
    ofstream cout(NAME".inp");

    int t = 5;
    cout << t << endl;
    vector<int> v;
    vector<int> s;
    for (int tid=0; tid<t; tid++){
        int n = rd(1,7);
        cout << n << endl;
        v.clear(); v.resize(n);
        s.clear();
        iota(all(v),1);
        shuffle(all(v),mt);
        for (int i=0; i<n; i++){
            int val = 0;
            for (int j=0; j<i; j++){
                if (v[i] < v[j]) ++val;
            }
            s.push_back(val);
        }
        for(int i=0; i<n; i++){
            cerr << v[i] << " " << s[i] << endl;
        }
        for (int i=1; i<n; i++){
            s[i] += s[i-1];
        }
        for (int i=0; i<n; i++){
            int flag = rd(0,1);
            if (flag) {
                cout << "p " << v[i] << endl;
            }
            else {
                cout << "s " << s[i] << endl;
            }
        }
    }

    cout.close();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    system("g++ " NAME ".cpp -o" NAME);

    srand(time(NULL));
    int TEST=1000;
    for (int testid = 1; testid<=TEST; testid++){
        cerr << "test: " << testid << endl;
        Gen();

        int ret = system("./" NAME);


        if (ret == -1) {
            perror("system");           // fork/exec machinery failed
        } else if (WIFSIGNALED(ret)) {
            int sig = WTERMSIG(ret);
            printf("Command crashed, killed by signal %d\n", sig);
            return 0;
            // e.g. 11 = SIGSEGV, 6 = SIGABRT
        } else if (WIFEXITED(ret)) {
            printf("Command exited normally with code %d\n", WEXITSTATUS(ret));
        }
    }

    return 0;
}
