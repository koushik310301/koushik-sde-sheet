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
#include<bits/stdc++.h>
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    stack<int> st;
    LinkedListNode<int>* ptr=head;
    while(ptr!=NULL){
        st.push(ptr->data);
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr!=NULL && st.empty()==false){
        if(ptr->data!=st.top()) return false;
        st.pop();
        ptr=ptr->next;
    }
    return true;
}