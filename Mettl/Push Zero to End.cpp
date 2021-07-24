#include<bits/stdc++.h>
using namespace std;
struct Result pushZeroesEnd(int input1[], int input2){
    Result* ans = new Result();
    int k = 0, count = 0;
    for(int i = 0; i < input2; i++){
        if(input1[i] == 0)
            count += 1;
        else
            ans->output1[k++] = input1[i];
    }
    while(count--)
        ans->output1[k++] = 0;
    return *ans;
};
