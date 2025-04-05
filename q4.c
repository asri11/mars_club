#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define WINDOW_SIZE 3

// Utility to swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Sort array (for median)
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Muchiko Filter - Moving Average
void muchiko_filter(int *input, int *output, int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0, count = 0;
        for (int j = i - WINDOW_SIZE / 2; j <= i + WINDOW_SIZE / 2; j++) {
            if (j >= 0 && j < n) {
                sum += input[j];
                count++;
            }
        }
        output[i] = sum / count;
    }
}

// Sanchiko Filter - Median Filter
void sanchiko_filter(int *input, int *output, int n) {
    for (int i = 0; i < n; i++) {
        int temp[WINDOW_SIZE];
        int count = 0;
        for (int j = i - WINDOW_SIZE / 2; j <= i + WINDOW_SIZE / 2; j++) {
            if (j >= 0 && j < n)
                temp[count++] = input[j];
        }
        bubble_sort(temp, count);
        output[i] = temp[count / 2];
    }
}

// Read log.txt and store numbers in arr, returns count
int read_log(const char *filename, int *arr) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("File opening failed");
        return -1;
    }
    int count = 0;
    while (fscanf(fp, "%d", &arr[count]) == 1)
        count++;
    fclose(fp);
    return count;
}

// Display array
void print_array(const char *label, int *arr, int n) {
    printf("%s:\n", label);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

int main() {
    int original[MAX], muchiko[MAX], sanchiko[MAX], hybrid[MAX];
    int n = read_log("log.txt", original);
    if (n <= 0) {
        printf("No data to process.\n");
        return 1;
    }

    muchiko_filter(original, muchiko, n);
    sanchiko_filter(original, sanchiko, n);

    // Hybrid: first Sanchiko, then Muchiko
    int temp[MAX];
    sanchiko_filter(original, temp, n);
    muchiko_filter(temp, hybrid, n);

    // Output
    print_array("Original", original, n);
    print_array("Muchiko Filtered", muchiko, n);
    print_array("Sanchiko Filtered", sanchiko, n);
    print_array("Hybrid Filtered (Sanchiko -> Muchiko)", hybrid, n);

    return 0;
}
