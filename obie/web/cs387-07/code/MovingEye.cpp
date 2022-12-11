#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

/* To move the eye and keep everything oriented properly for the glulookat 
command, we will maintain the following points and vectors:

	eye = (eyex, eyey, eyez) - the position of the eye
	center = (centerx, centery, centerz) - the center where the eye is looking
	Note the vector between the eye and the center is the lookat vector normalized.
	up = (upx, upy, upz) - up direction for the image
	right = (rightx, righty, rightz) - the right vector from the eye to the right
We will maintain the right vector, the up vector, and the lookat vector as a 
coordinate system anchored at the eye where all 3 vectors are perpendicular to each
other and each vector corresponds to one of the typical axis as below:

			right vector  - positive x-axis
			up vector	  - positive y-axis
			lookat vector - negative z-axis
*/

GLfloat eyex=0, eyey = 0, eyez=10, //bring up with eye at (0,0,10)
		centerx = 0, centery = 0, centerz=0, //and with center at (0.0.0)
		upx = 0, upy = 1, upz = 0,   //and up in the y-axis direction
		rightx = 1, righty = 0, rightz = 0; //right vector in x=axis direction
/*Note that the above vectors are:
		right  (1,0,0)
		up	   (0,1,0)
		lookat - unit vector in the direction of (0,0,-10), i.e. (0,0,-1)
*/

int w = 500, h = 500; //initial window size
const float piover180 = 0.0174532925f;  
float radians;
int degrees = 0;

void init(void)
{glClearColor(0.0,0.0,0.0,0.0);
}

void reshape (int w, int h)
{ glViewport(0,0,(GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, (GLfloat) w/ (GLfloat)h, 1.0, 10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(eyex,eyey,eyez,centerx,centery,centerz,upx,upy,upz);
}

void display(void)

{
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(eyex,eyey,eyez,centerx,centery,centerz,upx,upy,upz);
glPushMatrix();
glColor3f(1.0,1.0,0.0);

glRotatef(45.0,1.0,0.0,0.0); //rotate center sphere to 
							 //show better
glutWireSphere(1.0,10,12); //draw center sphere

glRotatef((GLfloat) 0.0,0.0,1.0,0.0);
glTranslatef(2.0,0.0,0.0);
glRotatef((GLfloat) 0.0,0.0,1.0,0.0);

glColor3f(0.0, 1.0,1.0);
glutWireSphere(0.5,10,8); //draw second sphere


glPopMatrix();

glutSwapBuffers();
}




void keyboard (unsigned char key, int x, int y)
{   degrees = (degrees + 2) % 360; 
	radians = degrees * piover180;
	switch(key) {
	case 'r':  //reset to original values
		eyex=0; eyey = 0; eyez=10; //bring up with eye at (0,0,10)
		centerx = 0; centery = 0; centerz=0; //and with center at (0.0.0)
		upx = 0; upy = 1; upz = 0;   //and up in the y-axis direction
		
		glutPostRedisplay();
		break;
	case 'z': //zoom in
		eyez = eyez - 1;
		glutPostRedisplay();
		break;
	case 'Z': //zoom out
		eyez = eyez + 1;
		glutPostRedisplay();
		break;
	case 'p': //pan left
		centerx = centerx -1;
		glutPostRedisplay();
		break;
	case 'P': //pan right
		centerx = centerx + 1;
		glutPostRedisplay();
		break;
	case 'D' : //look down
		centery = centery -1;
		glutPostRedisplay();
		break;
	case 'U' : //look up
		centery = centery + 1;
		glutPostRedisplay();
		break;

	/*case 'X':  //rotate eye around x-axis by additional 2 degrees
		eyey = cos(radians) * eyey - sin(radians) * eyez;
		eyez = sin(radians) * eyey + cos(radians) * eyez;
		glutPostRedisplay();
		break;
	case 'x':
		eyey = cos(-radians) * eyey - sin(-radians) * eyez;
		eyez = sin(-radians) * eyey + cos(radians) * eyez;
		glutPostRedisplay(); */
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
