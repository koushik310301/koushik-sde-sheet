#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* mergeLists(Node* a, Node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    Node* nh=NULL;
    Node* tail=NULL;
    if(a->data < b->data){
            nh=a;
            tail=a;
            a=a->child;
        }
        else{
            nh=b;
            tail=b;
            b=b->child;
        }
        
        while(a!=NULL && b!=NULL){
            if(a->data < b->data){
                tail->child=a;
                tail=a;
                a=a->child;
            }
            else{
                tail->child=b;
                tail=b;
                b=b->child;
            }
        }
        if(a==NULL){
         tail->child=b;
     }
     if(b==NULL){
         tail->child=a;
     }
     return nh;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    vector<Node*> v;
    Node* ptr=head;
    while(ptr!=NULL){
        v.push_back(ptr);
        ptr=ptr->next;
    }
    Node* new_head=NULL;
    for(int i=0;i<v.size();i++){

        new_head=mergeLists(new_head,v[i]);
    }
    return new_head;
}
