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

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    Node* ans=NULL;
    Node* ptr=NULL;
    int sum=0;
    while(l1!=NULL || l2!=NULL){
        int a,b,res;
        if(l1!=NULL){
            a=l1->data;
        }
        else{
            a=0;
        }
        
        if(l2!=NULL){
            b=l2->data;
        }
        else{
            b=0;
        }
        res=a+b+sum;
        sum=0;
        if(res>9){
            res=res-10;
            sum=1;
        }
        
        if(ans==NULL){
            ans=new Node(res);
            ptr=ans;
        }
        else{
            ptr->next=new Node(res);
            ptr=ptr->next;
        }
        
        if(l1!=NULL) l1=l1->next;
        if(l2!=NULL) l2=l2->next;
        
    }
    if(sum!=0){
        ptr->next=new Node(sum);
    }
    return ans;
}