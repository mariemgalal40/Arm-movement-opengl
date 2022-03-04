#include <stdlib.h>
#include <GL/glut.h>


static int shoulder = 0, elbow = 0, fingerBase1 = 0, fingerUp1 = 0, fingerBase2 = 0, fingerUp2 = 0, fingerBase3 = 0, fingerUp3 = 0, fingerBase4 = 0, fingerUp4 = 0, fingerBase5 = 0, fingerUp5 = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, .6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    //Draw finger base 1 
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase1, 0.0, 0.0, 1.0);
    glTranslatef(0.15, -0.25, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 1 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp1, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    //Draw finger base 2 
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.25, 0.45);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 2 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    
    //Draw finger base 3 
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase3, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.25, 0.15);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 3 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp3, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    
    //Draw finger base 4
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase4, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.25, -0.15);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 4 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp4, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    //Draw finger base 5
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase5, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.25, -0.45);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 5 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp5, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    glPopMatrix();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        if (shoulder < 90)
        {
            shoulder = (shoulder + 5) ;
            glutPostRedisplay();
        }
        break;
    case 'S':
        if (shoulder > -90)
        {
            shoulder = (shoulder - 5) ;
            glutPostRedisplay();
        }
        break;
    
    case 'e':
    if (elbow < 130)
    {
        elbow = (elbow + 5) ;
        glutPostRedisplay();
    }
        break;
    
    case 'E':
        if (elbow > 0)
        {
            elbow = (elbow - 5);
            glutPostRedisplay();
        }
        break;

    case 'f':
        if (fingerBase1 < 90) {
            fingerBase1 = (fingerBase1 + 5) ;
            glutPostRedisplay();
        }
        break;
    case 'F':
        if (fingerBase1 > 0) {
            fingerBase1 = (fingerBase1 - 5) ;
            glutPostRedisplay();
        }
        break;
    case 'g':
        if (fingerUp1 < 90) {
            fingerUp1 = (fingerUp1 + 5);
            glutPostRedisplay();
        }
        break;
    case 'G':
        if (fingerUp1 > 0) {
            fingerUp1 = (fingerUp1 - 5);
            glutPostRedisplay();
        }
        break;
    case 'h':
        if (fingerBase2 < 90) {
            fingerBase2 = (fingerBase2 + 5);
            glutPostRedisplay();
        }
        break;
    case 'H':
        if (fingerBase2 > -90) {
            fingerBase2 = (fingerBase2 - 5);
            glutPostRedisplay();
        }
        break;
    case 'j':
        if (fingerUp2 < 0) {
            fingerUp2 = (fingerUp2 + 5);
            glutPostRedisplay();
        }
        break;
    case 'J':
        if (fingerUp2 > -90) {
            fingerUp2 = (fingerUp2 - 5);
            glutPostRedisplay();
        }
        break;
    case 'k':
        if (fingerBase3 < 90) {
            fingerBase3 = (fingerBase3 + 5);
            glutPostRedisplay();
        }
        break;
    case 'K':
        if (fingerBase3 > -90) {
            fingerBase3 = (fingerBase3 - 5);
            glutPostRedisplay();
        }
        break;
    case 'l':
        if (fingerUp3 < 0) {
            fingerUp3 = (fingerUp3 + 5);
            glutPostRedisplay();
        }
        break;
    case 'L':
        if (fingerUp3 > -90) {
            fingerUp3 = (fingerUp3 - 5);
            glutPostRedisplay();
        }
        break;
    case 'z':
        if (fingerBase4 < 90) {
            fingerBase4 = (fingerBase4 + 5);
            glutPostRedisplay();
        }
        break;
    case 'Z':
        if (fingerBase4 > -90) {
            fingerBase4 = (fingerBase4 - 5);
            glutPostRedisplay();
        }
        break;
    case 'x':
        if (fingerUp4 < 0) {
            fingerUp4 = (fingerUp4 + 5);
            glutPostRedisplay();
        }
        break;
    case 'X':
        if (fingerUp4 > -90) {
            fingerUp4 = (fingerUp4 - 5);
            glutPostRedisplay();
        }
        break;
    case 'c':
        if (fingerBase5 < 90) {
            fingerBase5 = (fingerBase5 + 5);
            glutPostRedisplay();
        }
        break;
    case 'C':
        if (fingerBase5 > -90) {
            fingerBase5 = (fingerBase5 - 5);
            glutPostRedisplay();
        }
        break;
    case 'v':
        if (fingerUp5 < 0) {
            fingerUp5 = (fingerUp5 + 5);
            glutPostRedisplay();
        }
        break;
    case 'V':
        if (fingerUp5 > -90) {
            fingerUp5 = (fingerUp5 - 5);
            glutPostRedisplay();
        }
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
