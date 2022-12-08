#include <stdio.h>
#include <stdlib.h>

void main()
{
   FILE *input = fopen("input.txt", "r");
   if (input == NULL)
   {
      perror("Unable to open the file");
      exit(1);
   }

   char line[15], opponent, response;
   int score = 0;
   while (fgets(line, sizeof(line), input))
   {
      opponent = line[0];
      response = line[2];

      // FIRST PART OF THE CHALLENGE
      // if (response == 'X')
      // {
      //    score += 1;
      //    if (opponent == 'A')
      //    {
      //       score += +3;
      //    }
      //    else if (opponent == 'B')
      //    {
      //       score += 0;
      //    }
      //    else if (opponent == 'C')
      //    {
      //       score += 6;
      //    }
      // }
      // else if (response == 'Y')
      // {
      //    score += 2;
      //    if (opponent == 'A')
      //    {
      //       score += +6;
      //    }
      //    else if (opponent == 'B')
      //    {
      //       score += 3;
      //    }
      //    else if (opponent == 'C')
      //    {
      //       score += 0;
      //    }
      // }
      // else if (response == 'Z')
      // {
      //    score += 3;
      //    if (opponent == 'A')
      //    {
      //       score += +0;
      //    }
      //    else if (opponent == 'B')
      //    {
      //       score += 6;
      //    }
      //    else if (opponent == 'C')
      //    {
      //       score += 3;
      //    }
      // }

      // SECOND PART OF THE CHALLENGE
      if (opponent == 'A')
      {
         if (response == 'X')
         {
            score += 3;
         }
         else if (response == 'Y')
         {
            score += 4;
         }
         else if (response == 'Z')
         {
            score += 8;
         }
      }
      else if (opponent == 'B')
      {
         if (response == 'X')
         {
            score += 1;
         }
         else if (response == 'Y')
         {
            score += 5;
         }
         else if (response == 'Z')
         {
            score += 9;
         }
      }
      else if (opponent == 'C')
      {
         if (response == 'X')
         {
            score += +2;
         }
         else if (response == 'Y')
         {
            score += 6;
         }
         else if (response == 'Z')
         {
            score += 7;
         }
      }
   }

   printf("\nMy final score is %d\n\n", score);
}
