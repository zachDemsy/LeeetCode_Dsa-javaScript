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
            // If the character is found in the map and its index is after the start of the current substring,
            // update the start index to the index after the last occurrence of the character.
            if (charIndexMap.find(s[end]) != charIndexMap.end() && charIndexMap[s[end]] >= start) {
                start = charIndexMap[s[end]] + 1;
            }
            // Update the index of the current character in the map.
            charIndexMap[s[end]] = end;
            // Update the maximum length of the substring.
            maxLength = std::max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
