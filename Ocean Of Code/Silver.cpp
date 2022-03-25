#include <bits/stdc++.h>
#define ll long long
#define S second
#define F first
using namespace std;
const int N = 15;

char lastMove;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int memo[N][N];
bool vis[N][N];
bool visBuild[N][N];
int bestGrid[N][N];
char grid[N][N];
queue<pair<int, int>> ans;
set<pair<ll, ll>> validCord;

bool validIdx(int i , int j) {
    return i >= 0 and j >= 0 and i < 15 and j < 15 and grid[i][j] == '.';
}

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < 15 and j < 15 and grid[i][j] == '.' and !vis[i][j];
}

int longestPath(int row, int col) {
    if (!valid(row, col))return 0;
    int &ret = memo[row][col];
    if (~ret)return ret;
    ret = 1;
    int mx = -(1e5);
    vis[row][col] = true;
    for (int x = 0; x < 4; x++) {
        mx = max(mx, longestPath(row + dx[x], col + dy[x]));
    }
    vis[row][col] = false;
    return ret += mx;
}

void buildPathVersionTwo(int row, int col) {
    if (!valid(row, col))return;
    if (visBuild[row][col])return;
    visBuild[row][col] = true;
    ans.push({row, col});
    int mx = 0;
    for (int x = 0; x < 4; x++) {
        if (valid(row + dx[x], col + dy[x]) and !visBuild[row + dx[x]][col + dy[x]]) {
            mx = max(mx, bestGrid[row + dx[x]][col + dy[x]]);
        }
    }

    for (int x = 0; x < 4; x++) {
        if (mx == bestGrid[row + dx[x]][col + dy[x]]) {
            buildPathVersionTwo(row + dx[x], col + dy[x]);
            break;
        }
    }
}

queue<pair<int, int>> surface(int row, int col) {
    memset(memo, -1, sizeof memo);
    memset(visBuild, false, sizeof visBuild);
    memset(vis, false, sizeof vis);
    int best = longestPath(row, col);
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            bestGrid[i][j] = memo[i][j];
        }
    }
    while (!ans.empty()) ans.pop();
    buildPathVersionTwo(row, col);
    return ans;
}

void TargetLocation(char Direction) {
    cerr<<Direction<<endl;
    stack<pair<ll, ll>> V;
    lastMove = Direction;
    //V store valid coordinates.
    for (auto it: validCord) {
        ll NewX, NewY;
        if (Direction == 'N') {
            NewX = it.first - 1, NewY = it.second;
            if (NewX < 0 || NewY < 0 || NewX >= 15 || NewY >= 15 || grid[NewX][NewY] == 'x') {
                continue;
            } else {
                V.push({NewX, NewY});
            }
        }
        if (Direction == 'S') {
            NewX = it.first + 1, NewY = it.second;
            if (NewX < 0 || NewY < 0 || NewX >= 15 || NewY >= 15 || grid[NewX][NewY] == 'x') {
                continue;
            } else {
                V.push({NewX, NewY});
            }
        }
        if (Direction == 'E') {
            NewX = it.first, NewY = it.second + 1;
            if (NewX < 0 || NewY < 0 || NewX >= 15 || NewY >= 15 || grid[NewX][NewY] == 'x') {
                continue;
            } else {
                V.push({NewX, NewY});
            }
        }
        if (Direction == 'W') {
            NewX = it.first, NewY = it.second - 1;
            if (NewX < 0 || NewY < 0 || NewX >= 15 || NewY >= 15 || grid[NewX][NewY] == 'x') {
                continue;
            } else {
                V.push({NewX, NewY});
            }
        }
    }
    validCord.clear();
    while (!V.empty()) {
        validCord.insert(V.top());
        V.pop();
    }
    clog << "new set\n";
    for (auto it: validCord) clog << it.S << " " << it.F << "\n";
}

bool chaeckhit(int r, int c, int tr, int tc) {
    int disr = abs(r - tr);
    int disc = abs(c - tc);
    cerr<<"drrrrrrrp "<<disr<<" "<< disc<<endl;

    if (disc + disr < 5  && disc + disr > 1) return true;
    else return false;
}

