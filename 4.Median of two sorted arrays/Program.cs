public class Solution
{
    static void fillTheListAndSort(List<int> merged, int[] arr1, int[] arr2)
    {
        for (int i = 0; i < arr1.Length; i++)
        {
            merged.Add(arr1[i]);
        }
        for (int i = 0; i < arr2.Length; i++)
        {
            merged.Add(arr2[i]);

        }

        for (int i = 0; i < merged.Count; i++)
        {
            for (int j = 0; j < merged.Count; j++)
            {
                if (merged[i] < merged[j])
                {
                    var temp = merged[i];
                    merged[i] = merged[j];
                    merged[j] = temp;

                }

            }
        }
    }
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {

        var mergedList = new List<int>();
        var median = 0.0;

        fillTheListAndSort(mergedList, nums1, nums2);
        if (mergedList.Count % 2 != 0)
        {
            median = mergedList[mergedList.Count / 2];
        }
        else
        {
            median = (double)(mergedList[mergedList.Count / 2 - 1] + (double)mergedList[mergedList.Count / 2]) / 2;
        }

        return median;

    }
}