#include <bits/stdc++.h>
#include <chrono>
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
    int i = 5000;
    for(int sub = 2; sub < i ; sub = sub + 100){
        int average0[i];
        int average1[i];
        int average2[i];
        int average3[i];
        int average4[i];
        int average5[i];
        int average6[i];
            
        int k=16 ;
        for(int k=0;k < i ;k++){
            average0[k]= rand();
        }
        for(int k=0;k < i ;k++){
            average1[k]= rand();
        }
        for(int k=0;k < i ;k++){
            average2[k]= rand();
        }
            for(int k=0;k < i ;k++){
            average3[k]= rand();
        }
        for(int k=0;k < i ;k++){
            average4[k]= rand();
        }
        for(int k=0;k < i ;k++){
            average5[k]= rand();
        }
        for(int k=0;k < i ;k++){
             average6[k]= rand();
        }

        auto start1_1 = high_resolution_clock::now(); 
        mergeSort(average0, sub ,0, i - 1); 
        auto stop1_1 = high_resolution_clock::now(); 
        auto duration1_1 = duration_cast<microseconds>(stop1_1- start1_1);
        cout << duration1_1.count()<<" ";

        auto start1_2 = high_resolution_clock::now();
        mergeSort(average1, sub ,0, i - 1); 
        auto stop1_2 = high_resolution_clock::now(); 
        auto duration1_2 = duration_cast<microseconds>(stop1_2- start1_2);
        cout << duration1_2.count()<<" ";

        auto start1_3 = high_resolution_clock::now();
        mergeSort(average2, sub ,0, i - 1); 
        auto stop1_3 = high_resolution_clock::now(); 
        auto duration1_3 = duration_cast<microseconds>(stop1_3- start1_3);
        cout << duration1_3.count()<<" ";

        auto start1_4 = high_resolution_clock::now();
        mergeSort(average3, sub ,0, i - 1); 
        auto stop1_4 = high_resolution_clock::now(); 
        auto duration1_4 = duration_cast<microseconds>(stop1_4- start1_4);
        cout << duration1_4.count()<<" ";

        auto start1_5 = high_resolution_clock::now();
        mergeSort(average4, sub ,0, i - 1); 
        auto stop1_5 = high_resolution_clock::now(); 
        auto duration1_5 = duration_cast<microseconds>(stop1_5- start1_5);
        cout << duration1_5.count()<<" ";

        auto start1_6 = high_resolution_clock::now();
        mergeSort(average5, sub ,0, i - 1); 
        auto stop1_6 = high_resolution_clock::now(); 
        auto duration1_6 = duration_cast<microseconds>(stop1_6- start1_6);
        cout << duration1_6.count()<<" ";

        auto start1_7 = high_resolution_clock::now();
        mergeSort(average6, sub ,0, i - 1); 
        auto stop1_7 = high_resolution_clock::now(); 
        auto duration1_7 = duration_cast<microseconds>(stop1_7- start1_7);
        cout << duration1_7.count()<<" "<< endl;

    }
    return 0; 
} 
