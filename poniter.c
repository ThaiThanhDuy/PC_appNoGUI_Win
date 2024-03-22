#include <stdio.h>

int i=0;
void main(){
    int x= 10;
    int y =20;
    int *px = &x; // cu phap khai bao con tro con tro = dia chi bien
    *px=20; // thay doi  gia tri con tro -> doi dia chi nho cua bien va gia tri cua bien
    printf("%d\n",*px);
    printf("%d\n",x);

    printf("%p\n",px);
    printf("%p\n",&x);

    printf("%p\n",*px);
    printf("%p\n",x);

    printf("%p\n",&y);
    printf("%p",y);

} 