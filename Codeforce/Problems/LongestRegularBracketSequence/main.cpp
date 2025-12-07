#include <bits/stdc++.h>

using namespace std;

string st;
stack <int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> st;
    int mx = 0;
    int cnt = 1;
    int length = 0;
    s.push(-1);
    for (unsigned long long i=0; i<st.size(); i++){
        if (st[i] == ')'){
            if (s.size() == 1){
                length = 0;
                s.pop();
                s.push(i);
            }
            else{
                s.pop();
                length = i - s.top();
                if (length > mx){
                    mx = length;
                    cnt = 1;
                }
                else if (length == mx){
                    cnt++;
                }
            }
        }
        else s.push(i);
        //cout << i << " " << s.size() << " " << st[i] << " " << length << " " << cnt << " " << mx << " " << s.top() << "\n";
    }
    cout << mx << " " << cnt;
    //cout << endl;
    //cout << st.size();
    return 0;
}
