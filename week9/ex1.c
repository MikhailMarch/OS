#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Frame{
  bool rBit;
  unsigned int durationCode;
  int page_currNumberber;

} Frame;



int main(){
  int nFrames;
  int hit = 0;
  int miss = 0;
  int currNumber=0;
  scanf("%d", &nFrames);
  Frame frames[nFrames];
  FILE *in_file = fopen("input.txt", "r");
 

  for (int i = 0 ; i < nFrames; i++) {
    frames[i].durationCode = 0;
    frames[i].page_currNumberber = -1;
    frames[i].rBit = false;
  }

for(int j = 0; j < 1000; j++) {
    fscanf(in_file, "%d", &currNumber);
    bool found = false;

    for (int i = 0; i < nFrames; i++) {
      if (currNumber == frames[i].page_currNumberber) {
        frames[i].rBit = true;
        found = true;
        hit++;
      }
    }

    if(!found){
        unsigned int minValue = frames[0].durationCode;
        int minElementIndex = 0;
        for(int j = 1; j < nFrames; j++){
          if(frames[j].durationCode < minValue){
            minValue = frames[j].durationCode;
            minElementIndex = j;
          }
        }
        frames[minElementIndex].rBit = true;
        frames[minElementIndex].page_currNumberber = currNumber;
        miss++;
    }

    for(int k = 0; k < nFrames; k++){
        if (frames[k].rBit) 
            frames[k].durationCode = frames[k].durationCode >> 1 | (1 << 31);
        else
            frames[k].durationCode  =frames[k].durationCode >> 1;
    }
  }

  fclose(in_file);
  printf("hit = %d , miss = %d,  Ratio = %f\n",hit, miss, (float)hit/miss);

  return 0;
}