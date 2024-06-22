#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; 
        
        int currentPrefixSum = 0;
        int niceSubarrayCount = 0;
        
        for (int num : nums) {
            currentPrefixSum += (num % 2);
            if (prefixSumCount.find(currentPrefixSum - k) != prefixSumCount.end()) {
                niceSubarrayCount += prefixSumCount[currentPrefixSum - k];
            }
         
            prefixSumCount[currentPrefixSum]++;
        }
        
        return niceSubarrayCount;
    }
};
