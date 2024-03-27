public class Solution
{

    public int Reverse(int x)
    {
        if (x > Math.Pow(2, 31) - 1 || x < Math.Pow(-2, 31))
        {
            return 0;
        }
        int res = 0;
        while (x != 0)
        {
            int last = x % 10;
            if (res > Int32.MaxValue / 10 || (res == Int32.MaxValue / 10 && last > 7))
            {
                return 0;
            }
            if (res < Int32.MinValue / 10 || (res == Int32.MinValue / 10 && last < -8))
            {
                return 0;
            }
            res = (res * 10) + last;
            x /= 10;
        }
        return res;
    }
}