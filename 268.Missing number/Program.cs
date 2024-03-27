public class Solution
{
    public int MissingNumber(int[] nums)
    {
        int count = 0;
        Array.Sort(nums);
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] == count)
            {
                count++;
            }
        }
        return count;
    }
}