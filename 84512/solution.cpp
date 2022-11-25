#include <string>
#include <vector>

using namespace std;

bool found = false;
constexpr int NUM_AEIOU = 5;
std::vector<char> AEIOU = {'A', 'E', 'I', 'O', 'U'};

void pick(std::string &picked, std::string &target, int depth, int len,
          int &ans) {
    if (found || depth == NUM_AEIOU) {
        return;
    }

    for (int i = 0; !found && i < NUM_AEIOU; ++i) {
        picked += AEIOU[i];
        if (picked == target) {
            found = true;
            continue;
        }

        ans += 1;
        pick(picked, target, depth + 1, len + 1, ans);
        picked.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    std::string empty;

    found = false;
    pick(empty, word, 0, 0, answer);
    return answer + 1;
}
