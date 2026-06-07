int findDuplicate(int* nums, int numsSize) {
    int hashTable[numsSize];
    for(int i=0;i<numsSize;i++){
        hashTable[i]=0;
    }
    for (int i=0;i<numsSize;i++){
        hashTable[nums[i]]+=1;
    }
    for (int i=0;i<numsSize;i++){
        if (hashTable[i]>1){
            return i;
        }
    }
    return -1;
}