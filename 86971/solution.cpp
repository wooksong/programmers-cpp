
#include <bitset>
#include <list>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_NODES = 101;

std::vector<std::list<int>> tree;
std::bitset<MAX_NODES> visited;
size_t min_diff = SIZE_MAX;

void dfs(int node_s);

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    tree = std::vector<std::list<int>>(n + 1);

    for (auto iter = wires.begin(); iter != wires.end(); ++iter) {
        int nf = (*iter)[0];
        int ns = (*iter)[1];

        tree[nf].push_back(ns);
        tree[ns].push_back(nf);
    }

    for (auto iter = wires.begin(); iter != wires.end(); ++iter) {
        int nf = (*iter)[0];
        int ns = (*iter)[1];
        size_t num_nodes_big;
        size_t num_nodes_small;

        for (auto iter = tree[nf].begin(); iter != tree[nf].end(); ++iter) {
            if (*iter == ns) {
                tree[nf].erase(iter);
                break;
            }
        }

        for (auto iter = tree[ns].begin(); iter != tree[ns].end(); ++iter) {
            if (*iter == nf) {
                tree[ns].erase(iter);
                break;
            }
        }

        visited.reset();
        dfs(nf);
        num_nodes_big = visited.count();
        visited.reset();
        dfs(ns);
        num_nodes_small = visited.count();

        if (num_nodes_big < num_nodes_small)
            std::swap(num_nodes_big, num_nodes_small);
        min_diff = std::min(min_diff, num_nodes_big - num_nodes_small);
        tree[nf].push_back(ns);
        tree[ns].push_back(nf);
    }
    answer = static_cast<int>(min_diff);

    return answer;
}

void dfs(int node_s) {
    std::list<int> *link = &tree[node_s];

    visited.set(node_s, true);
    for (auto iter = link->begin(); iter != link->end(); ++iter) {
        if (!visited.test(*iter)) {
            dfs(*iter);
        }
    }
}
