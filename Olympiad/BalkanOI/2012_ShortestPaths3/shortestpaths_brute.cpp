//Almost the same as the official solution but a bit easier to implement
//Basically, because n is so small we can just run a dfs when removing each path to split the tree into 2 parts
//instead of finding the "lucky parent" for each node

//created by Oleksandr Gorpynich
#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

struct con{
    ll from;
    ll des;
    ll w;
};
ll n, m, a, b;
ll k;

ll dist_to_a[2001];
ll dist_to_b[2001];
ll lucky[2001];
ll ord[2001];
ll par[2001];
ll used[2001];

vector<con> cons[2001];


vector<con> all_cons;
vector<ll> rems;

vector<ll> treecons[2001];

void dfs(ll cur, ll col, ll n1, ll n2){
    used[cur] = col;
    for (auto next: treecons[cur]){
        if (used[next] == -1){
            if ((next != n1 || cur != n2) && (next != n2 || cur != n1)){
                dfs(next, col, n1, n2);
            }
        }
    }
}

void gencons(ll cur){
    if (used[cur] == 2){
        return;
    }
    used[cur] = 2;
    if (par[cur] != -1){
        treecons[par[cur]].push_back(cur);
        treecons[cur].push_back(par[cur]);
        gencons(par[cur]);
    }
}

void djikstra(ll source, ll dist[]){
    for (ll x = 0; x < n; x++){
        dist[x] = 1e9;
    }
    dist[source] = 0;
    priority_queue<pair<ll, ll>> q;
    q.push({0, source});
    while (q.size() > 0){
        ll di = q.top().first * -1;
        ll cur = q.top().second;
        q.pop();
        if (di == dist[cur]){
            for (con next: cons[cur]){
                bool works = (dist[next.des] > dist[cur] + next.w);
                if (dist[next.des] == dist[cur] + next.w){
                    if (lucky[cur] == next.des && lucky[next.des] == cur){
                        works = true;
                    }
                }
                if (works){
                    dist[next.des] = dist[cur] + next.w;
                    q.push({dist[next.des] * -1, next.des});
                    par[next.des] = cur;
                }
            }
        }
    }
}
int main(){
    freopen("shortestpaths.inp","r",stdin);
    freopen("shortestpaths.ans","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> a >> b;
    a -= 1;
    b -= 1;
    ll one, two, three;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three;
        cons[one - 1].push_back({one - 1, two - 1, three});
        cons[two - 1].push_back({two - 1, one - 1, three});
        all_cons.push_back({one - 1, two - 1, three});
    }
    cin >> k;
    ll temp;
    for (int x = 0; x < k; x++){
        cin >> temp;
        temp -= 1;
        rems.push_back(temp);
    }
    for (int x = 0; x < n; x++){
        lucky[x] = -1;
        ord[x] = -1;
        par[x] = -1;
        used[x] = 1;
    }
    for (int x = 0; x < k - 1; x++){
        lucky[rems[x]] = rems[x + 1];
        ord[rems[x]] = x;
    }

    djikstra(b, dist_to_b);
    for (int x = 0; x < n; x++){
        par[x] = -1;
    }
    djikstra(a, dist_to_a);

    for (int x = 0; x < n; x++){
        if (used[x] == 1){
            gencons(x);
        }
    }
    for (int x = 0; x < k - 1; x++){
        for (int y = 0; y < n; y++){
            used[y] = -1;
        }
        dfs(a, a, rems[x], rems[x + 1]);
        dfs(b, b, rems[x], rems[x + 1]);
        ll answer = 1e9;
        for (int y = 0; y < all_cons.size(); y++){
            ll one = all_cons[y].from;
            ll two = all_cons[y].des;
            if ((one != rems[x] || two != rems[x + 1]) && (two != rems[x] || one != rems[x + 1])){
                if (used[one] == b && used[two] == a){
                    answer = min(answer, dist_to_b[one] + dist_to_a[two] + all_cons[y].w);
                }
                else if (used[two] == b && used[one] == a){
                    answer = min(answer, dist_to_b[two] + dist_to_a[one] + all_cons[y].w);
                }
            }
        }
        cout << ((answer == 1e9) ? -1 : answer) << "\n";
    }
}
