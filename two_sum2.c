/*
167. Two Sum ll - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i = 0;
    int j = numbersSize-1;

    while(true){
        // if right and left pointer meet in the middle theres no answer
        if(i == j){
            *returnSize = 0;
            int* result = (int*)malloc(0 * sizeof(int));
            return result;
        }
        else if(numbers[i] + numbers[j] == target){

            // only allocate if answer is found
            *returnSize = 2;
            int* result = (int*)malloc(2 * sizeof(int));

            result[0] = i+1;
            result[1] = j+1;
            
            return result;

        }
        // move in right pointer
        else if(numbers[i] + numbers[j] > target){
            j--;
        }
        // move in left pointer
        else if(numbers[i] + numbers[j] < target){
            i++;
        }
        else{
            // some sort of error
            return 0;
        }
    }


    

}