#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nax = 1e6 + 5;
const int pot = 256 * 1024;
const ll INF = 3e18L;
ll cur_power[nax]; // the least power of 42 larger than the current value
// true_value + remaining = cur_power,  where remaining=tr[pot+i]

struct Node {
	ll local;
	ll lazy;
	ll smallest() { return local + lazy; } // smallest value in this subtree
} tr[2*pot];

void propagate(int i) {
	assert(i < pot);
	tr[2*i].lazy += tr[i].lazy;
	tr[2*i+1].lazy += tr[i].lazy;
	tr[i].local += tr[i].lazy;
	tr[i].lazy = 0;
}
void act(int i) {
	assert(i < pot);
	assert(tr[i].lazy == 0);
	tr[i].local = min(tr[2*i].smallest(), tr[2*i+1].smallest());
}

void change(int i, int low, int high, int q_low, int q_high, ll val) {
	if(q_low <= low && high <= q_high) {
		tr[i].lazy += val;
		return;
	}
	propagate(i);
	int mid1 = (low + high) / 2;
	if(q_low <= mid1)
		change(2*i, low, mid1, q_low, q_high, val);
	if(q_high >= mid1+1)
		change(2*i+1, mid1+1, high, q_low, q_high, val);
	act(i);
}
void change(int q_low, int q_high, ll val) {
	change(1, 0, pot - 1, q_low, q_high, val);
}

int where_smallest(int i = 1) {
	if(i >= pot) return i - pot;
	propagate(i);
	int ret;
	if(tr[2*i].smallest() < tr[2*i+1].smallest())
		ret = where_smallest(2*i);
	else
		ret = where_smallest(2*i+1);
	act(i);
	return ret;
}

ll move_power(int i, ll rem) {
	assert(rem <= 0);
	while(rem < 0) {
		ll cur_value = cur_power[i] - rem;
		cur_power[i] *= 42;
		rem = cur_power[i] - cur_value;
	}
	return rem;
}

set<int> interesting; // the set of indices i that t[i] != t[i+1] (and maybe few others)
// all other indices have value INF in the tree

ll get_value(int i) {
	assert(interesting.count(i));
	vector<int> w;
	for(int x = (pot + i) / 2; x >= 1; x /= 2)
		w.push_back(x);
	reverse(w.begin(), w.end());
	for(int x : w) propagate(x); // top-down
	return tr[pot+i].smallest();
}

const int SET_TYPE = 10042;
const int INC_TYPE = 10043;
void set_or_inc(int i, ll val, const int type) {
	vector<int> w;
	for(int x = (pot + i) / 2; x >= 1; x /= 2)
		w.push_back(x);
	reverse(w.begin(), w.end());
	for(int x : w) propagate(x); // top-down
	if(type == SET_TYPE) {
		tr[pot+i].lazy = 0;
		tr[pot+i].local = val;
	}
	else if(type == INC_TYPE) {
		tr[pot+i].local += val;
	}
	else assert(false);
	reverse(w.begin(), w.end());
	for(int x : w) act(x); // bottom-up
}

void re_insert(int i) {
	int j = *interesting.lower_bound(i);
	if(i == j) return;
	cur_power[i] = cur_power[j];
	set_or_inc(i, get_value(j), SET_TYPE);
	interesting.insert(i);
}

void init_value(int i, int val) {
	cur_power[i] = 1;
	ll how_much_remains = 1 - val; // how much remains to cur_power[i]
	ll rem = move_power(i, how_much_remains);
	set_or_inc(i, rem, SET_TYPE);
}

int main() {
    if (fopen("679E.inp","r")){
        freopen("679E.inp","r",stdin);
        freopen("679E.ans","w",stdout);
    }
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < 2 * pot; ++i)
		tr[i].local = INF;
	for(int i = 1; i <= n; ++i) {
		interesting.insert(i); // we don't mind that maybe t[i] = t[i+1]
		int val;
		scanf("%d", &val);
		init_value(i, val);
	}
	// queries
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 1) { // print value
			int i;
			scanf("%d", &i);
			i = *interesting.lower_bound(i);
			printf("%lld", cur_power[i] - get_value(i));
            cout << "\n";
		}
		else if(type == 2) { // set interval to x
			int low, high, val;
			scanf("%d%d%d", &low, &high, &val);
			// t[low] = t[low+1] = ... = t[high-1] = INF
			// t[high] = val
			if(low - 1 >= 1)
				re_insert(low - 1);
			interesting.insert(high);
			init_value(high, val);
			while(true) {
				auto it = interesting.lower_bound(low);
				assert(it != interesting.end());
				int i = *it;
				assert(i <= high);
				if(i == high) break; // we only want [low, high-1]
				interesting.erase(it);
				set_or_inc(i, INF, SET_TYPE);
			}
		}
		else { // increase by x
			assert(type == 3);
			int low, high, val;
			scanf("%d%d%d", &low, &high, &val);
			if(low - 1 >= 1)
				re_insert(low - 1);
			re_insert(high);
			bool ok = false;
			while(!ok) {
				ok = true;
				change(low, high, -val);
				while(true) {
					int i = where_smallest();
					ll rem = tr[pot+i].smallest();
					assert(1 <= i && i <= n);
					if(rem > 0) break;
					if(rem == 0) {
						ok = false;
						break;
					}
					ll new_rem = move_power(i, rem);
					set_or_inc(i, new_rem, SET_TYPE);
				}
			}
		}
	}
	return 0;
}