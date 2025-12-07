#include <bits/stdc++.h>

using namespace std;
int n;
float l,w;
//stringstream ss;
string s,st;
float x,r;
//float sx;
float ran;

int main()
{
    freopen("TUOICAY.INP","r",stdin);
    freopen("TUOICAY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(17);
    //sx = 1;
    //cout << sqrt(8.75);
    //cout << sx << endl;
    //getline(cin,s);
    //cout << s << endl;
    while (getline(cin,s) && s!=""){
        stringstream ss;
        ss << s;
        ss >> n >> l >> w;
        //ss.str("");
        //cout << s << endl;
        //cout << n<< " " << l << " "<< w << endl;
        pair<float,float> a[n];
        for (int i =0; i<n; i++){
            cin >> x >> r;
            //getline(cin,st);
            //cout << st << endl;
            //ss << st;
            //ss >> x >> r;
            //ss.str("");
            //ran = sqrtf((r*r) - (w/2*w/2));
            a[i].first = x-sqrtf((r*r) - (w/2*w/2));
            a[i].second = x+sqrtf((r*r) - (w/2*w/2));
            //cout << a[i].first << " " << a[i].second   << " "<< sqrt(r*r - w/2*w/2) << " "<< endl;
        }

        sort(a,a+n);

        float dist = 0;
        float range = 0;
        int i = 0;
        int c=0;
        while (i<n && dist < l && a[i].first <=dist){
            c++;
            while (i<n && a[i].first <=dist){
                if (a[i].second > range){
                    range = a[i].second;
                }
                i++;
                //cout << "woof";
            }
            dist = range;
            //cout << "meow";
        }

        if (range < l) cout << -1 << endl;
        else cout << c << endl;
        cin.ignore( 1000000, '\n' );
        //ss.str("");
        //getline(cin,s);
        //cout << s << endl;
    }
    return 0;
}
