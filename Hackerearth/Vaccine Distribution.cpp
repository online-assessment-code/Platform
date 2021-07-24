#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
int main() { 
    ll n,m,t, temp; 
    cin>>t; 
    while(t--) { 
        temp = 0; 
        cin>>n>>m; 
        vector<ll> a(m); 
        for(ll i = 0; i < m; i++) { 
            cin>>a[i]; 
            temp = max(temp, a[i]); 
        } 
        ll ans = INT_MAX; 
        ll l = 1, h = temp; 
        while(l <= h) { 
            ll curr = n; 
            ll mid = (l + h) / 2; 
            for(ll i = 0; i < m; i++) { 
                ll x = ceil(float(a[i]) / float(mid)); 
                curr -= x; 
            } 
            if(curr >= 0) { 
                ans = min(ans, mid); 
                h = mid - 1; 
            } 
            else { 
                l = mid + 1; 
            } 
        } 
        cout<<ans<<"\n"; 
    } 
    return 0; 
}
