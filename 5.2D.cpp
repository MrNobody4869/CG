//2D Transformation
#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
	int gd=DETECT,gm,s;
	initgraph(&gd,&gm,NULL);
	cout<<"MENU\n1.Translation\n2.Rotation\n3.Scaling\n"<<endl;
	cout<<"Enter your choice:";
	cin>>s;
	switch(s)
	{
    	case 1:
    	{   
           		int x1=200,y1=150,x2=300,y2=250;          	//Translation
            	int tx=50,ty=50;
            	cout<<"Rectangle before translation"<<endl;
            	setcolor(CYAN);
            	rectangle(x1,y1,x2,y2);
            	setcolor(GREEN);
            	cout<<"Rectangle after translation"<<endl;
            	rectangle(x1+tx,y1+ty,x2+tx,y2+ty);
            	getch();
            	break;
     	}
    	case 2:
    	{
         		int x1 = 200, y1 = 200;  // Top-left corner (pivot point)
            	int x2 = 300, y2 = 200;  // Top-right corner
            	int x3 = 300, y3 = 300;  // Bottom-right corner
            	int x4 = 200, y4 = 300;  // Bottom-left corner
            	double angle;
       	            cout << "Rectangle before rotation" << endl;
            	setcolor(CYAN);
            	rectangle(x1, y1, x3, y3);
            	cout << "Angle of rotation (in degrees): ";
            	cin >> angle;

            	// Convert the angle to radians
            	double radian = (angle * 3.14159265) / 180.0;

            	// Function to rotate a point around the pivot point (x1, y1)

            	auto rotatePoint = [&](int &x, int &y)
            	{
                	int x_new = x1 + (x - x1) * cos(radian) - (y - y1) * sin(radian);//calculating new coordinates
                	int y_new = y1 + (x - x1) * sin(radian) + (y - y1) * cos(radian);
                	x = x_new;                			 //Updating the Point's Coordinates
                	y = y_new;
            	};

            	// Rotate all four corners around the pivot point
            	rotatePoint(x2, y2); // Top-right corner
            	rotatePoint(x3, y3); // Bottom-right corner
            	rotatePoint(x4, y4); // Bottom-left corner

            	// Draw the rotated rectangle using the rotated points
            	setcolor(GREEN);
            	line(x1, y1, x2, y2);  // Top edge
            	line(x2, y2, x3, y3);  // Right edge
            	line(x3, y3, x4, y4);  // Bottom edge
            	line(x4, y4, x1, y1);  // Left edge
            	getch();
            	break;
    	}
    	case 3:
    	{
            	int x1=30,y1=30,x2=70,y2=70,sy=2,sx=2;       	//Scaling
            	cout<<"Before scaling"<<endl;
            	setcolor(CYAN);
            	rectangle(x1,y1,x2,y2);
            	cout<<"After scaling"<<endl;
            	setcolor(GREEN);
            	rectangle(x1*sx,y1*sy,x2*sx,y2*sy);
            	getch();
            	break;
     	}
   	default:
      	{
        		cout<<"Invalid Selection"<<endl;        	//Invalid Choice
        		break;
      	}

    }
   closegraph();
    return 0;
}
