class MovingAverage {
public:
    /** Initialize your data structure here. */
    int capacity;
    int size;
    double avg;
    queue<int> data;
    MovingAverage(int _capacity) {
        capacity = _capacity;
        size = 0;
        avg = 0;
    }
    
    double next(int val) {
        // cout << "size:" << size << "avg:" << avg << endl;
        if(data.size() == capacity){
            int remove = data.front();
            // cout << "remove:" << remove << endl;
            data.pop();
            data.push(val);
            double sum = size * avg - remove + val;
            avg = sum / size;
            return avg;
        }else{
            double sum = size * avg + val;
            size++;
            avg = sum / size;
            data.push(val);
            return avg;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */