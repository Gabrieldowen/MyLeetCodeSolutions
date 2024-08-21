/*
26. Remove Duplicates from Sorted Array (leetcode.com/problems/remove-duplicates-from-sorted-array/)

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
*/


int removeDuplicates(int* nums, int numsSize) {

    // function variables
    int maxNum = nums[numsSize-1];
    int k=1;

    for(int i =0; i < numsSize-1; i++){
        // if we change digits increment k and overwrite it into nums
        if(nums[i] != nums[i+1]){
            nums[k] = nums[i+1];
            k++;
        }

        // stop looking if we find the max number
        if (nums[i+1] == maxNum){
            break;
        } 
    }

    return k;
    
}