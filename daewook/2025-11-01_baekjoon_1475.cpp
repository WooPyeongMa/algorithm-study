#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v(10);

int main() {
    int num;
    cin >> num;
    
    while (num > 0) {
        v[num % 10]++;
        num /= 10;
    }

    // 6과 9는 중복으로 사용 가능하니, 숫자를 합하고 나누기 2를 통해 판수 측정 !

    v[6] += v[9];
    if (v[6] % 2 == 1)
        v[6] += 1;

    v[6] /= 2;
    v.pop_back();

    int maxValue = *max_element(v.begin(), v.end());
    cout << maxValue;

    return 0;
}