// Implement class for minStack.
#include<bits/stdc++.h>
class minStack
{
	// Write your code here.
	
	public:
		
		// Constructor
        stack<int> st;
        stack<int> min_stack_element;
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            st.push(num);
            if(min_stack_element.empty()==true){
                min_stack_element.push(num);
            }
            else{
                if(num<min_stack_element.top()){
                    min_stack_element.push(num);
                }
                else{
                    min_stack_element.push(min_stack_element.top());
                }
            }
            
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(st.empty()==true) return -1;
            int x=-1;
            if(st.empty()==false){
                x=st.top();
                st.pop();
                min_stack_element.pop();
            }
            return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            int x=-1;
            if(st.empty()==false){
                x=st.top();
            }
            return x;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(min_stack_element.empty()==true) return -1;
            return min_stack_element.top();
            
		}
};