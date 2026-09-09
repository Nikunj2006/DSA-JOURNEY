int cmp(const void* a, const void* b) {
    int x = *(int*)a, y = *(int*)b;
    return (x > y) - (x < y);
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    int* sorted = malloc(arrSize * sizeof(int));
    memcpy(sorted, arr, arrSize * sizeof(int));
    qsort(sorted, arrSize, sizeof(int), cmp);

    int uniqueSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1])
            sorted[uniqueSize++] = sorted[i];
    }

    int* result = malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        int lo = 0, hi = uniqueSize - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (sorted[mid] < arr[i]) lo = mid + 1;
            else hi = mid;
        }
        result[i] = lo + 1;
    }
    *returnSize = arrSize;
    return result;
}   