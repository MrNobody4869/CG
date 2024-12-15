#include <GL/glut.h>
#include <cmath>

// Global variables
float sunX = -0.75;    		// Initial sun position
float sunSpeed = 0.01; 	// Speed of sun movement
bool inSunrise = true;  	// Flag to determine if in sunrise phase

// Define colors as float arrays
float skyColor[] = {0.0, 0.5, 1.0};   		// Light blue sky
float sunriseColor[] = {1.0, 1.0, 0.0};   	// Yellow for sunrise
float sunsetColor[] = {1.0, 0.5, 0.0};		// Orange for sunset

void drawSky() 
{
	glColor3fv(skyColor);  // Use the color array for the sky
	glBegin(GL_QUADS);
    		glVertex2f(-1.0, -1.0);
    		glVertex2f(1.0, -1.0);
    		glVertex2f(1.0, 1.0);
    		glVertex2f(-1.0, 1.0);
	glEnd();
}

void drawSun() {
	glColor3fv(inSunrise ? sunriseColor : sunsetColor);  // Use color based on sunrise or sunset
	glBegin(GL_TRIANGLE_FAN);
    		glVertex2f(sunX, 0.0);  // Center of the sun
    		float radius = 0.1;
    		for (int i = 0; i <= 360; i += 10)
		{
        			float angle = i * M_PI / 180.0;
        			glVertex2f(sunX + radius * cos(angle), radius * sin(angle));
    		}
	glEnd();
}

void display() 
{
	drawSky();
	drawSun();
	glFlush();
}

void update(int value)
 {
	sunX += sunSpeed;  // Update sun position
	if (inSunrise && sunX >= 0.75) 
	{
    		inSunrise = false;  		// Switch to sunset
	} 
	glutPostRedisplay();  // Request redraw
	glutTimerFunc(30, update, 0);  	// Continue animation
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);                      	// Initialize the GLUT library
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// Set display mode to single buffer and RGB colors
	glutInitWindowSize(500, 500);               	// Set window size
	glutCreateWindow("Sunrise and Sunset Animation"); // Create window
	glutDisplayFunc(display);                   	// Register display callback function
	glutTimerFunc(30, update, 0);               	// Start animation timer
	glutMainLoop();                             	// Enter the GLUT event processing loop
	return 0;
}



