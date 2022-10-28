#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    std::vector<char> stack;
    stack.reserve(s.size());

    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        switch (*iter) {
        default:
        case '(':
            stack.push_back(')');
            break;
        case ')':
            if (stack.back() != *iter) {
                return false;
            }
            stack.pop_back();
            break;
        }
    }
    return stack.empty();
}
