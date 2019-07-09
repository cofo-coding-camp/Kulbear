class MedianFinder
{
private:
    priority_queue<int, vector<int>, greater<int>> r_;
    priority_queue<int, vector<int>, less<int>> l_;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num)
    {
        // step 1: add number
        if (l_.empty() || num <= l_.top())
        {
            l_.push(num);
        }
        else
        {
            r_.push(num);
        }

        // step 2: balance l_ and r_
        if (l_.size() < r_.size())
        {
            l_.push(r_.top());
            r_.pop();
        }
        else if (l_.size() - r_.size() == 2)
        {
            r_.push(l_.top());
            l_.pop();
        }
    }

    double findMedian()
    {
        if (l_.size() > r_.size())
        {
            return static_cast<double>(l_.top());
        }
        else
        {
            return (static_cast<double>(l_.top()) + r_.top()) / 2;
        }
    }
};