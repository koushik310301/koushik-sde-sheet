bool isValidParenthesis(string exp)
{
    // Write your code here.
    stack<char> st;
    //st.push(exp[0]);
    for(int i=0;i<exp.length();i++){
         if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
             st.push(exp[i]);
         }
        else{
             if(st.empty()==false){
                 if(exp[i]==')' && st.top()=='(') st.pop();
                 else if(exp[i]=='}' && st.top()=='{') st.pop();
                 else if(exp[i]==']' && st.top()=='[') st.pop();
                 else{
                     st.push(exp[i]);
                 }
             }
            else{
                st.push(exp[i]);
            }
        }
    }
    return st.empty()==true;
}