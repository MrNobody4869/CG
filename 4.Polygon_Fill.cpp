//Scan Line fill Algorithm
#include <graphics.h>

// Function to implement scan-line polygon filling
void scanFill(int x[], int y[], int edges)
{
	int i, j, temp;
	int ymax = 300, ymin = 100;

	
	// Scan each scan-line within the polygon's vertical extent
	for (i = ymin; i <= ymax; i++)
	{
        		// Initialize an array to store the intersection points
        		int interPoints[edges], count = 0;
        		for (j = 0; j < edges; j++)
        		{
                		int next = (j + 1) % edges;

                		// Check if the current edge intersects with the scan line
                		if ((y[j] > i && y[next] <= i) || (y[next] > i && y[j] <= i))
                		{
                    			interPoints[count++] = x[j] + (i - y[j]) * (x[next] - x[j]) / (y[next] - y[j]);
                		}
        		}

        		// Sort the intersection points in ascending order
        		for (j = 0; j < count - 1; j++)
        		{
                		for (int k = 0; k < count - j - 1; k++)
                		{
                    			if (interPoints[k] > interPoints[k + 1])
                    			{
                            			temp = interPoints[k];
                            			interPoints[k] = interPoints[k + 1];
                            			interPoints[k + 1] = temp;
                    			}
                		}
        		}

        		// Fill the pixels between pairs of intersection points
        		for (j = 0; j < count; j += 2)
        		{
                		line(interPoints[j], i, interPoints[j + 1], i);
        		}
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int x[] = {100, 200, 300};
	int y[] = {100, 300, 200};
	int edges = 3;
	scanFill(x, y, edges);
	delay(5000);
	closegraph();
	return 0;
}


/*
COMMANDS:

gcc test.cpp -o test -lgraph
./test

*/
