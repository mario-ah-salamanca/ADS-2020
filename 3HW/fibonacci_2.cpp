#include <bits/stdc++.h>
#include <chrono>

using namespace std;
unsigned int fibonacci(unsigned int n) 
{ 
  unsigned int f[n+1]; 
  int i; 
  f[0] = 0;   f[1] = 1;  
  for (i = 2; i <= n; i++) {
      f[i] = f[i-1] + f[i-2]; 
  }
  
  return f[n]; 
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