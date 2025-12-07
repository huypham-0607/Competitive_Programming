#include <iostream>
#include <queue>

using namespace std;

/*Global Variables*/
int n;
queue<int> q;

/*Solution*/
int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        q.push(x);
    }

    int i = 0;
    while (q.size()>1){
        ++i;
        if (i%3 == 0) q.push(q.front());
        q.pop();
    }
    cout << q.front();

    return 0;
}
