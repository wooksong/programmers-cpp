#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    const vector<vector<int>> patterns = {{1, 2, 3, 4, 5},
                                          {2, 1, 2, 3, 2, 4, 2, 5},
                                          {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    size_t num_problems;
    size_t num_patterns;
    int max_score = INT32_MIN;

    vector<int> scores;
    vector<int> answer;

    num_problems = answers.size();
    for (auto each_pattern : patterns) {
        int score = 0;
        int size_pattern = each_pattern.size();

        for (size_t i = 0; i < num_problems; ++i) {
            int idx = i % size_pattern;

            if (answers[i] == each_pattern[idx]) {
                score++;
            }
        }
        if (max_score < score) {
            max_score = score;
        }
        scores.push_back(score);
    }

    num_patterns = patterns.size();
    for (size_t i = 0; i < num_patterns; ++i) {
        if (max_score == scores[i]) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
