#include<iostream>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
using namespace std;
void k(int x1,int y1,int x5,int y5, int it){
	float x3,y3,x4,y4,x2,y2,x,y;
	float angle=60*3.142/180;
	x3=(2*x1+x5)/3;
	y3=(2*y1+y5)/3;
	x4=(x1+2*x5)/3;
	y4=(y1+2*y5)/3;
	x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
	y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);
	if(it==0){
		line(x1,y1,x5,y5);
	}
	else if(it==1){
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x5,y5);
	}
	else{
		k(x1,y1,x3,y3,it-1);
		k(x3,y3,x,y,it-1);
		k(x,y,x4,y4,it-1);
		k(x4,y4,x5,y5,it-1);
	}
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	int x1,y1,x2,y2,n;
	cout<<"Enter the first co-ord of line : "<<endl;
	cin>>x1>>y1;
	cout<<"Enter the second co-ord of line : "<<endl;
	cin>>x2>>y2;
	cout<<"Enter the no of iteration :"<<endl;
	cin>>n;
	line(x1,y1,x2,y2);
	k(x1,y1,x2,y2,n);
	getch();
	return 0;
}
