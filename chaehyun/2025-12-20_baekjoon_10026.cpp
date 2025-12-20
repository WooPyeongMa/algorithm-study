//
//  2025-12-20_baekjoon_10026.cpp
//  algorithm
//
//  Created by 김채현 on 12/20/25.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<string> board;
bool visited_normal[101][101];
bool visited_colorblind[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs_normal(int x, int y) {
    queue<pair<int, int>> q;
    char color;
    
    q.push({x, y});
    visited_normal[x][y] = true;
    color = board[x][y];
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx > n || ny > n) continue;
            if(visited_normal[nx][ny]) continue;
            if(board[nx][ny] != color) continue;
            
            q.push({nx, ny});
            visited_normal[nx][ny] = true;
        }
    }
}

void bfs_colorblind(int x, int y) {
    queue<pair<int, int>> q;
    char color;
    bool flag = false;
    
    q.push({x, y});
    visited_colorblind[x][y] = true;
    color = board[x][y];
    
    if(color == 'R' || color == 'G') flag = true;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx > n || ny > n) continue;
            if(visited_colorblind[nx][ny]) continue;
            if(flag == true && board[nx][ny] == 'B') continue;
            if(flag == false && board[nx][ny] != color) continue;
            
            q.push({nx, ny});
            visited_colorblind[nx][ny] = true;
        }
    }
}

int main(void) {
    int normal = 0;
    int colorblind = 0;
    
    cin >> n;
    
    board.resize(n);
    
    for(int i = 0; i < n; i++) cin >> board[i];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited_normal[i][j]) {
                bfs_normal(i, j);
                normal++;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited_colorblind[i][j]) {
                bfs_colorblind(i, j);
                colorblind++;
            }
        }
    }
    
    cout << normal << " " << colorblind;
    
    return 0;
}
