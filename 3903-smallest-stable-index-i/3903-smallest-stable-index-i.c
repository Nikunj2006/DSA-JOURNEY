int firstStableIndex(int* nums, int numsSize, int k) {
    int n = numsSize;
    int* right = (int*)malloc(n * sizeof(int));
    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] < nums[i] ? right[i + 1] : nums[i];
    }

    int left = nums[0];
    for (int i = 0; i < n; i++) {
        if (nums[i] > left) left = nums[i];
        if (left - right[i] <= k) {
            int res = i;
            free(right);
            return res;
        }
    }

    free(right);
    return -1;
}   