#include <iostream>
#include <string>
#include <list>

using namespace std;

// string으로 insert, erase를 하려했으나, 이 방법을 사용하면
// 내부 함수 자체가 O(N) 이므로, O(N^2)의 시간 복잡도를 갖게 되어 TLE가 된다.

int main() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    list<char> word(s.begin(), s.end());
    auto cursor = word.end();

    // m회 명령어 수행
    for (int i = 0; i < m; i++) {
        string inp;
        cin >> inp;

        if (inp == "L" && cursor != word.begin())
            cursor--;
        
        else if (inp == "D" && cursor != word.end())
            cursor++;

        else if (inp == "B" && cursor != word.begin()) {
            cursor = word.erase(--cursor);
        }

        else if (inp == "P") {
            char inp2;
            cin >> inp2;

            word.insert(cursor, inp2);
        }
    }
    
    for (char c : word)
        cout << c;
        
    return 0;
}