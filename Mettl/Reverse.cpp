#include<bits/stdc++.h>
using namespace std;
Result reverse(int input1[], int input2){
    Result ans;
    for(int i = 0; i < input2; i++)
        ans.output1[i] = input1[i];
    reverse(ans.output1, ans.output1 + input2);
    return ans;
}
