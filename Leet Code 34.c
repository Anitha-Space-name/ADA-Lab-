int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int first = -1;
    int last = -1;
    for(int i=0; i<numsSize; i++){
        if(nums[i] == target){
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }

    int* result = (int*)malloc(2*sizeof(int));
    result[0] = first;
    result[1] = last;
    *returnSize = 2;
    return result;
}