class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // template<
        //     class T,
        //     class Container = std::vector<T>,
        //     class Compare = std::less<typename Container::value_type>
        // > class priority_queue;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};