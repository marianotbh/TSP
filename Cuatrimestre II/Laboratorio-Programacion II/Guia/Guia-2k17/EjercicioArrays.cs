using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            Random r = new Random();

            Console.WriteLine("\n---------------------------------------------------------------------");
            Console.WriteLine("Array");

            int[] nums = new int[20];

            do
            {
                nums[i] = r.Next(-100,100);
                if (nums[i] != 0)
                    i++;
            }while(i < 20);

            foreach (int num in nums)
                Console.Write("{0} ", num);

            bool flagSwap;
            int auxSwap;

            do
            {
                flagSwap = false;
                for (int j = 0; j < nums.Length-1; j++)
                {
                    if (nums[j] < nums[j + 1])
                    {
                        auxSwap = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = auxSwap;
                        flagSwap = true;
                    }
                }
            } while (flagSwap);

            Console.WriteLine("\nPositivos decreciente");
            foreach (int num in nums)
                if(num > 0)
                    Console.Write("{0} ", num);

            Console.WriteLine("\nNegativos ascendente");
            for (int j = nums.Length-1; j >= 0; j--)
            {
                if (nums[j] < 0)
                    Console.Write("{0} ", nums[j]);
            }                

            Console.ReadKey();
            Console.WriteLine("\n---------------------------------------------------------------------");
            Console.WriteLine("\nLista");

            List<int> numsList = new List<int>();
            i = 0;
            do
            {
                int aux = r.Next(-100, 100);
                if (aux != 0)
                {
                    numsList.Add(aux);
                    i++;
                }
            } while (i < 20);

            foreach (int num in numsList)
                Console.Write("{0} ", num);

            Console.WriteLine("\nLista positivos decreciente");
            numsList.Sort();
            numsList.Reverse();
            foreach (int num in numsList)
            {
                if(num > 0)
                    Console.Write("{0} ", num);
            }

            Console.WriteLine("\nLista negativos ascendente");
            numsList.Sort();
            foreach (int num in numsList)
            {
                if (num < 0)
                    Console.Write("{0} ", num);
            }
                
            Console.ReadKey();
            Console.WriteLine("\n---------------------------------------------------------------------");
            Console.WriteLine("\nFila");

            Queue<int> numsQ = new Queue<int>();
            i = 0;

            do
            {
                numsQ.Enqueue(nums[i]);
                i++;
            } while (i < 20);

            foreach (int num in numsQ)
                Console.Write("{0} ", num);

            Console.WriteLine("\nQ positivos descendente");
            foreach (int num in numsQ)
                if (num > 0)
                    Console.Write("{0} ", num);

            Console.WriteLine("\nQ negativos ascendente");
            i = 0;
            do
            {
                numsQ.Enqueue(nums[i]);
                i++;
            } while (i < 20);

            foreach (int num in numsQ)
                if (num < 0)
                    Console.Write("{0} ", num);            

            Console.ReadKey();
            Console.WriteLine("\n---------------------------------------------------------------------");
            Console.WriteLine("\nPila");

            Stack<int> numsStack = new Stack<int>();
            i = 0;

            do
            {
                int aux = r.Next(-100, 100);
                if (aux != 0)
                {
                    numsStack.Push(aux);
                    i++;
                }
            } while (i < 20);

            foreach (int num in numsStack)
                Console.Write("{0} ", num);

            Console.ReadKey();
        }
    }
}
