#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(int arr[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

bool isSafe(int arr[9][9], int row, int col, int num) {
  for (int x = 0; x <= 8; x++) {
    if (arr[row][x] == num) {
      return false;
    }
  }

  for (int x = 0; x <= 8; x++) {
    if (arr[x][col] == num) {
      return false;
    }
  }

  int startRow = row - row % 3;
  int startCol = col - col % 3;
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arr[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }

  return true;
}

bool solveSudoku(int arr[9][9], int row, int col) {
  if (row == 8 && col == 9) {
    return true;
  }

  if (col == 9) {
    row++;
    col = 0;
  }

  if (arr[row][col] > 0){
    return solveSudoku(arr, row, col + 1);
  }

  for (int num = 1; num <= 9; num++) {
    if (isSafe(arr, row, col, num)) {
      arr[row][col] = num;
      if (solveSudoku(arr, row, col + 1)) {
        return true;
      }
    }
    arr[row][col] = 0;
  }

  return false;
}
int main() {
  int arr[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0} };

  if (solveSudoku(arr, 0, 0)) {
    print(arr);
  }else{
    cout << "There is no solution for this sudoku grid." << endl;
  }
  
  return 0;
}