#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
char grid[MAXN][MAXN];
int memo[20][20];
bool vis[15][15];

bool valid(int i , int j) {
    return i >= 0 and j >= 0 and i < 15 and j < 15 and grid[i][j] == '.' and !vis[i][j];
}

int longestPath(int row , int col) {
    if(!valid(row , col))return 0;
    int &ret = memo[row][col];
    if(~ret)return ret;
    ret = 1;
    vis[row][col] = true;
    int path1 = longestPath(row + 1, col);
    int path2 = longestPath(row, col + 1);
    int path3 = longestPath(row - 1, col);
    int path4 = longestPath(row, col - 1);
    vis[row][col] = false;
    return ret += max({path1 , path2 , path3 , path4});
}

queue<pair<int , int>> path;
bool visBuild[15][15];
int bestGrid[15][15];

void buildPathVersionTwo(int row, int col) {
    if(!valid(row , col))return;
    if(visBuild[row][col])return ;
    visBuild[row][col] = true;
    path.push({row, col});
    int mx = 0;
    if(valid(row+1 , col) and !visBuild[row+1][col])mx = max(mx, bestGrid[row+1][col]);
    if(valid(row-1 , col) and !visBuild[row-1][col])mx = max(mx, bestGrid[row-1][col]);
    if(valid(row , col+1) and !visBuild[row][col+1])mx = max(mx, bestGrid[row][col+1]);
    if(valid(row , col-1) and !visBuild[row][col-1])mx = max(mx, bestGrid[row][col-1]);

    if(mx == bestGrid[row + 1] [col]){
        buildPathVersionTwo(row + 1, col);
    }else if(mx == bestGrid[row - 1][col]){
        buildPathVersionTwo(row - 1, col);
    }else if(mx == bestGrid[row][col+1]){
        buildPathVersionTwo(row, col+1);
    }else if(mx == bestGrid[row][col-1]){
        buildPathVersionTwo(row, col-1);
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
    while (!path.empty()) path.pop();
    buildPathVersionTwo(row, col);
    return path;
}

int charge = 0;
int last = 0;

void torpedo(int row , int col) {
  // random attack
  if(charge < 3)return;
  if(last == 0) {
    cout << " TORPEDO | TORPEDO " << row + 2 << ' ' << col;
    last = 1;
    charge = 0;
  } else if(last == 1) {
    cout << " TORPEDO | TORPEDO " << row - 2  << ' ' << col;
    last = 2;
    charge = 0;
  } else if(last == 2) {
    cout << " TORPEDO | TORPEDO " << row  << ' ' << col + 2;
    last = 3;
    charge = 0;
  } else {
    cout << " TORPEDO | TORPEDO " << row << ' ' << col - 2;
    last = 1;
    charge = 0;
  }
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
    path.pop();
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
        ++charge;
        if(path.empty()) {
            cout << "SURFACE\n";
            path = surface(x , y);
            path.pop();
            continue;
        }
        int row = path.front().first;
        int col = path.front().second;
        path.pop();
        if(row == x and col == y+1)cout<<"MOVE E";
        else if(row == x and col == y-1)cout<<"MOVE W";
        else if(row == x-1 and col == y)cout<<"MOVE N";
        else cout<<"MOVE S";
        torpedo(row , col);
        cout<<"\n";
    }
}
