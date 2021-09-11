int segment(int k, vector<int> arr){
	map<int, int> Map;
	int l = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		l++;
		Map[arr[i]]++;
		if (l == k) {
			auto itMax = Map.end();
			itMax--;
			auto itMin = Map.begin();
			ans.push_back(itMin->first);
			Map[arr[i - k + 1]]--;
			if (Map[arr[i - k + 1]] == 0) {
				Map.erase(arr[i - k + 1]);
			}
			l--;
		}
	}
	sort(ans.begin(), ans.end());
	return ans.back();
}
