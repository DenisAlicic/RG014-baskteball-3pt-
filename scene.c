#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "scene.h"
#include "variables.h"

extern Position p_of_camera;
void draw_basket(){
    

    GLfloat white_color[]={1,1,1,1};
    GLfloat blue_color[]={0,0,1,1};
    GLfloat orange_color[]={0.75,0.25,0,1};
     /*
     * Kreira se kocka(stub1) i primenjuje se geometrijska transformacija na
     * njega.
     */
    glPushMatrix();
    //glColor3f(0, 0, 1);
    glMaterialfv(GL_FRONT,GL_AMBIENT,blue_color);
    glMaterialfv(GL_FRONT,GL_SPECULAR,blue_color);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,blue_color);
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
    //glColor3f(0, 1, 0);
    glMaterialfv(GL_FRONT,GL_AMBIENT,blue_color);
    glMaterialfv(GL_FRONT,GL_SPECULAR,blue_color);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,blue_color);
    glTranslatef(-2, 1.525, 0.3);
    glScalef(.2, 3.05, .2);
    glutSolidCube(1);
    glPopMatrix();
    
    /* Kreiranje sipke 1*/
    glPushMatrix();
    //glColor3f(1,0,0);
    glMaterialfv(GL_FRONT,GL_AMBIENT,blue_color); 
    glMaterialfv(GL_FRONT,GL_SPECULAR,blue_color); 
    glMaterialfv(GL_FRONT,GL_DIFFUSE,blue_color); 
    glTranslatef(-1.6,3.,0.3);
    glScalef(0.9,.2,.2);
    glutSolidCube(1);
    glPopMatrix();
    
    /* Kreiranje sipke 2*/
    glPushMatrix();
    //glColor3f(1,0,0);
    glMaterialfv(GL_FRONT,GL_AMBIENT,blue_color); 
    glMaterialfv(GL_FRONT,GL_SPECULAR,blue_color); 
    glMaterialfv(GL_FRONT,GL_DIFFUSE,blue_color); 
    glTranslatef(-1.6,3.,-0.3);
    glScalef(0.9,.2,.2);
    glutSolidCube(1);
    glPopMatrix();
    
    /*tabla*/
    glPushMatrix();
    glMaterialfv(GL_FRONT,GL_AMBIENT,white_color);
    glMaterialfv(GL_FRONT,GL_SPECULAR,white_color);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,white_color);
    glColor3f(0.5,0.5,0);
    glTranslatef(-1,3.50,0);
    glScalef(0.2,1.5,1.5);
    
    glutSolidCube(1);
    glPopMatrix();
    /* Obruc */
    glPushMatrix();
    GLfloat shininess_of_table = 40;
    glMaterialfv(GL_FRONT,GL_AMBIENT,orange_color);
    glMaterialfv(GL_FRONT,GL_SPECULAR,orange_color); 
    glMaterialfv(GL_FRONT,GL_DIFFUSE,orange_color); 
    glMaterialf(GL_FRONT,GL_SHININESS,shininess_of_table);
    glTranslatef(-0.3,3.05,0);
    glRotatef(90,1,0,0);
    glutSolidTorus(0.05,0.50,50,30);
    glPopMatrix();
}

void draw_hall(){
    
     /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0, 0, 0.1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.7, 0.7, 0.7, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 0, 0, 0, 0 };

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
    glVertex3f(0,0,15);
    glVertex3f(0,15,15);
    glVertex3f(0,15,-15);
    glVertex3f(0,0,-15);
    glEnd();
    glPopMatrix();


    /* line for 3pt */
    glPushMatrix();
    glDisable(GL_LIGHTING);
    float r=6.75;
    float u;
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(u=0;u<=PI;u+=PI/1000){
       glVertex3f(r*sin(u),0,r*cos(u)); 
    } 
    glEnd();
    glEnable(GL_LIGHTING);

    glPopMatrix();
}
void set_position_of_camera(int number_of_position){
    
    p_of_camera.y=1.95;
    switch(number_of_position){
    
        case 1: p_of_camera.x=0;
                p_of_camera.z=-6.75;
                break;
        case 2: p_of_camera.x=4.77;
                p_of_camera.z=-4.77;
                break;
        case 3: p_of_camera.x=6.75;
                p_of_camera.z=0;
                break;
        case 4: p_of_camera.x=4.77;
                p_of_camera.z=4.77;
                break;
        case 5: p_of_camera.x=0;
                p_of_camera.z=6.75;
    }

}
