int min(int a, int b) {
    return a < b ? a : b;
}

int minSwap(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int keep = 0;  // no swap at current position
    int swap = 1;  // swap at current position

    for (int i = 1; i < nums1Size; i++) {
        int newKeep = 1000000;
        int newSwap = 1000000;

        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
            newKeep = min(newKeep, keep);
            newSwap = min(newSwap, swap + 1);
        }

        if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
            newKeep = min(newKeep, swap);
            newSwap = min(newSwap, keep + 1);
        }

        keep = newKeep;
        swap = newSwap;
    }

    return min(keep, swap);
}