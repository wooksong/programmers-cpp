#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> picked;
vector<int> nums;
vector<int> is_picked;
set<int> candidates;
vector<int> prime_numbers;

int max_num = INT32_MIN;

void pick(int num_picks, int depth);
void sieve(int max);

int solution(string numbers) {
    size_t len = numbers.length();
    int answer = 0;

    nums = vector<int>(len);
    picked = vector<int>(len);
    is_picked = vector<int>(len, 0);

    for (size_t i = 0; i < len; ++i) {
        nums[i] = static_cast<int>(numbers[i] - '0');
    }

    for (size_t i = 1; i <= len; ++i) {
        pick(i, 0);
    }
    sieve(max_num);
    for (auto iter = candidates.begin(); iter != candidates.end(); ++iter) {
        if (prime_numbers[*iter])
            answer++;
    }
    return answer;
}

void pick(int num_picks, int depth) {
    size_t len = nums.size();

    if (num_picks == depth) {
        int val = 0;
        int mul = 1;
        for (int i = 0; i < depth; ++i) {
            val += (picked[i] * mul);
            mul *= 10;
        }
        max_num = std::max(max_num, val);
        candidates.insert(val);
        return;
    }

    for (size_t i = 0; i < len; ++i) {
        if (!is_picked[i]) {
            is_picked[i] = 1;
            picked[depth] = nums[i];
            pick(num_picks, depth + 1);
            is_picked[i] = 0;
        }
    }
}

void sieve(int max) {
    prime_numbers = vector<int>(max + 1, 1);

    prime_numbers[0] = 0;
    prime_numbers[1] = 0;
    for (int i = 2; i < max + 1; ++i) {
        for (int j = 2; i * j < max + 1; ++j) {
            prime_numbers[i * j] = 0;
        }
    }
}
