#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int x;
    cin >> x;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] == x)
            cnt++;
    }

    cout << cnt;

    return 0;
}