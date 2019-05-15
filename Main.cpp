#include <iostream>
#include <vector>
using namespace std;
using std::cout;

int main() {

  cout << endl;
  cout << "This program generates a random maze." << endl;
  cout << "The starting point is designated by a '2' and the end point is deisgnated by a '3'." << endl;
  cout << "The maze can start / end anywehere in the dimension you provide." << endl;
  cout << endl;

  int c;
  cout << "Enter number of columns: ";
  cin >> c;
  
  int r;
  cout << "Enter number of rows: ";
  cin >> r;
  
  const int rows = r;
  const int cols = c;

  int cells[rows][cols];
  
  srand (time(NULL));
  int start = rand() % 4;
  
  int start_row = 0;
  int end_row = 0;
  int start_col = 0;
  int end_col = 0;

  //make all dimensions '0' when not in the path
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cells[row][col] = 0;
    }
  }

  //random start-end generated maze
  //methods will keep being repeated in if else statements to account for the inputted dimensions

  if (start == 0){ 
    start_row = rand() % (rows - 1); 
    start_col = cols - cols;
    end_row = rows - 1; 
    end_col = rand() % (cols - 1) + 1; 
    std::cout << endl; //print to a new line

    int row = start_row;
    int col = start_col;

    while ((col < end_col) || (row < end_row)) {
      //0= right, 1= down
      int move = (rand() % 2);
      // path goes down
      if(move && (row < end_row)){
	cells[row++][col]=1;
      } else if(!move && (col < end_col)){
	cells[row][col++]=1;
	//path goes right
      }
    }
  } else if (start == 1){
    start_row = rows - rows;//first row
    start_col = rand() % (cols - 1);
    end_row = rand() % (rows - 1) + 1;
    end_col = cols - 1;//last column

    // path of next row/column
    int row = start_row;
    int col = start_col;
    // 0 = right
    // 1 = down
    while ((col < end_col) || (row < end_row)) {
      int move = (rand() % 2);
      if(move && (row < end_row)){
	// down
	cells[row++][col]=1;
      } else if(!move && (col < end_col)){
	// right
	cells[row][col++]=1;
      }
    }
    
  } else if (start == 2){ 
    start_row = rows - 1;//last row
    start_col = rand() % (cols - 1) + 1;
    end_row = rand() % (rows - 1);
    end_col = cols - cols;//first column

    //another path
    int row = start_row;
    int col = start_col;
    while ((col > end_col) || (row > end_row)) {
      // 0 = left
      // 1 = up
      int move = (rand() % 2);
      if(move && (row > end_row)){
	// down
	cells[row--][col]=1;
      } else if(!move && (col > end_col)){
	// right
	cells[row][col--]=1;
      }
    }
  } else { 
    start_row = rand() % (rows - 1) + 1;
    start_col = cols - 1;
    end_row = rows - rows;
    end_col = rand() % (cols - 1);

    //another path
    int row = start_row;
    int col = start_col;

    while ((col > end_col) || (row > end_row)) {
      // 0 = left
      //1 = up
      int move = (rand() % 2);
      if(move && (row > end_row)){
	cells[row--][col]=1;
      } else if(!move && (col > end_col)){
	cells[row][col--]=1;
      }
    }
  }
  
  cells[start_row][start_col] = 2; //start is designated by a '2'
  cells[end_row][end_col] = 3; //end is designated by a '3'

  
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      std::cout << cells[row][col];
      //prints the dimensions
    }
    std::cout << endl;
    //prints new lines
  }
  

  // solves for starting the columns and rows
  int cRow = start_row;
  int cCol = start_col;
  
  bool used[rows][cols];
  
  //checks to see if the dimensions are used
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      used[row][col] = false;
    }
  }
 
  used[start_row][start_col] = true;

  cout << endl;
  cout << "Here is how the maze is solved." << endl;
  
  while (cells[cRow][cCol] != 3){
    if (cCol < cols - 1 && !used[cRow][cCol + 1] && (cells[cRow][cCol + 1] == 1 || cells[cRow][cCol + 1] == 3)){
      cout << "Right ";
      cCol++;

    } else if (cCol > 0 && !used[cRow][cCol - 1] && (cells[cRow][cCol - 1] == 1 || cells[cRow][cCol - 1] == 3)){
      cout << "Left ";
      cCol--;

    } else if (cRow < rows - 1 && !used[cRow + 1][cCol] && (cells[cRow + 1][cCol] == 1 || cells[cRow + 1][cCol] == 3)){
      cout << "Down ";
      cRow++;

    } else if (cRow > 0 && !used[cRow - 1][cCol] && (cells[cRow - 1][cCol] == 1 || cells[cRow - 1][cCol] == 3)){
      cout << "Up ";
      cRow--;
    }
    
    cout << endl;

    used[cRow][cCol] = true;
  }
}
