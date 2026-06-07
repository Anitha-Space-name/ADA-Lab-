int missingNumber(int* nums, int numsSize) {
    int n = numsSize * (numsSize+1) / 2;
    int new = 0;
    for(int i=0; i<numsSize; i++){
        new += nums[i];
    }
    return n - new;
}