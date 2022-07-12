#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here.
    if(head==NULL || k==0) return head;
    LinkedListNode<int>* ptr=head;
    k--;
    while(k--){
        ptr=ptr->next;
    }

    if(ptr->next==NULL){
        head=head->next;
        return head;
    }
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* slow=head;
    while(ptr->next!=NULL){
        prev=slow;
        slow=slow->next;
        ptr=ptr->next;
    }
    prev->next=slow->next;
    //delete slow;
    return head;
}