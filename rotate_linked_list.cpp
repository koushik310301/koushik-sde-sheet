#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    Node* ptr=head;
    deque<int> dq;
    int n=0;
    while(ptr!=NULL){
        dq.push_back(ptr->data);
        ptr=ptr->next;
        n++;
    }
    k=k%n;
    while(k--){
        int x= dq.back();
        dq.pop_back();
        dq.push_front(x);
    }
    ptr=head;
    while(dq.empty()==false){
        ptr->data=dq.front();
        ptr=ptr->next;
        dq.pop_front();
    }
    
    return head;
    
}