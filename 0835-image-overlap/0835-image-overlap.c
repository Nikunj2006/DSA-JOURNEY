int largestOverlap(int** img1, int img1Size, int* img1ColSize,
                   int** img2, int img2Size, int* img2ColSize) {
    int n = img1Size;
    int cnt[60][60]; // offsets range from -(n-1) to (n-1), offset by n
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (img1[i][j])
                for (int h = 0; h < n; h++)
                    for (int k = 0; k < n; k++)
                        if (img2[h][k]) {
                            int c = ++cnt[i - h + n][j - k + n];
                            if (c > ans) ans = c;
                        }
    return ans;
}   