#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    size_t len;
    size_t i;

    sort(citations.rbegin(), citations.rend());

    if (citations[0] == 0)
        return 0;

    len = citations.size();
    for (i = 1; i <= len; ++i) {
        if (citations[i] <= i) {
            answer = i;
            break;
        }
    }
    return answer;
}
