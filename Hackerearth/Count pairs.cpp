#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> freq, dCount;
long long solve(vector<int> A, int X){
    int N = A.size();
    freq = vector<int> (maxn);
    dCount = vector<int> (maxn);
    for(int i = 0; i < N; i++) {
		A[i] = __gcd(A[i], X);
		freq[A[i]]++;
	}
	vector<int> divisors;
	for (int i = 1; i <= X; i++) {
		if (X % i == 0)
			divisors.push_back(i);
	}
	for (auto i : divisors) {
		int cnt = 0;
		for (int j = i; j < maxn; j += i)
			cnt += freq[j];
		dCount[i] = cnt;
	}
	long long res = 0;
	for (int i = 0; i < N; ++i) {
		int _X = X / A[i];
		res += dCount[_X];
		if (A[i] % _X == 0)
            --res;
	}
	res /= 2;
	return res;
}
long long count_pairs(int N, vector<int> A, int X){
    map<int, vector<int> > m1;
    for(int i = 0; i < N; i++)
        m1[A[i]].push_back(i + 1);
    int ans = 0;
    for(auto it: m1)
        ans += solve(it.second, X);
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, i, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(i = 0; i < n; i++)
            cin >> arr[i];
        cout << count_pairs(n, arr, k) << endl;
    }
    return 0;
}
