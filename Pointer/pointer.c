#include <stdio.h>

int i=0;
void main(){
    int x= 10;
    int y =20;
    int *px = &x; // cu phap khai bao con tro con tro = dia chi bien
    *px=20; // thay doi  gia tri con tro -> doi dia chi nho cua bien va gia tri cua bien
    printf("*px:%d\n",*px);
    printf("x:%d\n",x);
    
    printf("px:%p\n",px);
    printf("&x:%p\n",&x);

    printf("*px:%p\n",*px);
    printf("x:%p\n",x);

    printf("&y:%p\n",&y);
    printf("y:%p",y);

} 