#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::deque<int> maxDeque, minDeque;
        int left = 0, right = 0;
        int result = 0;
        
        while (right < nums.size()) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            while (!maxDeque.empty() && !minDeque.empty() && 
                   nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                ++left;
                if (maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() < left) {
                    minDeque.pop_front();
                }
            }
            result = std::max(result, right - left + 1);
            ++right;
        }
        
        return result;
    }
};
