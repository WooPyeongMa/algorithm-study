#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 입력 첫째 줄 (수열의 크기)
    int n;
    cin >> n;

    // 수열 입력 받기
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    // x값 받기
    int x;
    cin >> x;

    // vector 값 정렬 후, 좌우에서 줄이는 방법 쓰기
    int result = 0;
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = v[left] + v[right];

        if (sum == x) {
            result++;
            left++;
            right--;
        }

        else if (sum < x) {
            left++;
        }

        else {
            right--;
        }
    }

    cout << result;
    return 0;
}