#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
	Node* a = new Node(data);	
    if(head == NULL){
    	return a;
	}
	a->next = head;
	return a;
}

// print the list content on a line
void print(Node* head) {
	Node* h = head;
	while(h!= NULL){
		cout << h->data << " ";
		h = h->next;
	}
   	cout << endl;	
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL){
    	next = current->next;
    	current->next = prev;
    	prev = current;
    	current = next;
	}
	
	head = prev;
	return head;
}
  
int main() {
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
