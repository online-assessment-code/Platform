void closestNumbers(vector<int> numbers){
    long
    sort(numbers.begin(), numbers.end());
    int n = numbers.size(), low = INT_MAX;
    for(int i = 1; i < n; i++)
        low = min(low, numbers[i] - numbers[i - 1]);
    for(int i = 1; i < n; i++){
        if((numbers[i] - numbers[i - 1]) == low)
            cout << numbers[i - 1] << " " << numbers[i] << endl;
    }
}
