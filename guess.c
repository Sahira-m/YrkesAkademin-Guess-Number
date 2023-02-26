#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define Yes y | Y
#define No n | N
// function to check the input is string or number
char Isnumbercheck(char *guess)
{
  char isnumber = TRUE;
  int len = strlen(guess);
  int i;
  for (i = 0; i < len; i++)
    if (!isdigit(guess[i]))
    {
      isnumber = FALSE;
      break;
    }

  return isnumber;
}
// Main function
void main()
{
  char playAgain[4], isnumber = FALSE;
  char guess[3];
  int randomNumber, numTries;
  srand(time(NULL));
  /*Generate random number*/
  randomNumber = rand() % 100 + 1;

  do
  {

    printf("I've chosen a number between 1 and 100. Can you guess what it is?\n");
    numTries = 1; /*Initialize the Num of entries to 1*/

    while (numTries < 5)
    {
      printf("Guess %d: ", numTries);
      scanf("%s", &guess);
      isnumber = Isnumbercheck(guess);
      if (isnumber == FALSE)
      {
        printf("Entered input is not a number\n");
      }
      else
      {
        int guessNumber = atoi(guess); /*Converting string to number*/

        if (guessNumber > 0 && guessNumber < 100)
        {
          if (guessNumber == randomNumber)
          {
            printf("Right! You guessed right in %d tries.", numTries);
            break;
          }
          else if (guessNumber > randomNumber)
            printf("The number is Smaller.\n");

          else if (guessNumber < randomNumber)
            printf("The number is Larger.\n");
          numTries++;
        }
        else
          printf("\n please choose a number between 1 and 100");
      }
    }
    printf("\n Guess number is %d:", randomNumber);
    printf("\n Do you want to play again (Yes/No)? ");
    scanf("%s", playAgain);
  } while (playAgain[0] == 'Y' || playAgain[0] == 'y');
}
