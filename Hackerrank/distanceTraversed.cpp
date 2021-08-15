int X[4] = {1,0,-1,0};
int Y[4] = {0,-1,0,1};
bool isValid(int x, int y, int n, int m){
    if(x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return true;
}
int distanceTraversed(vector<vector<int> > &lot){
    int n = lot.size(), m = lot[0].size();
    queue<pair<int, int> > q;
    bool ok = true;
    int xx = -1, yy = -1;
    map<int, map<int, int> > m1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            m1[i][j] = INT_MAX;
            if(lot[i][j] == 9){
                xx = i;
                yy = j;
            }
        }
    }
    if(xx == -1 && yy == -1)
        return -1;
    if(lot[0][0] == 1){
        q.push({0,0});
        m1[0][0] = 0;
    }
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int new_x = temp.first + X[i];
            int new_y = temp.second + Y[i];
            if(isValid(new_x, new_y, n, m) && (lot[new_x][new_y] == 1 || lot[new_x][new_y] == 9)){
                if(m1[new_x][new_y] > 1 + m1[temp.first][temp.second]){
                    m1[new_x][new_y] = 1 + m1[temp.first][temp.second];
                    q.push({new_x, new_y});
                }
            }
        }
    }
    if(m1[xx][yy] == INT_MAX)
        return -1;
    return m1[xx][yy];
}
