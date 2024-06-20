#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        
        int left = 1;
        int right = position.back() - position.front();
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBalls(position, m, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

private:
    bool canPlaceBalls(const std::vector<int>& position, int m, int minDist) {
        int count = 1;  // Place the first ball in the first basket
        int lastPos = position[0];
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];
                if (count == m) return true;
            }
        }
        
        return false;
    }
};
