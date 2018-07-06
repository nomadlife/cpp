// p079 

class Problem79B
{
    static int[] log = {319,680,...,716};

    public static void Solve()
    {
        ArrayList digits = new ArrayList();
        for(int i=0; i<log.Length; i++)
        {
            int n = log[i];
            for(int j=0; j<3; j++)
            {
                if(!digits.Contains(n%10)) digits.Add(n%10);
                n /= 10;
            }
        }

        for(int i=0; i<log.Length; i++)
        {
            // digits
            int d0 = (log[i]/100);
            int d1 = (log[i]/10)%10;
            int d2 = log[i]%10;

            // offsets
            int o0 = digits.IndexOf(d0);
            int o1 = digits.IndexOf(d1);
            int o2 = digits.IndexOf(d2);

            // check if digits are in right order
            // if not, swap them
            if(o1>=0 && o0>o1)
            {
                digits[o0] = d1;
                digits[o1] = d0;
                // update o1 for next check
                o1 = o0;
            }
            if(o2>=0 && o1>o2)
            {
                digits[o1] = d2;
                digits[o2] = d1;
            }
        }

        for(int i=0; i<digits.Count; i++)
            Console.Write(digits[i]);
        Console.WriteLine();
    }
}