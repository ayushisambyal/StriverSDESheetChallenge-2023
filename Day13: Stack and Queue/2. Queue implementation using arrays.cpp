class Queue {
    vector<int> v;
    int fro=0, rear=0;
public:
    Queue() {
        // Implement the Constructor
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return fro == rear;
    }

    void enqueue(int data) {
        v.push_back(data);
        rear++;
    }

    int dequeue() {
        if(fro == rear) return -1;
        int ans = v[fro];
        fro++;
        return ans;
    }

    int front() {
        if(fro == rear) return -1;
        return v[fro];
    }
};
