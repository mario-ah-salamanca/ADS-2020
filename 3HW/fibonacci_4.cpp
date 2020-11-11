#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void multiplicacion(unsigned long long int matr[2][2], unsigned long long int auxmat[2][2]) 
{ 
  unsigned long long int primero =  matr[0][0]*auxmat[0][0] + matr[0][1]*auxmat[1][0]; 
  unsigned long long int segundo =  matr[0][0]*auxmat[0][1] + matr[0][1]*auxmat[1][1]; 
  unsigned long long int tercero =  matr[1][0]*auxmat[0][0] + matr[1][1]*auxmat[1][0]; 
  unsigned long long int cuarto =  matr[1][0]*auxmat[0][1] + matr[1][1]*auxmat[1][1]; 
  
  matr[0][0] = primero; 
  matr[0][1] = segundo; 
  matr[1][0] = tercero; 
  matr[1][1] = cuarto; 
} 
  
void power(unsigned long long int matr[2][2], unsigned long long int n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  unsigned long long int auxmat[2][2] = {{1,1},{1,0}}; 
  
  power(matr, n/2); 
  multiplicacion(matr, matr); 
  
  if (n%2 != 0) 
     multiplicacion(matr, auxmat); 
} 

unsigned long long int fibonacci(unsigned long long int n) 
{ 
  unsigned long long int matr[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(matr, n-1); 
  
  return matr[0][0]; 
} 
  



int main(){
	unsigned long long int n = 0 ;

	
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