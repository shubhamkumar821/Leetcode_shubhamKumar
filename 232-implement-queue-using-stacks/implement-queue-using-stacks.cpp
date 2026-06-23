class MyQueue {
public:
 stack<int> q1,q2;
    MyQueue() {
        
    }
    
    void push(int x) {
         q1.push(x);
    
        
    }
    
    int pop() {
        int p=0;

           if(q1.size()>0){
            
            while(q1.size()>1){
                q2.push(q1.top());
                q1.pop();
            }
            p=q1.top();
            q1.pop();
            
            while(q2.size()>0){
                q1.push(q2.top());
                q2.pop();
            }
        }
        return p;
        
    }
    
    int peek() {
        int front =0;

         if(q1.size()<1)return 0;
        
         if(q1.size()>0){
            
            while(q1.size()>1){
                q2.push(q1.top());
                q1.pop();
            }
         front=q1.top();
            q1.pop();
            q2.push(front);
            
            while(q2.size()>0){
                q1.push(q2.top());
                q2.pop();
            }
            return front;
        }
        return front;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */