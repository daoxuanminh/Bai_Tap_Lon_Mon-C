#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
#include "student.h"

void nhapN(student sv[], int n, int dem){
    for (; dem< n; dem++)
    {
    printf("\nNhap ten sinh vien:");
    fflush(stdin); gets(sv[dem].name);
    fflush(stdin);
    printf("nhap diem:");
    scanf("%d",&sv[dem].point);   
    }
}
void ghifile(student sv[],int n,int dem){
    FILE *fp;
    fp=fopen("SV2021.dat","ab");
    for (; dem < n; dem++)
    {
        fprintf(fp,"%s\n",sv[dem].name);
        fprintf(fp,"%d\n",sv[dem].point);
    }
    fclose(fp);
}  
void docfile(student sv[], int &n){
    FILE *fp;
    fp=fopen("SV2021.dat","rb");
    int i=0;
    while(fscanf(fp,"%[^\n]",&sv[i].name)!=EOF){
        fscanf(fp,"\n%d\n",&sv[i].point);
        i++;
    }
    n=i;
    fclose(fp);
}
void xuatfile(student sv){
    FILE *fp;
    fp=fopen("output.txt","a");
    fprintf(fp,"Ten sinh vien:%40sDiem:%10d\n",sv.name,sv.point);
    fclose(fp);   
}
void timsv(student sv[],int n){
    char timsv[40];
    printf("Nhap ten sinh vien:");
    fflush(stdin);
    gets(timsv);
    int dem=0;
    for (int i = 0; i < n; i++)
    {
        char *x;
        x=strstr(sv[i].name,timsv);
        if (x!=NULL)
        {
            printf("\n%20s%10d",sv[i].name,sv[i].point);
            xuatfile(sv[i]);
            dem++;
        }
    }
    if (dem==0)
    {
        printf("Khong tim thay nguoi nay");
    }
    
    /*for (int i = 0; i < n; i++)
    {
        if(strstr(strupr(sv[i].name),strupr(name))!=NULL){
            printf("%10s %10d",sv[i].name,sv[i].point);
            xuatfile(sv[i]);
        };
    }
    */
}
int main(){
    student sv[5];
    int key,n,themsv,dem;
    while(true){
        system("cls");
        printf("    CHUONG TRINH QUAN LY SINH VIEN    \n");
        printf("--------------------------------------\n");
        printf("    1.Xem danh sach sinh vien         \n");
        printf("    2.Nhap them sinh vien             \n");
        printf("    3.Tim theo ten sinh vien          \n");
        printf("    4.Thoat chuong trinh              \n");
        printf("**************************************\n");
        printf("**       Nhap lua chon cua ban      **\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            docfile(sv,n);
            printf("%20s%10s\n","Ho ten","Diem");
            for (int i = 0; i < n; i++)
            {
                printf("%20s%10d\n",sv[i].name,sv[i].point);
            }
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
        case 2:
            printf("Nhap so luong sinh vien can them");
            scanf("%d",&themsv);
            dem=n;
            n+=themsv;
            nhapN(sv,n,dem);
            ghifile(sv,n,dem);
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
        case 3:
            timsv(sv,n);
            getch();
            break;
        case 4:
            printf("\nBan da chon thoat chuong trinh!");
            getch();
            return 0;
        default:
            printf("\nKhong co chuc nang nay!");
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
            break;
        }
    }
}