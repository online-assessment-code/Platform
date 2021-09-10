#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 998244353;
ll n,m,cnt=0;
vector<vector<ll> > adj;
vector<bool> visited;
ll modinv(ll a, ll m){
    assert(m > 0);
    if(m == 1)
        return 0;
    a %= m;
    if(a < 0)
        a += m;
    assert(a != 0);
    if(a == 1)
        return 1;
    return m - modinv(m, a) * m / a;
}
ll mulmod(ll a, ll b, ll mod){
    ll res = 0;
    a %= mod;
    while(b > 0){
        if(b & 1)
            res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return (res % mod);
}
void dfs(ll i){
    if(!visited[i]){
        visited[i] = true;
        cnt += 1;
        for(auto it: adj[i])
            dfs(it);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll x,y,i;
        cin>>n>>m;
        vector<ll> arr(n);
        visited = vector<bool> (n, false);
        adj = vector<vector<ll> > (n);
        for(i = 0; i < m; i++){
            cin >> x >> y;
            x -= 1;
            y -= 1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        vector<ll> a;
        for(i = 0; i < n; i++){
            if(!visited[i]){
                cnt = 0;
                dfs(i);
                a.push_back(cnt);
            }
        }
        ll curr = 0, ans = 0;
        sort(a.rbegin(), a.rend());
        for(i = 0; i < a.size(); i++){
            ll sum = 0;
            while(a[i]--){
                sum = (sum % mod + arr[curr]%mod)%mod;
                curr += 1;
            }
            sum = mulmod(sum, sum - 1, mod);
            sum = mulmod(sum, modinv(2, mod), mod);
            ans = (ans % mod + sum % mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}

