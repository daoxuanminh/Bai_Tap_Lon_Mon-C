#include <stdio.h>
#include <math.h>

void ComputeTriangle (double a,double b,double c,double &area,double &perimeter){
	double S;
	perimeter = a+b+c;
	S = (perimeter/2)*((perimeter/2)-a)*((perimeter/2)-b)*((perimeter/2)-c);
	area = sqrt(S);
}

int main (){
	double a,b,c;
	double area,perimeter;
	printf ("Nhap vao do dai 3 canh\n");
	scanf ("%lf %lf %lf",&a,&b,&c);
	if (a+b>c && a+c>b && b+c>a && a>0 && b>0 && c>0){
		ComputeTriangle (a,b,c,area,perimeter);
		printf ("Nua chu vi cua tam giac = %lf",perimeter/2);
		printf ("Dien tich cua tam giac = %lf\n",area);
	}
	else {
		printf ("Khong ton tai tam giac co so do %lf %lf %lf",a,b,c);
	}
	return 0;
}
có ai thấy chỗ này bị sửa ko !!!
	
