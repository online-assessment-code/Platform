long howManySwaps(vector<int> arr) {
    multiset<int> set1;
    set1.insert(arr[0]);
    int invcount = 0, n = arr.size();
    multiset<int>::iterator itset1;
    for (int i=1; i<n; i++){
        set1.insert(arr[i]);
        itset1 = set1.upper_bound(arr[i]);
        invcount += distance(itset1, set1.end());
    }
    return invcount;
}
