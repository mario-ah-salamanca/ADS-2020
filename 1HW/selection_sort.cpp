#include <algorithm> 
#include <chrono> 
#include <iostream> 
using namespace std; 
using namespace std::chrono; 
void selection_sort(int Arr[], int n){
	//define variables
	int i , j , min_indx;		// 1
	i=0; 						// 1
	int temp;					// 1
	//begining of the algorithm
	for(i; i < n - 1 ; i++){ 	//n
		// I assume that the smaller value is i 
		min_indx = i;//
		for(j = i + 1 ; j < n ; j++){  // (n/2)(n+1) +1
			if(Arr[j] < Arr[min_indx]){//(n/2)(n+1) +1
				min_indx = j; 
			}
		}
		temp=Arr[i]; //n
		Arr[i]=Arr[min_indx];//n
		Arr[min_indx]=temp;//n
	}
	return; 
	/* total sum of process 2((n/2)(n+1)+1)+4n+3
		but for runing time we usuallu take the highest value in this case (n/2)(n+1)
		so we have a (n^2)
	*/
}
// small fuction because im lazy to do it in the main

void worst_case(int arr[], int size, int worst[] ) 
{ 
    int i , j;
    j=0; 
    for (i=size-1; i >= 0; i--) {
    	worst[i] = arr[j];
    	j++;
    }
    return;
} 
void avere(int arr[], int size, int average[]){
	 int i;
	 for (i=0; i < size; i++) {
	 	average[i]=arr[i];
	 }
	 return;        
}

void best_case(int arr[], int size, int best[]){
	 int i;
	 for (i=0; i < size; i++) {
	 	best[i]=arr[i];
	 }
	 return;        
}


int main(){
 	for(int i= 1000; i < 100000; i = i + 1000 ){ 	
	 	int array[i];
	 	int average[i];
	 	int worst[i];
	 	int best[i];
 		for(int k=0;k < i ;k++){
 			array[k]= rand()%100;
		}


		avere(array,i,average);
		//average case

		auto start1 = high_resolution_clock::now(); 
		selection_sort(average,i);
		auto stop1 = high_resolution_clock::now(); 
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		cout << duration1.count()<<" ";





		//worst Case
		worst_case(array,i,worst);
		auto start2 = high_resolution_clock::now(); 
		selection_sort(worst,i);
		auto stop2 = high_resolution_clock::now(); 
		auto duration2 = duration_cast<microseconds>(stop2 - start2);
		cout << duration2.count()<<" ";



		//Best Case 
		best_case(array,i,best);
		auto start3 = high_resolution_clock::now(); 
		selection_sort(best,i);
		auto stop3 = high_resolution_clock::now(); 
		auto duration3 = duration_cast<microseconds>(stop3 - start3);
		cout << duration3.count()<<" "<<endl;


 	}

	return 0;
}
