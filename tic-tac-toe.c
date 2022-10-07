//Katherine Co
//CS2600
//Quiz 2: Tic-Tac-Toe
#include <stdio.h>
#include <stdlib.h>

// Tic Tac Toe game between 2 players or player vs computer
char boardSpot[3][3];
int row;
int column;
char player1 = 'X';
char player2 = 'O';

void board();
void player1Move();

int main()
{
    int userInput;
    char winner = ' ';
    
    // Prompt user for game they wish to play (person vs. person or player vs. computer)
    printf("Welcome to the game of Tic-Tac-Toe!\n");
    printf("Please enter 1 for person vs. person or 2 for person vs. computer: ");

    // Read information from console and converts to integer
    scanf("%d", &userInput);

    if (userInput == 1)
    {
        printf("You chose person vs. person\n");
        printf("\nPlayer 1 is 'X' and Player 2 is 'O'\n");
        
        while(winner == ' ')
        {
            board();
            
            // Ask the player to make their first move and display their move on the board
            player1Move();
        }
    }

    else
    {
        printf("You chose person vs. computer\n");
        board();
        printf("\nPlayer 1 (You) is 'X' and Player 2 (Computer) is 'O'\n");
        printf("Player 1 please make your move with the range of (0,0) to (2,2). Enter with format like '0 0': ");
        scanf("%d %d", &row, &column);
    }

    // Display a blank board game

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
    printf("| %c | %c | %c |\n", boardSpot[0][0], boardSpot[0][1], boardSpot[0][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", boardSpot[1][0], boardSpot[1][1], boardSpot[1][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", boardSpot[2][0], boardSpot[2][1], boardSpot[2][2]);
    printf("+-----------+\n");   
}

// Ask the player to make their first move and display their move on the board
void player1Move()
{
    int row;
    int column;
    
    do
    {
        printf("Player 1 please make your move with the range of (0,0) to (2,2). Enter with format like '0 0': ");
        scanf("%d %d", &row, &column);
        
        if (boardSpot[row][column] != ' ')
        {
            printf("Invalid! Spot is already taken\n");
        }
        else
        {
            boardSpot[row][column] = player1;
        }
    }
    while(boardSpot[row][column] != ' ');
}