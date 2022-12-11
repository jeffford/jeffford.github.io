//Modified from Jeff Molefee's code
//http://nehe.gamedev.net

#include <windows.h>
#include <stdio.h>
#include <gl.h>
#include <glu.h>
#include <glut.h>
#include "tgaload.h"


#define MAX_NO_TEXTURES 1   //this can be changed to allow for more textures

#define CUBE_TEXTURE 0      //need more if handling more than one texture

GLuint texture_id[MAX_NO_TEXTURES];   //can use more than one texture

float xrot; //hold values for rotation - usual rotating cube stuff
float yrot;
float zrot;
float ratio;

void init(void)
{
   glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
   glClearColor(1.0f, 1.0f, 1.0f, 0.5f);			// White Background
   glEnable ( GL_COLOR_MATERIAL );					// usual color for materials 
   glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

   glEnable ( GL_TEXTURE_2D );                      //required to get texturing
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );
   glGenTextures (1, texture_id);					//create 1 texture name

   image_t   temp_image;  //need more if handling more than one texture

   glBindTexture ( GL_TEXTURE_2D, texture_id[CUBE_TEXTURE] );  //specifying bindings
   tgaLoad  ( "mypic.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );  //do the load
   glEnable ( GL_CULL_FACE );

   //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void reshape( int w, int h )  //usual reshape type stuff with good error checking
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(80,ratio,1,200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 30,
		      0,0,10,
			  0.0f,1.0f,0.0f);
}

void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glLoadIdentity ( );
   glPushMatrix();
   glTranslatef ( 0.0, 0.0, -5.0 );			//move back
   glRotatef ( xrot, 1.0, 0.0, 0.0 );		//set for rotation
   glRotatef ( yrot, 0.0, 1.0, 0.0 );
   glRotatef ( zrot, 0.0, 0.0, 1.0 );

   glBindTexture ( GL_TEXTURE_2D, texture_id[0] );  //bind texture

   glBegin ( GL_QUADS ); //Here's where the mapping occurs
   // Front Face
			//Attach lower left of texture to lower left of front face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
			//Attach lower right of texture to lower right of front face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
			//Attach upper right of texture to upper right of front face
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
			//Attach upper left of texture to upper left of front face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	
    // Back Face--- these are done in a similar manner
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
   glEnd();
   
   glPopMatrix();
   xrot+=0.3f;   //automatically rotate
   yrot+=0.2f;
   zrot+=0.4f;
   glutSwapBuffers();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
  switch ( key ) {
    case 27:        // When Escape Is Pressed...
      exit ( 0 );   // Exit The Program
      break;        // Ready For Next Case
    default:        // Now Wrap It Up
      break;
  }
}

void arrow_keys ( int a_keys, int x, int y )  // Create Special Function (required for arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
      glutFullScreen ( ); // Go Into Full Screen Mode
      break;
    case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
      glutReshapeWindow ( 500, 500 ); // Go Into A 500 By 500 Window
      break;
    default:
      break;
  }
}

void main ( int argc, char** argv )   // Create Main Function For Bringing It All Together
{
  glutInit            ( &argc, argv ); 
  glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA ); // Display Mode
  glutInitWindowPosition (0,0);
  glutInitWindowSize  ( 500, 500 ); // If glutFullScreen wasn't called this is the window size
  glutCreateWindow    ( "Texture Mapped Cube" ); // Window Title
  init ();
  glutFullScreen      ( );          // Put Into Full Screen
  glutDisplayFunc     ( display );  // Matching Earlier Functions To Their Counterparts
  glutReshapeFunc     ( reshape );
  glutKeyboardFunc    ( keyboard );
  glutSpecialFunc     ( arrow_keys );
  glutIdleFunc		  ( display );
  glutMainLoop        ( );          // Initialize The Main Loop
}




