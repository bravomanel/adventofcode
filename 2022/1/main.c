#include <stdio.h>
#include <stdlib.h>

void main()
{
   // char text = getline("testinput.txt");
   FILE *input = fopen("input.txt", "r");
   if (input == NULL)
   {
      perror("Unable to open the file");
      exit(1);
   }

   int sum = 0, bigger = 0, bigger2 = 0, bigger3 = 0;
   char line[100];
   while (fgets(line, sizeof(line), input))
   {
      int value = atoi(line);
      // printf("my value is %d, my sum is %d and my bigger is %d\n", value, sum, bigger);
      if (value > 100)
      {
         sum += value;
      }
      else
      {
         if (sum > bigger3)
         {
            if (sum > bigger2)
            {
               if (sum > bigger)
               {
                  bigger3 = bigger2;
                  bigger2 = bigger;
                  bigger = sum;
               } else {
                  bigger3 = bigger2;
                  bigger2 = sum;
               }
            }
            else
            {
               bigger3 = sum;
            }
         }
         // printf("my sum is %d and my bigger is %d\n", sum, bigger);
         sum = 0;
      }
   }
   printf("\nResultado Final\n");
   printf("\nMinha soma eh %d", sum);
   printf("\nMy bigger value is %d", bigger);
   printf("\nMy bigger2 value is %d", bigger2);
   printf("\nMy bigger3 value is %d", bigger3);
   printf("\nMy bigger SUMs is %d", (bigger + bigger2 + bigger3));
   
}
