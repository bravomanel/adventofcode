#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fullOverlap(int first[2], int second[2], int fullOverlapCounter)
{
   if (first[0] == second[0])
   {
      fullOverlapCounter++;
   }
   if (first[0] < second[0] && first[1] >= second[1])
   {
      fullOverlapCounter++;
   }
   if (first[0] > second[0] && first[1] <= second[1])
   {
      fullOverlapCounter++;
   }
   return fullOverlapCounter;
}

int overlap(int first[2], int second[2], int overlapCounter)
{
   if (first[1] >= second[0] && first[0] <= second[1] || first[0] <= second[1] && first[1] >= second[0])
   {
      overlapCounter++;
   }
   return overlapCounter;
}

int main()
{
   FILE *input = fopen("input.txt", "r");
   if (input == NULL)
   {
      perror("Unable to open the file");
      exit(1);
   }

   char line[20];
   int fullOverlapCounter = 0;
   int overlapCounter = 0;

   while (fgets(line, sizeof(line), input))
   {
      char *a = strtok(line, ",");
      char *b = strtok(NULL, ",");
      int first[2], second[2];
      first[0] = atoi(strtok(line, "-"));
      first[1] = atoi(strtok(NULL, "-"));
      second[0] = atoi(strtok(b, "-"));
      second[1] = atoi(strtok(NULL, "-"));

      fullOverlapCounter = fullOverlap(first, second, fullOverlapCounter);
      overlapCounter = overlap(first, second, overlapCounter);
   }
   printf("counter: %d\n", fullOverlapCounter);
   printf("counter: %d\n", overlapCounter);

   return 0;
}