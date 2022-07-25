// #include <bits/stdc++.h> 
// /****************************************************************

//     Following is the class structure of the Node class:

//         class Node
//         {
//         public:
// 	        int data;
// 	        Node *next;
// 	        Node(int data)
// 	        {
// 		        this->data = data;
// 		        this->next = NULL;
// 	        }
//         };

// *****************************************************************/

// Node *getListAfterReverseOperation(Node *head, int n, int b[]){
// 	// Write your code here.
//     Node* ptr=head;
//     vector<vector<int>> v;
//     vector<int> tmp;
//     int k=0;
//     while(ptr!=NULL){
//         tmp.push_back(ptr->data);
//         if(tmp.size()==b[k]){
//             reverse(tmp.begin(),tmp.end());
//             v.push_back(tmp);
//             tmp.clear();
//             k++;
//         }
//         ptr=ptr->next;
//     }
//     if(tmp.size()>0){
//         if(k!=n){
//             reverse(tmp.begin(),tmp.end());
//         } 
//         v.push_back(tmp);
//     }
//     ptr=head;
//     for(auto ls : v){
//         for(int i : ls){
//             ptr->data=i;
//             ptr=ptr->next;
//         }
//     }
//     return head;
// }
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
// Write your code here.
   Node *dummy = new Node(0);
   dummy->next = head;
   
   Node *pre = dummy;
   Node *cur = dummy;
   Node *nex = dummy;
   
   int count = 0;    
   while(cur->next != NULL){
       cur = cur->next;
       count++;
   }
   
   int j = 0;
   while(count>0 && j<n){
       cur = pre->next;
       nex = cur->next;
       int x = (b[j]<=count) ? b[j] : count;
       if(x==0){
           j++;
           continue;
       }
       for(int i=1;i<x;i++){
           cur->next = nex->next;
           nex->next = pre->next;
           pre->next = nex;
           nex = cur->next;
       }
       pre = cur;
       count -= b[j];
       j++;
   }
   return dummy->next;
}