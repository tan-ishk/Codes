#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &visited, int x, int y,
            vector<vector<int>> &arr, int n) {

  if (visited[x][y] == 0 && arr[x][y] == 1 &&
      x >= 0 && x < n && y >= 0 && y < n) {
    return true;
  }
      return false;
}

void solve(vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<int>> &visited, string path, int x, int y) {
               
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }
  visited[x][y] = 1;

  // down
  int newx = x;
  int newy = y+1;
  if (isSafe(visited, newx, newy, arr, n)) {
    path.push_back('D');
    solve(arr, n, ans, visited, path, newx, newy);
    path.pop_back();
  }
  // up
  newx = x;
  newy = y-1;
  if (isSafe(visited, newx, newy, arr, n)) {
    path.push_back('U');
    solve(arr, n, ans, visited, path, newx, newy);
    path.pop_back();
  }
  // right
  newx = x+1;
  newy = y;
  if (isSafe(visited, newx, newy, arr, n)) {
    path.push_back('R');
    solve(arr, n, ans, visited, path, newx, newy);
    path.pop_back();
  }
  // left
  newx = x-1;
  newy = y;
  if (isSafe(visited, newx, newy, arr, n)) {
    path.push_back('L');
    solve(arr, n, ans, visited, path, newx, newy);
    path.pop_back();
  }

  visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  vector<string> ans;

  if (arr[0][0] == 0) {
    return ans;
  }

  int srcX = 0;
  int srcY = 0;

  vector<vector<int>> visited(n, vector<int>(n, 0));

  string path = "";
  solve(arr, n, ans, visited, path, srcX, srcY);
  sort(ans.begin(), ans.end());
  return ans;
}

int main(){
    vector<vector<int>> arr = {{1,0,0,0},
                                {1,1,0,0},
                                {1,1,0,0},
                                {0,1,1,1}};

    int n = 4;
    vector<string> ans = searchMaze(arr, n);
    cout<<"ans is : \n";
    for (int i = 0; i < n; i++){
        cout<<ans[i];
    }
}