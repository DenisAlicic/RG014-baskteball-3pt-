#include <stdlib.h>
#include <GL/glut.h>
#include "scene.h"
#include "variables.h"

void draw_basket(){
    
     /*
     * Kreira se kocka(stub1) i primenjuje se geometrijska transformacija na
     * njega.
     */
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(-2, 1.525, -0.3);
    glScalef(.2, 3.05, .2);
    /* Koeficijenti difuzne refleksije materijala. */
    
    glutSolidCube(1);
    /* ponistavanje transformacija*/
    glPopMatrix();
    
    /*
     * Kreira se kocka(stub2) i primenjuje se geometrijska transformacija na
     * njega.
     */
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(-2, 1.525, 0.3);
    glScalef(.2, 3.05, .2);
    glutSolidCube(1);
    glPopMatrix();
    
    /* Kreiranje sipke 1*/
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-1.6,3.,0.3);
    glScalef(0.9,.2,.2);
    glutSolidCube(1);
    glPopMatrix();
    
    /* Kreiranje sipke 2*/
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-1.6,3.,-0.3);
    glScalef(0.9,.2,.2);
    glutSolidCube(1);
    glPopMatrix();
    
    /*tabla*/
    glPushMatrix();
    
    glColor3f(0.5,0.5,0);
    glTranslatef(-1,3.50,0);
    glScalef(0.2,1.5,1.5);
    
    glutSolidCube(1);
    glPopMatrix();
    /* Obruc */
    glPushMatrix();
    glTranslatef(0,3.05,0);
    glRotatef(90,1,0,0);
    glutSolidTorus(0.05,0.50,50,30);
    glPopMatrix();
}

void draw_hall(){
    
     /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0, 0, 0.1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.1, 0.5, 0.8, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 30;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    /* behind basket */
    glPushMatrix();
    glTranslatef(-10,0,0);
    glBegin(GL_POLYGON);
    glNormal3f(1,0,0);
    glColor3f(0,0,0);
    glVertex3f(0,0,15);
    glVertex3f(0,15,15);
    glVertex3f(0,15,-15);
    glVertex3f(0,0,-15);
    glEnd();
    glPopMatrix();
    
    /* front of basket */
    glPushMatrix();
    glTranslatef(20,0,0);
    glBegin(GL_POLYGON);
    glNormal3f(1,0,0);
    glColor3f(1,0,0);
    glVertex3f(0,0,15);
    glVertex3f(0,15,15);
    glVertex3f(0,15,-15);
    glVertex3f(0,0,-15);
    glEnd();
    glPopMatrix();
}
