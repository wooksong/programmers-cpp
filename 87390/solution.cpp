#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll_t = long long;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    ll_t idx_r, idx_c;
    int cnt;

    idx_r = left / n;
    idx_c = left % n;
    cnt = right - left + 1;

    for (int i = 0; i < cnt; ++i, ++idx_c) {
        int num;

        if (idx_c == n) {
            idx_r = idx_r + 1;
            idx_c = 0;
        }

        num = idx_r;
        if (idx_c > idx_r)
            num = idx_c;
        answer.push_back(num + 1);
    }
    return answer;
}
