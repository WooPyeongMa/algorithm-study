#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string pw;
        cin >> pw;

        list<char> password;
        auto cursor = password.end();
        for (char c : pw)
        {
            if (c == '<' && cursor != password.begin())
                cursor--;
            
            else if (c == '>' && cursor != password.end())
                cursor++;

            else if (c == '-' && cursor != password.begin()) 
                cursor = password.erase(--cursor);

            else if (c == '<' || c == '>' || c == '-')
                continue;
            
            else {
                password.insert(cursor, c);
            }
        }

        for (char c : password)
            cout << c;

        if (i == n - 1)
            continue;

        cout << "\n";
    }

    return 0;
}