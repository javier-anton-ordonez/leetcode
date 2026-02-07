#include <stdio.h>

int romanToInt(char* s) {
    int solution = 0;
    int longitud = (sizeof(s)-1);
    int i=0;
    for(;i<longitud;i++){
        switch(s[i]){
            case 'I':
                if(s[i++] != 'I' || s[i++] != NULL)
                  solution--;
                else 
                  solution++;
                break;
            case 'V':
                if(s[i++] != 'V' || s[i++] != 'I' || s[i++] != NULL)
                  solution -= 5;
                else          
                  solution += 5;
                break;
            case 'X':
                if(s[i++] != 'X' || s[i++] != 'V' || s[i++] != 'I' || s[i++] != NULL)
                  solution -= 10;
                else
                  solution += 10;
                break;
            case 'L':
                if(s[i++] != 'L' || s[i++] != 'X' || s[i++] != 'V' || s[i++] != 'I' || s[i++] != NULL)
                  solution -= 50;
                else 
                  solution += 50;
                break;
            case 'C':
                if(s[i++] != 'C' || s[i++] != 'L' || s[i++] != 'X' || s[i++] != 'V' || s[i++] != 'I' || s[i++] != NULL)
                  solution -= 100;
                else 
                  solution += 100;
                break;
            case 'D':
                if(s[i++] != 'D' || s[i++] != 'C' || s[i++] != 'L' || s[i++] != 'X' || s[i++] != 'V' || s[i++] != 'I' || s[i++] != NULL)
                  solution -= 500;
                else 
                  solution += 500;
                break;
            case 'M':
                solution += 1000;
                break;
        }
    }
    return(solution);
}

void main(){
  char *s = "MCMXCIV";
  int solucion = romanToInt(s);

  printf("%d\n", solucion);


}
