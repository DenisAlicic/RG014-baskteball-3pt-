#include <stdlib.h>
#include <GL/glut.h>

/* Dimenzije prozora */
static int window_width, window_height;

/* Deklaracije callback funkcija. */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* Kreira se prozor. */
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    /* Registruju se callback funkcije. */
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;
    }
}

static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
}

static void on_display(void)
{
    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* ne znam zasto ne radi z buffer sa ovim*/
    /*gluPerspective(
            60,
            window_width/(float)window_height,
            -20, 0);*/
    /* a sa ovim radi,mozda i nije do z baffera*/
    glFrustum(-1, 1, -1, 1, 1, 10);

    /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            4.77, 1.95,0.1,
            0, 1.95 , 0,
            0, 1, 0
        );
    
    
    /*iscrtavanje daljeg stuba*/
    
    glTranslatef(0.5,3.05/2,-2);
    glScalef(0.2,3.05,0.2);
    glColor3f(1,0,0);
    glutSolidCube(1);
    /* ponistavanje transformacija*/
    glScalef(1/0.2,1/3.05,1/0.2);
    glTranslatef(-0.5,-3.05/2,2);
    
    
    /*iscrtavanje blizeg stuba*/
    
    glTranslatef(-0.5,3.05/2,-2);
    glScalef(0.2,3.05,0.2);
    glColor3f(0,0,1);
    glutSolidCube(1);
    /* ponistavanje transformacija*/
    glScalef(1/0.2,1/3.05,1/0.2);
    glTranslatef(0.5,-3.05/2,2);
    
    /*iscrtavanja dalje paralelne sipke */
    
    glTranslatef(0.5,2.95,-1.4);
    glScalef(0.2,0.2,1);
    glColor3f(1,0,0);
    glutSolidCube(1);
    glScalef(1/0.2,1/0.2,1/1);
    glTranslatef(-0.5,-2.95,1.4);
    
      /*iscrtavanja blize paralelne sipke */

    glTranslatef(-0.5,2.95,-1.4);
    glScalef(0.2,0.2,1);
    glColor3f(0,0,1);
    glutSolidCube(1);
    glScalef(1/0.2,1/0.2,1/1);
    glTranslatef(0.5,-2.95,1.4);
    
    /* Tabla   */
    
    glTranslatef(0,3.05,-0.7);
    glScalef(2,2,0.2);
    glColor3f(0,1,0);
    glutSolidCube(1);
    glScalef(1/2,1/2,1/0.2);
    glTranslatef(0,-3.05,0.7);
    
    
    
    

    /* Nova slika se salje na ekran. */
    glutSwapBuffers();
}