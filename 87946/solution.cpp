#include <string>
#include <vector>

using namespace std;

vector<int> is_picked;
vector<int> picked_idxes;
int max_ds = INT32_MIN;

void pick(vector<vector<int>> &dungeons, int init, int num_picks, int depth);
int solution(int k, vector<vector<int>> dungeons) {
    int num_dungeons = dungeons.size();
    int answer = -1;

    is_picked = vector<int>(num_dungeons, 0);
    picked_idxes = vector<int>(num_dungeons);

    for (int i = num_dungeons; i > 0; --i) {
        pick(dungeons, k, i, 0);
        if (max_ds != INT32_MIN)
            break;
    }

    answer = max_ds;
    return answer;
}

void pick(vector<vector<int>> &dungeons, int init, int num_picks, int depth) {
    int num_dungeons = dungeons.size();

    if (num_picks == depth) {
        int fatigue = init;
        int cnt = 0;

        for (int i = 0; i < depth; ++i) {
            vector<int> d = dungeons[picked_idxes[i]];

            if (fatigue < d[0])
                return;
            fatigue -= d[1];

            cnt++;
        }

        max_ds = max(max_ds, cnt);
        return;
    }

    for (int i = 0; i < num_dungeons; ++i) {
        if (!is_picked[i]) {
            is_picked[i] = 1;
            picked_idxes[depth] = i;
            pick(dungeons, init, num_picks, depth + 1);
            is_picked[i] = 0;
        }
    }
}
