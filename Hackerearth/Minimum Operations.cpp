#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		ll n = str.length(), i;
		string a, b;
		for(i = 0; i < n; i++){
			if(i&1)
				a += str[i];
			else
				b += str[i];
		}
		ll temp = stoll(a, nullptr, 10);
		ll flag = stoll(b, nullptr, 10);
		cout << temp + flag << endl;
	}
	return 0;
}
