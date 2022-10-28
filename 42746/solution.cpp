#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    struct {
        bool operator()(int lhs, int rhs) {
            string lr = to_string(lhs).append(to_string(rhs));
            string rl = to_string(rhs).append(to_string(lhs));
            int mul = 1;
            int lr_num = 0;
            int rl_num = 0;
            size_t i;

            for (i = 0; i < lr.length(); ++i) {
                if (lr[i] != '0')
                    break;
            }

            lr = string(lr.begin() + i, lr.end());
            for (i = 0; i < rl.length(); ++i) {
                if (rl[i] != '0')
                    break;
            }

            rl = string(rl.begin() + i, rl.end());

            for (auto iter = lr.rbegin(); iter != lr.rend(); ++iter) {
                lr_num += ((*iter - '0') * mul);
                mul *= 10;
            }

            mul = 1;
            for (auto iter = rl.rbegin(); iter != rl.rend(); ++iter) {
                rl_num += ((*iter - '0') * mul);
                mul *= 10;
            }

            return lr_num > rl_num;
        }
    } Comp;

    sort(numbers.begin(), numbers.end(), Comp);
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
        answer += to_string(*iter);
    }
    size_t i;
    for (i = 0; i < answer.length(); ++i) {
        if (answer[i] != '0')
            break;
    }

    answer = string(answer.begin() + i, answer.end());
    if (answer.empty())
        answer = "0";
    return answer;
}
