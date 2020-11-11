#include <iostream>
using namespace std;
template <class T>
class Stack{
private:
	struct node
	{
		T data;
		node* sig; // sig = next in spanish
	};
	node* top;
	int size;
	int current_size;
public:
	void display() {
	   node* ptr = new node();
	   if(top==NULL)
	      cout<<"Stack is empty";
	   else {   
	      ptr = top; 
	      cout<<"Stack elements are: ";
	      while (ptr != NULL) { 
	         cout<< ptr->data <<" "; 
	         ptr = ptr->sig; 
	      } 
	   }
	   cout<<endl;
	}
	void push(T element){
		if((size != -1) && (size == current_size)){
			cout<<"stack overflow"<<endl;
		}
		else{
			node *new_node = new node();
			new_node->data = element;
			new_node ->sig = top;
			top = new_node;
			if(size!=-1){
				current_size++;
			}
		}
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack underflow"<<endl;
		}
		else{
			node* temp= top;
			top = top->sig;
			delete(temp); 
			if(size!=-1){
				current_size--;
			}
		}
	}
	bool isEmpty(){
		if(top == NULL ){
			return true;
		}
		else{
			return false;
		}
	}
	Stack(int new_size){
			top = NULL;
			size = new_size;
			current_size=0;
	}
	Stack(){
			top = NULL;
			size = -1;
			current_size=-1;
	}
};



int main(){
	Stack<char> charro(10);//change this to 10 aso you can get the stack overfloww
	Stack<char> culero;
	Stack<int> heh;
	for(int i = 97 ; i < 109 ; i++){
		heh.push(i);
		heh.push(i);
	}
	for(int i = 97 ; i < 109 ; i++){
		charro.push(i);
		culero.push(i);
	}
	charro.display();
	culero.display();
	heh.display();
	for(int i = 0 ; i < 11 ; i++){
		charro.pop();
		culero.pop();
	}
	return 0;
}