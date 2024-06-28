#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        std::vector<long long> degree(n, 0);
        for (const std::vector<int>& edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        std::sort(degree.begin(), degree.end());
        long long value = 1;
        long long totalImportance = 0;
        for (long long d : degree) {
            totalImportance += (value * d);
            value++;
        }

        return totalImportance;
    }
};
