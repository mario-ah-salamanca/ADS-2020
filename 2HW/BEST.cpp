#include <bits/stdc++.h>
#include <chrono>

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r]
using namespace std::chrono; 
using namespace std; 
 void insertion_sort(int array[] , int l, int r ){
    int i , j; //counter
    int key;
    i = l;
    for(i;i<r ; i++){
        key=array[i];
        j = i-1;
        while( (j>=l) && (key < array[j])  ){
            array[j+1]=array[j];
            j=j-1;
         }
         array[j+1]=key;
     }
     return;
 }
 // Merges two subarrays of array[]. 
// First subarray is array[l..m] 
// Second subarray is array[m+1..r]
using namespace std::chrono; 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[],int sub ,int l, int r) 
{ 
	/* sub is the size k of the sub array in witch
	we will applied insertion sort */
    int size = r - l + 1 ; 
    if(sub <= size){
        insertion_sort(arr, l , r);
    }
    else
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, sub ,l, m); 
        mergeSort(arr, sub ,m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
 
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main() 
{ 

    int i = 10000;
    for(int sub = 500; sub < i ; sub=sub+100){ 
        int Best[i];
        for(int k=0;k < i ;k++){
            Best[k]= rand()%100;
        }
        sort(Best, Best+i);
       	auto start3 = high_resolution_clock::now();

        mergeSort(Best, sub ,0, i - 1);

        auto stop3 = high_resolution_clock::now(); 
		auto duration3 = duration_cast<microseconds>(stop3 - start3);

		cout << duration3.count()<<" "<<endl;
		
    }
    return 0; 
} 
