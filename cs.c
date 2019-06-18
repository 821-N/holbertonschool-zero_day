#include <stdio.h>
#include <string.h>

//print array
void pa(int array[], int len){
  int i;
  for(i=0;i<len;i++)
    printf("%d\n",array[i]);
}

///////////////////
// Counting Sort //
/////////////////// ~12
void cs(int * array, size_t len){
  size_t i;
  int min,max;
  min=max=array[0];
  for(i=1;i<len;i++){
    int x=array[i];
    if(x<min)
      min=x;
    else if(x>max)
      max=x;
  }
  int range=max-min+1;
  size_t counts[range];
  memset(counts,0,sizeof counts);
  for(i=0;i<len;i++)
    counts[array[i]-min]++;
  for(i=0;i<range;i++)
    while(counts[i]--)
      *array++=i+min;
}

int main(){
  //  int test[10] = {1,2,3,4,5,6,7,8,9,10};
  int test[10] = {698,123,6,1,5,2,2,2,34,123};
  cs(test,10);
  pa(test,10);
}
