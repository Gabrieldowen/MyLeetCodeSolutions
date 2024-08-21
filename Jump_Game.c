/*
55. Jump Game (leetcode.com/problems/jump-game/)

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

bool canJump(int* nums, int numsSize) {

    int zeroIndex = 0;
    bool zeroFound = 0;
    int maxJump = 0;

    if (numsSize == 1) return true;

    // find the first zero
    for(int i=0; i<numsSize; i++){
        if(nums[i]==0){
            zeroFound=1;
            zeroIndex=i;
            break;
        }
    }

    // if theres no zeros youre gaurunteed to reach the end
    if(!zeroFound) return true;

    // find the max number plus their index will be greater than zero index
    for(int i=0; i<zeroIndex; i++){

        // if any number can reach the end return with true
        if(i+nums[i] >= numsSize-1){
            printf("reached the final element");
            return true;
        }

        if(i+nums[i] > maxJump) maxJump = i+nums[i];

    }

    // check if the farther jump can pass the current zero
    if(maxJump > zeroIndex){

        // replace the zero with the remainder of jumps from the previous number
        nums[zeroIndex] = maxJump - zeroIndex;

        // recursivley call canJump for arrays with multiple zeros
        return canJump(&nums[zeroIndex], numsSize-(zeroIndex));
    }

    // if you cant jump any farther return false
    return false;


}