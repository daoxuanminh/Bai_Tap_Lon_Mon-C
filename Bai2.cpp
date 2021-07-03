#include<stdio.h>
#include<stdlib.h>
 struct object
{
    char name;
    float g,v,quantity;
    int solution;
};
void swap(object &x,  object &y)
{
    object temp = x;
    x = y;
    y = temp;
}
void SapXep(object sp[], int n)
 {
    for(int i = 0; i <= n - 1; i++)
       for(int j = i + 1; j <= n; j++)
       if (sp[i].quantity < sp[j].quantity)
       swap(sp[i], sp[j]);
 }
 void Greedy(object sp[], int n, float W)
 {
     float tonggia=0;
      for (int i = 0; i < n; i++) {
            sp[i].solution = W / sp[i].g;
            W -= sp[i].solution * sp[i].g;
            tonggia+=sp[i].solution*sp[i].v;
      }
      printf("%2.0f\n",tonggia);
 }
int main(){
    int n,w,i;
    struct object sp[4];
    i=0;
    FILE *fiop;
    fiop=fopen("BAG.INP","r");
    fscanf(fiop,"%d %d\n",&n,&w);
    while (fscanf(fiop,"%f %f %c\n",&sp[i].g,&sp[i].v,&sp[i].name)!=EOF)
    {
        ++i;
    }
    fclose(fiop);
   for (int i = 0; i < n; i++)
   {
       sp[i].quantity=sp[i].v/sp[i].g;
   }
    SapXep(sp,n);
    Greedy(sp,n,(float)w);
    for (int i = 0; i <n; i++)
    {   
        if (sp[i].solution!=0)
        {
              printf("%c ",sp[i].name);
             printf("%d\n",sp[i].solution);
    }
 }   
}