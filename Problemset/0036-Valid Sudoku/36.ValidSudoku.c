#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>



bool isValidSudokuBits(char** board, int boardSize, int* boardColSize) {
  int i, j, m, w;
  
  // Primero verificamos filas y columnas
  for (i = 0; i < boardSize; i++) {
    for (j = 0; j < boardSize; j++) {
      if (board[i][j] == '.') {
        continue;
      }
      
      // Verificar fila
      for (w = 0; w < boardSize; w++) {
        if (j == w || board[i][w] == '.') {
          continue;
        }
        if (board[i][j] == board[i][w]) {
          return false;
        }
      }
      
      // Verificar columna
      for (m = 0; m < boardSize; m++) {
        if (i == m || board[m][j] == '.') {
          continue;        
        }
        if (board[i][j] == board[m][j]) {
          return false;
        }
      }
    }
  }
  
  // Ahora verificamos cada subgrilla de 3x3 usando bits
  for (int vert = 0; vert < 9; vert += 3) {
    for (int hori = 0; hori < 9; hori += 3) {
      uint16_t bits = 0; // Usamos 9 bits, uno para cada número del 1 al 9
      
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          char cell = board[vert + i][hori + j];
          if (cell != '.') {
            int num = cell - '1'; // Convertimos el carácter a un número entre 0 y 8
            uint16_t bit = 1 << num; // Creamos una máscara de bit para este número
            
            // Verificamos si este número ya existe en la subgrilla
            if (bits & bit) {
              return false; // El número ya está presente en la subgrilla
            }
            
            // Marcamos el número como presente
            bits |= bit;
          }
        }
      }
    }
  }
  
  return true;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
  
  int map[9] = {false};
  int i,j,m,w;

  for (i=0; i<boardSize; i++) {
    for (j=0; j<boardSize; j++) {
      if (board[i][j]=='.') {
        continue;
      }
      for (w=0; w<boardSize; w++) {
        if (j==w || board[i][w]=='.') {
          continue;
        }
        if (board[i][j]==board[i][w]) {
          return false;
        }
      }
      for (m=0;m<boardSize; m++) {
        if (i==m || board[m][j]=='.') {
          continue;        
        }
        if (board[i][j]==board[m][j]) {
          return false;
        }
      }
      //printf("%c ", board[i][j]);
    }
  }

  for(int vert=0; vert<9;vert+=3){
    for (int hori=0; hori<9; hori+=3) {
      for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
          if (board[vert+i][hori+j] != '.') {
            if (map[board[vert+i][hori+j]-'1'] == true)
              return false;
            else
              map[board[vert+i][hori+j] - '1'] = true;
          }
        }
      }
      memset(map, 0, sizeof(map));
    }
  }
  return true;
}

int main(){
  bool sol;
  int boardSize = 9;
  int boardColSize = 9;

  // Crear el array dinámico
  char **board = calloc(boardSize, sizeof(char *));
  for (int i = 0; i < boardSize; i++) {
    board[i] = calloc(boardColSize, sizeof(char));
  }

  // Inicializar el tablero fila por fila
  /*char rows[9][9] = {*/
  /*  {'.', '3', '.', '5', '7', '.', '.', '.', '.'},*/
  /*  {'6', '.', '.', '1', '9', '.', '.', '.', '.'},*/
  /*  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},*/
  /*  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},*/
  /*  {'4', '.', '.', '.', '.', '3', '.', '.', '1'},*/
  /*  {'7', '.', '.', '5', '2', '.', '.', '.', '6'},*/
  /*  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},*/
  /*  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},*/
  /*  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}*/
  /*};*/
  

  char rows[9][9] = {
    {'.', '1', '.', '5', '2', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '6', '4', '3', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'5', '.', '.', '.', '.', '.', '9', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '5', '.'},
    {'.', '.', '.', '6', '.', '.', '.', '.', '.'},
    {'9', '.', '.', '.', '.', '3', '.', '.', '.'},
    {'.', '.', '6', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
  };
  // Copiar cada fila al tablero dinámico
  for (int i = 0; i < boardSize; i++) {
    for (int j=0; j<boardSize; j++) {
      board[i][j]=rows[i][j];
    }
  }
  
  sol=isValidSudokuBits(board, boardSize, &boardColSize);
  
  if (sol) {
    printf("True\n");
  }
  else {
    printf("False\n");
  }

  return 1;
}
