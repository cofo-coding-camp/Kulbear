class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {   
            // no way to have postives sum to 0
            if (nums[i] > 0)
            {
                break;
            }

            // duplicate entries in the array
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                // get one answer!
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        --r;
                    }
                }
                // we need the start point to be larger
                else if (nums[i] + nums[l] + nums[r] < 0)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }
        return ans;
    }
};