void EachSector(ll MinX, ll MaxX, ll MinY, ll MaxY) {
    set<pair<ll, ll>> Temp;
    for (auto it: validCord) {
        ll curX = it.first, curY = it.second;//11
        if (curX < MinX || curX > MaxX || curY < MinY || curY > MaxY) continue;
        else {
            Temp.insert({curX, curY});
        }
    }
    for(auto it: Temp){
        validCord.insert(it);
    }
    clog << "New\n";
    for (auto it: validCord) {
        clog << it.S << " " << it.F << "\n";
    }
}

void TargetSector(char Sector) {
    if (Sector == '1') EachSector(0, 4, 0, 4);// 0 4 0 4
    if (Sector == '2') EachSector(5, 9, 0, 4); // 5 9 0 4
    if (Sector == '3') EachSector(10, 14, 0, 4); // 10 14 0 4
    if (Sector == '4') EachSector(0, 4, 5, 9); // 0 4 5 9
    if (Sector == '5') EachSector(5, 9, 5, 9); // 5 9 5 9
    if (Sector == '6') EachSector(10, 14, 5, 9);// 10 14 5 9
    if (Sector == '7') EachSector(0, 4, 10, 14);// 0 4 10 14
    if (Sector == '8') EachSector(5, 9, 10, 14);//5 9 10 14
    if (Sector == '9') EachSector(10, 14, 10, 14);// 10 14 10 14

}

void TaragetTORPEDO(ll Tx, ll Ty) {
    set<pair<ll, ll>> Temp;

    for (auto it: validCord) {
        ll curX = it.first, curY = it.second;
        ll Diff = abs(curY - Tx) + abs(curX - Ty);
        if (Diff <= 4) {
            Temp.insert({curX, curY});
        }
    }
    validCord.clear();
    for(auto it: Temp){
        validCord.insert(it);
    }
    clog << "New\n";
    for (auto it: validCord) {
        clog << it.S << " " << it.F << "\n";
    }
}

void TargetSilence() {
    stack<pair<ll, ll>> Temp;
    for (auto it: validCord) {
        ll curX = it.first, curY = it.second;
        //temper
        int x = 4;
        if (lastMove == 'N') {
            // To E
            for (ll i = 1; i <= x; i++) {
                ll tempY = curY + i;
                if (tempY >= 15) break;
                else if (grid[curX][tempY] == 'x') break;
                Temp.push({curX, tempY});
            }
            // To W
            for (ll i = 1; i <= x; i++) {
                ll tempY = curY - i;
                if (tempY < 0) break;
                else if (grid[curX][tempY] == 'x') break;
                Temp.push({curX, tempY});
            }
            // To N
            for (ll i = 1; i <= x; i++) {
                ll tempX = curX - i;
                if (tempX < 0) break;
                if (grid[tempX][curY] == 'x') break;
                Temp.push({tempX, curY});
            }
        } else if (lastMove == 'S') {
            // To E
            for (ll i = 1; i <= x; i++) {
                ll tempY = curY + i;
                if (tempY >= 15) break;
                else if (grid[curX][tempY] == 'x') break;
                Temp.push({curX, tempY});
            }
            // To W
            for (ll i = 1; i <= x; i++) {
                ll tempY = curY - i;
                if (tempY < 0) break;
                else if (grid[curX][tempY] == 'x') break;
                Temp.push({curX, tempY});
            }
            // To S
            for (ll i = 1; i <= x; i++) {
                ll tempX = curX + i;
                if (tempX >= 15) break;
                if (grid[tempX][curY] == 'x') break;
                Temp.push({tempX, curY});
            }
        } else if (lastMove == 'W') {
            // To W
            for (ll i = 1; i <= x; i++) {
                ll tempY = curY - i;
                if (tempY < 0) break;
                else if (grid[curX][tempY] == 'x') break;
                Temp.push({curX, tempY});
            }
            // To N
            for (ll i = 1; i <= x; i++) {
                ll tempX = curX - i;
                if (tempX < 0) break;
                if (grid[tempX][curY] == 'x') break;
                Temp.push({tempX, curY});
            }
            // To S
            for (ll i = 1; i <= x; i++) {
                ll tempX = curX + i;
                if (tempX >= 15) break;
                if (grid[tempX][curY] == 'x') break;
                Temp.push({tempX, curY});
            }
        } else if (lastMove == 'E') {
            // To E
            for (ll i = 1; i <= x; i++) {
                ll tempY = curY + i;
                if (tempY >= 15) break;
                else if (grid[curX][tempY] == 'x') break;
                Temp.push({curX, tempY});
            }
            // To N
            for (ll i = 1; i <= x; i++) {
                ll tempX = curX - i;
                if (tempX < 0) break;
                if (grid[tempX][curY] == 'x') break;
                Temp.push({tempX, curY});
            }
            // To S
            for (ll i = 1; i <= x; i++) {
                ll tempX = curX + i;
                if (tempX >= 15) break;
                if (grid[tempX][curY] == 'x') break;
                Temp.push({tempX, curY});
            }
        }
    }

    while (!Temp.empty()) {
        validCord.insert(Temp.top());
        Temp.pop();
    }
    for (auto &it: validCord) {
        clog << it.S << " " << it.F << "\n";
    }
}

