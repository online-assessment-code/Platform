int maxShared(int n, vector<int> from, vector<int> to, vector<int> w){
    int m = from.size();
    int ans = INT_MIN, res = INT_MIN;
    map<int, map<int, int> > m1;
    for(int i = 0; i < m; i++){
        int small = min(from[i], to[i]);
        int high = max(from[i], to[i]);
        m1[small][high] += 1;
        res = max(res, m1[small][high]);
    }
    for(auto it1: m1){
        for(auto it2: it1.second){
            if(it2.second == res)
                ans = max(ans, it1.first * it2.first);
        }
    }
    return ans;
}
