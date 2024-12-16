#include <graphics.h>  // Include the graphics.h library for drawing

int main()  
{  
    int gd = DETECT, gm, i;  
    float x, y, dx, dy, steps, xin, yin;  
    int x0, x1, y0, y1;  

    // Initialize the graphics system
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);  // Set the background color to white

    // Initial and final coordinates for the line
    x0 = 100, y0 = 200, x1 = 500, y1 = 300;  

    // Calculate the differences in x and y
    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0);  

    // Determine the number of steps required for drawing the line
    if(dx >= dy)  
    {  
        steps = dx;  // If the difference in x is greater, use dx for steps
    }  
    else  
    {  
        steps = dy;  // If the difference in y is greater, use dy for steps
    }  

    // Calculate the increment values for x and y for each step
    xin = dx / steps;  
    yin = dy / steps;  

    // Start at the initial point (x0, y0)
    x = x0;  
    y = y0;  

    // Loop to plot the points for the line
    for(i = 1; i <= steps; i++)  
    {  
        // Plot the current point
        putpixel(x, y, RED);  

        // Update the x and y values for the next point
        x = x + xin;  
        y = y + yin;
    }

    // Wait for user input before closing the window
    getch();  

    // Close the graphics window
    closegraph();  
}

/*

COMMANDS:

To compile and run the code, use the following commands:

gcc test.cpp -o test -lgraph   // Compile the code with the graphics library
./test                         // Run the program

*/

