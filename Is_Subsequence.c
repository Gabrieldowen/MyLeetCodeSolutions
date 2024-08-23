/*
392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
*/

bool isSubsequence(char* s, char* t) {
    int i, j = 0;
    while(true){
        
        // if all of subsequence is found return true if not return false
        if(s[i] == '\0') return true;
        if(t[j] == '\0') return false;

        // if sub string character is found in t look for the next character
        if(s[i] == t[j]){
            i++;
            j++;
        }
        // otherwise search the next of t
        else{
            j++;
        }
    }
}