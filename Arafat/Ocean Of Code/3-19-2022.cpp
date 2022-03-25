#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
set<pair<ll, ll>> ValidCord;
map<pair<ll, ll>, bool> Island;
ll w = 15, h = 15;
char Grid[15][15];
/*
NOT FULLY FINISHED !!!!!
1- fix X,Y bug
2- fix silence Test cases
*/
void TakeInput()
{
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            cin >> Grid[i][j];
            if (Grid[i][j] == 'X')
                Island[ {i, j}] = 1;
            else
                ValidCord.insert({i, j});
        }
    }
}

void TargetLocation(char Direction)
{
    // cout<<Direction<<"\n";
    stack<pair<ll, ll>> UV, V;
    for (auto &it : ValidCord)
    {
        //cout<<it.first<<" "<<it.second<<"\n";
        ll NewX, NewY;
        if (Direction == 'N')
        {
            NewX = it.first - 1, NewY = it.second;
            if (NewX < 0 || NewY < 0 || NewX >= w || NewY >= w || Island.find({NewX, NewY}) != Island.end())
            {
                continue;
            }
        }
        if (Direction == 'S')
        {
            NewX = it.first + 1, NewY = it.second;
            if (NewX < 0 || NewY < 0 || NewX >= w || NewY >= w || Island.find({NewX, NewY}) != Island.end())
            {
                continue;
            }
        }
        if (Direction == 'E')
        {
            NewX = it.first, NewY = it.second + 1;
            if (NewX < 0 || NewY < 0 || NewX >= w || NewY >= w || Island.find({NewX, NewY}) != Island.end())
            {
                continue;
            }
        }
        if (Direction == 'W')
        {
            NewX = it.first, NewY = it.second - 1;
            if (NewX < 0 || NewY < 0 || NewX >= w || NewY >= w || Island.find({NewX, NewY}) != Island.end())
            {
                continue;
            }
        }
        V.push({it.first, it.second});
    }
    ValidCord.clear();
    cout << " valid\n";
    while (!V.empty())
    {
        ll X = V.top().first, Y = V.top().second;
        if (Direction == 'N') X--;
        if (Direction == 'S') X++;
        if (Direction == 'E') Y++;
        if (Direction == 'W') Y--;
        ValidCord.insert({X, Y});
        V.pop();
    }
    cout << "new set\n";
    for (auto &it : ValidCord) cout << it.first << " " << it.second << "\n";
    //puts("");


}
void EachSector(ll MinX,ll MaxX, ll MinY,ll MaxY)
{
    set<pair<ll, ll>> Temp;
    for (auto &it : ValidCord)// 0 11
    {
        // 0                    11
        ll curY = it.first, curX = it.second;//11
        if(curX < MinX || curX > MaxX || curY < MinY || curY > MaxY) continue;
        else Temp.insert({curX, curY});
    }
    ValidCord = Temp;
    cout<<"New\n";
    for (auto &it : ValidCord)
    {
        cout<<it.first<<" "<<it.second<<"\n";
    }
}


void TargetSector(char Sector)// 5
{
    //cout<<"THERE "<<Sector<<"\n";
    if(Sector == '1') EachSector(0,4,0,4);// 0 4 0 4
    if(Sector == '2') EachSector(5,9,0,4); // 5 9 0 4
    if(Sector == '3') EachSector(10,14,0,4); // 10 14 0 4
    if(Sector == '4') EachSector(0,4,5,9); // 0 4 5 9
    if(Sector == '5') EachSector(5,9,5,9); // 5 9 5 9
    if(Sector == '6') EachSector(10,14,5,9);// 10 14 5 9
    if(Sector == '7') EachSector(0,4,10,14);// 0 4 10 14
    if(Sector == '8') EachSector(5,9,10,14);//5 9 10 14
    if(Sector == '9') EachSector(10,14,10,14);// 10 14 10 14

}

