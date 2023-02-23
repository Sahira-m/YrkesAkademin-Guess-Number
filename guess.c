#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<conio.h>
//Main function
void main() 
{
  char playAgain[4];
  int guess, num, numTries;
  srand(time(NULL));
  do 
  {
    numTries = 1;
    num = rand() % 100 + 1;
    printf("I've chosen a number between 1 and 100. Can you guess what it is?\n");
    do {
      printf("Guess %d: ", numTries);
      scanf("%d", &guess);
      if(isdigit(guess)!=0)
      {
        printf("it is a string please enter a number again");
        scanf("%d", &guess);
        return;
      }
      else
      {
 numTries++;
   if(guess>0 && guess <100)
        {
           if(guess==num)
      {
        printf("Right! You guessed right in %d tries.", numTries);
        break;
      }
      else if (guess > num) 
        printf("The number is Smaller.\n");
        
       else if (guess < num) 
         printf("The number is Larger.\n");  
       
       }
 else
       printf("please choose a number between 1 and 100");
      }
    }
    while (numTries!=5);
    printf("Do you want to play again (Yes/No)? ");
    scanf("%s", playAgain);
  }

 while (playAgain[0] == 'Y' || playAgain[0] == 'y');
  printf("Thanks for this time!\n");
  getch();
}

