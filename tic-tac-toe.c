//Katherine Co
//CS2600
//Quiz 2: Tic-Tac-Toe
#include <stdio.h>
#include <stdlib.h>

// Tic Tac Toe game between 2 players or player vs computer
char boardspot[3][3];
void board();

int main()
{
    int userInput;
    
    // Prompt user for game they wish to play (person vs. person or player vs. computer)
    printf("Welcome to the game of Tic-Tac-Toe!\n");
    printf("Please enter 1 for person vs. person or 2 for person vs. computer: ");

    // Read information from console and converts to integer
    scanf("%d", &userInput);
    
    if (userInput == 1)
    {
        printf("You chose person vs. person\n");
        board();
    }
    else
    {
        printf("You chose person vs. computer\n");
        board();
    }

    // Display a blank board game

    // Ask the player to make their first move and display their move on the board

        // Detect invalid inputs from the user

    // Continue to play back and forth until there is a win

    // If there is a win, immediately display who won

    // If there is a tie, immediately stop the program and say it was a tie

    // Prompt the user if they would like to play again
  
    return 0;
}

// An empty layout of the tic-tac-toe board
void board()
{
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", boardspot[0][0], boardspot[0][1], boardspot[0][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", boardspot[1][0], boardspot[1][1], boardspot[1][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", boardspot[2][0], boardspot[2][1], boardspot[2][2]);
    printf("+-----------+\n");
}