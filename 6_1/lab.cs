using System;

namespace sharp_6LAB
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            char[] array = new char [10];
            int[] array_1 = new int [20];
            int tmp = 1, tmp1 = 0;
            Console.WriteLine("Input string");
            foreach (var s in array)
            {
                array[s] = Convert.ToChar(Console.ReadLine());
            }
            for (var i = 0; i < array.Length; i++)
            {
                if (array_1[i] == array_1[i + 1]) tmp++;
                else
                {
                    array_1[tmp1] = tmp;
                    tmp1++;
                    tmp = 1;
                }
                
            }

            int max, index = 0;
            max = array_1[0];
            for (int i = 0; i < array_1.Length; i++)
            {
                if(max < array_1[i]){
                    max = array_1[i];
                    index = i;
                };
            }
            if ((array[0] == '1') && ((index % 2 == 0) || index == 0))
            {
                for (int i = 0; i < max; i++) Console.Write("1");
            }
            if ((array[0] == '1') && (index % 2 == 1)) {
                for (int i = 0; i < max; i++) Console.Write("0");
            }
            if ((array[0] == '0') && (index % 2 == 0)) {
                for (int i = 0; i < max; i++) Console.Write("0");
            }
            if ((array[0] == '0') && (index % 2 == 1)) {
                for (int i = 0; i < max; i++) Console.Write("1");
            }
            Console.Write('S');

        }
    }
}
