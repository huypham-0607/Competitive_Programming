typedef long long ll;
ll pie(ll army){return (1ll<<army);}
//#include "circus.h"
#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define endl '\n'
#define mid ((left+right)>>1)
const ll inf=2000000000000000005;
const int sonsuz=2000000005;
using namespace std;
ll fpow(ll x,ll y,ll m=0){if(y<0){cout<<"powError";return -1;}if(m)x%=m;ll res=1;while(y>0){if(y&1)res*=x;x*=x;if(m){x%=m;res%=m;}y>>=1;}return res;}

struct Seg{
	int n;
	vector<int>arr,tree,lazy,razy,mn,mx;
	void build(int node=1,int left=0,int right=-1){
		if(right==-1)right=n-1;
		tree[node]=sonsuz;
		lazy[node]=-sonsuz;
		razy[node]=sonsuz;
		mn[node]=arr[left];
		mx[node]=arr[right];
		if(left==right)return;
		build(node*2,left,mid);
		build(node*2+1,mid+1,right);
	}
	void init(vector<int> Arr){
		arr=Arr;
		n=arr.size();
		tree.resize(n<<2);
		lazy.resize(n<<2);
		razy.resize(n<<2);
		mn.resize(n<<2);
		mx.resize(n<<2);
		build();
	}
	void push(int node,int left,int right){
		if(lazy[node]!=-sonsuz){
			tree[node]=min(tree[node],mn[node]-lazy[node]);
			if(left!=right){
				lazy[node*2]=max(lazy[node],lazy[node*2]);
				lazy[node*2+1]=max(lazy[node],lazy[node*2+1]);
			}
			lazy[node]=-sonsuz;
		}
		if(razy[node]!=sonsuz){
			tree[node]=min(tree[node],razy[node]-mx[node]);
			if(left!=right){
				razy[node*2]=min(razy[node],razy[node*2]);
				razy[node*2+1]=min(razy[node],razy[node*2+1]);
			}
			razy[node]=sonsuz;
		}
	}
	void comb(int node,int left,int right){
		if(mn[node*2]==-23){
			tree[node]=tree[node*2+1];
			mn[node]=mn[node*2+1];
			mx[node]=mx[node*2+1];
		}
		else if(mn[node*2+1]==-23){
			tree[node]=tree[node*2];
			mn[node]=mn[node*2];
			mx[node]=mx[node*2];
		}
		else{
			tree[node]=min(tree[node*2],tree[node*2+1]);
			mn[node]=min(mn[node*2],mn[node*2+1]);
			mx[node]=max(mx[node*2],mx[node*2+1]);
		}
	}
	int l,r,tip,x;
	void up(int node=1,int left=0,int right=-1){
		if(right==-1)right=n-1;
		if(left>=l&&right<=r){
			if(tip){
				razy[node]=min(razy[node],x);
			}
			else{
				lazy[node]=max(lazy[node],x);
			}
			push(node,left,right);
			return;
		}
		push(node,left,right);
		if(left>r||right<l)return;
		up(node*2,left,mid);
		up(node*2+1,mid+1,right);
		comb(node,left,right);
	}
	void update(int lef,int rig,int val,int tp){
		l=lef;
		r=rig;
		x=val;
		tip=tp;
		up();
	}
	void dal(int node=1,int left=0,int right=-1){
		if(right==-1)right=n-1;
		push(node,left,right);
		if(left==right){
			arr[left]=-23;
			mn[node]=-23;
			return;
		}
		if(l>mid)dal(node*2+1,mid+1,right);
		else dal(node*2,left,mid);
		comb(node,left,right);
	}
	void sil(int tar){
		l=tar;
		dal();
	}
	int walk(int node=1,int left=0,int right=-1){
		if(right==-1)right=n-1;
		push(node,left,right);
		if(left==right){
			return left;
		}
		push(node*2,left,mid);
		push(node*2+1,mid+1,right);
		if((mn[node*2+1]!=-23&&tree[node*2+1]==tree[node])||mn[node*2]==-23){
			return walk(node*2+1,mid+1,right);
		}
		else{
			return walk(node*2,left,mid);
		}
	}
};

int n;
int arr[100001],need[100001],mn[400005],mx[400005];
Seg seg;

void build(int node=1,int left=0,int right=-1){
	if(right==-1)right=n-1;
	if(left==right){
		mn[node]=arr[left]+need[left];
		mx[node]=arr[left]-need[left];
		return;
	}
	build(node*2,left,mid);
	build(node*2+1,mid+1,right);
	mx[node]=max(mx[node*2],mx[node*2+1]);
	mn[node]=min(mn[node*2],mn[node*2+1]);
}

int mxwalk(int k,int node=1,int left=0,int right=-1){
	if(right==-1)right=n-1;
	if(left==right)return arr[left]-k;
	if(mx[node*2]>=k)return mxwalk(k,node*2,left,mid);
	return mxwalk(k,node*2+1,mid+1,right);
}

int mnwalk(int k,int node=1,int left=0,int right=-1){
	if(right==-1)right=n-1;
	if(mn[node]>k)return sonsuz;
	if(left==right)return k-arr[left];
	if(mn[node*2+1]<=k)return mnwalk(k,node*2+1,mid+1,right);
	return mnwalk(k,node*2,left,mid);
}

void init(int N,int M,int P[]){
	n=N+1;
	for(int i=0;i<N;i++){
		arr[i]=P[i];
	}
	sort(arr,arr+N);
	arr[n-1]=M;

	vector<int>temp;
	for(int i=0;i<N;i++)
		temp.pb(arr[i]);
	seg.init(temp);
	seg.update(0,N-1,M,1);
	for(int i=0;i<N;i++){
		int pos=seg.walk();
		need[pos]=seg.tree[1];
		seg.sil(pos);
		int l=-1,r=pos-1;
		while(l<r){
			int mi=(l+r+1)/2;
			if(arr[pos]-arr[mi]>=need[pos])l=mi;
			else r=mi-1;
		}
		if(l!=-1){
			seg.update(0,l,arr[pos],1);
		}
		l=pos+1;r=N;
		while(l<r){
			int mi=(l+r)/2;
			if(arr[mi]-arr[pos]>=need[pos])r=mi;
			else l=mi+1;
		}
		if(l!=N){
			seg.update(l,N-1,arr[pos],0);
		}
	}

	build();
}

int minLength(int D){
	return min(mnwalk(D),mxwalk(D));
}

int _n,_m;
int _p[100001];
int _q;

void Solve(){
    cin >> _n >> _m;
    for (int i=0; i<_n; i++){
        cin >> _p[i];
    }
    init(_n,_m,_p);
    cin >> _q;
    for (int i=1; i<=_q; i++){
        int x; cin >> x;
        cout << minLength(x) << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen("circus.inp","r",stdin);
    freopen("circus.ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solve();

    return 0;
}
