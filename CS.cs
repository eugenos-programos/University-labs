using System;
namespace first_program
{
    static class My_First_Class_In_C_sharp

    {
        public static void Main()
        {
            Console.Write("Hello,world\n");
            char[] array_of_string = new char[5];
            for (int i = 0; i < 5; i++)
            {
                array_of_string[i] = Convert.ToChar(Console.Read());
            }
            Console.WriteLine("ARRAY-");
            char tmp = ' ';
            for (int i = 0; i < 5; i++)
            {
                tmp = array_of_string[i];
                for (int j = 0; j < 5; j++)
                {
                    if (tmp > array_of_string[i])
                    {
                        char tmp1 = ' ';
                        tmp1 = array_of_string[i];
                        array_of_string[i] = tmp;
                        tmp = tmp1;
                    }
                }
            }
            for(int i = 0;i<5;i++){Console.WriteLine($" {array_of_string[i]} ");}
        }
    }
}
