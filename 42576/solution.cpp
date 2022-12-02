#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr size_t MAX_NUM_PARTICIPANTS = 100000;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> dict;
    string answer;

    dict.reserve(participant.size());
    for (auto iter = participant.begin(); iter != participant.end(); ++iter) {
        if (dict.find(*iter) == dict.end()) {
            dict[*iter] = 1;
            continue;
        }

        ++dict[*iter];
    }

    for (auto iter = completion.begin(); iter != completion.end(); ++iter) {
        --dict[*iter];
    }

    for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
        if (iter->second != 0) {
            answer = iter->first;
            break;
        }
    }

    return answer;
}

int main() {
    size_t num_cases;
    vector<vector<string>> participants = {
        {"leo", "kiki", "eden"},
        {"marina", "josipa", "nikola", "vinko", "filipa"},
        {"mislav", "stanko", "mislav", "ana"},
    };
    vector<vector<string>> completions = {
        {"eden", "kiki"},
        {"josipa", "filipa", "marina", "nikola"},
        {"stanko", "ana", "mislav"}};
    vector<string> answers = {"leo", "vinko", "mislav"};
    bool is_passed = true;

    num_cases = participants.size();
    for (size_t i = 0; i < num_cases; ++i) {
        if (answers[i] != solution(participants[i], completions[i])) {
            is_passed = false;
            break;
        }
    }

    cout << (is_passed ? "PASSED\n" : "FAILED\n");
    return 0;
}
