#include <stdlib.h>
#include <GL/glut.h>
#include "scene.h"
#include <math.h>
#include "variables.h"
#include "light.h"
#include "callback_functions.h"

/* Global variables */
Position p_of_camera;
int number_of_position = 2;
int animation_ongoing = 0;
float angle = PI / 3;
float v0 = 8;
float t = 0;
float x_t;
float y_t;
int z_positive = 1;
/* Dimension of window */
int window_width, window_height;

extern void set_position_of_camera(int number_of_position);
void on_keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		/* Finishing */
		exit(0);
		break;
	case 's':
	case 'S':
		if (!animation_ongoing) {
			animation_ongoing = 1;
			glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
		}
		break;
		/* Setting up position of shooting */
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
		number_of_position = key - '0';
		glutPostRedisplay();
		break;
		/* Increasing of the angle */
	case '+':
		if (!animation_ongoing) {
			if (angle < PI / 2 - 3 * PI / 36) {
				angle += PI / 36;
			}
		}
		break;
		/* Decreasing of the angle */
	case '-':
		if (!animation_ongoing) {
			if (angle > PI / 6) {
				angle -= PI / 36;
			}
		}
		break;
		/* Increasing of the start velocity */
	case '*':
		if (!animation_ongoing) {
			if (v0 < 12) {
				v0 += 0.3;
			}
		}
		break;
		/* Decreasing of the start velocity */
	case '/':
		if (!animation_ongoing) {
			if (v0 > 2) {
				v0 -= 0.3;
			}
		}
		break;
	}
}

void on_reshape(int width, int height)
{
	/* Remember width and height of window */
	window_width = width;
	window_height = height;
}

void on_display(void)
{
	/* Clearing buffers */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Setting up  viewport */
	glViewport(0, 0, window_width, window_height);

	/* Setting up projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, window_width / (float)window_height, 0.5, -30);

	/* Setting up point of view */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	set_position_of_camera(number_of_position);

	gluLookAt(p_of_camera.x, p_of_camera.y, p_of_camera.z,
		  0, p_of_camera.y, 0, 0, 1, 0);
	set_light();
	draw_hall();
	draw_basket();
	draw_ball(number_of_position);

	/* Show this picture */
	glutSwapBuffers();
}

void on_timer(int id)
{
	if (id != TIMER_ID)
		return;

	/* Animation is stopped when ball fals down or x coordinates iz less then 0 */
	if (((number_of_position == 2 || number_of_position == 4)
	     && x_t < -3.77) || (y_t + p_of_camera.y) < 1) {
		animation_ongoing = 0;
		t = 0;
	} else
	    if (((number_of_position == 1 || number_of_position == 3
		  || number_of_position == 5) && x_t < -5.75)
		|| (y_t + p_of_camera.y) < 1) {
		animation_ongoing = 0;
		t = 0;
	} else {
		t += 0.02;
	}

	/* Tell glut to call function on_display */
	glutPostRedisplay();

	/* Set the timer if animation is still active */
	if (animation_ongoing) {
		glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
	}

}
