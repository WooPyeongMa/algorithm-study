//
//  2025-12-06_baekjoon_2178.cpp
//  algorithm
//
//  Created by 김채현 on 12/6/25.
//

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maze[101][101];
int dist[101][101];

int bfs() {
    queue<pair<int, int>> q;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    q.push(make_pair(0, 0));
    dist[0][0] = 1;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx > n || ny > m) continue;
            if(maze[nx][ny] == 0) continue;
            if(dist[nx][ny]) continue;
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    
    return dist[n-1][m-1];
}

int main(void) {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < m; j++) maze[i][j] = input[j] - '0';
    }
    
    cout << bfs();
    
    return 0;
}

