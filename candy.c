/*
135. Candy (leetcode.com/problems/candy/)

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
*/
int candy(int* ratings, int ratingsSize) {

    int candiesCount = 0;
    int *candiesCountArray = (int *)malloc(ratingsSize * sizeof(int)); // Allocate memory for the array


    // Initialize all elements to 1
    for (int i = 0; i < ratingsSize; i++) {
        candiesCountArray[i] = 1;
    }

    // compare each rating with the next
    for(int i=0; i<ratingsSize-1 ;i++){

        // gives candy to current rating if its greater than the next
        if (ratings[i] > ratings[i+1]){
            if(candiesCountArray[i] <= candiesCountArray[i+1]){
                candiesCountArray[i] = candiesCountArray[i+1] +1;
            }
        }

        // gives candy to next rating if its greater than the current
        if (ratings[i+1] > ratings[i]){
            if(candiesCountArray[i+1] <= candiesCountArray[i]){
                candiesCountArray[i+1] = candiesCountArray[i] + 1;
            }
        }

    }

    // compare each rating with the previous
    for(int i=ratingsSize-1; i>0 ;i--){

        // gives candy to current rating if its greater than the next
        if (ratings[i] > ratings[i-1]){
            if(candiesCountArray[i] <= candiesCountArray[i-1]){
                candiesCountArray[i] = candiesCountArray[i-1] +1;
            }
        }

        // gives candy to next rating if its greater than the current
        if (ratings[i-1] > ratings[i]){
            if(candiesCountArray[i-1] <= candiesCountArray[i]){
                candiesCountArray[i-1] = candiesCountArray[i] + 1;
            }
        }

    }

    // sum together the total candy
    for (int i = 0; i < ratingsSize; i++) {
        candiesCount += candiesCountArray[i];
    }


    free(candiesCountArray);
    return candiesCount;
}

