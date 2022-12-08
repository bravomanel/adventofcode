// A = Rock
// B = Paper
// C = Scissors

// X = Rock
// Y = Paper
// Z = Scissors

// X = Lose
// Y = Draw
// Z = Win

// 1 for Rock
// 2 for Paper
// 3 for Scissors

// 0 lost, 3 draw, 6 won

#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *input;
   char line[2];

   input = fopen("b.txt", "r");
   if (input == NULL)
   {
      perror("Unable to open file");
      exit(1);
   }

   // char play1, play2;
   int points1, points2;

   // fgets(line, 3, input);
   // printf("%s", line);

   while (fgets(line, 2, input))
   {
      // printf("player1: %s, player2: \n", line);
      // char p1 = line[0];
      // printf("%s", line);
      // printf("%c", p1);
      char play1 = line[0];
      char play2 = line[2];
      printf("Play 1: %c\nPlay 2: %c\n", play1, play2);
      printf("%s", line);
      // printf("%c", line[0]);
   }
   printf("\b");
   fclose(input);

   return 0;
}