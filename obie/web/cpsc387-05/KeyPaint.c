/* KeyPaint.c   */

/* This program illustrates the use of the GLUT library for
interfacing with a window system using menus, a 2-button mouse,
and keyboard choices 

This differs from Paint.c in that color changes are made by hitting 
the lower or upper case keys for  red (r), blue (b), green (g), 
cyan (c), magenta (m), yellow (y), white (w), or black (k). 
White is the default drawing color.
*/

#define NULL 0			//aliases for constants that provide meaning
#define LINE 1
#define RECTANGLE 2
#define TRIANGLE  3
#define POINTS 4

#include <stdlib.h>
#include <GL/glut.h>

void mouse(int, int, int, int);			//declare functions to avoid ordering problems
void key(unsigned char, int, int);
void display(void);
void drawSquare(int, int);
void myReshape(GLsizei, GLsizei);

void myinit(void);						

void screen_box(int, int, int);
void right_menu(int);
void top_menu(int);
void square_menu(int);
void fill_menu(int);
int pick(int, int);

/* globals */

GLsizei wh = 500, ww = 500;			/* initial window size */
GLfloat size = 3.0;					/* half side length of square */
int draw_mode = 0;					/* drawing mode */
int rx, ry;							/*raster position*/

GLfloat r = 1.0, g = 1.0, b = 1.0;	/* drawing color */
int fill = 0;						/* fill flag */

void drawSquare(int x, int y) //when selected, draws a randomly-colored square
{
        y=wh-y;
        glColor3ub( (unsigned char) rand()%256, rand()%256, rand()%256); 
        glBegin(GL_POLYGON);
                glVertex2f(x+size, y+size);
                glVertex2f(x-size, y+size);
                glVertex2f(x-size, y-size);
                glVertex2f(x+size, y-size);
        glEnd();
}


/* rehaping routine called whenever window is resized or moved */

void myReshape(GLsizei w, GLsizei h)
{

/* adjust clipping box */

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); 
        glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity(); 

/* adjust viewport and  clear */

        glViewport(0,0,w,h);
		glClearColor (0.8, 0.8, 0.8, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        display();
        glFlush();

/* set global size for use by drawing routine */

        ww = w;
        wh = h; 
}

void myinit(void)
{

	glViewport(0,0,ww,wh);


/* Pick 2D clipping window to match size of X window This choice avoids 
having to scale object coordinates each time window is resized */

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); 
        glOrtho(0.0, (GLdouble) ww , 0.0, (GLdouble) wh , -1.0, 1.0);

/* set clear color to black and clear window */

        glClearColor (0.8, 0.8, 0.8, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
}

void mouse(int btn, int state, int x, int y) //determine which box is chosen by mouse
											 //and draw the appropriate item
{
    static int count;
    int where;
    static int xp[2],yp[2];
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
    {
       glPushAttrib(GL_ALL_ATTRIB_BITS);
       
       where = pick(x,y);  //pick returns 0, LINE, RECTANGLE, TRIANGLE, POINTS, TEXT
       glColor3f(r, g, b);
       if(where != 0)
       {
          count = 0;
          draw_mode = where;
       }
       else switch(draw_mode)
       {
         case(LINE):
          if(count==0)
          {
              count++;
              xp[0] = x;
              yp[0] = y;
          }
          else 
          {
              glBegin(GL_LINES); 
                 glVertex2i(x,wh-y);
                 glVertex2i(xp[0],wh-yp[0]);
              glEnd();
              draw_mode=0;
              count=0;
          }
          break;
        case(RECTANGLE):
          if(count == 0)
          {
              count++;
              xp[0] = x;
              yp[0] = y;
          }
          else 
          {
              if(fill) glBegin(GL_POLYGON);
              else glBegin(GL_LINE_LOOP);
                 glVertex2i(x,wh-y);
                 glVertex2i(x,wh-yp[0]);
                 glVertex2i(xp[0],wh-yp[0]);
                 glVertex2i(xp[0],wh-y);
              glEnd();
              draw_mode=0;
              count=0;
          }
          break;
        case (TRIANGLE):
          switch(count)
          {
            case(0):
              count++;
              xp[0] = x;
              yp[0] = y;
              break;
            case(1):
              count++;
              xp[1] = x;
              yp[1] = y;
              break;
            case(2): 
              if(fill) glBegin(GL_POLYGON);
              else glBegin(GL_LINE_LOOP);
                 glVertex2i(xp[0],wh-yp[0]);
                 glVertex2i(xp[1],wh-yp[1]);
                 glVertex2i(x,wh-y);
              glEnd();
              draw_mode=0;
              count=0;
          }
          break;
        case(POINTS):
          {
             drawSquare(x,y);
             count++;
          }
		  break;	
       }

       glPopAttrib();
       glFlush();
     }
}

