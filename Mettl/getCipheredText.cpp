void leftrotate(string &s, int d){
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}
void rightrotate(string &s, int d){
   leftrotate(s, s.length()-d);
}
char* getCipheredText(int input1, char* input2, char* input3){
    string dir(input2), str(input3);
    if(dir == "left")
        leftrotate(str, input1);
    else
        rightrotate(str, input1);
    char *ans = new char;
    strcpy(ans, str.c_str());
    return ans;
}
