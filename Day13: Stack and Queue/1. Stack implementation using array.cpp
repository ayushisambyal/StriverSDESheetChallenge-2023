// Stack class.
class Stack {
    vector<int> v;
    int capacity;
public:
    
    Stack(int capacity) {
        this->capacity= capacity;
    }

    void push(int num) {
        if(v.size()<capacity){
            v.push_back(num);
        }
    }

    int pop() {
        if(v.size()==0) return -1;
        int ans= v.back();
        v.pop_back();
        return ans;
    }
    
    int top() {
        if(v.size()==0) return -1;
        return v.back();
    }
    
    int isEmpty() {
        return v.size()>0 ? 0 : 1;
    }
    
    int isFull() {
        return v.size()==capacity ? 1:0;
    }
    
};
