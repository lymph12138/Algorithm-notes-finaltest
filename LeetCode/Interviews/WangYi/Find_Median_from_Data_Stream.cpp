/*
295
*/
class MedianFinder {
private:
    priority_queue<int> minHeap;
    priority_queue<int,vector<int>, greater<int>> maxHeap;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(minHeap.empty() || minHeap.top()>num)
            minHeap.push(num);
        else    maxHeap.push(num);
        if(minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size())
            return (double(maxHeap.top()+minHeap.top()))/2;
        else if(maxHeap.size()>minHeap.size())  
            return double(maxHeap.top());
        else    return double(minHeap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */