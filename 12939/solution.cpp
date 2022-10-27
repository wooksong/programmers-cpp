#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> v_tmp;
std::vector<int> v_sorted;

int to_integer(std::string numstr);
void merge(int idx_s, int idx_m, int idx_e);
void sort(int idx_s, int idx_e);

string solution(string s) {
    std::string numstr;
    string answer = "";
    size_t n;

    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        if (*iter == ' ') {
            v_sorted.push_back(to_integer(numstr));
            numstr.clear();
        } else {
            numstr += *iter;
        }
    }

    if (!numstr.empty()) {
        v_sorted.push_back(to_integer(numstr));
    }

    n = v_sorted.size();
    v_tmp = std::vector<int>(n);
    sort(0, n);

    answer.append(std::to_string(v_sorted.front()));
    answer += ' ';
    answer.append(std::to_string(v_sorted.back()));

    return answer;
}

void merge(int idx_s, int idx_m, int idx_e) {
    int i, j, pos;

    i = idx_s;
    j = idx_m;
    pos = idx_s;
    while (i < idx_m && j < idx_e) {
        if (v_sorted[i] < v_sorted[j]) {
            v_tmp[pos++] = v_sorted[i++];
        } else {
            v_tmp[pos++] = v_sorted[j++];
        }
    }

    while (i < idx_m) {
        v_tmp[pos++] = v_sorted[i++];
    }

    while (j < idx_e) {
        v_tmp[pos++] = v_sorted[j++];
    }

    for (i = idx_s; i < idx_e; ++i) {
        v_sorted[i] = v_tmp[i];
    }
}

void sort(int idx_s, int idx_e) {
    int idx_m;

    if (idx_s + 1 >= idx_e)
        return;

    idx_m = idx_s + (idx_e - idx_s) / 2;
    sort(idx_s, idx_m);
    sort(idx_m, idx_e);
    merge(idx_s, idx_m, idx_e);
}

int to_integer(std::string numstr) {
    bool negative = false;
    int val = 0;
    int mul = 1;

    for (auto iter = numstr.rbegin(); iter != numstr.rend(); ++iter) {
        if (*iter == '-') {
            negative = true;
            continue;
        }
        val += (static_cast<int>(*iter - '0') * mul);
        mul *= 10;
    }
    if (negative)
        val = -val;

    return val;
}
