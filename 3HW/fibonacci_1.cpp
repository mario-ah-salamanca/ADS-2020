#include <bits/stdc++.h>
#include <chrono>
using namespace std;

unsigned int fibonacci(unsigned int n){
	if(n<2){
		return n;
	}
	else{
		return fibonacci(n-1) + fibonacci(n-2);
	}

}

int main(){
	unsigned int n = 0 ;

	for(n ; n < 100 ; n++ ){
		for(int i = 0 ; i < 51 ; i++){
			auto start = chrono::steady_clock::now();
			//star measure
			fibonacci(n);
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