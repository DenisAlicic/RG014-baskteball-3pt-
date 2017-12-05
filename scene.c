#include <stdlib.h>
#include <GL/glut.h>
#include "scene.h"
#include "variables.h"

void draw_hall(){
    
    /* siling */
    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0,15,0);
    glScalef(40,0.2,30);
    glutWireCube(1);
    glPopMatrix();
    
    
    
    /* floor */
    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0,-0.2,0);
    glScalef(40,0.2,30);
    glutWireCube(1);
    glPopMatrix();
    
    
}
void draw_basket(){
    
    glPushMatrix();
     /*
     * Kreira se kocka(stub1) i primenjuje se geometrijska transformacija na
     * njega.
     */
    glColor3f(0, 0, 1);
    glTranslatef(-2, 1.525, -0.3);
    glScalef(.2, 3.05, .2);
    glutSolidCube(1);
    /* ponistavanje transformacija*/
    glScalef(1/.2, 1/3.05, 1/.2);
    glTranslatef(2, -1.525, 0.3);
    
    /*
     * Kreira se kocka(stub2) i primenjuje se geometrijska transformacija na
     * njega.
     */
    glColor3f(0, 1, 0);
    glTranslatef(-2, 1.525, 0.3);
    glScalef(.2, 3.05, .2);
    glutSolidCube(1);
    glScalef(1/.2, 1/3.05, 1/.2);
    glTranslatef(2, -1.525, -0.3);
    
    /* Kreiranje sipke 1*/
    glColor3f(1,0,0);
    glTranslatef(-1.6,3.,0.3);
    glScalef(0.9,.2,.2);
    glutSolidCube(1);
    glScalef(1/0.9,1/.2,1/.2);
    glTranslatef(1.6,-3.,-0.3);
    
    /* Kreiranje sipke 2*/
    glColor3f(1,0,0);
    glTranslatef(-1.6,3.,-0.3);
    glScalef(0.9,.2,.2);
    glutSolidCube(1);
    glScalef(1/0.9,1/.2,1/.2);
    glTranslatef(1.6,-3.,0.3);
    
    /*tabla*/
    glColor3f(0.5,0.5,0);
    glTranslatef(-1,3.05,0);
    glScalef(0.2,1.2,1.2);
    glutWireCube(1);
    
    
    glPopMatrix();
    
    
}