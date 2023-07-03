#include<bits/stdc++.h>

bool isValid(int arr[9][9], int row, int col, int digit) {

  for (int i = 0; i < 9; i++) {

    if (arr[i][col] == digit) return false;
    if (arr[row][i] == digit) return false;
    if (arr[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit) return false;
  }
  return true;
}

bool isItSudoku(int matrix[9][9]){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){

            // if the cell is empty
            if(matrix[i][j] == 0){

                for(int digit=1; digit<=9; digit++){
                    
                    if(isValid(matrix, i, j, digit) == true){
                        
                        matrix[i][j] = digit;
                        if(isItSudoku(matrix) == true) return true;
                        else matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
