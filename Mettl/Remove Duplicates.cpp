#include<bits/stdc++.h>
using namespace std;
char* removeDuplicates(char* input1){
    map<char, int> m1;
    string ans;
    int n = strlen(input1);
    for(int i = 0; i < n; i++){
        if(m1.find(input1[i]) == m1.end())
            ans += input1[i];
        m1[input1[i]] = 1;
    }
    int len = ans.length();
    char *res = new char;
    strcpy(res, ans.c_str());
    return res;
}
