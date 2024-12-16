#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class kochCurve
{
    public:
        void koch(int it, int x1, int y1, int x5, int y5)
        {
            int x2, y2, x3, y3, x4, y4;
            int dx, dy;
            if (it == 0)
            {
                // Base case: Draw line when iterations reach 0
                line(x1, y1, x5, y5);
            }
            else
            {
                delay(10);  // Small delay for visual effect
                dx = (x5 - x1) / 3;
                dy = (y5 - y1) / 3;
                
                // Calculate the coordinates for the 4 new points
                x2 = x1 + dx;
                y2 = y1 + dy;
                
                x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6);
                y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);
                
                x4 = 2 * dx + x1;
                y4 = 2 * dy + y1;
                
                // Recursively draw the smaller Koch curves
                koch(it - 1, x1, y1, x2, y2);
                koch(it - 1, x2, y2, x3, y3);
                koch(it - 1, x3, y3, x4, y4);
                koch(it - 1, x4, y4, x5, y5);
            }
        }
};

int main()
{
    kochCurve k;
    int it;
    cout << "Enter Number Of Iterations : " << endl;
    cin >> it;
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Initialize graphics mode
    
    // Draw the Koch curve for three sides of an equilateral triangle
    k.koch(it, 150, 20, 20, 280);  // First side
    k.koch(it, 280, 280, 150, 20);  // Second side
    k.koch(it, 20, 280, 280, 280);  // Third side
    
    getch();
    closegraph();
    return 0;
}

/*
COMMANDS:

g++ test.cpp -o test -lgraph
./test

*/

/*
# Method/Function-related Theory:

1. **koch()**:
   - This is the recursive method that draws the Koch curve. The function takes the number of iterations (`it`), and two points `(x1, y1)` and `(x5, y5)`.
   - For each iteration, it splits the line segment into 4 smaller segments, where each segment forms a "bump" of the Koch curve.
   - The recursive call continues until `it` reaches 0, at which point a straight line is drawn using the `line()` function.

2. **line()**:
   - The `line(x1, y1, x5, y5)` function is used to draw a straight line between the points `(x1, y1)` and `(x5, y5)` once the recursion terminates.

3. **delay()**:
   - The `delay(10)` function introduces a small delay between each iteration to make the drawing process visible, giving a step-by-step animation effect.

4. **main()**:
   - The program initializes the graphics mode, asks for the number of iterations, and then calls `koch()` recursively to draw the Koch snowflake by drawing 3 sides of an equilateral triangle.

*/
