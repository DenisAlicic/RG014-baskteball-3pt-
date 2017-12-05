#include <stdlib.h>
#include <GL/glut.h>
#include "scene.h"
#include "variables.h"

void draw_hall(){
    
     /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 1.0, 0.1, 0.1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.1, 0.5, 0.8, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 10;
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    /* siling */
    glPushMatrix();
    /*glColor3f(0,0,1);*/
    glTranslatef(0,15,0);
    glScalef(40,0.2,30);
    glutSolidCube(1);
    glPopMatrix();
    
    
    
    /* floor */
    glPushMatrix();
    /*glColor3f(0,0,1);*/
    glTranslatef(0,-0.2,0);
    glScalef(40,0.2,30);
    glutSolidCube(1);
    glPopMatrix();
    
    /* behind basket */
    glPushMatrix();
    /*glColor3f(0,0,1);*/
    glTranslatef(-20,15.2/2,0);
    glScalef(0.2,15.2,30);
    glutSolidCube(1);
    glPopMatrix();
    
    /* front of basket */
    glPushMatrix();
    /*glColor3f(0,0,1);*/
    glTranslatef(40-18.5,15.2/2,0);
    glScalef(0.2,15.2,30);
    glutSolidCube(1);
    glPopMatrix();
    
    /*TODO levi i desni zid*/
    
}
void draw_basket(){
    
    
}