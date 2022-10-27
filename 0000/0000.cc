#include <iostream>
#include <string>
#include <vector>

using namespace std;

string to_binary(size_t len) {
    string reversed;

    while (len > 0) {
        if (len % 2 == 1) {
            reversed += '1';
        } else {
            reversed += '0';
        }
        len /= 2;
    }

    return string(reversed.rbegin(), reversed.rend());
}

vector<int> solution(string s) {
    string converted_s = s;
    size_t len_s = converted_s.length();
    int num_converted = 0;
    int num_removed_zs = 0;

    vector<int> answer;

    while (converted_s != "1") {
        string without_zs;

        for (size_t i = 0; i < len_s; ++i) {
            if (converted_s[i] == '0') {
                num_removed_zs++;
                continue;
            }
            without_zs += '1';
        }
        converted_s = to_binary(without_zs.length());

        len_s = converted_s.length();
        num_converted++;
    }

    answer.push_back(num_converted);
    answer.push_back(num_removed_zs);

    return answer;
}
int main() {
    solution("110010101001");
    return 0;
}
