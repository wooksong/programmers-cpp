#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int h_max = INT32_MIN;
    int v_max = INT32_MIN;

    for (auto it_sz = sizes.begin(); it_sz != sizes.end(); ++it_sz) {
        int h = (*it_sz).front();
        int v = (*it_sz).back();

        if (h < v) {
            swap(h, v);
        }

        if (h_max < h) {
            h_max = h;
        }

        if (v_max < v) {
            v_max = v;
        }
    }

    return h_max * v_max;
}
