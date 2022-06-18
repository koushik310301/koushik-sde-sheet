class Queue {
public:
    vector<int> v;
    int f;
    Queue() {
        // Implement the Constructor
        f=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return v.empty();
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        v.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(v.size()==0) return -1;
        int x=v.front();
        for(int i=1;i<v.size();i++){
            swap(v[i-1],v[i]);
        }
        v.pop_back();
        return x;
    }

    int front() {
        // Implement the front() function
        if(v.size()==0) return -1;
        return v.front();
    }
};