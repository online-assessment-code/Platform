#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b = "abcdefghijklmnopqrstuvwxyz";
        cin >> a;
        int n1 = a.length(), n2 = 26;
        int dp[n1 + 5][n2 + 5];
        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n2; j++)
                dp[i][j] = 0;
        }
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << (26 - dp[n1][n2]) << endl;
    }
    return 0;
}
