// 9. Palindrome Number www.leetcode.com/problems/palindrome-number/ 
// "Given an integer x, return true if x is a palindrome, and false otherwise."
//"An integer is a palindrome when it reads the same forward and backward."

bool isPalindrome(int x) {
    // if number is negative it cant be a palindrome
    if (x < 0) return 0;

    // reverse x 
    long int reverse = 0;
    int temp = x;
    while(temp!=0){
        // make the least signifigant digit of temp the MSD of reverse
        reverse *= 10;
        reverse += temp%10;
        temp /= 10;
    }

    // check if reversed is equal to original
    if (x == reverse) 
        return 1;
    else 
        return 0;
}