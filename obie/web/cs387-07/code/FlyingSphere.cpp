#include <GL/glut.h>
#include <stdlib.h>

/* Programmer: Obie
Purpose: Demo for CPSC 387 to illustrate viewing
transformations and how to place objects in the 
world.

Description of the program:
The program draws a yellow sphere in the center and a cyan
sphere to its right. The orbit variable starts at 0 and the
rotation variable at 0. By hitting the 'r' key, the rotation 
is increased by 5 (mod 360). By hitting the 'o' key, the 
orbit is increased by 10 (mod 360) */

static int orbit = 0, rotation = 0; 

void init(void)
{glClearColor(0.0,0.0,0.0,0.0);
}

void display(void)
/* Sets the two spheres in their proper places using
the Model_view matrix. Rotations are all relative to
the value for orbit and rotation. */

{glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0);

glPushMatrix();
glRotatef(45.0,1.0,0.0,0.0); //rotate center sphere to 
							 //show better
glutWireSphere(1.0,10,12); //draw center sphere

glRotatef((GLfloat) orbit,0.0,1.0,0.0);
glTranslatef(2.0,0.0,0.0);
glRotatef((GLfloat) rotation,0.0,1.0,0.0);

glColor3f(0.0, 1.0,1.0);
glutWireSphere(0.5,10,8); //draw second sphere
glPopMatrix();

glutSwapBuffers();
}

void reshape (int w, int h)
/* Called before the initial window is drawn or
immediately after any reshaping of the window */
{ 
glViewport(0,0,(GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, (GLfloat) w/ (GLfloat)h, 1.0, 10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{ switch(key) {
	case 'r':
		rotation = (rotation + 5) % 360;
		glutPostRedisplay();
		break;
	case 'o':
		orbit = (orbit + 10) % 360;
		glutPostRedisplay();
		break;
	default:
		break;
}}

void main (int argc, char** argv)
{ glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow(argv[0]);
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();
}
