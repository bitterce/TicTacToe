#include "grid.h"
#include <iostream>

// Post: prints the grid in the required form
void print_grid() {
  std::cout << grid(0, 0) << " " << grid(0, 1) << " " << grid(0, 2) << "\n";
  std::cout << grid(1, 0) << " " << grid(1, 1) << " " << grid(1, 2) << "\n";
  std::cout << grid(2, 0) << " " << grid(2, 1) << " " << grid(2, 2) << "\n";
}

/*bool is_empty(int row, int col) {
  if((row >=  0 && row <= 2) && (col >= 0 && col <= 2) && grid(row, col) == '_') {
    return true;
  }
  else return false;
}*/

bool is_empty(int row, int col) {
  if(grid(row, col) == '_' && row >=  0 && row <= 2 && col >= 0 && col <= 2) {
    return true;
  }
  else return false;
}


// Post: Returns true if one of the winning strategy is true
bool player1_wins() {
  bool a = grid(0, 0) == 'O' && grid(0, 1) == 'O' && grid(0, 2) == 'O';
  bool b = grid(1, 0) == 'O' && grid(1, 1) == 'O' && grid(1, 2) == 'O';
  bool c = grid(2, 0) == 'O' && grid(2, 1) == 'O' && grid(2, 2) == 'O';
  
  bool d = grid(0, 0) == 'O' && grid(1, 0) == 'O' && grid(2, 0) == 'O';
  bool e = grid(0, 1) == 'O' && grid(1, 1) == 'O' && grid(2, 1) == 'O';
  bool f = grid(0, 2) == 'O' && grid(1, 2) == 'O' && grid(2, 2) == 'O';
  
  bool g = grid(0, 0) == 'O' && grid(1, 1) == 'O' && grid(2, 2) == 'O';
  bool h = grid(2, 0) == 'O' && grid(1, 1) == 'O' && grid(0, 2) == 'O';
  if(a || b || c || d || e || f || g || h) {
    return true;
  }
  else return false;
}

bool player2_wins() {
  bool a = grid(0, 0) == 'X' && grid(0, 1) == 'X' && grid(0, 2) == 'X';
  bool b = grid(1, 0) == 'X' && grid(1, 1) == 'X' && grid(1, 2) == 'X';
  bool c = grid(2, 0) == 'X' && grid(2, 1) == 'X' && grid(2, 2) == 'X';
  
  bool d = grid(0, 0) == 'X' && grid(1, 0) == 'X' && grid(2, 0) == 'X';
  bool e = grid(0, 1) == 'X' && grid(1, 1) == 'X' && grid(2, 1) == 'X';
  bool f = grid(0, 2) == 'X' && grid(1, 2) == 'X' && grid(2, 2) == 'X';
  
  bool g = grid(0, 0) == 'X' && grid(1, 1) == 'X' && grid(2, 2) == 'X';
  bool h = grid(2, 0) == 'X' && grid(1, 1) == 'X' && grid(0, 2) == 'X';

  if(a || b || c || d || e || f || g || h) {
    return true;
  }
  else {
    return false;
  }
}

// Post: returns true, if the grid is full and player1 and player2
// did not win
bool draw() {
  unsigned int n = 0;
  for(unsigned int i = 0; i <= 2; ++i) {
    for(unsigned int j = 0; j <= 2; ++j) {
      if(grid(i, j) == 'O' || grid(i, j) == 'X') ++n;
    }
  }
  if(n == 9 && !player1_wins() && !player2_wins()) return true;
  else return false;
}

// Game_ends when either player1 or player2 or no one wins
bool game_ends() {
  if(player1_wins() || player2_wins() || draw()) {
    return true;
  }
  return false;
}
// function to fill the grid (mainly to try out if the other 
// functions work)
void fill_grid(char x) {
  for(unsigned int i = 1; i <= 2; ++i) {
    for(unsigned int j = 0; j <= 2; ++j) {
      grid(i, j) = x;
    }
  }
}

int main() {
  print_grid();
  
  /*
  fill_grid('X');
  print_grid();
  
  if(grid_full()) {
    std::cout << "Draw! \n";
  }
  */
  
  int row, col;
  
  while(!game_ends()) {
    std::cout << "Player 1 please enter your next move (row/col): \n";
    std::cin >> row >> col;
    
    if(is_empty(row, col)) {
      grid(row, col) = 'O';
      print_grid();
    }
    else {
      std::cout << "Invalid move! \n";
      continue;
    }
    
    if(!game_ends()) {
      while(!is_empty(row, col)) {
        std::cout << "Player 2 please enter your next move (row/col): \n";
        std::cin >> row >> col;
        if(!is_empty(row, col)) std::cout << "Invalid move! \n";
        else continue;
      }
      grid(row, col) = 'X';
      print_grid();
    }
    else break;
  }
  print_grid();
  if(player1_wins()) std::cout << "O won! \n";
  else if (player2_wins()) std::cout << "X won! \n";
  else std::cout << "Draw! \n";
  
  return 0;
}
