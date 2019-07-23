class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2; // overflow
            if (nums[mid] == target)
            {
                return mid;
            }
            // nums = [2 2 3 4 0 1] and mid = 3, so nums[mid] == 4
            // target = 2
            // the first half is sorted
            else if (nums[l] <= nums[mid])
            {
                // target in the first half, shrink the right boundary
                if (target < nums[mid] && target >= nums[l])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            // nums = [7 8 0 1 2 3] and mid = 3, so nums[mid] == 1
            // target = 2
            // the second half is sorted
            else if (nums[mid] <= nums[r])
            {
                if (target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};