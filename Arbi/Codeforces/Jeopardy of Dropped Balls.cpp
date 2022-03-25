/**
   Author : 3RB
**/
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
 
using namespace std;
 
 
 
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n , m , k;
  cin >> n >> m >> k;
  vector<vector<int>> grid(n , vector <int>(m , 0));
  for(auto &row : grid){
   for(auto &col : row){
    cin >> col;
   }
  }
  for(int i = 0;i < k;i++) {
    int col;
    cin >> col;
    --col;
    int row = 0;
    while(row < n) {
     if(grid[row][col] == 1) {
      grid[row][col] = 2;
      ++col;
     } else if(grid[row][col] == 2) {
      grid[row][col] = 2;
      row++;
     } else {
      grid[row][col] = 2;
      --col;
     }
    }
    cout << col + 1 << ' ';
  }
}
