#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pci pair<char,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,t;

bool upcheck(char c){
    return (c>='A' && c<='Z');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        deque<pci> up,down;
        for (int i=0; i<int(s.size()); i++){
            if (s[i] == 'B'){
                if (up.empty()) continue;
                up.pop_front();
            }
            else if (s[i] == 'b'){
                if (down.empty()) continue;
                down.pop_front();
            }
            else if (upcheck(s[i])){
                up.push_front({s[i],i});
            }
            else if (!upcheck(s[i])){
                down.push_front({s[i],i});
            }
            //cout << up.front().fi << " meow " << down.front().fi << endl;
        }
//        cout << down.back().fi << endl;
        while (!up.empty() || !down.empty()){
            if (up.empty() && !down.empty()){
                cout << down.back().fi;
                down.pop_back();
            }
            else if (down.empty() && !up.empty()){
                cout << up.back().fi;
                up.pop_back();
            }
            else{
                if (up.back().se < down.back().se){
                    cout << up.back().fi;
                    up.pop_back();
                }
                else {
                    cout << down.back().fi;
                    down.pop_back();
                }
            }
        }
        cout << endl;
    }
    return 0;
}
