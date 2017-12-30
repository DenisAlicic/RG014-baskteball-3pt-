#include <stdlib.h>
#include <GL/glut.h>
#include "scene.h"
#include <math.h>
#include "variables.h"
#include "light.h"
/* Global variables */
Position p_of_camera;
int number_of_position = 2;
int animation_ongoing = 0;
float angle = PI/3;
float v0 = 8;
float t = 0;
float x_t;
float y_t;
int z_positive=1;
/* Dimension of window */
static int window_width, window_height;

/* Declarations of callback functions */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int id);
extern void set_position_of_camera(int number_of_position);

int main(int argc, char **argv)
{
    /* Initialization of GLUT */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* Creation of window */
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3pt_contest!");

    /* Registration of callback function */
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* OpenGL initialization */
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    

    /* Program get into main loop */
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Finishing */
        exit(0);
        break;
    case 's':
    case 'S':
        if(!animation_ongoing){
            animation_ongoing=1;
            glutTimerFunc(TIMER_INTERVAL,on_timer,TIMER_ID);
        }
        break;
        /* Setting up position of shooting */
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
        number_of_position = key -'0';
        glutPostRedisplay();
        break;
        /* Increasing of the angle */
    case '+':
        if(!animation_ongoing){
            if(angle < PI/2-3*PI/36){
                angle+=PI/36;
            }
        }
        break;
        /* Decreasing of the angle */
    case '-':
        if(!animation_ongoing){
            if(angle > PI/6){
                angle -= PI/36; 
            }
        }
        break;


    }
}

static void on_reshape(int width, int height)
{
    /* Remember width and height of window */
    window_width = width;
    window_height = height;
}

static void on_display(void)
{
    /* Clearing buffers */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Setting up  viewport */
    glViewport(0, 0, window_width, window_height);

    /* Setting up projection */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0.5, -30);

    /* Setting up point of view */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    set_position_of_camera(number_of_position);
   
    gluLookAt(
            p_of_camera.x, p_of_camera.y, p_of_camera.z,
            0, 1.95 , 0,
            0, 1, 0
        );
    set_light();
    draw_basket();
    draw_hall();
    draw_ball(number_of_position); 
    

    /* Show this picture*/
    glutSwapBuffers();
}
static void on_timer(int id)
{
    if (id != TIMER_ID) return;

    /* animacija se zaustavlja kada lopta padne na zemlju */
    if(x_t < -5){
        animation_ongoing = 0;
        t=0;
    }
    else{
         t +=0.02;
    }
    
    /* Forsira se ponovno iscrtavanje prozora. */
    glutPostRedisplay();

    /* Po potrebi se ponovo postavlja tajmer. */
    if (animation_ongoing) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }

}

