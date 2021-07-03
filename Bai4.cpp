#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
bool c[13][4];
int random(int min,int max){
    return min+rand()%(max+min-1);
}
int chiabai(){

    int x=random(1,52);
    int y=x;
    while(c[x/4][x%4]==true){
        x++;
        if (x>52)
        {
            x=1;
        }
        if (x==y)
        {
            break;
        }
    }
    if(c[x/4][x%4]==false) c[x/4][x%4]=true;
    return x;
}
void chia4(int a[],int b[],int c[],int d[]){
    for (int i = 0; i < 13; i++)
    {
        a[i]=chiabai();
        b[i]=chiabai();
        c[i]=chiabai();
        d[i]=chiabai();
    }
}
void demtuquy(int a[]){
    int tuquy[13];
    for (int i = 0; i < 13; i++)
    {
        tuquy[i]=0;
    }
    
    for (int i = 0; i < 13; i++)
    {
        tuquy[a[i]/4]++;
    }
    int dem=0;
    for (int i = 0; i < 13; i++)
    {
        if (tuquy[i]==4)
        {
            printf("\nco tu quy:%d",i);
            dem++;
        }
    }
    if (dem==0)
    {
        printf("\nkhong co tu quy nao");
    }
}
int main(){
    srand((int)time(0));
    int a[13],b[13],c[13],d[13];
    chia4(a,b,c,d);
    printf("\n Bai duoc chia cho nguoi thu 1 la:");
    for (int i = 0; i < 13; i++)
    {
        printf("%d   ",a[i]);
    }
    demtuquy(a);
    printf("\n Bai duoc chia cho nguoi thu 2 la:");
    for (int i = 0; i < 13; i++)
    {
        printf("%d   ",b[i]);
    }
    demtuquy(b);
    printf("\n Bai duoc chia cho nguoi thu 3 la:");
    for (int i = 0; i < 13; i++)
    {
        printf("%d   ",c[i]);
    }
    demtuquy(c);
    printf("\n Bai duoc chia cho nguoi thu  la:");
    for (int i = 0; i < 13; i++)
    {
        printf("%d   ",d[i]);
    }
    demtuquy(d);
}