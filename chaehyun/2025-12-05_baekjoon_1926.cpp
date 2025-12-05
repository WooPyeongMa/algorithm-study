//
//  2025-12-05_baekjoon_1926.cpp
//  algorithm
//
//  Created by 김채현 on 12/5/25.
//

#include <iostream>
#include <queue>

using namespace std;

int board[501][501];
bool visited[501][501];
int n, m;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    int area = 1;
    
    //상하좌우
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        auto cur = q.front();
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx > n || ny > m) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] == 0) continue;
            
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            area++;
        }
    }
    
    return area;
}


int main(void) {
    int cnt=0, max_area=0;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1 && !visited[i][j]) {
                cnt++;
                visited[i][j] = true;
                int area = bfs(i, j);
                if(area > max_area) max_area = area;
            }
        }
    }
    
    cout << cnt << endl << max_area;
    
    return 0;
}
