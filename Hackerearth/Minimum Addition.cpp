#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> arr){
    int n = arr.size(), i, ans;
    multiset<int> s;
    multiset<int>::iterator it;
    for(i = 0; i < n; i++){
        s.insert(arr[i]);
        it = s.upper_bound(arr[i]);
        if(it != s.end())
            s.erase(it);
    }
    return s.size();
}
int minOperations (int n, vector<int> arr, int k) {
    int ans = 0, i, j;
    for(i = 0; i < k; i++){
        vector<int> temp;
        for(j = i; j < n; j += k)
            temp.push_back(arr[j]);
        int m = temp.size();
        ans += (m - lis(temp));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, i;
        cin >> n;
        vector<int> arr(n);
        for(i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << minOperations(n, arr, k) << endl;
    }
    return 0;
}
