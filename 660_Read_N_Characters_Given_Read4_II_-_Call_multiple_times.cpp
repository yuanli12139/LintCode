/*
660. Read N Characters Given Read4 II - Call multiple times
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Notice
The read function may be called multiple times.


Author: Yuan Li
Date: 9/17/2018 
Difficulty: Hard
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    Solution() {
        buffer_ = new char[4];
        head_ = 0;
        tail_ = 0;
    } 
    
    ~Solution() {
        delete [] buffer_;
    }
     
    int read(char *buf, int n) {
        // Write your code here
        int i = 0;
        while (i < n) {
            if (head_ == tail_) { // empty buffer/queue
                head_ = 0;
                tail_ = read4(buffer_);
                if (tail_ == 0) { // nothing to read
                    break;
                }
            }
            while (i < n && head_ < tail_) {
                buf[i++] = buffer_[head_++];
            }
        }
        return i;
    }
    
  private:
    char *buffer_;
    int head_;
    int tail_;
};

