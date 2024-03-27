public class Solution
{


    int findEl(int[] arr)
    {
        int res = 0;
        for (int i = 0; i < arr.Length; i++)
        {
            res ^= arr[i];
        }
        return res;
    }
    public int SingleNumber(int[] nums)
    {
        int res = findEl(nums);
        return res;



    }
}
