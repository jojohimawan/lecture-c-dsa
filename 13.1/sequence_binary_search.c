//
// Created by jordan on 5/17/2023.
//
#include <stdio.h>
#define MAX 10

void generateRandom(int []);
void inputArray(int []);
void sequenceSearch(int [], int);
void binarySearch(int [], int);

int main()
{
    int arr_worst[MAX] = {10, 9, 8, 7, 6, 5, 4, 4, 2, 1};
    int arr_sort[MAX] = { 5, 1, 1, 4, 7, 7, 8, 9, 10, 6 };
    int arr_best[MAX] = {1, 5, 5, 5, 5, 5, 7, 8, 9, 10};

    binarySearch(arr_best, 15);

    return 0;
}

void sequenceSearch(int A[], int key)
{
    int i  = 0, count = 0;

    while (i < MAX) {
        if (A[i] == key) {count++;}
        i++;
    }

    if(!count) {
        printf("Key %d tidak ada\n", key);
    } else {
        printf("Key %d ditemukan sebanyak %d\n", key, count);
    }
}

void binarySearch(int A[], int key)
{
    int l = 0, r = MAX - 1, mid = (l + r) / 2, count = 0;

    if(key == A[mid]) {
        count++;
        int decr = mid - 1, incr = mid + 1;
        while(decr >= l) {
            if(A[decr] == key) {count++;}
            decr--;
        }
        while(incr < r) {
            if(A[incr] == key) {count++;}
            incr++;
        }
    } else if(key < A[mid]) {
        r = mid - 1;
        while(l < r) {
            if (A[l] == key) {count++;}
            l++;
        }
    } else {
        l = mid + 1;
        while(l < r) {
            if(A[l] == key) {count++;}
            l++;
        }
    }

    if(!count) {
        printf("Key %d tidak ada\n", key);
    } else {
        printf("Key %d ditemukan sebanyak %d\n", key, count);
    }
}
