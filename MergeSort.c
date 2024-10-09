#include<stdio.h>

void mergeArray(int a[], int b[], int arr[], int m, int n){
    int i=0, j=0, k=0;
    while (i < m && j < n) {
        if (a[i] <= b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
    while (i < m){
        arr[k++] = a[i++];
    }
    while (j < n){
        arr[k++] = b[j++];
    }
}

void mergeSort(int nums[], int n){
    if (n < 2) return; // Base case

    int mid = n / 2;
    int a[mid];
    int b[n - mid];
    for(int i = 0; i < mid; i++){
        a[i] = nums[i];
    }
    for(int i = mid; i < n; i++){
        b[i - mid] = nums[i];
    }
    //magic
    mergeSort(a, mid);
    mergeSort(b, n - mid);
    //merge the two sorted subarrays
    mergeArray(a, b, nums, mid, n - mid);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int nums[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printArray(nums, n);
    mergeSort(nums, n);
    printArray(nums, n);
    return 0;
}
