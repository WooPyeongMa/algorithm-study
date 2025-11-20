//
//  2025-11-20_baekjoon_3015.cpp
//  algorithm
//
//  Created by 김채현 on 11/20/25.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int, int>> st;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n = 0;
    long long count = 0;
    
    cin >> n;
  
    for (int i = 0; i < n; i++)
    {
        int height = 0;
        
        cin >> height;
        
        while (!st.empty() && st.top().first < height)
        {
            count += st.top().second;
            st.pop();
        }
 
        if (st.empty()) st.push({ height, 1 });
        else if (st.top().first == height)
        {
            int temp = st.top().second;
            count += temp;
            st.pop();
            if (st.size() >= 1) count++;
            st.push({ height, temp + 1});
        }
        else
        {
            st.push({ height, 1 });
            count++;
        }
    }
 
    cout << count;
 
    return 0;
}
