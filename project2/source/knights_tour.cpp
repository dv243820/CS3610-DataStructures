#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size)
{
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i)
  {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print()
{
  for (int i = 0; i < this->board_size; i++)
  {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl
       << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(
    int row, int col,
    int row_moves[], int col_moves[], int &num_moves)
{

  // I tried another way first and for the life of me I couldn't get it to work so I individually checked each move despite not really wanting to

  // first check (had to make sure they were all in the right order)
  if (row - 1 < board_size && row - 1 >= 0 && col + 2 < 5 && col + 2 >= 0)
  {
    if (board[row - 1][col + 2] == 0) // check if the spot we are going to is empty
    {
      row_moves[num_moves] = row - 1; // if so, record the move
      col_moves[num_moves] = col + 2;
      num_moves++; // increment num_moves
    }
  }
  // second check (row + 1 and col + 2)
  if (row + 1 < board_size && row + 1 >= 0 && col + 2 < 5 && col + 2 >= 0)
  {
    if (board[row + 1][col + 2] == 0)
    {
      row_moves[num_moves] = row + 1;
      col_moves[num_moves] = col + 2;
      num_moves++;
    }
  }

  // third check (row + 2 and col + 1)
  if (row + 2 < board_size && row + 2 >= 0 && col + 1 < 5 && col + 1 >= 0)
  {
    if (board[row + 2][col + 1] == 0)
    {
      row_moves[num_moves] = row + 2;
      col_moves[num_moves] = col + 1;
      num_moves++;
    }
  }

  // fourth check (row + 2 and col - 1)
  if (row + 2 < board_size && row + 2 >= 0 && col - 1 < 5 && col - 1 >= 0)
  {
    if (board[row + 2][col - 1] == 0)
    {
      row_moves[num_moves] = row + 2;
      col_moves[num_moves] = col - 1;
      num_moves++;
    }
  }

  // fifth move check (row + 1 and col - 2)
  if (row + 1 < board_size && row + 1 >= 0 && col - 2 < 5 && col - 2 >= 0)
  {
    if (board[row + 1][col - 2] == 0)
    {
      row_moves[num_moves] = row + 1;
      col_moves[num_moves] = col - 2;
      num_moves++;
    }
  }

  // sixth move check (row - 1 and col -2 )
  if (row - 1 < board_size && row - 1 >= 0 && col - 2 < 5 && col - 2 >= 0)
  {
    if (board[row - 1][col - 2] == 0)
    {
      row_moves[num_moves] = row - 1;
      col_moves[num_moves] = col - 2;
      num_moves++;
    }
  }

  // seventh move check (row - 2 and col - 1)
  if (row - 2 < board_size && row - 2 >= 0 && col - 1 < 5 && col - 1 >= 0)
  {
    if (board[row - 2][col - 1] == 0)
    {
      row_moves[num_moves] = row - 2;
      col_moves[num_moves] = col - 1;
      num_moves++;
    }
  }
  // final move check (row -2 and col + 1)
  if (row - 2 < board_size && row - 2 >= 0 && col + 1 < 5 && col + 1 >= 0)
  {
    if (board[row - 2][col + 1] == 0)
    {
      row_moves[num_moves] = row - 2;
      col_moves[num_moves] = col + 1;
      num_moves++;
    }
  }
}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int &m, int &num_tours)
{
  m++;                 // first have to increment move id for first turn
  board[row][col] = m; // sets that we've been there and what turn

  int row_moves[8]; // 8 for the moves we can make, needed to pass thru get_moves later
  int col_moves[8];

  if (m >= board_size * board_size) // then we've checked every spot (25), BASE CASE!!!!
  {
    num_tours++;         // increment total number of tours for the end
    print();             // print
    board[row][col] = 0; // backtracking
    m--;
    return;
  }
  else
  {
    int num_moves = 0; // initialize as 0, will change in get_moves

    get_moves(row, col, row_moves, col_moves, num_moves); // GET MOVES ---- GETS THE MOVES POSSIBLE INTO ROW_MOVES AND COL_MOVES

    for (int i = 0; i < num_moves; i++) //for loop, checks all our moves recursively
    {
      move(row_moves[i], col_moves[i], m, num_tours); // recursive call
    }
  }

  board[row][col] = 0; // BACKTRACKING, SETS SPOT BACK TO UNVISITED
  m--;                 // deincrement the move id, since we're backtracking
}

int KnightsTour::generate(int row, int col)
{
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
