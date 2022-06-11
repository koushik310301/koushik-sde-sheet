#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    map<LinkedListNode<int>*,LinkedListNode<int>*> mp;
    LinkedListNode<int>* ptr=head;
    while(ptr!=NULL){
        LinkedListNode<int>* copy= new LinkedListNode<int>(ptr->data);
        mp[ptr]=copy;
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr!=NULL){
        mp[ptr]->next=mp[ptr->next];
        mp[ptr]->random=mp[ptr->random];
        ptr=ptr->next;
    }
    return mp[head];
}
