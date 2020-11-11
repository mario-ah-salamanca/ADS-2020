#include <bits/stdc++.h>
using namespace std;
// reference https://www.geeksforgeeks.org/heap-sort/
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
} 
void max_heapify(int HEAPTIME[], int n, int index) 
{ 
    int raiz = index; // Initialize raiz as root 
    int l = 2*index + 1; // left = 2*index + 1 
    int r = 2*index + 2; // right = 2*index + 2 
  
    // If left child is larger than root 
    if (l < n && HEAPTIME[l] > HEAPTIME[raiz]) 
        raiz = l; 
  
    // If right child is larger than raiz so far 
    if (r < n && HEAPTIME[r] > HEAPTIME[raiz]) 
        raiz = r; 
  
    // If raiz is not root 
    if (raiz != index) 
    { 
        swap(HEAPTIME[index], HEAPTIME[raiz]); 
  
        // Recursively max_heapify the affected sub-tree 
        max_heapify(HEAPTIME, n, raiz); 
    } 
} 

// main function to do heap sort
void HeapSort(int HEAPTIME[], int n) 
{ 
    // Build heap (reHEAPTIMEange HEAPTIMEay) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        max_heapify(HEAPTIME, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(HEAPTIME[0], HEAPTIME[i]); 
  
        // call max max_heapify on the reduced heap 
        max_heapify(HEAPTIME, i, 0); 
    } 
} 



int main(){
	int n = 1 ;
	
	for(n ; n < 10000 ;n = n+ rand()%100){
		cout<<n<< " ";
		int HEAPTIME[n];
		for(int j = 0 ; j < n ; j++){
			HEAPTIME[j] = rand()%100; 
		}
		for(int i = 0 ; i < 10 ; i++){
			auto start = chrono::steady_clock::now();
			//star measure
			HeapSort(HEAPTIME, n);
			//end measure 
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			auto diff_sec = chrono::duration_cast<chrono::nanoseconds>(diff);
			cout << diff_sec.count()<<" ";
		}
		cout<<endl;
	}

	return 0;
}