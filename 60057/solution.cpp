#include <string>
#include <vector>

using namespace std;

constexpr int MAX_LEN_S = 1001;

int solution(string s) {
    size_t len = s.length();
    int answer = len;

    for (size_t cmp_len = 1; cmp_len < (len / 2 + 1); ++cmp_len) {
        size_t curLen = len;

        for (size_t i = 0; i < len; i += cmp_len) {
            if (i + cmp_len  > len)
                break;

            string cur = s.substr(i, cmp_len);
            size_t cnt = 1;

            for (size_t j = i + cmp_len; j < len; j += cmp_len) {
                string next = s.substr(j, cmp_len);

                if (cur != next) {
                    break;
                }
                cnt++;
            }

            if (cnt > 1) {
                size_t jmp = cmp_len * (cnt - 1);
                size_t lenCntStr = 1;

                if (cnt > 9) {
                    lenCntStr = 2;
                } else if (cnt > 99) {
                    lenCntStr = 3;
                } else if (cnt > 999) {
                    lenCntStr = 4;
                }
                curLen = curLen - jmp + lenCntStr;
                i += jmp;
            }
        }
        if (curLen < answer) {
            answer = curLen;
        }
    }

    return answer;
}
