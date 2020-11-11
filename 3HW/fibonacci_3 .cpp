#include <bits/stdc++.h>
#include <chrono>
using namespace std;
const long  double Phi = 1.6180339887498948;
const long double rooo_of_5 = 2.2360679775;
unsigned int fibonacci(unsigned int n){
	long double result;
	result = pow(Phi,n) / rooo_of_5;
	return round(result);
	

}
int main(){
	int n;
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