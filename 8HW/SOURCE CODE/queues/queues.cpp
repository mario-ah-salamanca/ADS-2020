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
	T toop(){
		return top->data;
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
template <class T>
class Queue{
private:
	Stack<T> s1;
	Stack<T> s2;
public:
	    void push(T x) 
	    { 
	        // Move all elements from s1 to s2 
	        while (!s1.isEmpty()) { 
	            s2.push(s1.toop()); 
	            s1.pop(); 
	        } 
	  
	        // Push item into s1 
	        s1.push(x); 
	  
	        // Push everything back to s1 
	        while (!s2.isEmpty()) { 
	            s1.push(s2.toop()); 
	            s2.pop(); 
	        } 
	    } 
	  
	    // Dequeue an item from the queue 
	    T pop() 
	    { 
	        // if first stack is Empty 
	        if (s1.isEmpty()) { 
	            cout << "Q is Empty"; 
	            exit(0); 
	        } 
	  
	        // Return top of s1 
	        T x = s1.toop(); 
	        s1.pop(); 
	        return x; 
	    } 
};


int main(){
    Queue<int> q; 
    q.push(1); 
    q.push(2); 
    q.push(3); 
  
    cout << q.pop() << '\n'; 
    cout << q.pop() << '\n'; 
    cout << q.pop() << '\n'; 

    Queue<double> q; 
    q.push(1.5); 
    q.push(2.9); 
    q.push(3.68); 
  
    cout << q.pop() << '\n'; 
    cout << q.pop() << '\n'; 
    cout << q.pop() << '\n'; 

    
  
    return 0; 
} 
