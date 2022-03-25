#include <bits/stdc++.h>
using namespace std;
const int N = 15;
// Authors
// 1- 3rbi
// 2- Desouky

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int memo[N][N];
bool vis[N][N];
queue<pair<int , int>> ans;
bool visBuild[N][N];
int bestGrid[N][N];
char grid[N][N];

bool valid(int i , int j) {
    return i >= 0 and j >= 0 and i < 15 and j < 15 and grid[i][j] == '.' and !vis[i][j];
}

int longestPath(int row , int col) {
    if(!valid(row , col))return 0;
    int &ret = memo[row][col];
    if(~ret)return ret;
    ret = 1;
    int mx = -(1e5);
    vis[row][col] = true;
    for(int x = 0; x<4; x++) {
        mx = max(mx, longestPath(row + dx[x], col + dy[x]));
    }
    vis[row][col] = false;
    return ret += mx;
}

void buildPathVersionTwo(int row, int col) {
    if(!valid(row , col))return;
    if(visBuild[row][col])return ;
    visBuild[row][col] = true;
    ans.push({row, col});
    int mx = 0;
    for(int x = 0; x<4; x++){
        if(valid(row+dx[x] , col+dy[x]) and !visBuild[row+dx[x]][col+dy[x]]){
            mx = max(mx, bestGrid[row+dx[x]][col+dy[x]]);
        }
    }

    for(int x = 0; x<4; x++){
        if(mx == bestGrid[row+dx[x]][col+dy[x]]){
            buildPathVersionTwo(row+dx[x] , col+dy[x]);
            break;
        }
    }
}

queue<pair<int , int>> surface(int row , int col){
    memset(memo, -1, sizeof memo);
    memset(visBuild, false, sizeof visBuild);
    memset(vis, false, sizeof vis);
    int best = longestPath(row , col);
    for(int i = 0; i<15; i++){
        for(int j = 0; j<15; j++){
            bestGrid[i][j] = memo[i][j];
        }
    }
    while (!ans.empty()) ans.pop();
    buildPathVersionTwo(row, col);
    return ans;
}

int main()
{
    int width;
    int height;
    int my_id;
    cin >> width >> height >> my_id; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        for(int j = 0;j < height;j++) {
            grid[i][j] = line[j];
        }
    }
    int longest = 0;
    int startRow{0}, startCol (0);
    for(int x = 0; x<15; x++){
        for(int y=0; y<15; y++){
            if(grid[x][y] == 'x')continue;
            memset(memo , -1 , sizeof  memo);
            memset(vis, false, sizeof vis);
            int ret = longestPath(x , y);
            if(ret > longest) {
                for(int i = 0; i<15; i++){
                    for(int j = 0; j<15; j++){
                        bestGrid[i][j] = memo[i][j];
                    }
                }
                longest = ret;
                startCol = y;
                startRow = x;
            }
        }
    }

    buildPathVersionTwo(startRow , startCol);
    cout << startCol << ' ' <<  startRow << endl;
    cerr<< ans.size()<<"size";
    ans.pop();
    while (1) {
        int x;
        int y;
        int my_life;
        int opp_life;
        int torpedo_cooldown;
        int sonar_cooldown;
        int silence_cooldown;
        int mine_cooldown;
        cin >> x >> y >> my_life >> opp_life >> torpedo_cooldown >> sonar_cooldown >> silence_cooldown >> mine_cooldown; cin.ignore();
        string sonar_result;
        cin >> sonar_result; cin.ignore();
        string opponent_orders;
        getline(cin, opponent_orders);
        swap(x, y);
        if(ans.empty()) {
            cout << "SURFACE\n";
            ans = surface(x , y);
            ans.pop();
            continue;
        }
        int row = ans.front().first;
        int col = ans.front().second;
        ans.pop();
        if(row == x and col == y+1)cout<<"MOVE E";
        else if(row == x and col == y-1)cout<<"MOVE W";
        else if(row == x-1 and col == y)cout<<"MOVE N";
        else cout<<"MOVE S";
        cout<<"\n";
    }
}
