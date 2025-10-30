#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string word;
    vector<string> v = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", 
        "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    };

    cin >> word;

    for (string s : v) {
        int count = 0;

        for (char c : word) {
            if (string(1, c) == s)
                count++;
        }
        if (s == "z") {
            cout << count;
            return 0;
        }

        cout << count << " ";
    }
    return 0;
}
