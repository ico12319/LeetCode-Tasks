public class Solution
{
    public int[] SortedSquares(int[] nums)
    {

        int[] result = new int[nums.Length];
        int left = 0;
        int right = nums.Length - 1;
        int index = nums.Length - 1;

        while (left <= right)
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare)
            {
                result[index] = leftSquare;
                left++;
            }
            else
            {
                result[index] = rightSquare;
                right--;
            }
            index--;
        }

        return result;
    }
}