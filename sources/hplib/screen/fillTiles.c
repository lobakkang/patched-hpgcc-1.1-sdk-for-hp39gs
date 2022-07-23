#include <hpscreen.h>

void fillTiles(unsigned char* sprite, int length, int x,int y, int right, int down){

    int startX=x;
    int rightCount;

    while(down>0){

    rightCount = right;
     x=startX;

     while(rightCount>0){

     drawBlockOR(sprite, length,x, y);
     rightCount--;
     x=x+8; //move accross one
     }

    y=y+length;
    down--;

     }
 return;
}

