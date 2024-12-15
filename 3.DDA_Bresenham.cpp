//Program 3 To draw Pattern by using DDA Line drawing & Bresenham circle drawing algorithm
#include<graphics.h>
void drawCircle(int xc, int yc, int x, int y)
{
 	putpixel(xc+x, yc+y, WHITE);
    	putpixel(xc-x, yc+y, WHITE);
    	putpixel(xc+x, yc-y, WHITE);
    	putpixel(xc-x, yc-y, WHITE);
    	putpixel(xc+y, yc+x, WHITE);
    	putpixel(xc-y, yc+x, WHITE);
    	putpixel(xc+y, yc-x, WHITE);
    	putpixel(xc-y, yc-x, WHITE);
}


void circleBres(int xc, int yc, int r) //Bresenham's circle drawing algorithm
{
    	int x = 0, y = r;
    	int d = 3 - 2 * r;
    	drawCircle(xc, yc, x, y);
    	while (y >= x)
    	{
   		 x++;
 		if (d > 0)
   		 {
   			 y--;
   			 d = d + 4 * (x - y) + 10;
   		 }
   		 else
   			 d = d + 4 * x + 6;
   		 drawCircle(xc, yc, x, y);
   		 delay(10);
    	}
}
void dda(int x0,int y0,int x1,int y1)  //DDA line drawing algorithm
{
    	int i;  
    	float x, y,dx,dy,steps,xin,yin; 	 
    	dx = (float)(x1 - x0);  
    	dy = (float)(y1 - y0);  
    	if(dx>=dy)  
    	{  
        		steps = dx;  
    	}  
    	else  
    	{  
        		steps = dy;  
    	}  
    	xin = dx/steps;  
    	yin = dy/steps;  
    	x = x0;  
    	y = y0;  
	for(int i=1; i<=steps;i++)
    	{  
        		putpixel(x, y, WHITE);  
        		x =x + xin;  
        		y =y + yin;  
        	}  
}

int main()
{
    	int xc = 100, yc = 70, r = 30;   	//Inner circle
    	int xc1 = 100, yc1 = 70, r1 = 60;   	// Outer circle
    	int x1 = 50 , y1 = 100, x2 = 150, y2 = 100,x3= 100, y3=10; // 3 points to draw three lines
 	int gd = DETECT, gm;
    	initgraph(&gd, &gm, NULL);  
    	circleBres(xc, yc, r);   		//Function call for Inner Circle
    	circleBres(xc1, yc1, r1);	 //Function call for Outer Circle
   	 dda(x1,y1,x2,y2);     		 //Function call for line1
    	dda(x1,y1,x3,y3);     	 	//Function call for line2
    	dda(x3,y3,x2,y2);     		 //Function call for line3
    	delay(50000);
    	return 0;
}
