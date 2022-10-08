//Katherine Co
//CS2600
//Quiz 2: Tic-Tac-Toe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Tic Tac Toe game between 2 players or player vs computer
char boardSpot[3][3];
int row;
int column;
char player1 = 'X';
char player2 = 'O';
char computer = 'O';

void board();
void player1Move();
void player2Move();
void computerMove();
int spacesLeft();
void resetBoard();
char checkWin();
void sayWinner(char);
void sayWinnerAgainstPC(char);

int main()
{
    char userAgain = ' ';

    do
    {
        int userInput;
        char winner = ' ';
        
        // Prompt user for game they wish to play (person vs. person or player vs. computer)
        printf("Welcome to the game of Tic-Tac-Toe!\n");
        printf("Please enter 1 for person vs. person or 2 for person vs. computer: ");

        // Read information from console and converts to integer
        scanf(" %d", &userInput);

        if (userInput == 1) // If user chooses person vs. person
        {
            printf("You chose person vs. person\n");
            printf("\nPlayer 1 is 'X' and Player 2 is 'O'\n");
            resetBoard();
            board();

            while(winner == ' ')
            {   
                // Ask the player to make their first move and display their move on the board
                player1Move();
                board();
                // Check the board to see if there is a winner
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
            // Displays the winner and if no winner, will display a tie
            sayWinner(winner);
        }

        else if (userInput == 2) // If user chooses person vs. computer
        {
            printf("You chose person vs. computer\n");
            printf("\nPlayer 1 (You) is 'X' and Player 2 (Computer) is 'O'\n");
            resetBoard();
            board();

            while(winner == ' ')
            {   
                // Ask the player to make their first move and display their move on the board
                player1Move();
                board();
                // Check the board to see if there is a winner
                winner = checkWin();
                if (winner != ' ')
                {
                    break;
                }

                // Continue to play back and forth until there is a win
                computerMove();
                board();
                winner = checkWin();
                if (winner != ' ')
                {
                    break;
                }
            }
            
            printf("\nHere are the results\n");
            board();
            // Displays the winner and if no winner, will display a tie
            sayWinnerAgainstPC(winner);
        }

        else // If user enter a value other than 1 or 2
        {
            printf("\nInvalid input. You must enter either 1 or 2. Please restart the game.\n");
            break;
        }

        printf("\nWould you like to play again (y/n)? ");   // Asks user if they would like play again
        scanf("\n%c", &userAgain);
        userAgain = tolower(userAgain);
    }
    while (userAgain == 'y');   // loops while user agrees to play again

    printf("This is the end of the game. Thank you for playing!");
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

// Asks player 1 to make their move and input their move on the board
void player1Move()
{
    int row;
    int column;
    
    do
    {
        printf("Player 1 please enter your move with range of 0-2 for row and 0-2 for column. Enter '<row> <column>' format like '0 0': ");
        scanf("%d %d", &row, &column);
        
        // Checks if the spot user inputted is occupied
        if (boardSpot[row][column] != ' ')
        {
            printf("Invalid move! Please try again.\n");
        }
        else
        {
            boardSpot[row][column] = player1;
            break;
        }
    }
    while (boardSpot[row][column] != ' ');  // loops while spot on board is occupied
}

// Asks player 2 to make their move and input their move on the board
void player2Move()
{
    int row;
    int column;
    
    do
    {
        printf("Player 2 please enter your move with range of 0-2 for row and 0-2 for column. Enter '<row> <column>' format like '0 0': ");
        scanf("%d %d", &row, &column);
        
        // Checks if the spot user inputted is occupied
        if (boardSpot[row][column] != ' ')
        {
            printf("Invalid move! Please try again.\n");
        }
        else
        {
            boardSpot[row][column] = player2;
            break;
        }
    }
    while (boardSpot[row][column] != ' ');  // loops while spot on board is occupied
    
}

// Computer moves using sran() generator
void computerMove()
{
    srand(time(0));
    int row;
    int column;
    
    printf("Computer's move\n");
    if (spacesLeft() > 0)   // Checks first to see if there is space left or it's a tie
    {
        do
        {
            row = rand() % 3;
            column = rand() % 3;
        }
        while(boardSpot[row][column] != ' ');   // Runs only if spot it initially checked is already occupied
    boardSpot[row][column] = computer;
    }
    else
    {
        sayWinner(' ');
    }
}

// This is to check for a tie for person vs. computer
int spacesLeft()
{
    int spacesLeft = 9;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(boardSpot[i][j] != ' ')
            {
                spacesLeft--;
            }
        }
    }
    
    return spacesLeft;
}

//Checks to see if there is a winner
char checkWin()
{
    // Checks for row win
    if (boardSpot[0][0] == boardSpot[0][1] && boardSpot[0][1] == boardSpot[0][2])
    {
        return boardSpot[0][0];
    }
    else if (boardSpot[1][0] == boardSpot[1][1] && boardSpot[1][1] == boardSpot[1][2])
    {
        return boardSpot[1][0];
    }
    else if (boardSpot[2][0] == boardSpot[2][1] && boardSpot[2][1] == boardSpot[2][2])
    {
        return boardSpot[2][0];
    }
    // Checks for column win
    else if (boardSpot[0][0] == boardSpot[1][0] && boardSpot[1][0] == boardSpot[2][0])
    {
        return boardSpot[0][0];
    }
    else if (boardSpot[0][1] == boardSpot[1][1] && boardSpot[1][1] == boardSpot[2][1])
    {
        return boardSpot[0][1];
    }
    else if (boardSpot[0][2] == boardSpot[1][2] && boardSpot[1][2] == boardSpot[2][2])
    {
        return boardSpot[0][2];
    }
    // Checks for diagonal win
    else if (boardSpot[0][0] == boardSpot[1][1] && boardSpot[1][1] == boardSpot[2][2])
    {
        return boardSpot[0][0];
    }
    else if (boardSpot[0][2] == boardSpot[1][1] && boardSpot[1][1] == boardSpot[2][0])
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

// Winning message for person vs. person
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

// Winning message for person vs. computer
void sayWinnerAgainstPC(char winner)
{
    if (winner == player1)
    {
        printf("You win!");
    }
    else if (winner == computer)
    {
        printf("Oh no! You lost.");
    }
    else
    {
        printf("You ended the game with a tie!");
    }
}