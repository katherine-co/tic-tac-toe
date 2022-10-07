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
void player2Move();
void resetBoard();
char checkWin();
void sayWinner(char);

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
        resetBoard();
        board();
        char winner = ' ';

        while(winner == ' ')
        {   
            // Ask the player to make their first move and display their move on the board
            player1Move();
            board();
            // Check the board to see if ther is a winner
            winner = checkWin();
            if (winner != ' ')
            {
                break;
            }

            // Continue to play back and forth until there is a win
            player2Move();
            board();
            winner = checkWin();
            if (winner != ' ')
            {
                break;
            }
        }

        printf("\nHere are the results\n");
        board();
        sayWinner(winner);
    }

    else
    {
        printf("You chose person vs. computer\n");
        board();
        printf("\nPlayer 1 (You) is 'X' and Player 2 (Computer) is 'O'\n");
        printf("Player 1 please make your move with the range of (0,0) to (2,2). Enter with format like '0 0': ");
        scanf("%d %d", &row, &column);
    }

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

// Resets the board so that the spaces are ' '
void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            boardSpot[i][j] = ' ';
        }
    }
}

// Ask the player to make their first move and display their move on the board
void player1Move()
{
    int row;
    int column;
    
    do
    {
        printf("Player 1 please enter your move with range of (0,0) to (2,2). Enter with format like '0 0': ");
        scanf("%d %d", &row, &column);
        
        // Checks to see if the spot user inputted is occupied
        if (boardSpot[row][column] != ' ')
        {
            printf("Invalid! Spot is already taken\n");
        }
        else
        {
            boardSpot[row][column] = player1;
            break;
        }
    }
    while (boardSpot[row][column] != ' ');
}

void player2Move()
{
    int row;
    int column;
    
    do
    {
        printf("Player 2 please enter your move with range of (0,0) to (2,2). Enter with format like '0 0': ");
        scanf("%d %d", &row, &column);
        
        // Checks to see if the spot user inputted is occupied
        if (boardSpot[row][column] != ' ')
        {
            printf("Invalid! Spot is already taken\n");
        }
        else
        {
            boardSpot[row][column] = player2;
            break;
        }
    }
    while (boardSpot[row][column] != ' ');
    
}

//Checks to see if there is a winner
char checkWin()
{
    // Checks for row win
    if (boardSpot[0][0] == boardSpot[0][1] && boardSpot[0][0] == boardSpot[0][2])
    {
        return boardSpot[0][0];
    }
    else if (boardSpot[1][0] == boardSpot[1][1] && boardSpot[1][0] == boardSpot[1][2])
    {
        return boardSpot[1][0];
    }
    else if (boardSpot[2][0] == boardSpot[2][1] && boardSpot[2][0] == boardSpot[2][2])
    {
        return boardSpot[2][0];
    }
    // Checks for column win
    else if (boardSpot[0][0] == boardSpot[1][0] && boardSpot[0][0] == boardSpot[2][0])
    {
        return boardSpot[0][0];
    }
    else if (boardSpot[0][1] == boardSpot[1][1] && boardSpot[0][1] == boardSpot[2][1])
    {
        return boardSpot[0][1];
    }
    else if (boardSpot[0][2] == boardSpot[1][2] && boardSpot[0][2] == boardSpot[2][2])
    {
        return boardSpot[0][2];
    }
    // Checks for diagonal win
    else if (boardSpot[0][0] == boardSpot[1][1] && boardSpot[0][0] == boardSpot[2][2])
    {
        return boardSpot[0][0];
    }
    else if (boardSpot[0][2] == boardSpot[1][1] && boardSpot[0][2] == boardSpot[2][0])
    {
        return boardSpot[0][2];
    }
    // Checks for a tie
    else if (boardSpot[0][0] != ' ' && boardSpot[0][1] != ' ' && boardSpot[0][2] != ' ' && boardSpot[1][0] != ' ' && boardSpot[1][1] != ' '
    && boardSpot[1][2] != ' ' && boardSpot[2][0] != ' ' && boardSpot[2][1] != ' ' && boardSpot[2][2] != ' ')
    {
        return 'T';
    }
    else
    {
        return ' ';
    }
}

void sayWinner(char winner)
{
    if (winner == player1)
    {
        printf("Player 1 wins!");
    }
    else if (winner == player2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("You ended the game with a tie!");
    }
}