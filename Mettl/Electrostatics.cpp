#include<bits/stdc++.h>
using namespace std;
int findMaximum(int input1[], char* input2, int input3){
    int charge = 0;
    for(int i = 0; i < input3; i++){
        if(input2[i] == 'P')
            charge += input1[i];
        else
            charge -= input1[i];
    }
    return abs(charge * 100);
}

