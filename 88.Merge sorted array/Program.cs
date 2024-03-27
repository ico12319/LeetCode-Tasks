public class Solution
{
    public void Merge(int[] nums1, int m, int[] nums2, int n)
    {


        for (int i = m, k = 0; i < nums1.Length; i++, k++)
        {
            nums1[i] = nums2[k];

        }
        Array.Sort(nums1);


    }
}
