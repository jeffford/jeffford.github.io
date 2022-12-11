/* cube.c        */

/* Rotating cube with color interpolation */

/* Demonstration of use of homogeneous coordinate transformations 
and simple data structure for representing a spinning cube*/

/* Colors are assigned to the vertices and color interpolates along edges */
/* keys control the direction of rotation and exiting form program */

#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>  //required for Sleep function


	GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
	{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0}, 
	{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};

	GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},
	{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, 
	{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

	//If this is omitted, because the normals are vectors from origin
	//to each vertex, the code would still run. This is a very special
	//case.
	GLfloat normals[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
	{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
	{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};


void polygon(int a, int b, int c , int d)
{

/* draw a polygon via list of vertices */

 	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normals[a]); //associate normal with vertex
		//Again, in this special case, each of the glNormal3fv 
		//calls could be omitted
		glVertex3fv(vertices[a]);
		glColor3fv(colors[b]);
		glNormal3fv(normals[b]); //associate normal with vertex
		glVertex3fv(vertices[b]);
		glColor3fv(colors[c]);
		glNormal3fv(normals[c]); //associate normal with vertex
		glVertex3fv(vertices[c]);
		glColor3fv(colors[d]);
		glNormal3fv(normals[d]); //associate normal with vertex
		glVertex3fv(vertices[d]);
	glEnd();
																										}

void colorcube(void)
{

/* map vertices to faces */

	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
}

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

void display(void)
{
/* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

 colorcube();

 glFlush();
	glutSwapBuffers();
}

void spinCube()
{

/* Idle callback, spin cube 2 degrees about selected axis */

	theta[axis] += 2.0;
	if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
	Sleep(500); //parameter is in milliseconds
	glutPostRedisplay();
}

/*void mouse(int btn, int state, int x, int y)
{

 If had 3-button mouse, this mouse callback would select an axis about which to rotate 

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
} */

void keys(unsigned char key, int x, int y)
/* Used to control axis of rotation or quit*/
{
	if (key == 'x') axis = 0; // select x axis
	if (key == 'y') axis = 1; // select y axis
	if (key == 'z') axis = 2; // select z axis
	if (key == 'q') exit(0);  //exit
	display();
} 


void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void
main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	glutIdleFunc(spinCube);
//	glutMouseFunc(mouse);   need if use 3-button mouse
    glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
    glutMainLoop();
}
