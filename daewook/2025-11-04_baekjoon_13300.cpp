#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // 성별에 따른 학년 인원 수 계산
    vector<int> w = {0, 0, 0, 0, 0, 0};
    vector<int> m = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < N; i++) {
        int S, Y;
        cin >> S >> Y;
        if (S == 0)
            w[Y - 1]++;
        
        else
            m[Y - 1]++;
    }

    int result = 0;
    for (int i : w) {
        result += (i / K);
        if (i % K != 0)
            result += 1;
    }

    for (int i : m) {
        result += (i / K);
        if (i % K != 0)
            result += 1;
    }

    cout << result;
    
    return 0;
}