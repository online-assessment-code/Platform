Result findCommonElements(int input1[], int input2[], int input3[], int input4, int input5, int input6){
    map<int, int> m1, m2, m3;
    for(int i = 0; i < input4; i++)
        m1[input1[i]] += 1;
    for(int i = 0; i < input5; i++)
        m2[input2[i]] += 1;
    for(int i = 0; i < input6; i++)
        m3[input3[i]] += 1;
    Result ans;
    int k = 0;
    for(auto it: m1){
        int num = it.first;
        if(m1[num] > 0 && m2[num] > 0 && m3[num] > 0)
            ans.output1[k++] = num;
    }
    return ans;
}
