#include <bits/stdc++.h>

using namespace std;

int maxsum = INT_MIN;
int l,r,m,n;
int rowsum[100],sum,a[100][100];

int kadane(int n){
    int sum=0,maxsum=INT_MIN,finish = -1;

    for(int i =0; i<n; i++){
        sum+=rowsum[i];

        if (sum<0){
            sum=0;
        }
        else if (sum > maxsum){
            maxsum = sum;
            finish = i;
        }
    }

    if (finish!=-1){
        return maxsum;
    }

    maxsum = rowsum[0];
    finish = 0;

    for (int i =1; i<n;i++){
        if (rowsum[i]>maxsum){
            maxsum = rowsum[i];
        }
    }
    return maxsum;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i =0; i<n; i++){
        for (int j =0; j<m; j++){
            cin >> a[i][j];
        }
    }

    for (l=0; l<m; l++){
        fill_n(rowsum,n,0);
        for (r=l; r<m; r++){
            //cout << l+1 << " " << r+1 << endl;
            for (int i =0; i<n; i++){
                rowsum[i]+=a[i][r];
                //cout << rowsum[i] << " ";
            }
            //cout << endl;
            sum = kadane(n);
            //cout << sum << endl << endl;
            if (sum > maxsum)
                maxsum = sum;
        }
    }
    cout << maxsum;

    return 0;
}
