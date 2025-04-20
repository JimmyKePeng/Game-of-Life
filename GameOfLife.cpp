#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void setBoard(vector<vector<int>> &board);
void printBoard(vector<vector<int>> &board, int &cells);
void gameOfLife(vector<vector<int>> &board);
int countHelper(vector<vector<int>> &board, int i, int j, int rows, int cols);
int helper(vector<vector<int>> &board, int i, int j, int rows, int cols);

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Green text

    vector<vector<int>> board(30, vector<int>(50, 0));
    setBoard(board); // set random cells in the board
    int cells = INT_MAX;
    int cycles = 1;
    while (cells)
    {
        printBoard(board, cells);
        cout << "total cells: " << cells << endl;
        cout << "total cycles: " << cycles++ << endl;
        gameOfLife(board);
        Sleep(1500);
        system("cls");
    }
    return 0;
}

void gameOfLife(vector<vector<int>> &board)
{
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> ans(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int count = countHelper(board, i, j, rows, cols);
            if (count == 3)
            {
                ans[i][j] = 1;
            }
            else if (board[i][j] == 1 && count == 2)
            {
                ans[i][j] = 1;
            }
        }
    }
    board = ans;
}
int countHelper(vector<vector<int>> &board, int i, int j, int rows, int cols)
{
    return helper(board, i - 1, j - 1, rows, cols) +
           helper(board, i - 1, j, rows, cols) +
           helper(board, i - 1, j + 1, rows, cols) +
           helper(board, i, j - 1, rows, cols) +
           helper(board, i, j + 1, rows, cols) +
           helper(board, i + 1, j - 1, rows, cols) +
           helper(board, i + 1, j, rows, cols) +
           helper(board, i + 1, j + 1, rows, cols);
}
int helper(vector<vector<int>> &board, int i, int j, int rows, int cols)
{
    if (i >= rows || j >= cols || i < 0 || j < 0 || board[i][j] == 0)
        return 0;
    return 1;
}

void setBoard(vector<vector<int>> &board) // set random cells
{
    srand(time(0));
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(vector<vector<int>> &board, int &cells)
{
    cells = 0;
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "o ";
                cells++;
            }
            else
                cout << "  ";
        }
        cout << endl;
    }
}