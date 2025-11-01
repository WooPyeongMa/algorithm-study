#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num1, num2, num3;
    vector<char> numlist = {
        '0', '1', '2', '3', '4',
        '5', '6', '7', '8', '9'
    };

    cin >> num1;
    cin >> num2;
    cin >> num3;

    int mul = num1 * num2 * num3;
    string mulS = to_string(mul);

    for (char n : numlist) {
        int count = 0;

        for (char c : mulS) {
            if (c == n)
                count++;
        }

        if (n == '9') {
            cout << count;
            return 0;
        }
        cout << count << "\n";
    }
}