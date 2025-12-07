#include <IOSTREAM>
#include <TIME.H>
#include <STDIO.H>
#include <IOMANIP>

// problem in printer function
//  need to read about call satcks (have a long path to go yet ;) tired but yay)
// should the board be **board or ***board?
using namespace std;

void std_option_list();
void board_generator(int n, int bomb_num, int **);
void board_printer(int **);
void board_checker(int **);
void game_mode(int **);
void flag(int **);

int **board, N;

int main()
{
    cout << "\n\nHelllo world!";
    std_option_list();
    game_mode(board);
    return 0;
}

void std_option_list()
{
    cout << "\n1. Easy (5x5)\n2. Medium (10x10)\n3. Hard (15x15)\n4. Custom\n5. Exit\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
    {
        board_generator(5, 5, board);
        N = 5;
        break;
    }
    case 2:
    {
        board_generator(10, 10, board);
        N = 10;
        break;
    }
    case 3:
    {
        board_generator(15, 15, board);
        N = 15;
        break;
    }
    case 4:
    {
        int n = 5, bomb = 5; // n is dimension
        do
        {
            cout << "\nEnter the number of dimension: ";
            cin >> n;
            cout << "\nEnter the number of bombs: ";
            cin >> bomb;
        } while ((n < 5 || bomb < 5 || bomb > n * n) && (cout << "Invalid input\n"));
        board_generator(n, bomb, board);
        N = n;
        break;
    }
    case 5:
    {
        cout << "Are you sure?[y/n]";
        char n;
        cin >> n;
        if (n == 'y')
        {
            return;
        }
        else
        {
            std_option_list();
        }
        break;
    }
    default:
        cout << "Invalid input\n";
        break;
    }
}

void board_generator(int n, int bomb_num, int **board)
{
    cout << "Starting to generate the field!";
    board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        board[i] = (int *)malloc(n * sizeof(int));
    cout << "\nAlmost there...";
    for (int f = 0; f < n; f++)
    {
        for (int j = 0; j < n; j++)
            board[f][j] = 0;
    }
    // srand(time(NULL));
    // for (bomb_num; bomb_num > 0; bomb_num--)
    // {
    //     int x = rand() % n;
    //     int y = rand() % n;
    //     if (board[x][y] == 0)
    //     {
    //         board[x][y] = -1;
    //     }
    //     else
    //     {
    //         bomb_num++;
    //     }
    // }
    while (bomb_num > 0)
    {
        int x = rand() % n;
        int y = rand() % n;
        if (board[x][y] == 0)
        {
            board[x][y] = -1;
            bomb_num--;
        }
    }
    cout << "\nDone!\n";
}

void board_printer(int **board)
{
    cout << "   ";
    for (int f = 0; f < N; f++)
    {
        cout << f + 1 << setw(3);
    }
    for (int i = 0; i < N; i++)
    {
        cout << endl
             << i + 1 << setw(3);
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] < 1)
            {
                cout << "X" << setw(3);
            }
            else
            {
                cout << board[i][j] - 1 << setw(3);
            }
        }
    }
}

void board_checker(int **board) // this function gets the location the player chooses and if it's safe puts the number of bombs around in the place of the player has chosen
{
    cout << "Enter the row and then column number: (from 1 to " << N << ")\n0. return\n";
    int row, clm;
    cin >> row;
    if (row == 0)
        return;
    cin >> clm;
    row--;
    clm--;
    if (row < 0 || row >= N || clm < 0 || clm >= N)
    {
        cout << "Invalid input\nTry again.\n";
        board_checker(board);
        return;
    }
    else if (board[row][clm] == -1 || board[row][clm] == -3)
    {
        cout << "Game Over\n"; // should do sth after this! needs attention!!!
    }
    else
    {
        int bomb_counter = 1;
        int istart = row - 1, iend = row + 1, jstart = clm - 1, jend = clm + 1;
        if (row == 0)
        {
            istart = 0;
            iend = 1;
        }
        else if (row == N - 1)
        {
            iend = row;
            istart = row - 1;
        }
        if (clm == 0)
        {
            jstart = 0;
            jend = 1;
        }
        else if (clm == N - 1)
        {
            jend = clm;
            jstart = clm - 1;
        }
        for (istart; istart <= iend; istart++)
        {
            for (; jstart <= jend; jstart++)
            {
                if (board[istart][jstart] == -1 || board[istart][jstart] == -3)
                {
                    bomb_counter++;
                }
            }
        }
        board[row][clm] = bomb_counter;
    }
}

void flag(int **board)
{
    cout << "Enter the row and then column number: (from 1 to " << N << ")\n0. return\n";
    int row, clm;
    cin >> row;
    if (row == 0)
        return;
    cin >> clm;
    row--;
    clm--;
    if (row < 0 || row >= N || clm < 0 || clm >= N)
    {
        cout << "Invalid input\nTry again.\n";
        flag(board);
        return;
    }
    else if (board[row][clm] < -1)
        cout << "This block is already flagged!";
    else if (board[row][clm] > 0)
        cout << "This block has been unlocked";
    else if (board[row][clm] == 0)
        board[row][clm] = -2;
    else if (board[row][clm] == -1)
        board[row][clm] = -3;
}

void game_mode(int **board)
{
    board_printer(board);
    cout << "\n1. Check\n2. Flag\n3. Exit\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        board_checker(board);
        game_mode(board);
        break;
    case 2:
        flag(board);
        game_mode(board);
        break;
    case 3:
        std_option_list();
        break;
    default:
        game_mode(board);
        break;
    }
}
