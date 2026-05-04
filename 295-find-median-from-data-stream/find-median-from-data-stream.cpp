class MedianFinder {
public:
    
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    MedianFinder() {}

    void addNum(int num) {
        
        // Step 1: push into left
        left.push(num);

        // Step 2: move largest of left → right
        right.push(left.top());
        left.pop();

        // Step 3: balance sizes
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        
        if(left.size() > right.size()){
            return left.top();
        }
        else{
            return (left.top() + right.top()) / 2.0;
        }
    }
};