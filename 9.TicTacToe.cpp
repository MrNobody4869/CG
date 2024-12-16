#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Set up the game board as an array
vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

// Function to print the game board
void printBoard() 
{
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to handle a player's turn
void takeTurn(string player) 
{
    cout << player << "'s turn." << endl;
    cout << "Choose a position from 1-9: ";
    int position;
    cin >> position;
    position -= 1;
    
    // Check for valid input or if position is already taken
    while (position < 0 || position > 8 || board[position] != "-") 
    {
        cout << "Invalid input or position already taken. Choose a different position: ";
        cin >> position;
        position -= 1;
    }
    board[position] = player;  // Update the board
    printBoard();  // Display updated board
}

// Function to check if the game is over (win, tie, or continue playing)
string checkGameOver() 
{
    // Check for a win (rows, columns, or diagonals)
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != "-") ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != "-") ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != "-") ||
        (board[0] == board[3] && board[3] == board[6] && board[0] != "-") ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != "-") ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != "-") ||
        (board[0] == board[4] && board[4] == board[8] && board[0] != "-") ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != "-")) 
    {
        return "win";  // A player has won
    }
    
    // Check for a tie
    else if (count(board.begin(), board.end(), "-") == 0) 
    {
        return "tie";  // No empty spaces left, it's a tie
    }
    
    // If no win or tie, the game is still going
    else 
    {
        return "play";  // Game is ongoing
    }
}

// Main game loop
int main() 
{
    printBoard();  // Display the initial empty board
    string currentPlayer = "X";  // X starts the game
    bool gameOver = false;  // Game is not over initially
    
    while (!gameOver) 
    {
        takeTurn(currentPlayer);  // Handle current player's turn
        string gameResult = checkGameOver();  // Check if the game is over
        
        if (gameResult == "win") 
        {
            cout << currentPlayer << " wins!" << endl;  // Print winning message
            gameOver = true;  // End the game
        } 
        else if (gameResult == "tie") 
        {
            cout << "It's a tie!" << endl;  // Print tie message
            gameOver = true;  // End the game
        } 
        else 
        {
            // Switch players if the game is not over
            currentPlayer = currentPlayer == "X" ? "O" : "X";
        }
    }
    
    return 0;  // End the program
}

/*
COMMANDS:

g++ test.cpp -o test
./test
*/
