// Stack class.
class Stack {
    
public:
    vector<int> v;
    int cap;
    Stack(int capacity) {
        // Write your code here.
        cap=capacity;
        
        
    }

    void push(int num) {
        // Write your code here.
        v.push_back(num);
        if(v.size()>cap) v.pop_back();
     }

    int pop() {
        // Write your code here.
        int x=-1;
        if(v.size()!=0){
            x=v.back();
            v.pop_back();
        }
        return x;
    }
    
    int top() {
        // Write your code here.
        if(v.size()!=0) return v.back();
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        return v.empty();
    }
    
    int isFull() {
        // Write your code here.
        return v.size()==cap;
    }
    
};