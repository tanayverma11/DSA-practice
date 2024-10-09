#include<stdio.h>

int getMax(int arr[], int n){
    int max=-1;
    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int pos){
    int count[10] = {0};
    int helper[n];    
    int i=0;
    // filling the count array with frequency of digits
    for(i=0; i<n; i++){
        ++count[ (arr[i]/pos) % 10 ];
    }
    // updating the count array, to reflect the actual position
    for(i=1; i<10; i++){
        count[i] = count[i] + count[i-1];
    }
    // building the helper array
    for(i=n-1; i>=0; i--){
        helper[ --count[(arr[i]/pos) % 10] ] = arr[i];
    }
    // copying the elements from helper to arr(original array)
    for(i=0; i<n; i++){
        arr[i] = helper[i];
    }
}

void radixSort(int arr[], int n){
    int max = getMax(arr,n);
    for(int pos=1; max/pos>0; pos=pos*10){
        countSort(arr,n,pos);
    }
}

int main(){
    int n=0;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Before sorting:\n");
    for(int i=0; i<n; i++){
        printf("%d  ",arr[i]);
    }

    radixSort(arr,n);

    printf("\nAfter sorting:\n");
    for(int i=0; i<n; i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}