#include <stdlib.h>
#include <GL/glut.h>
#include "scene.h"
#include <math.h>
#include "variables.h"
#include "light.h"
#include "callback_functions.h"

/* Global variables */
Position p_of_camera;
Position_of_shooting p_shoot = Right_side;
int animation_ongoing = 0;
int reflection = 0;
int point = 0;
float x_r = 0;
float y_r = 0;
float angle = PI / 3;
float v0 = 8;
float t1 = 0;
float h0 = 0;
float t2 = 0;
float x_t;
float rotation_param = 0;
float y_t;
int z_positive = 1;
/* Dimension of window */
int window_width, window_height;

extern void set_position_of_camera(Position_of_shooting p_shoot);
void on_keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		/* Finishing */
		exit(0);
		break;
	case 's':
	case 'S':
		if (!animation_ongoing && !reflection) {
			animation_ongoing = 1;
			glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
		}
		break;
		/* Setting up position of shooting */
	case '1':
		if (!animation_ongoing && !reflection) {
			p_shoot = Right_corner;
			glutPostRedisplay();
		}
		break;
	case '2':
		if (!animation_ongoing && !reflection) {
			p_shoot = Right_side;
			glutPostRedisplay();
		}
		break;
	case '3':
		if (!animation_ongoing && !reflection) {
			p_shoot = Center;
			glutPostRedisplay();
		}
		break;
	case '4':
		if (!animation_ongoing && !reflection) {
			p_shoot = Left_side;
			glutPostRedisplay();
		}
		break;
	case '5':
		if (!animation_ongoing && !reflection) {
			p_shoot = Left_corner;
			glutPostRedisplay();
		}
		break;
		/* Increasing of the angle */
	case '+':
		if (!animation_ongoing) {
			if (angle < PI / 2 - 2 * PI / 72) {
				angle += PI / 72;
			}
		}
		glutPostRedisplay();
		break;
		/* Decreasing of the angle */
	case '-':
		if (!animation_ongoing) {
			if (angle > PI / 6) {
				angle -= PI / 72;
			}
		}
		glutPostRedisplay();
		break;
		/* Increasing of the start velocity */
	case '*':
		if (!animation_ongoing) {
			if (v0 < 20) {
				v0 += 0.3;
			}
		}
		glutPostRedisplay();
		break;
		/* Decreasing of the start velocity */
	case '/':
		if (!animation_ongoing) {
			if (v0 > 2) {
				v0 -= 0.3;
			}
		}
		glutPostRedisplay();
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
	set_position_of_camera(p_shoot);

	gluLookAt(p_of_camera.x, p_of_camera.y, p_of_camera.z,
		  0, p_of_camera.y, 0, 0, 1, 0);
	set_light();
	/* Rotate and translate entire scene */
	glRotatef(z_positive * rotation_param, 0, 1, 0);
	glTranslatef(0, -rotation_param / 45, 0);
	draw_hall();
	draw_basket();
	draw_ball(p_shoot);

	/* Show this picture */
	glutSwapBuffers();
}

void on_timer(int id)
{
	if (id != TIMER_ID)
		return;

	/* Animation is stopped when ball fals down or x coordinates iz less then 0 */
	if (((p_shoot == Right_side || p_shoot == Left_side)
	     && x_t < (-p_of_camera.x + 1)) || (y_t + p_of_camera.y) < 1) {
		animation_ongoing = 0;
		t1 = 0;
	} else
	    if (((p_shoot == Right_corner || p_shoot == Center
		  || p_shoot == Left_corner) && x_t < -6.75)
		|| (y_t + p_of_camera.y) < 1) {
		animation_ongoing = 0;
		t1 = 0;
	} else {
		t1 += 0.02;
	}
	/* Handling reflection */
	if (p_shoot == Right_side || p_shoot == Left_side || p_shoot == Center) {
		if (animation_ongoing
		    &&
		    ((p_shoot != Center && x_t < -3.3
		      && x_t > -(p_of_camera.x - 1))
		     || (p_shoot == Center && x_t < -5.35
			 && x_t > -(p_of_camera.x - 1)))
		    && y_t > 1.05 && y_t < 2.5) {
			reflection = 1;
			/* When ball kick the table we catch x (and z) and y coordinates of ball */
			animation_ongoing = 0;
			h0 = y_t + 1.95;
			x_r = -(p_of_camera.x + x_t);
		}
		/* End of reflection */
		if (y_r < 0) {
			reflection = 0;
			t1 = 0;

		}
		if (reflection == 1) {
			t2 += 0.02;
		} else {
			t2 = 0;
		}
	}
	/* Rotation and translation of scene is active if ball is in the fly */
	if (animation_ongoing || reflection) {
		rotation_param += 0.5;
	} else {
		rotation_param = 0;
	}

	/* Tell glut to call function on_display */
	glutPostRedisplay();

	/* Set the timer if animation is still active */
	if (animation_ongoing || reflection) {
		glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
	}

}
