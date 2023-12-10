#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
static int xmax,ymax,xmin,ymin;
int getcode(int x,int y){
	int code=0;
	if(y>ymax) code|=TOP;
	if(y<ymin) code|=BOTTOM;
	if(x>xmax) code|=RIGHT;
	if(x<xmin) code|=LEFT;
	return code;
}
int main(){
	int gd=DETECT,gm,x1,y1,x2,y2;
	initgraph(&gd,&gm,(char*)" ");
	cout<<"Enter the maximum co-ords of Window"<<endl;
	cin>>xmax>>ymax;
	cout<<"Enter the minimum co-ords of Window"<<endl;
	cin>>xmin>>ymin;
	rectangle(xmin,ymin,xmax,ymax);
	cout<<"Enter the first co-ords of line to be clipped :"<<endl;
	cin>>x1>>y1;
	cout<<"Enter the second co-ords of line to be clipped "<<endl;
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	int outcode1=getcode(x1,y1),outcode2=getcode(x2,y2);
	cout<<outcode1<<endl;
	cout<<outcode2<<endl;
	int accept=0;
	while(1){
		float m=(float)(y2-y1)/(x2-x1);
		if(outcode1==0 && outcode2==0){
			accept=1;
			break;
		}
		else if(outcode1 & outcode2!=0){
			break;
		}
		else{
			int x,y,temp;
			if(outcode1==0){
				temp=outcode2;
			}
			else{
				temp=outcode1;
			}
			if(temp&TOP){
				x=x1+m*(ymax-y1);
				y=ymax;
				cout<<"TT"<<x<<","<<y<<endl;
			}
			else if(temp&BOTTOM){
				x=x1+m*(ymin-y1);
				y=ymin;
				cout<<"TB"<<x<<","<<y<<endl;
			}
			else if(temp&RIGHT){
				y=y1+m/(xmax-x1);
				x=xmax;
				cout<<"TR"<<x<<","<<y<<endl;
			}
			else if(temp&LEFT){
				y=y1+m/(xmin-x1);
				x=xmin;
				cout<<"TL"<<x<<","<<y<<endl;
			}
			if(temp==outcode1){
				x1=x;
				y1=y;
				outcode1=getcode(x1,y1);
			}
			else if(temp==outcode2){
				x2=x;
				y2=y;
				outcode2=getcode(x2,y2);
			}
		}
	
		}
		if(accept){
		cout<<"line accepted";
    	cout<<x1<<endl;
    	cout<<y1<<endl;
    	cout<<x2<<endl;
    	cout<<y2<<endl;
    	cleardevice();
    	rectangle(xmin,ymin,xmax,ymax);
    	setcolor(YELLOW);
    	line(x1,y1,x2,y2);
		}
		else{
			"Line rejected";
		}
		getch();
		return 0;
	}
	

