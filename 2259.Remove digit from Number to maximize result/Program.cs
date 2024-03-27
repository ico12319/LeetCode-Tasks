using System.Numerics;

public class Solution
{
    public string RemoveDigit(string number, char digit)
    {
        string str = string.Empty;
        List<BigInteger> list = new List<BigInteger>();
        for (int i = 0; i < number.Length; i++)
        {
            str = number;
            if (str[i] == digit)
            {
                str = str.Remove(i, 1);
                BigInteger result = BigInteger.Parse(str);
                list.Add(result);
            }
        }
        return list.Max().ToString();
    }
}