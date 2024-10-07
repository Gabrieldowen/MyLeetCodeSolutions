/*
2696. Minimum String Length After Removing Substrings
Easy

Topics
Companies

Hint
You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

*/

class Solution {
public:
    int minLength(string s) {

        for(int i = 0; i < s.length(); i++){
            if((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'C' && s[i+1] == 'D')){
                s.erase(i, 2);

                // set to -1 so when incremented it restarts at the first index 0
                i = -1;
            }

        }

        return s.length();
    }
};