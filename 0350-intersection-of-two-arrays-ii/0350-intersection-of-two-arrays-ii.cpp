class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        
        unordered_map<int, int> count;
        for (int num : nums1) {
            count[num]++;
        }
        
        vector<int> result;
        for (int num : nums2) {
            if (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        return result;  
    }
};