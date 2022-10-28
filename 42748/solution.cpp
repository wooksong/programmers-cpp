#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto iter_v = commands.begin(); iter_v != commands.end(); ++iter_v) {
        vector<int> *com = &(*iter_v);
        vector<int> new_v;
        int from, to, nth;

        from = com->at(0) - 1;
        to = com->at(1);
        nth = com->at(2);

        new_v = vector<int>(array.begin() + from, array.begin() + to);
        sort(new_v.begin(), new_v.end());
        answer.push_back(new_v[nth - 1]);
    }
    return answer;
}
