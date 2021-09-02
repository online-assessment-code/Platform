#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,m,k,a,b,tot;
vector<vector<ll> > dp;
vector<vector<ll> > adj;
vector<bool> visited;
vector<pair<ll,ll> > arr;
vector<ll> skill, cost;
void dfs(ll i, ll par){
    if(!visited[i]){
        visited[i] = true;
        a += arr[i].first;
        b += arr[i].second;
        for(auto it: adj[i]){
            if(it != par)
                dfs(it, i);
        }
    }
}
ll go(ll index, ll curr) {
    if(index == tot)
        return 0;
    if(curr > k)
        return 0;
    if(dp[index][curr] != -1)
        return dp[index][curr];
    ll ans1 = 0, ans2 = 0;
    ans1 = go(index + 1, curr);
    if((curr + cost[index]) <= k)
        ans2 = skill[index] + go(index + 1, curr + cost[index]);
    return dp[index][curr] = max(ans1, ans2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll x, y, i, flag;
    cin >> n >> flag;
    visited = vector<bool> (n);
    adj = vector<vector<ll> > (n);
    arr = vector<pair<ll,ll> > (n);
    for(i = 0; i < n; i++){
        cin >> x >> y;
        arr[i].first = x;
        arr[i].second = y;
    }
    cin >> m >> flag;
    for(i = 0; i < m; i++){
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> k;
    dp = vector<vector<ll> > (n + 5, vector<ll> (k + 5, -1));
    for(i = 0; i < n; i++){
        a = 0; b = 0;
        if(!visited[i]){
            dfs(i, i);
            skill.push_back(a);
            cost.push_back(b);
        }
    }
    tot = skill.size();
    cout << go(0, 0) << endl;
    return 0;
}
/*
8 2
3 47
6 13
4 47
7 39
8 24
7 23
7 35
4 50
3 2
5 7
6 8
5 6
240
answer = 43
*/

/*
4 2
12 7
9 5
13 8
15 11
2 2
1 3
2 4
17
answer = 25
*/
