vector<string> split(string str,char delimeter){
    stringstream ss(str);
    string s;
    vector<string> out;
    while(getline(ss,s,delimeter)){
        if(s.length()!=0)
            out.push_back(s);
    }
    return out;
}
vector<string> sortBoxes(vector<string> boxList){
    int n = boxList.size();
    vector<pair<string, string> > older;
    vector<string> newer;
    for(int i = 0; i < n; i++){
        vector<string> temp = split(boxList[i],' ');
        string identifier = temp[0];
        string curr;
        bool ok = true;
        for(int j = 1; j < temp.size(); j++){
            if(temp[j][0] >= 'a' && temp[j][0] <= 'z')
                ok = false;
            curr += temp[j];
            curr += ' ';
        }
        if(ok){
            identifier += ' ';
            identifier += curr;
            newer.push_back(identifier);
        }
        else{
            older.push_back({curr, identifier});
        }
    }
    sort(older.begin(),older.end());
    vector<string> ans;
    for(auto it: older){
        string flag = it.second;
        flag += ' ';
        flag += it.first;
        ans.push_back(flag);
    }
    for(auto it: newer)
        ans.push_back(it);
    return ans;
}
