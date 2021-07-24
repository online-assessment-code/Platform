Result validateNumberSequence(int input1[]){
    int n, i = 0;
    while(i >= 0){
        if(input1[i] == 0)
            break;
        i += 1;
    }
    n = i;
    map<int, int> m1;
    for(int i = 0; i < n; i++){
        m1[input1[i]] += 1;
    }
    Result *ans = new Result();
    int k = 0;
    for(int i = 20; i <= 30; i++){
        if(m1[i] == 0)
            ans->output1[k++] = i;
    }
    return *ans;
}
