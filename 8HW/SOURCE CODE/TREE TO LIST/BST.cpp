#include <iostream>

using namespace std;


typedef struct node_tree {

	int data;

	struct node_tree *left;
	struct node_tree *right;
} Node_tree;

typedef struct tree {

	Node_tree *root;
} Tree; 


bool init_tree(Tree *tree) {
	if (NULL == tree) {
		return false;
	}
	if (NULL != tree->root) {
		return false;
	}
	tree->root = NULL;
	return true;
}

Node_tree *new_node(int valor) {
	Node_tree *temp = new Node_tree;
	temp->data = valor;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool add_node(Node_tree *padre, int valor) {
	if (NULL == padre) {
		return false;
	}
	if (padre->data < valor) {
		if (padre->right == NULL) {
			padre->right = new_node(valor);
		} else {
			add_node(padre->right, valor);
		}
	} else {
		if (padre->left == NULL) {
			padre->left = new_node(valor);
		} else {
			add_node(padre->left, valor);
		}
	}	
	return true;
}

bool add_leaf(Tree *tree, int valor) {
	if (NULL == tree) {
		return false;
	}
	if (NULL == tree->root) {
		tree->root = new_node(valor);
		return true;
	}
	return add_node(tree->root, valor);
}

void print_node(Node_tree *padre) {
	if (NULL != padre) {
		print_node(padre->left);
		cout << padre->data << " ";
		print_node(padre->right);
	}
}

void print_tree(Tree *tree) {
	if (NULL == tree) {
		return;
	}
	print_node(tree->root);
}


class linked_list
{
private:
	struct Node_list {

	int data;

	Node_list *next;
	};
    Node_list *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(int n)
    {
        Node_list *tmp = new Node_list;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    bool is_empty(){
    	if(this->head == NULL){
    		return true;
    	}
    	else{
    		return false;
    	}
    }
    void print_list()
	{
		Node_list* temp = this->head;
		while(temp!=NULL)
	         {
	            cout<<temp->data<<endl;
	            temp = temp->next;
	         }
	}
};




//homework 8.2 b solution

void node_tree_to_list(Node_tree *father , linked_list mylist){
	if(NULL != father){
		node_tree_to_list(father->left,mylist);
		mylist.add_node(father->data);
		cout<< "checked ";
		node_tree_to_list(father->right,mylist);
	}
}

void tree_to_list(Tree *tree, linked_list mylist){
	if (NULL == tree) {
		return;
	}
	node_tree_to_list(tree->root,mylist);
}

//end here
int menu() {
	int action;
	cout << endl << endl;
	cout << "Menu:" << endl;
	cout << "--------------------------------------------------" << endl << endl;
	cout << "1) insert data to tree." << endl;
	cout << "2) print tree." << endl;
	cout << "3) move a tree to a list" << endl;
	cout << "4) print list"<<endl;
	cout << "0) close." << endl << endl;;
	cout << "action: ";
	cin >> action;
	return action;
}

int main(void) {
	Tree *miArbol = new Tree;
	linked_list milista;
	int action = 1;
	int valor;
	init_tree(miArbol);
	while (0 != action) {
		action = menu();
		switch (action) {
		case 1:
			cout << "insert an element: ";
			cin >> valor;
			add_leaf(miArbol, valor);
			break;
		case 2:
			print_tree(miArbol);
			break;
		
		case 3:
			tree_to_list(miArbol,milista);
			break;
		case 4:
			milista.print_list();
		}
	}
	return 0;
}