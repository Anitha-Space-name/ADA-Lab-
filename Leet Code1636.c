#include <stdlib.h>

int freq[201];

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (freq[x + 100] == freq[y + 100])
        return y - x;          // same frequency -> larger number first

    return freq[x + 100] - freq[y + 100]; // lower frequency first
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    for (int i = 0; i < 201; i++)
        freq[i] = 0;

    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + 100]++;

    qsort(nums, numsSize, sizeof(int), compare);

    return nums;
}