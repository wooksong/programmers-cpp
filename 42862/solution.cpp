#include <string>
#include <vector>

using namespace std;

int ans = INT32_MIN;

vector<int> num_gymsuits;

void solve(int n) {
    int cnt;

    for (int i = 1; i <= n; ++i) {
        if (num_gymsuits[i] == 2) {
            if ((i - 1) >= 1 && num_gymsuits[i - 1] == 0) {
                num_gymsuits[i - 1] = 1;
                num_gymsuits[i] = 1;
                solve(n);
                num_gymsuits[i - 1] = 0;
                num_gymsuits[i] = 2;

            } else if ((i + 1) <= n && num_gymsuits[i + 1] == 0) {
                num_gymsuits[i + 1] = 1;
                num_gymsuits[i] = 1;
                solve(n);
                num_gymsuits[i + 1] = 0;
                num_gymsuits[i] = 2;
            }
        }
    }

    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (num_gymsuits[i] != 0) {
            cnt++;
        }
    }

    ans = max(ans, cnt);
    return;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    num_gymsuits = vector<int>(n + 1, 1);
    num_gymsuits[0] = 0;
    for (auto iter = reserve.begin(); iter != reserve.end(); ++iter) {
        ++num_gymsuits[*iter];
    }

    for (auto iter = lost.begin(); iter != lost.end(); ++iter) {
        --num_gymsuits[*iter];
    }

    solve(n);

    return ans;
}
