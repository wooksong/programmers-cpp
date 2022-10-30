#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    if (arr.empty())
        return answer;
    answer.push_back(arr[0]);

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] == answer.back())
            continue;
        answer.push_back(arr[i]);
    }

    return answer;
}
