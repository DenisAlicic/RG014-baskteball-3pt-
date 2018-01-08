#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "scene.h"
#include "variables.h"

extern int animation_ongoing;
extern float x_t;
extern float y_t;
extern float t;
extern float angle;
extern float v0;
extern Position p_of_camera;
extern int z_positive;
extern int number_of_position;
void draw_basket()
{

	GLfloat white_color[] = { 1, 1, 1, 1 };
	GLfloat black_color[] = { 0.0, 0.0, 0, 1 };
	GLfloat orange_color[] = { 0.75, 0.25, 0, 1 };
	GLfloat red_color[] = { 1, 0, 0, 1 };
	/*
	 * Creation of a pillar1 and posting to the position
	 */
	glPushMatrix();

	glTranslatef(0.3, 0, 0);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(-1.95, 1.525, -0.3);
	glScalef(.2, 3.05, .2);
	glutSolidCube(1);
	glPopMatrix();

	/*
	 * Creation of a pillar2 and posting to the position
	 */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(-1.95, 1.525, 0.3);
	glScalef(.2, 3.05, .2);
	glutSolidCube(1);
	glPopMatrix();

	/* Creation of a bar1 and posting to the position */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(-1.6, 3., 0.3);
	glScalef(0.9, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	/* Creation of a bar2 and posting to the position */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(-1.6, 3., -0.3);
	glScalef(0.9, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	/* Table */
	glPushMatrix();
	GLfloat shininess_of_table = 90;
	glMaterialfv(GL_FRONT, GL_AMBIENT, white_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white_color);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess_of_table);
	if (animation_ongoing && score() == 1) {
		glMaterialfv(GL_FRONT, GL_AMBIENT, red_color);
		glMaterialfv(GL_FRONT, GL_SPECULAR, red_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red_color);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess_of_table);
	}
	glTranslatef(-1, 3.50, 0);
	glScalef(0.2, 1.8, 1.8);

	glutSolidCube(1);
	glPopMatrix();
	/* Lines on the table */
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.89, 2.6, 0.9);
	glVertex3f(-0.89, 4.4, 0.9);
	glVertex3f(-0.89, 4.4, -0.9);
	glVertex3f(-0.89, 2.6, -0.9);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.89, 2.8, 0.4);
	glVertex3f(-0.89, 3.6, 0.4);
	glVertex3f(-0.89, 3.6, -0.4);
	glVertex3f(-0.89, 2.8, -0.4);
	glEnd();
	glLineWidth(1);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	/* Hoop */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, orange_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange_color);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess_of_table);
	glTranslatef(-0.3, 3.05, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.05, 0.50, 50, 30);
	glPopMatrix();

	glPopMatrix();

	/* Network */
	glPushMatrix();
	float u;
	float h = 0.1;
	glDisable(GL_LIGHTING);
	glTranslatef(0, 2.05, 0);
	glColor3f(0, 0, 0);
	float r1 = 0.45;
	float r2 = 0.3;
	for (u = 0; u <= 2 * PI; u += PI / 8) {
		glBegin(GL_LINES);
		glVertex3f(r1 * cos(u), 1, r1 * sin(u));
		glVertex3f(r2 * cos(u + PI / 8), h, r2 * sin(u + PI / 8));
		glEnd();
		glBegin(GL_LINES);
		glVertex3f(r1 * cos(u + PI / 16), 1, r1 * sin(u + PI / 16));
		glVertex3f(r2 * cos(u - PI / 8 + PI / 16), h,
			   r2 * sin(u - PI / 8 + PI / 16));
		glEnd();
	}
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void draw_hall()
{

	GLfloat green[] = { 0.2, 1, 0.2, 1 };
	GLfloat shininess = 30;
	GLfloat orange[] = { 1, 0.2, 0, 1 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, green);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glMaterialfv(GL_FRONT, GL_SPECULAR, green);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	/* Behind basket */
	glPushMatrix();
	glTranslatef(-8.5, 0, 0);
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(0, 0, 15);
	glVertex3f(0, 15, 15);
	glVertex3f(0, 15, -15);
	glVertex3f(0, 0, -15);
	glEnd();
	glPopMatrix();

	/* Front of basket */
	glPushMatrix();
	glTranslatef(25, 0, 0);
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(0, 0, 15);
	glVertex3f(0, 15, 15);
	glVertex3f(0, 15, -15);
	glVertex3f(0, 0, -15);
	glEnd();
	glPopMatrix();
	/* Left wall */
	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-10, 0, 15);
	glVertex3f(-10, 15, 15);
	glVertex3f(25, 15, 15);
	glVertex3f(25, 0, 15);

	glEnd();
	glPopMatrix();

	/* Right wall */
	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-10, 0, -15);
	glVertex3f(-10, 15, -15);
	glVertex3f(25, 15, -15);
	glVertex3f(25, 0, -15);
	glEnd();
	glPopMatrix();
	/* Siling */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glMaterialfv(GL_FRONT, GL_AMBIENT, green);
	glMaterialfv(GL_FRONT, GL_SPECULAR, green);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-10, 15, 17);
	glVertex3f(-10, 15, -17);
	glVertex3f(25, 15, -17);
	glVertex3f(25, 15, 17);
	glEnd();
	glPopMatrix();

	/* Floor */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange);
	glMaterialfv(GL_FRONT, GL_SPECULAR, orange);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-10, -0.1, 17);
	glVertex3f(-10, -0.1, -17);
	glVertex3f(25, -0.1, -17);
	glVertex3f(25, -0.1, 17);
	glEnd();
	glPopMatrix();

	/* Lines on the floor */
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 9);
	glVertex3f(0, 0, -9);
	glVertex3f(20, 0, -9);
	glVertex3f(20, 0, 9);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 1.5);
	glVertex3f(0, 0, -1.5);
	glVertex3f(4, 0, -1.5);
	glVertex3f(4, 0, 1.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	float v;
	for (v = 0; v <= 2 * PI; v += PI / 60) {
		glVertex3f(4 + 1.5 * sin(v), 0, 1.5 * cos(v));
	}
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	/* Line for 3pt */
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glLineWidth(3);
	float r = 6.75;
	float u;
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	for (u = 0; u <= PI; u += PI / 1000) {
		glVertex3f(r * sin(u), 0, r * cos(u));
	}
	glLineWidth(1);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void set_position_of_camera(int number_of_position)
{

	p_of_camera.y = 1.95;
	switch (number_of_position) {

	case 1:
		p_of_camera.x = 0;
		p_of_camera.z = -6.75;
		z_positive = 1;
		break;
	case 2:
		p_of_camera.x = 4.77;
		p_of_camera.z = -4.77;
		z_positive = 1;
		break;
	case 3:
		p_of_camera.x = 6.75;
		p_of_camera.z = 0;
		z_positive = 1;
		break;
	case 4:
		p_of_camera.x = 4.77;
		p_of_camera.z = 4.77;
		z_positive = -1;
		break;
	case 5:
		p_of_camera.x = 0;
		p_of_camera.z = 6.75;
		z_positive = -1;
	}

}

/* Function returns 1 if ball is enough close to the hoop
 * or 0 if not */
int score()
{

	switch (number_of_position) {

	case 2:
	case 4:
		if (x_t < -3 && x_t > -3.3 && y_t < 1.75 && y_t > 1) {
			return 1;
		} else {
			return 0;
		}
		break;
	case 1:
	case 3:
	case 5:
		if (x_t < -5 && x_t > -5.75 && y_t < 1.75 && y_t > 1) {
			return 1;
		} else {
			return 0;
		}
		break;
	default:
		return 0;
	}

}

void draw_ball(int number_of_position)
{
	/* Equation of projectile motion */
	x_t = -v0 * t * cos(angle);
	y_t = v0 * t * sin(angle) - G * t * t / 2;
	/* Ball */
	glPushMatrix();
	GLfloat orange_color[] = { 1, 0.278, 0.102, 1 };
	GLfloat shininess_of_ball = 90;
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, orange_color);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess_of_ball);
	switch (number_of_position) {
	case 2:
	case 4:
		if (animation_ongoing) {
			glTranslatef(x_t, y_t, -z_positive * x_t);
		}
		glTranslatef(p_of_camera.x - 1, p_of_camera.y - .3,
			     p_of_camera.z + z_positive);
		break;
	case 3:
		if (animation_ongoing) {
			glTranslatef(x_t, y_t, 0);
		}
		glTranslatef(p_of_camera.x - 1, p_of_camera.y - .3,
			     p_of_camera.z);
		break;
	case 5:
	case 1:
		if (animation_ongoing) {
			glTranslatef(0, y_t, -x_t * z_positive);
		}
		glTranslatef(p_of_camera.x, p_of_camera.y - .3,
			     p_of_camera.z + z_positive);
	}
	glutSolidSphere(.3, 50, 50);
	glPopMatrix();
}
