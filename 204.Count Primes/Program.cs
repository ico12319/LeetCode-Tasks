public class Solution
{

    static void fillTheList(List<bool> seq, int n)
    {
        for (int i = 0; i < n; i++)
        {
            seq.Add(false);
        }
    }


    static void markAsNotPrime(List<bool> arr, int curr)
    {
        int toMark = 2 * curr;
        while (toMark < arr.Count)
        {
            arr[toMark] = true;
            toMark += curr;
        }
    }
    static void sieve(List<bool> arr, List<int> seq, int n)
    {
        for (int i = 2; i < arr.Count; i++)
        {
            if (!arr[i] && i < n)
            {
                seq.Add(i);
                markAsNotPrime(arr, i);
            }
        }
    }
    public int CountPrimes(int n)
    {
        var toPrint = new List<int>();
        var arr = new List<bool>();
        fillTheList(arr, n);
        sieve(arr, toPrint, n);
        var count = toPrint.Count;
        return count;
    }
}
