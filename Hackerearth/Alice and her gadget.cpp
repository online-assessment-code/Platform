#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n, i, j, ans = 0;
        cin >> n;
        string str;
        cin >> str;
        vector<vector<ll> > arr{
            {1,1,1,1,1,1,0},
            {0,1,1,0,0,0,0},
            {1,1,0,1,1,0,1},
            {1,1,1,1,0,0,1},
            {0,1,1,0,0,1,1},
            {1,0,1,1,0,1,1},
            {0,0,1,1,1,1,1},
            {1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1},
            {1,1,1,0,0,1,1}
        };
        vector<ll> a(7, 0);
        for(i = 0; i < n; i++){
            ll num = str[i] - '0';
            for(j = 0; j < 7; j++){
                if(arr[num][j] == 1){
                    if(a[j] == 0){
                        a[j] = 1;
                        ans += 1;
                    }
                }
                else{
                    if(a[j] == 1){
                        a[j] = 0;
                        ans += 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}


