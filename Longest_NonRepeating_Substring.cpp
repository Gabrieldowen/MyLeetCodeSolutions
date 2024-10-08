/*3. Longest Substring Without Repeating Characters
Solved
Medium

Topics
Companies

Hint
Given a string s, find the length of the longest 
substring
without repeating characters.*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashMap[200];
        int maxLen = 0, currLen = 0, index = 0, firstCharIndex = 0;
        
        for(int i = 0; i < s.length(); i++){
            
            // get the location for each character in the hash map
            if (isalpha(s[i])) {
                if (isupper(s[i])) {
                    index = s[i] - 'A' + 1; // For uppercase letters
                } else {
                    index = s[i] - 'a' + 27; // For lowercase letters
                }
            } else if (isdigit(s[i])) {
                index = s[i] - '0' + 53; // For digits (0-9)
            } else if (isspace(s[i])) {
                index = 0; // Consider space position as 0
            } else {
                index = static_cast<int>(s[i]) + 64; // ASCII value for symbols
            }

            if(hashMap[index] != '\0'){
                // reset the hashmap and index 1 past to the last occurance of the repeated character
                i = hashMap[index] - 1;
                memset(hashMap, '\0', sizeof(hashMap));                
                currLen = 0;
            }
            else{
                // cout << "bigger substring" << endl;
                hashMap[index] = i+1;
                currLen++;
            }

            // update the return value
            if(currLen > maxLen){
                maxLen = currLen;
            }
        
        }

        return maxLen;
    }
};