int pick(int x, int y)
{   y = wh - y;
	{if(y < wh-ww/10) return 0;
    else if(x < ww/10) return LINE;
    else if(x < ww/5) return RECTANGLE;
    else if(x < 3*ww/10) return TRIANGLE;
    else if(x < 2*ww/5) return POINTS;
    }
}

void screen_box(int x, int y, int s )
{
    glBegin(GL_QUADS);
      glVertex2i(x, y);
      glVertex2i(x+s, y);
      glVertex2i(x+s, y+s);
      glVertex2i(x, y+s);
    glEnd();
}

void right_menu(int id)
{
   if(id == 1) exit(0);
   else display();
}

void top_menu(int id)
{

}

void square_menu(int id)  //doubles size of square to increase; half size to decrease
{
   if (id == 1) size = 2 * size;
   else if (size > 1) size = size/2;
}

void fill_menu(int id)
{
   if (id == 1) fill = 1; 
   else fill = 0;
}

void key(unsigned char k, int xx, int yy) //keys set the colors
{ switch (k)
	{	case 'r': case 'R':
			r = 1.0; g = 0.0; b = 0.0;  //red
			break;						
		case 'g': case 'G':
			r = 0.0; g = 1.0; b = 0.0;	//green
			break; 		
		case 'b': case 'B':
			r = 0.0; g = 0.0; b = 1.0;	//blue
			break; 	
		case 'c': case 'C':
			r = 0.0; g = 1.0; b = 1.0;	//cyan
			break; 
		case 'm': case 'M':
			r = 1.0; g = 0.0; b = 1.0;	//magenta
			break;
		case 'y': case 'Y':
			r = 1.0; g = 1.0; b = 0.0;	//yellow
			break;
		case 'w': case 'W':
			r = 1.0; g = 1.0; b = 1.0;	//white
			break;
		case 'k': case 'K':
			r = 0.0; g = 0.0; b = 0.0;	//black
			break;
		default: 
			r = 1.0; g = 1.0; b = 1.0;	//white is default
}}


void display(void)
{
	int shift=0;
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glClearColor (0.8, 0.8, 0.8, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    screen_box(0,wh-ww/10,ww/10);
    glColor3f(1.0, 0.0, 0.0);
    screen_box(ww/10,wh-ww/10,ww/10);
    glColor3f(0.0, 1.0, 0.0);
    screen_box(ww/5,wh-ww/10,ww/10);
    glColor3f(0.0, 0.0, 1.0);
    screen_box(3*ww/10,wh-ww/10,ww/10);
    glColor3f(0.0, 0.0, 0.0);
	screen_box(ww/10+ww/40,wh-ww/10+ww/40,ww/20);
    glBegin(GL_LINES);
       glVertex2i(wh/40,wh-ww/20);
       glVertex2i(wh/40+ww/20,wh-ww/20);
    glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2i(ww/5+ww/40,wh-ww/10+ww/40);
       glVertex2i(ww/5+ww/20,wh-ww/40);
       glVertex2i(ww/5+3*ww/40,wh-ww/10+ww/40);
    glEnd();
    glPointSize(3.0);
    glBegin(GL_POINTS);
       glVertex2i(3*ww/10+ww/20, wh-ww/20);
    glEnd();
	
	
    glFlush();
    glPopAttrib();
}


int main(int argc, char** argv)
{
    int  p_menu, f_menu, r_menu; 

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
    glutCreateWindow("square");
    glutDisplayFunc(display);

	/* Create 3 menus each of which will be controlled by another menu, top_menu */ 
    p_menu = glutCreateMenu(square_menu); 
		glutAddMenuEntry("increase random-colored square size", 1);
		glutAddMenuEntry("decrease random-colored square size", 2);
    f_menu = glutCreateMenu(fill_menu); 
		glutAddMenuEntry("fill on", 1);
		glutAddMenuEntry("fill off", 2);
	r_menu = glutCreateMenu(right_menu);
		glutAddMenuEntry("quit",1);
		glutAddMenuEntry("clear",2);
    
    /* Create the controlling menu, top_menu, which allows the invoking of the various submenus.*/
	glutCreateMenu(top_menu);
		glutAddSubMenu("Square Size", p_menu);
		glutAddSubMenu("Fill", f_menu);
		glutAddSubMenu("Clear/quit", r_menu);
		glutAttachMenu(GLUT_RIGHT_BUTTON);   /*With only two buttons, the right button will make the 
											 menu selections and the left will pick from the boxed 
											 selections on the screen. Color choices will be made from
											 the keyboard. */
    
	myinit ();						//usual initialization stuff
    glutReshapeFunc (myReshape);	//invoke when reshaping window
	glutKeyboardFunc(key);
    glutMouseFunc (mouse);
    glutMainLoop();

}
