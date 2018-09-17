/*
642. Moving Average from Data Stream
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example
MovingAverage m = new MovingAverage(3);
m.next(1) = 1 // return 1.00000
m.next(10) = (1 + 10) / 2 // return 5.50000
m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
m.next(5) = (10 + 3 + 5) / 3 // return 6.00000


Author: Yuan Li
Date: 7/23/2018 
Difficulty: Easy
*/

class MovingAverage {
  public:
    /*
    * @param size: An integer
    */
    MovingAverage(int size) {
        // do intialization if necessary
        this->size = size;
        sum = 0.0;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        if (q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        
        q.push(val);
        sum += val;
        
        return sum / q.size();
    }

  private:
    queue<int> q;
    int size;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */


// Date: 9/16/2018
// rolling array 
class MovingAverage {
  public:
    /*
    * @param size: An integer
    */
    MovingAverage(int size) {
        // do intialization if necessary
        size_ = size;
        sum_.resize(size_ + 1, 0);
        idx_ = 0;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        ++idx_;
        sum_[mod(idx_)] = sum_[mod(idx_ - 1)] + val;
        if (idx_ - size_ >= 0) {
            return (sum_[mod(idx_)] - sum_[mod(idx_ - size_)]) / size_;
        }
        return sum_[idx_] / idx_;
    }

  private:
    vector<double> sum_;
    int size_;
    int idx_;
    
  private:
    int mod(int n) {
        return n % (size_ + 1);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
 