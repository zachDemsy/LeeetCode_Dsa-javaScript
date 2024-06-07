#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int maxLength = 0;
        std::unordered_map<char, int> charIndexMap;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            
            if (charIndexMap.find(s[end]) != charIndexMap.end() && charIndexMap[s[end]] >= start) {
                start = charIndexMap[s[end]] + 1;
            }
            charIndexMap[s[end]] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
