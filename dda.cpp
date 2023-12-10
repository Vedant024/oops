#include<iostream>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
using namespace std;
void d(float x1,float y1,float x2,float y2){
	float dx,dy,xi,yi,x,y,len;
	int i;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy)){
		len=abs(dx);
	}
	else{
		len=abs(dy);
	}
	xi=dx/len;
	yi=dy/len;
	putpixel(x1,y1,15);
	x=x1;
	y=y1;
	for(i=0;i<len;i++){
		x=x+xi;
		y=y+yi;
		putpixel(x,y,15);
	}
}
void c(float xc, float yc, float r){
	float x,y,s;
	s=3-2*r;
	x=0;
	y=r;
	while(x<=y){
		putpixel(xc+x,yc+y,15);
		putpixel(xc-x,yc-y,15);
		putpixel(xc+x,yc-y,15);
		putpixel(xc-x,yc+y,15);
		putpixel(xc+y,yc+x,15);
		putpixel(xc-y,yc-x,15);
		putpixel(xc+y,yc-x,15);
		putpixel(xc-y,yc+x,15);
	if(s<0){
		s=s+4*x+6;
		x=x+1;
	}
	else{
		s=s+4*(x-y)+10;
		x=x+1;
		y=y-1;
	}}
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)" ");
	float x1,y1,x2,y2,x3,y3,xc,yc,r1,r2;
	cout<<"Enter the first co-ord of triangle :";
	cin>>x1>>y1;
	cout<<"Enter the second co-ord of triangle :";
	cin>>x2>>y2;
	cout<<"Enter the third co-ord of triangle :";
	cin>>x3>>y3;
	cout<<"Enter the Centre of circle :";
	cin>>xc>>yc;
	cout<<"Enter the radius of small circle :";
	cin>>r1;
	cout<<"Enter the radius of large circle :";
	cin>>r2;
	d(x1,y1,x2,y2);
	d(x2,y2,x3,y3);
	d(x3,y3,x1,y1);
	c(xc,yc,r1);
	c(xc,yc,r2);
	getch();
	return 0;
}
