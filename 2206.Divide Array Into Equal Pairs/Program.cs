public class Solution
{
    public bool DivideArray(int[] nums)
    {
        List<int> list = new List<int>();
        List<int> list1 = new List<int>();
        list1 = nums.ToList();
        int pairs = nums.Length / 2;
        for (int i = 0; i < list1.Count; i++)
        {
            int count = 0;
            for (int j = i + 1; j < list1.Count; j++)
            {
                if (list1[i] == list1[j])
                {
                    count++;
                    list.Add(nums[i]);
                    list.Add(nums[j]);
                    list1.RemoveAt(j);
                    if (count == 1)
                    {
                        break;
                    }
                }
            }
        }
        if (list.Count / 2 == pairs)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}