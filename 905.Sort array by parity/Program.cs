public class Solution
{
    public int[] SortArrayByParity(int[] nums)
    {
        List<int> list = new List<int>();
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] % 2 == 0)
            {
                list.Add(nums[i]);
            }
        }
        for (int j = 0; j < nums.Length; j++)
        {
            if (nums[j] % 2 != 0)
            {
                list.Add(nums[j]);
            }
        }
        nums = list.ToArray();
        return nums;
    }
}