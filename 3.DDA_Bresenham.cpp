#include <graphics.h>  // Include the graphics library for graphical output

// Function to plot points in all 8 symmetric locations for the circle
void drawCircle(int xc, int yc, int x, int y)
{
    // Plot all the symmetrical points for the circle at (xc, yc) with radius (x, y)
    putpixel(xc + x, yc + y, WHITE);   // First octant (x, y)
    putpixel(xc - x, yc + y, WHITE);   // Second octant (-x, y)
    putpixel(xc + x, yc - y, WHITE);   // Third octant (x, -y)
    putpixel(xc - x, yc - y, WHITE);   // Fourth octant (-x, -y)
    putpixel(xc + y, yc + x, WHITE);   // Fifth octant (y, x)
    putpixel(xc - y, yc + x, WHITE);   // Sixth octant (-y, x)
    putpixel(xc + y, yc - x, WHITE);   // Seventh octant (y, -x)
    putpixel(xc - y, yc - x, WHITE);   // Eighth octant (-y, -x)
}

// Bresenham's Circle Drawing Algorithm
void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;  // Starting point of the circle at (0, r)
    int d = 3 - 2 * r;  // Initial decision parameter
    drawCircle(xc, yc, x, y);  // Draw the initial points

    // Loop until y >= x, which means the entire circle is drawn
    while (y >= x)
    {
        x++;  // Increment x-coordinate
        // Check the decision parameter to decide if y should decrease
        if (d > 0)
        {
            y--;  // Decrease y-coordinate
            d = d + 4 * (x - y) + 10;  // Update decision parameter if y is decreased
        }
        else
        {
            d = d + 4 * x + 6;  // Update decision parameter if y is not decreased
        }
        drawCircle(xc, yc, x, y);  // Draw the points based on the updated (x, y)
        delay(10);  // Delay to allow visualization of the drawing
    }
}

// DDA Line Drawing Algorithm
void dda(int x0, int y0, int x1, int y1)
{
    int i;
    float x, y, dx, dy, steps, xin, yin;

    dx = (float)(x1 - x0);  // Calculate the difference in x-coordinates
    dy = (float)(y1 - y0);  // Calculate the difference in y-coordinates

    // Determine the number of steps required for the line
    if (dx >= dy)
        steps = dx;
    else
        steps = dy;

    // Calculate the increment values for x and y
    xin = dx / steps;
    yin = dy / steps;

    x = x0;  // Initialize x-coordinate
    y = y0;  // Initialize y-coordinate

    // Loop through and plot the points on the line
    for (i = 1; i <= steps; i++)
    {
        putpixel(x, y, WHITE);  // Plot the pixel at the current (x, y)
        x = x + xin;  // Increment x-coordinate
        y = y + yin;  // Increment y-coordinate
    }
}

int main()
{
    int xc = 100, yc = 70, r = 30;    // Inner circle parameters (center at (100, 70), radius 30)
    int xc1 = 100, yc1 = 70, r1 = 60;  // Outer circle parameters (center at (100, 70), radius 60)
    int x1 = 50, y1 = 100, x2 = 150, y2 = 100, x3 = 100, y3 = 10; // Points for the three lines
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Function calls to draw circles
    circleBres(xc, yc, r);   // Draw the inner circle
    circleBres(xc1, yc1, r1);  // Draw the outer circle

    // Function calls to draw lines
    dda(x1, y1, x2, y2);  // Draw the first line
    dda(x1, y1, x3, y3);  // Draw the second line
    dda(x3, y3, x2, y2);  // Draw the third line

    delay(50000);  // Delay before closing the graphics window
    return 0;
}

/*
COMMANDS:

To compile and run the program, use the following commands:

gcc test.cpp -o test -lgraph   // Compile the C++ program with the graphics library
./test                         // Run the compiled program

*/
