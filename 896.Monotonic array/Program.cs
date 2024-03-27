public class Solution
{
    public bool IsMonotonic(int[] nums)
    {
        bool increasing = true;
        bool decreasing = true;
        for (int i = 0; i < nums.Length - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                decreasing = false;
            }
            else if (nums[i] < nums[i + 1])
            {
                increasing = false;
            }

            if (!increasing && !decreasing)
            {
                return false;
            }


        }
        return true;
    }
}