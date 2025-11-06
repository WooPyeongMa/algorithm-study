#include <iostream>
#include <vector>

using namespace std;

int main() {
    string word1, word2;

    cin >> word1;
    cin >> word2;

    vector<int> v1(26), v2(26);

    for (char c : word1)
        v1[c - 'a']++;
    
    for (char c : word2)
        v2[c - 'a']++;

    int result = 0;

    for (int i = 0; i < 26; i++) {
        result += abs(v1[i] - v2[i]);
    }

    cout << result;

    return 0;
}