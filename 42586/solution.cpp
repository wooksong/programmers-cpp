#include <cmath>
#include <vector>

using namespace std;

constexpr int MAX_NUM_JOBS = 101;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    size_t num_jobs = progresses.size();
    vector<int> answer;
    vector<int> days_needed(num_jobs);

    for (size_t i = 0; i < num_jobs; ++i) {
        days_needed[i] = std::ceil((double)(100 - progresses[i]) / speeds[i]);
    }

    for (size_t i = 0; i < num_jobs;) {
        int cur = days_needed[i];
        int cnt = 0;

        for (size_t j = i; j < num_jobs; ++j) {
            if (days_needed[j] > cur) {
                i = j;
                break;
            }
            ++cnt;
            ++i;
        }

        answer.push_back(cnt);
    }

    return answer;
}
