public class Solution
{
    public int[] SortEvenOdd(int[] nums)
    {
        for (int i = 0; i < nums.Length; i++)
        {
            if (i % 2 != 0)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (j % 2 != 0)
                    {
                        if (nums[i] < nums[j])
                        {
                            int temp = nums[i];
                            nums[i] = nums[j];
                            nums[j] = temp;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < nums.Length; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (j % 2 == 0)
                    {
                        if (nums[i] > nums[j])
                        {
                            int temp = nums[i];
                            nums[i] = nums[j];
                            nums[j] = temp;
                        }
                    }
                }
            }
        }
        return nums;
    }
}