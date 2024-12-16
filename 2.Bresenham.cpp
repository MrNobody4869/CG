#include <graphics.h>  // Include the graphics.h library for drawing

// Function to put pixels at corresponding symmetrical points
void drawCircle(int xc, int yc, int x, int y)
{
    // Plot the 8 symmetric points of the circle
    putpixel(xc + x, yc + y, RED);   // (x + xc, y + yc)
    putpixel(xc - x, yc + y, RED);   // (-x + xc, y + yc)
    putpixel(xc + x, yc - y, RED);   // (x + xc, -y + yc)
    putpixel(xc - x, yc - y, RED);   // (-x + xc, -y + yc)
    putpixel(xc + y, yc + x, RED);   // (y + xc, x + yc)
    putpixel(xc - y, yc + x, RED);   // (-y + xc, x + yc)
    putpixel(xc + y, yc - x, RED);   // (y + xc, -x + yc)
    putpixel(xc - y, yc - x, RED);   // (-y + xc, -x + yc)
}

// Function to generate a circle using Bresenham's algorithm
void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;  // Starting point at (0, r)
    int d = 3 - 2 * r;  // Initial decision parameter for the circle

    // Draw the initial points
    drawCircle(xc, yc, x, y);

    // Iterate until y is greater than or equal to x
    while (y >= x)
    {
        x++;  // Increment x
        // Check the decision parameter and update it accordingly
        if (d > 0)
        {
            y--;  // Decrease y if the decision parameter is positive
            d = d + 4 * (x - y) + 10;  // Update d for the new point
        }
        else
        {
            d = d + 4 * x + 6;  // Update d if the decision parameter is not positive
        }
        // Plot the new points
        drawCircle(xc, yc, x, y);
        delay(50);  // Add delay for visual effect
    }
}

// Driver code to initialize graphics and draw the circle
int main()
{
    int xc = 50, yc = 50, r = 30;  // Circle center at (50, 50) and radius 30
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Initialize graphics mode

    // Call the circle drawing function
    circleBres(xc, yc, r);

    delay(50000);  // Wait before closing the graphics window
    return 0;
}

/*
COMMANDS:

To compile and run the code, use the following commands:

gcc test.cpp -o test -lgraph   // Compile the code with the graphics library
./test                         // Run the program

*/
