#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
	int key;
	int value;
};

class HashTable{
private:
	Node arr[200];
	int maxsize;
	int currentsize;
public:
	HashTable();
	int HashCode(int key);
	void insertNode(int key, int value);
	int get(int key);
	bool isEmpty(int index);
};

HashTable::HashTable(){
	maxsize = 200;
	currentsize = 0;
	Node NuLl = {0,0};
	for(int i = 0; i < maxsize; i++){
		arr[i] = NuLl;
	}
}

bool HashTable::isEmpty(int index){
  if (this->arr[index].key == 0){
    return true;
  }
  else{
  	return false;
  }
}

int HashTable::HashCode(int key){
	return key%maxsize;
}

void HashTable::insertNode(int key, int value){
	 int x = HashCode(key);
     bool empty = isEmpty(x);
     while (empty != 1) {
       x++;
       empty = isEmpty(x);
     }
     Node node = {key, value};
     arr[x] = node;
     cout << "inserted at position "<< x <<endl;
 }

int HashTable::get(int key){//getter
      int x = HashCode(key);
      bool z = false;
      if (this->arr[x].key == key){
      	cout<<x<<endl;
        return x;
        z = true;
      }
      else {
        while (this->arr[x].key != key && x < maxsize){
          x++;
        }
        if(x==maxsize){
        	if(!z){
    		cout<<"key not found"<<endl;
    		return -1;
    	}
    }
        cout<<x<<endl;
        z=true;
       return x;
    }
}

int main(){
  HashTable hash;//testing
  hash.insertNode(100, 8);
  hash.insertNode(100, 9);
  hash.insertNode(300, 11);
  hash.insertNode(300, 14);
  hash.get(300);
  hash.get(10);
  hash.get(100);
  hash.get(8);
  return 0;
}