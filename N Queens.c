#include <stdio.h>

#define MAX 20

int n;
int board[MAX][MAX];
int countSolutions = 0;

int isSafe(int row, int col)
{
    int i, j;

    for(i = 0; i < row; i++)
        if(board[i][col])
            return 0;

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;

    for(i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j])
            return 0;

    return 1;
}

void printBoard()
{
    int i, j;

    printf("\nSolution %d:\n", countSolutions);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void solve(int row)
{
    int col;

    if(row == n)
    {
        countSolutions++;
        printBoard();
        return;
    }

    for(col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {
            board[row][col] = 1;

            solve(row + 1);

            board[row][col] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            board[i][j] = 0;

    solve(0);

    printf("\nTotal number of solutions = %d\n", countSolutions);

    return 0;
}
