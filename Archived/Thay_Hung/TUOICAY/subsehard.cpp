#include<bits/stdc++.h>
using namespace std;
int pre[1000010];
int a[1000010];
int main(){
    int t;
    cin>>t;
    while (t--){
          int n;
          cin>>n;
          for (int i=1;i<=n;i++) cin>>a[i];
          memset(pre,0,sizeof(pre));
          for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
          map<int,int> mp;
          mp[0]=1;
          int ans=0;
          for (int i=1;i<=n;i++){
               ans+=mp[pre[i]-47];
               mp[pre[i]]++;
          }
          cout<<ans<<endl;
    }
}
