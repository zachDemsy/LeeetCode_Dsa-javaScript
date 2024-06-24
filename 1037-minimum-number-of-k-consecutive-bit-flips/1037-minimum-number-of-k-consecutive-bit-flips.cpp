#include <vector>
#include <queue>

class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipCount = 0; 
        std::queue<int> flipQueue;
        
        for (int i = 0; i < n; ++i) {
            if (!flipQueue.empty() && flipQueue.front() <= i - k) {
                flipQueue.pop();
            }
            if (flipQueue.size() % 2 != 0) {
                nums[i] ^= 1;  
            }
            if (nums[i] == 0) {
                if (i + k > n) return -1;
                flipQueue.push(i);
                nums[i] = 1;
                flips++; 
            }
        }
        
        return flips;
    }
};
