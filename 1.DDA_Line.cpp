//Line drawing Algorithm
	#include<graphics.h>
    
   
	int main()  
	{  
        		int gd = DETECT ,gm, i;  
        		float x, y,dx,dy,steps,xin,yin;  
        		int x0, x1, y0, y1;  
        		initgraph(&gd, &gm, NULL);  
        		setbkcolor(WHITE);  
       	         	x0 = 100 , y0 = 200, x1 = 500, y1 = 300;  
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

        		for(i=1;i<=steps;i++)
        		{
                		putpixel(x, y, RED);  
                		x =x + xin;  
                		y =y + yin;
        		}

       	         	getch();  
        		closegraph();  
	}




