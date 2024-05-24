class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    int size = nums.size();
    int totalSize = 1 << size;
    std::vector<std::vector<int>> res;
    
    for (int i = 0; i < totalSize; ++i) {
        std::vector<int> subset;
        for (int j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        res.push_back(subset);
    }
    return res;
    }
};
