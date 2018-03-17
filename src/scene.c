#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "scene.h"
#include "variables.h"

extern int animation_ongoing;
extern int reflection;
extern int point;
extern float x_t;
extern float y_t;
extern float t1;
extern float h0;
extern float x_r;
extern float y_r;
extern float t2;
extern float angle;
extern float v0;
extern Position p_of_camera;
extern int z_positive;
extern Position_of_shooting p_shoot;
void draw_basket()
{

	GLfloat white_color[] = { 1, 1, 1, 1 };
	GLfloat black_color[] = { 0.0, 0.0, 0, 1 };
	GLfloat orange_color[] = { 0.75, 0.25, 0, 1 };
	GLfloat red_color[] = { 1, 0, 0, 1 };

	float height_of_hoop = 3.05;
	float pillar_width = 0.2;
	float x_of_pillar = -1.95;
	float y_of_pillar = 1.525;
	float z_of_pillar = 0.3;
	/*
	 * Creation of a pillar1 and posting to the position
	 */
	glPushMatrix();

	glTranslatef(0.3, 0, 0);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(x_of_pillar, y_of_pillar, -z_of_pillar);
	glScalef(pillar_width, height_of_hoop, pillar_width);
	glutSolidCube(1);
	glPopMatrix();

	/*
	 * Creation of a pillar2 and posting to the position
	 */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(x_of_pillar, y_of_pillar, z_of_pillar);
	glScalef(pillar_width, height_of_hoop, pillar_width);
	glutSolidCube(1);
	glPopMatrix();

	/* Creation of a bar1 and posting to the position */
	glPushMatrix();
	float x_bar = -1.6;
	float y_bar = 3;
	float bar_length = 0.9;
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(x_bar, y_bar, z_of_pillar);
	glScalef(bar_length, pillar_width, pillar_width);
	glutSolidCube(1);
	glPopMatrix();

	/* Creation of a bar2 and posting to the position */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glTranslatef(x_bar, y_bar, -z_of_pillar);
	glScalef(bar_length, pillar_width, pillar_width);
	glutSolidCube(1);
	glPopMatrix();

	/* Table */
	glPushMatrix();
	GLfloat shininess_of_table = 90;
	float y_of_table = 3.5;
	float table_width = 1.8;
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

	glTranslatef(-1, y_of_table, 0);
	glScalef(pillar_width, table_width, table_width);

	glutSolidCube(1);
	glPopMatrix();
	/* Lines on the table */
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(0, 0, 0);
	glLineWidth(3);
	float x_of_table = -0.89;
	float z_of_table1 = 0.9;
	float z_of_table2 = 0.4;
	/* external line */
	glBegin(GL_LINE_LOOP);
	glVertex3f(x_of_table, y_of_table - z_of_table1, z_of_table1);
	glVertex3f(x_of_table, y_of_table + z_of_table1, z_of_table1);
	glVertex3f(x_of_table, y_of_table + z_of_table1, -z_of_table1);
	glVertex3f(x_of_table, y_of_table - z_of_table1, -z_of_table1);
	glEnd();
	/* internal line */
	glBegin(GL_LINE_LOOP);
	glVertex3f(x_of_table, 2.8, z_of_table2);
	glVertex3f(x_of_table, 3.6, z_of_table2);
	glVertex3f(x_of_table, 3.6, -z_of_table2);
	glVertex3f(x_of_table, 2.8, -z_of_table2);
	glEnd();
	glLineWidth(1);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	/* Hoop */
	glPushMatrix();
	float r_of_hoop = 0.50;
	float weight_of_hoop = 0.05;
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, orange_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange_color);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess_of_table);
	glTranslatef(-r_of_hoop / 2 - weight_of_hoop, height_of_hoop, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(weight_of_hoop, r_of_hoop, 50, 30);
	glPopMatrix();

	glPopMatrix();

	/* Network */
	glPushMatrix();
	float u;
	float h = 0.1;
	glDisable(GL_LIGHTING);
	glTranslatef(0, height_of_hoop - 1, 0);
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

	float height_of_wall = 15;
	glMaterialfv(GL_FRONT, GL_AMBIENT, green);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glMaterialfv(GL_FRONT, GL_SPECULAR, green);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	/* Behind basket */
	glPushMatrix();
	glTranslatef(-8.5, 0, 0);
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(0, 0, height_of_wall);
	glVertex3f(0, height_of_wall, height_of_wall);
	glVertex3f(0, height_of_wall, -height_of_wall);
	glVertex3f(0, 0, -height_of_wall);
	glEnd();
	glPopMatrix();

	/* Front of basket */
	glPushMatrix();
	float x_wall1 = 25;
	float x_wall2 = -10;
	float z_wall = 17;
	glTranslatef(x_wall1, 0, 0);
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(0, 0, height_of_wall);
	glVertex3f(0, height_of_wall, height_of_wall);
	glVertex3f(0, height_of_wall, -height_of_wall);
	glVertex3f(0, 0, -height_of_wall);
	glEnd();
	glPopMatrix();
	/* Left wall */
	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(x_wall2, 0, height_of_wall);
	glVertex3f(x_wall2, height_of_wall, height_of_wall);
	glVertex3f(x_wall1, height_of_wall, height_of_wall);
	glVertex3f(x_wall1, 0, height_of_wall);

	glEnd();
	glPopMatrix();

	/* Right wall */
	glPushMatrix();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(x_wall2, 0, -height_of_wall);
	glVertex3f(x_wall2, height_of_wall, -height_of_wall);
	glVertex3f(x_wall1, height_of_wall, -height_of_wall);
	glVertex3f(x_wall1, 0, -height_of_wall);
	glEnd();
	glPopMatrix();
	/* Siling */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glMaterialfv(GL_FRONT, GL_AMBIENT, green);
	glMaterialfv(GL_FRONT, GL_SPECULAR, green);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(x_wall2, height_of_wall, z_wall);
	glVertex3f(x_wall2, height_of_wall, -z_wall);
	glVertex3f(x_wall1, height_of_wall, -z_wall);
	glVertex3f(x_wall1, height_of_wall, z_wall);
	glEnd();
	glPopMatrix();

	/* Floor */
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange);
	glMaterialfv(GL_FRONT, GL_SPECULAR, orange);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(x_wall2, -0.1, z_wall);
	glVertex3f(x_wall2, -0.1, -z_wall);
	glVertex3f(x_wall1, -0.1, -z_wall);
	glVertex3f(x_wall1, -0.1, z_wall);
	glEnd();
	glPopMatrix();

	/* Lines on the floor */
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glLineWidth(3);
	float floor_x1 = 20;
	float floor_x2 = 4;
	float floor_z1 = 9;
	float floor_z2 = 1.5;
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, floor_z1);
	glVertex3f(0, 0, -floor_z1);
	glVertex3f(floor_x1, 0, -floor_z1);
	glVertex3f(floor_x1, 0, floor_z1);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, floor_z2);
	glVertex3f(0, 0, -floor_z2);
	glVertex3f(floor_x2, 0, -floor_z2);
	glVertex3f(floor_x2, 0, floor_z2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	float v;
	float r_of_small_circle = 1.5;
	float x_of_small_circle = 4;
	for (v = 0; v <= 2 * PI; v += PI / 60) {
		glVertex3f(x_of_small_circle + r_of_small_circle * sin(v), 0,
			   r_of_small_circle * cos(v));
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

void set_position_of_camera(Position_of_shooting p_shoot)
{

	p_of_camera.y = 1.95;
	switch (p_shoot) {

	case Right_corner:
		p_of_camera.x = 0;
		p_of_camera.z = -6.75;
		z_positive = 1;
		break;
	case Right_side:
		p_of_camera.x = 4.77;
		p_of_camera.z = -4.77;
		z_positive = 1;
		break;
	case Center:
		p_of_camera.x = 6.75;
		p_of_camera.z = 0;
		z_positive = 1;
		break;
	case Left_side:
		p_of_camera.x = 4.77;
		p_of_camera.z = 4.77;
		z_positive = -1;
		break;
	case Left_corner:
		p_of_camera.x = 0;
		p_of_camera.z = 6.75;
		z_positive = -1;
	}

}

/* Function returns 1 if ball is enough close to the hoop
 * or 0 if not */
int score()
{

	if (angle < PI / 4)
		return 0;
	switch (p_shoot) {

	case Right_side:
	case Left_side:
		if (x_t < -3.2 && x_t > -3.3 && y_t < 1.75 && y_t > 1.35) {
			return 1;
			point = 1;
		} else {
			return 0;
		}
		break;
	case Right_corner:
	case Center:
	case Left_corner:
		if (x_t < -5.3 && x_t > -5.9 && y_t < 1.75 && y_t > 1.35) {
			return 1;
			point = 1;
		} else {
			return 0;
		}
		break;
	default:
		return 0;
	}

}

void draw_ball(Position_of_shooting p_shoot)
{
	/* Equation of projectile motion */
	x_t = -v0 * t1 * cos(angle);
	y_t = v0 * t1 * sin(angle) - G * t1 * t1 / 2;
	/* Equation of horizontal motion */
	x_r = v0 / 7 * t2;
	y_r = h0 - (G * t2 * t2) / 2;
	/* variable for moving ball from the center of screen */
	float move_y = 0.3;
	/* Ball */
	glPushMatrix();
	GLfloat orange_color[] = { 1, 0.278, 0.102, 1 };
	GLfloat shininess_of_ball = 90;
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange_color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, orange_color);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess_of_ball);
	/* When ball hit the table,until fall down */
	switch (p_shoot) {
	case Right_side:
	case Left_side:
		/* Move the ball if is necessary */
		if (animation_ongoing) {
			glTranslatef(x_t, y_t, -z_positive * x_t);
		}
		/* When ball hit the table,until fall down */
		if (reflection) {
			glTranslatef(x_r, y_r, z_positive * x_r);
		}
		if (!reflection) {
			glTranslatef(p_of_camera.x - 1, p_of_camera.y - move_y,
				     p_of_camera.z + z_positive);
		}
		/* draw line for navigation */
		if (!animation_ongoing && !reflection) {
			glDisable(GL_LIGHTING);
			glLineWidth(9);
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex3f(0, 0, 0);
			glColor3f(1, 0, 0);
			glVertex3f(v0 * cos(angle) / 15, v0 * sin(angle) / 15,
				   -z_positive * v0 * cos(angle) / 15);
			glEnd();
			glEnable(GL_LIGHTING);
		}
		break;
	case Center:
		if (animation_ongoing) {
			glTranslatef(x_t, y_t, 0);
		}
		if (reflection) {
			glTranslatef(x_r, y_r, 0);
		}
		if (!reflection) {
			glTranslatef(p_of_camera.x - 1, p_of_camera.y - move_y,
				     p_of_camera.z);
		}
		/* draw line for navigation */
		if (!animation_ongoing && !reflection) {
			glDisable(GL_LIGHTING);
			glLineWidth(9);
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex3f(0, 0, 0);
			glColor3f(0, 1, 0);
			glVertex3f(v0 * cos(angle) / 15, v0 * sin(angle) / 15,
				   0);
			glEnd();
			glEnable(GL_LIGHTING);
		}
		break;
	case Left_corner:
	case Right_corner:
		if (animation_ongoing) {
			glTranslatef(0, y_t, -x_t * z_positive);
		}
		glTranslatef(p_of_camera.x, p_of_camera.y - move_y,
			     p_of_camera.z + z_positive);
		/* draw line for navigation */
		if (!animation_ongoing && !reflection) {
			glDisable(GL_LIGHTING);
			glLineWidth(9);
			glColor3f(0, 1, 0);
			glBegin(GL_LINES);
			glVertex3f(0, 0, 0);
			glColor3f(1, 0, 0);
			glVertex3f(0, v0 * sin(angle) / 15,
				   -z_positive * v0 * cos(angle) / 15);
			glEnd();
			glEnable(GL_LIGHTING);
		}
		break;

	}
	glutSolidSphere(.3, 50, 50);
	glPopMatrix();
}
