using System.Text;

public class Solution
{
    static string concatString(string input)
    {
        var concatStr = new StringBuilder();

        for (int i = 0; i < input.Length; i++)
        {
            if (char.IsDigit(input[i]) || char.IsLetter(input[i]))
            {
                concatStr.Append(input[i]);
            }
        }

        return concatStr.ToString().ToLower();
    }
    public bool IsPalindrome(string s)
    {
        var concatedStr = concatString(s);
        var str2 = new StringBuilder();

        for (int i = concatedStr.Length - 1; i >= 0; i--)
        {
            str2.Append(concatedStr[i]);
        }

        for (int i = 0; i < concatedStr.Length; i++)
        {
            if (concatedStr[i] != str2[i])
            {
                return false;
            }
        }
        return true;
    }
}