#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
vector<int> MergeSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Write your code here.
     int m=nums1.size();
        int n=nums2.size();
    vector<int> ans;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
}
void fun(Node<int>* head,vector<int>& v){
    Node<int>* ptr=head;
    while(ptr!=NULL){
        v.push_back(ptr->data);
        ptr=ptr->next;
    }
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL) return second;
    if(second==NULL) return first;
    vector<int> v1;
    vector<int> v2;
    fun(first,v1);
    fun(second,v2);
    v1=MergeSortedArrays(v1,v2);
    Node<int>* ptr=first;
    int ind=0;
    while(ptr->next!=NULL){
        ptr->data=v1[ind];
        ptr=ptr->next;
        ind++;
    }
    ptr->next=second;
    while(ptr!=NULL){
        ptr->data=v1[ind];
        ptr=ptr->next;
        ind++;
    }
    return first;
    
}
