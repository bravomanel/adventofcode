#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEST_SIZE 64

int findrepeated(char line[])
{
   int lineLength = strlen(line) - 1, value;
   char repeated;

   for (int i = 0; i < (lineLength / 2); i++)
   {
      for (int j = ((lineLength) / 2); j < lineLength; j++)
      {
         if (line[i] == line[j])
         {
            repeated = line[i];
            break;
         }
      }
   }

   if (repeated > 93)
   {
      value = repeated - 96;
   }
   else
   {
      value = repeated - 38;
   }

   return value;
}

int findbadge(char p1[], char p2[], char p3[])
{
   char badge;
   int p1Length = strlen(p1), p2Length = strlen(p2), p3Length = strlen(p3);
   int value = 0;
   for (int i = 0; i < p1Length; i++)
   {
      for (int j = 0; j < p2Length; j++)
      {
         if (p1[i] == p2[j])
         {
            for (int k = 0; k < p3Length; k++)
            {
               if (p1[i] == p3[k] && p2[j] == p3[k])
               {
                  badge = p1[i];
                  i = 100;
                  j = 100;
                  k = 100000;
               }
            }
         }
      }
   }

   if (badge > 93)
   {
      value = badge - 96;
   }
   else
   {
      value = badge - 38;
   }

   return value;
}

void main()
{
   FILE *input = fopen("input.txt", "r");
   if (input == NULL)
   {
      perror("Unable to open the file");
      exit(1);
   }

   char line[80], p1[80], p2[80], p3[80];
   int priorities = 0, index = 0;

   // FIRST PART OF CHALLENGE
   // while (fgets(line, sizeof(line), input))
   // {
   //    priorities += findrepeated(line);
   // }

   // SECOND PART OF CHALLENGE
   while (fgets(line, sizeof(line), input))
   {
      index++;
      if (index % 3 == 1)
      {
         strcpy(p1, line);
      }
      else if (index % 3 == 2)
      {
         strcpy(p2, line);
      }
      else
      {
         strcpy(p3, line);
         priorities += findbadge(p1, p2, p3);
      }
   }

   printf("The final priorities sum is %d\n", priorities);
}