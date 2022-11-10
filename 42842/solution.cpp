#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<pair<int, int>> candidates;
    vector<int> answer;
    size_t len;

    for (int i = 1; i <= yellow; ++i) {
        if (yellow % i == 0) {
            int q = yellow / i;
            if (i > q)
                break;
            candidates.push_back({i, q});
        }
    }

    len = candidates.size();
    for (int i = 0; i < len; ++i) {
        int h, w;

        h = candidates[i].first + 2;
        w = candidates[i].second + 2;

        if (((h + w) * 2 - 4) == brown) {
            if (w > h) {
                swap(h, w);
            }
            answer.push_back(h);
            answer.push_back(w);
            break;
        }
    }
    return answer;
}
