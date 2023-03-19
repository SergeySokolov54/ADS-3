// Copyright 2021 NNTU-CS

int sorted(int* arr, int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (arr[j] > arr[j + 1]) {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
    return *arr;
}

int cbinsearch(int* arr, int size, int value) {
    sorted(arr, size);
    int c = size / 2;
    int k = -size;
    while (k != size) {
        k++;
        if (arr[c] > value) {
            c /= 2;
        } else if (arr[c] < value) {
            c += c / 2;
        } else if (arr[c] == value) {
            int a = 1;
            for (int i = c-1; arr[i] == value; i--) {
                a += 1;
            }
            for (int i = c + 1; arr[i] == value; i++) {
                a += 1;
            }
            return a;
        }
    }
    return 0;
}
