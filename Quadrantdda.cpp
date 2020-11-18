#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<string.h>
using namespace std;
int abs (int n)
{
	return ( (n>0) ? n : ( n * (-1)));
}

//DDA Function for line generation
void DDA(int X0, int Y0, int X1, int Y1)
{
	// calculate dx & dy
	int dx = X1 - X0;
	int dy = Y1 - Y0;

	// calculate steps required for generating pixels
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	// calculate increment in x & y for each steps
	float Xinc = dx / (float) steps;
	float Yinc = dy / (float) steps;

	// Put pixel for each step
	float X = X0;
	float Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		putpixel (X,Y,WHITE); // put pixel at (X,Y)
		X += Xinc;		 // increment in x at each step
		Y += Yinc;		 // increment in y at each step
		delay(100);		 // for visualization of line-
							// generation step by step
	}
}

int main(){
  int gm,gd;
  int x,y;
  detectgraph(&gm,&gd);
  initgraph(&gm,&gd,NULL);
  x= getmaxx()/2;
  y= getmaxy()/2;
  line(x,0,x,y);
  line(0,y,x,y);
  line(x,y,getmaxx(),y);
  line(x,y,x,getmaxy());

  int X0 = x, Y0 = y, X1 = 550, Y1 = 200;
  DDA(X0, Y0, X1, Y1);
  line(x,y,X1,Y1);
  float slp=float((Y1-Y0))/float((X1-X0));
  printf("%s %f","Slope:", slp);

  delay(500000);

  
  closegraph();
  return 0;
}
