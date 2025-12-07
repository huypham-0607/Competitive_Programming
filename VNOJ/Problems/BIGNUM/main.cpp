#include <bits/stdc++.h>

using namespace std;

string a,b;

int so(char x){
    return x-'0';
}

char chu(int x){
    return char(x+'0');
}

string add(string a, string b){
    int mem=0,x=0;
    if (a.size() < b.size()) swap(a,b);
    while (b.size() < a.size()) b = "0"+b;
    for (int i=b.size()-1; i>=0; i--){
        //cout << i << endl;
        x = so(a[i]) + so(b[i]) + mem;
        a[i] = chu(x%10);
        mem = x/10;
    }
    if (mem) a = "1" + a;
    while (!so(a[0])) a = a.substr(1,a.size()-1);
    if (a=="") a="0";
    return a;
}

string sub(string a, string b){
    int mem=0,x=0;
    bool neg = false;
    while (b.size() < a.size()) {
            b = "0"+b;
            //cout << "meow" << endl;
    }
    while (a.size() < b.size()) {
            a = "0"+a;
            //cout << "woof" << endl;
    }
    if (a<b){
        neg = true;
        swap(a,b);
    }

    for (int i=b.size()-1; i>=0; i--){
        //cout << i << endl;
        x = so(a[i]) - so(b[i]) - mem;
        if (x<0){
            mem=1;
            x+=10;
        }
        else mem=0;
        a[i] = chu(x%10);
    }
    while (!so(a[0])) a = a.substr(1,a.size()-1);
    if (a=="") a="0";
    if (neg) a = "-" + a;
    return a;
}

string simmul(string a, string b){
    string ans="";
    string temp="";
    for (unsigned long long i=0; i<a.size()+b.size(); i++){
        ans = "0" + ans;
    }

    for (int j=b.size()-1; j>=0; j--){
        int x=0,mem=0;
        string c=temp;
        for (int i=a.size()-1; i>=0; i--){
            x=so(a[i])*so(b[j])+mem;
            c = chu(x%10) + c;
            mem = x/10;
            //cout << i << " " << j << " " << c << endl;
        }
        if (mem) c = chu(mem) + c;
        ans = add(ans,c);
        temp = "0" + temp;
    }
    //if (mem) ans = chu(mem) + ans;
    while (!so(ans[0])) ans = ans.substr(1,ans.size()-1);
    if (ans=="") ans="0";
    return ans;

}

string karatsuba(string a, string b){
    if (a.size() < b.size()) swap(a,b);
    while (b.size() < a.size()) b = "0"+b;
    int base = a.size()/2;
    string
        x0 = a.substr(a.size()-base,base),
        x1 = a.substr(0,a.size()-base),
        y0 = b.substr(b.size()-base,base),
        y1 = b.substr(0,b.size()-base);
    string
        z0 = simmul(x0,y0),
        z2 = simmul(x1,y1);
    string z1 = sub(sub(simmul(add(x1,x0),add(y1,y0)),z2),z0);
    for (int i=0; i<base; i++){
        z2+="0";
        z1+="0";
    }
    for (int i=0; i<base; i++){
        z2+="0";
    }
    return add(add(z2,z1),z0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    cout << add(a,b) << endl;
    cout << sub(a,b) << endl;
    //cout << simmul(a,b) << endl;
    cout << karatsuba(a,b) << endl;

    return 0;
}