void  TaragetTORPEDO(ll Tx,ll Ty)
{
    set<pair<ll, ll>> Temp;
    for (auto &it : ValidCord)// 0 11
    {
        ll curY = it.first, curX = it.second;
        ll Diff = abs(curY - Ty) + abs(curX - Tx);
        if(Diff <= 4) Temp.insert({curX, curY});
    }
    ValidCord = Temp;
    cout<<"New\n";
    for (auto &it : ValidCord)
    {
        cout<<it.first<<" "<<it.second<<"\n";
    }
}

void TargetSilence()
{
    //cout<<"lngth"<<ValidCord.size()<<endl;
    stack<pair<ll,ll>>Temp;
    for (auto &it : ValidCord)// 0 11
    {
        ll curY = it.first, curX = it.second;//11
        // To E
        for( ll i = 1; i<=4; i++)
        {
            cout<<"first loop"<<endl;
            ll tempX = curX + i;
            if(tempX >= 15) break;
            if(Island.find({curY,tempX}) != Island.end()) break;
            Temp.push({curY,tempX});
        }
        // To W
        for( ll i = 1; i<=4; i++)
        {
            ll tempX = curX - i ;
            if(tempX < 0) break;
            if(Island.find({curY,tempX}) != Island.end()) break;
            Temp.push({curY,tempX});
        }
        // To N
        for( ll i = 1; i<=4; i++)
        {
            ll tempX = curY - i;
            if(tempX < 0) break;
            if(Island.find({tempX,curX}) != Island.end()) break;
           Temp.push({tempX,curX});
        }
        // To S
        for( ll i = 1; i<=4; i++)
        {
            ll tempX = curY + i;
            if(tempX >= 15) break;
            if(Island.find({tempX,curX}) != Island.end()) break;
            Temp.push({tempX,curX});
        }
    }
    while(!Temp.empty())
    {
        ValidCord.insert(Temp.top());
        Temp.pop();
    }
    for (auto &it : ValidCord)// 0 11
    {
        cout<<it.first<<" "<<it.second<<"\n";
    }

}

void ParseAction(string Action)// TORPEDO 13 14
{
    //cout<<Action;
    if (Action.find("MOVE") != -1) TargetLocation(Action[Action.size()-1]);
    else if (Action.find("SURFACE") != -1) TargetSector(Action[Action.size()-1]);
    else if (Action.find("TORPEDO") != -1 )
    {
        string X, Y;
        ll cur1 = -1;
        for(ll i = 8; i<Action.size(); i++)
        {
            if(cur1 == -1 && Action[i] == ' ')cur1 = 0;

            else if(cur1 == -1)X += Action[i];

            else Y += Action[i];


        }
        ll Tx = stoi(X), Ty = stoi(Y);
        TaragetTORPEDO(Tx,Ty);
    }
    else if (Action.find("SILENCE")!= -1) TargetSilence();
    else if (Action.find("TARGET") != -1 ) {}
}

/*
2 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 X 0 X 0 0 0 0 0 0 0 0 0 0 0
0 0 0 X X 0 0 0 X X 0 0 0 X X
0 0 X 0 0 0 0 X 0 0 0 0 X 0 0
0 X 0 0 0 0 X 0 0 0 0 X 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 X 0 X 0 0 0 0 0 0 0 0 0 0 0
0 0 0 X X 0 0 0 X X 0 0 0 X X
0 0 X 0 0 0 0 X 0 0 0 0 X 0 0
0 X 0 0 0 0 X 0 0 0 0 X 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 X 0 X 0 0 0 0 0 0 0 0 0 0 0
0 0 0 X X 0 0 0 X X 0 0 0 X X
0 0 X 0 0 0 0 X 0 0 0 0 0 0 0
0 X 0 0 0 0 X 0 0 0 0 X 0 0 o
*/
int main()
{


    // cin >> w >> h;

    TakeInput();
    while(1)
    {
        string User;
        getline(cin,User);
        ParseAction(User);

    }


    //   puts("");
    //   for (auto &it : ValidCord) {
    //     cout << it.first << " " << it.second << "\n";
    //   }
    //puts("");

}
