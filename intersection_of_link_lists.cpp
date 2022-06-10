#include <bits/stdc++.h> 
/****************************************************************
 
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

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_map<Node*,int> mp;
    
    while(firstHead!=NULL && secondHead!=NULL){
        if(mp[firstHead]!=0) return firstHead->data;
        if(mp[secondHead]!=0) return secondHead->data;
        
        mp[firstHead]=1;
        mp[secondHead]=1;
        firstHead=firstHead->next;
        secondHead=secondHead->next;
    }
    
    while(firstHead!=NULL){
        if(mp[firstHead]!=0) return firstHead->data;
        mp[firstHead]=1;
        firstHead=firstHead->next;
    }
    
    while(secondHead!=NULL){
        if(mp[secondHead]!=0) return secondHead->data;
        mp[secondHead]=1;
        secondHead=secondHead->next;
    }
    
    return -1;
    
}