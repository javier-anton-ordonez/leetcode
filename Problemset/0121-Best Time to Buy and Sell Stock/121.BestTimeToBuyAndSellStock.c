#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
    
  int maxProfit=0,minValue=prices[0];
  for (int i=0; i<pricesSize; i++) {
    if (minValue>prices[i]) {
      minValue=prices[i];
    }
    else {
      int profit=prices[i]-minValue;
      if (maxProfit<profit) {
        maxProfit=profit;
      }
    }
  }

  return maxProfit;
}

int main(int argc, char *argv[]){

  int price[]={7,1,5,3,6,4};
  
  int profit = maxProfit(price, 5);

  printf("%d\n", profit);
  return 1;
}