void tokenize(string const &str, const char delim,std::vector<std::string> &out){
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

void ParseAction(string Action) {
    if(Action.find('|') != -1){
        vector<string> temp , ans;
        tokenize(Action, '|', temp);
        for(auto it: temp){
            if(it.find("MSG") == -1){
                ans.push_back(it);
            }
        }
        if(ans.size() > 0)
            ParseAction(ans[0]);
        if(ans.size() > 1)
            ParseAction(ans[1]);
        return;
    }

    if (Action.find("MOVE") != -1) {
        cerr<<"here"<<endl;
        TargetLocation(Action[Action.size()-1]);
    }
    else if (Action.find("SURFACE") != -1) TargetSector(Action[Action.size()-1]); // TARGET 12 10
    else if (Action[0]=='T'){
        if(Action.size()>8) {   //TORPEDO 7 7
            cerr<<"klhxlknklnkldbfnzknbklb"<<endl;
            string tor = Action.substr(Action.find('T') + 8);

            cerr<<tor<<endl;
            string X, Y;
            int index=0;
            while (tor[index]!=' ')
            {
                X+=tor[index];
                index++;
            }
            for(int i=index+1;i<tor.size();i++)Y+=tor[i];
            ll Tx = stoi(X), Ty = stoi(Y);
            cerr << Tx << " " << Ty << endl;
            TaragetTORPEDO(Tx, Ty);
        }
    }
    else if (Action.find("SILENCE")!= -1) TargetSilence();
}

bool silenceReady , mine1Ready , mine2Ready ,torpedoReady;

int power = 0;

void charge(){
    if (power < 6) cout << "SILENCE";
    else if (power < 12) cout << "MINE";
    else if (power < 15) cout << "TORPEDO";
    power++;
    if(power == 6) silenceReady = true;
    else if(power == 9) mine1Ready = true;
    else if(power == 12) {
        mine2Ready = true;
        if(torpedoReady) power = 0;
    }
    else if(power == 15) torpedoReady = true;
    power %= 15;
}

void move(int row, int col , int x,int y){
    cerr<<"inside move\n";
    cerr<<row<<" "<<col<<" "<<x<<" ";
    if (row == x and col == y + 1)cout << "MOVE E ";
    else if (row == x and col == y - 1)cout << "MOVE W ";
    else if (row == x - 1 and col == y)cout << "MOVE N ";
    else if(row == x+1 and col == y)cout << "MOVE S ";
}

bool isMined[15][15];

bool distance(int x, int y , int mineX, int mineY){
    return abs(x-mineX)>1 and abs(y-mineY)>1;
}

map<pair<int , int>, bool> allMines;

void mineExp(int x ,int y){
    if(!allMines.empty()) {
        vector <pair<int, int>> intersection;
        for (auto it1: validCord) {
            for (auto it2: allMines) {
                if (it1.F == it2.F.F and it1.S == it2.F.S and it2.S) {
                    intersection.push_back(it2.F);
                }
            }
        }
        if(intersection.size()) {
            for(int r = 0; r<intersection.size(); r++){
                bool dis = distance(x, y , intersection[r].F , intersection[r].S);
                if(dis){
                    isMined[intersection[r].F][intersection[r].S] = false;
                    allMines[intersection[r]] = false;
                    cout << "TRIGGER " << intersection[r].S << " " << intersection[r].F << " | ";
                    break;
                }
            }
        }
    }
}

int main() {
    int width;
    int height;
    int my_id;
    cin >> width >> height >> my_id;
    cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < height; j++) {
            grid[i][j] = line[j];
            if (grid[i][j] == '.') validCord.insert({i, j});
        }
    }
    int longest = 0;
    int startRow{0}, startCol(0);
    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            if (grid[x][y] == 'x')continue;
            memset(memo, -1, sizeof memo);
            memset(vis, false, sizeof vis);
            int ret = longestPath(x, y);
            if (ret > longest) {
                for (int i = 0; i < 15; i++) {
                    for (int j = 0; j < 15; j++) {
                        bestGrid[i][j] = memo[i][j];
                    }
                }
                longest = ret;
                startCol = y;
                startRow = x;
            }
        }
    }
    buildPathVersionTwo(startRow, startCol);
    cout << startCol << ' ' << startRow << endl;
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
        cin >> x >> y >> my_life >> opp_life >> torpedo_cooldown >> sonar_cooldown >> silence_cooldown >> mine_cooldown;
        cin.ignore();
        string sonar_result;
        cin >> sonar_result;
        cin.ignore();
        string opponent_orders;
        getline(cin, opponent_orders);
        ParseAction(opponent_orders);
        swap(x, y);
        if (ans.empty()) {
            cout << "SURFACE\n";
            ans = surface(x, y);
            ans.pop();
            continue;
        }
        else {
            int row = ans.front().first;
            int col = ans.front().second;
            ans.pop();
            int targetx = (*validCord.begin()).first, targety = (*validCord.begin()).second;
            if (validCord.size() == 1 && chaeckhit(row, col, targetx, targety) && torpedoReady) {
                cerr << "YES" << endl;
                move(row, col , x ,y);
                charge();
                cout << "| TORPEDO " << targety << " " << targetx;
                cout << endl;
                torpedoReady = false;
                continue;
            }
            else if(silenceReady){
                if (row == x and col == y + 1) cout << "SILENCE E 1";
                else if (row == x and col == y - 1)cout << "SILENCE W 1";
                else if (row == x - 1 and col == y)cout << "SILENCE N 1";
                else cout << "SILENCE S 1";
                cout<<endl;
                silenceReady = false;
                continue;
            }
            else if (mine1Ready or mine2Ready){
                for(int r = 0; r<4; r++){
                    int newRow = x + dx[r];
                    int newCol = y + dy[r];
                    if(validIdx(newRow, newCol) and !isMined[newRow][newCol]){
                        allMines[{newRow, newCol}] = true;
                        cerr<<newRow<<" "<<newCol<<" MINE HERE\n";
                        if(x == newRow and newCol == y+1) {  cout << "MINE E | "; }
                        else if(x == newRow and newCol == y-1)cout<<"MINE W | ";
                        else if(x+1 == newRow and y == newCol) cout<<"MINE S | ";
                        else cout<<"MINE N | ";
                        isMined[newRow][newCol] = true;
                        break;
                    }
                }
                if(mine1Ready) mine1Ready = false;
                else mine2Ready = false;
                mineExp(x,y);
                move(row, col , x, y);
                charge();
                cout<<endl;
                continue;
            }
            else{
                mineExp(x,y);
                move(row, col, x, y);
                charge();
                cout << endl;
            }
        }
    }
}
