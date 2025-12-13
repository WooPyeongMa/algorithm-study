//
//  2025-12-09_baekjoon_4179.cpp
//  algorithm
//
//  Created by 김채현 on 12/9/25.
//

#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

vector<string> maze;
queue<pair<int, int>> fire_q;
queue<pair<int, int>> human_q;

int main(void) {
    int r, c;
    int fire[1001][1001], human[1001][1001];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    cin >> r >> c;
    
    maze.resize(r);
    
    for(int i = 0; i < r; i++) cin >> maze[i];
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            fire[i][j] = INF;
            human[i][j] = -1;
            if(maze[i][j] == 'F') {
                fire[i][j] = 0;
                fire_q.push(make_pair(i, j));
            }
            else if(maze[i][j] == 'J') {
                human[i][j] = 0;
                human_q.push(make_pair(i, j));
            }
        }
    }
    
    while(!fire_q.empty()) {
        auto cur = fire_q.front();
        fire_q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
            if(maze[ny][nx] == '#') continue;
            if(fire[ny][nx] != INF) continue;
            
            fire[ny][nx] = fire[cur.first][cur.second] + 1;
            fire_q.push(make_pair(ny, nx));
        }
    }
    
    while(!human_q.empty()) {
        auto cur = human_q.front();
        human_q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];
            int nt = human[cur.first][cur.second] + 1;
            
            if(nx < 0 || ny < 0 || nx >= c || ny >= r) {
                cout << nt;
                return 0;
            }
            if(maze[ny][nx] == '#') continue;
            if(fire[ny][nx] <= nt) continue;
            if(human[ny][nx] >= 0) continue;
            
            human[ny][nx] = nt;
            human_q.push(make_pair(ny, nx));
        }
    }
    
    cout << "IMPOSSIBLE";
    
    return 0;
}
