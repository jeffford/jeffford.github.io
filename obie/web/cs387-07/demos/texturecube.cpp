//Sample program to show how to texture a rotating cube using one texture
//programmer: Obie Slotterbeck


#include <windows.h>
#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
#include "tgaload.cpp"   //this converts a targa file to a texture

#define MAX_NO_TEXTURES 1     //handling multiple textures can be done

#define CUBE_TEXTURE 0        //each texture must have an id

GLuint texture_id[MAX_NO_TEXTURES];

float xrot;             //degrees for rotations around obvious axis
float yrot;
float zrot;
float ratio;

void init(void)
{
   glShadeModel(GL_SMOOTH);				
   glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  
   glEnable ( GL_COLOR_MATERIAL );
   glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

   glEnable ( GL_TEXTURE_2D );                  //enable 2d texturing
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );
   glGenTextures (1, texture_id);

   image_t   temp_image;

   glBindTexture ( GL_TEXTURE_2D, texture_id[CUBE_TEXTURE] );
 
   //this file name is hardwired, but could be input
   //change to "<name>.tga"
   tgaLoad  ( "swirl.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );
   glEnable ( GL_CULL_FACE );
}

void reshape( int w, int h )
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
   glTranslatef ( 0.0, 0.0, -5.0 );
   glRotatef ( xrot, 1.0, 0.0, 0.0 );
   glRotatef ( yrot, 0.0, 1.0, 0.0 );
   glRotatef ( zrot, 0.0, 0.0, 1.0 );

   glBindTexture ( GL_TEXTURE_2D, texture_id[0] );

   glBegin ( GL_QUADS );
   // Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
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

   //change for rotating
   xrot+=0.3f;
   yrot+=0.2f;
   zrot+=0.4f;
   glutSwapBuffers();
}

void keyboard ( unsigned char key, int x, int y )  
{
  switch ( key ) {
    case 27:        // escape key exits program.
      exit ( 0 );   
      break;      
    default:        
      break;
  }
}

void arrow_keys ( int a_keys, int x, int y )  // Create function for arrow keys
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     
      glutFullScreen ( ); // go to full screen mode on up arrow press
      break;
    case GLUT_KEY_DOWN:               
      glutReshapeWindow ( 500, 500 ); // Go to 500 By 500 window when down arrow pressed
      break;
    default:
      break;
  }
}

void main ( int argc, char** argv )   
{
  glutInit            ( &argc, argv );
  glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA ); // Display Mode
  glutInitWindowPosition (0,0);
  glutInitWindowSize  ( 500, 500 ); // If glutFullScreen wasn't called this is the window size
  glutCreateWindow    ( "Texturing Example" ); 
  init ();
  glutFullScreen      ( );          
  glutDisplayFunc     ( display );  
  glutReshapeFunc     ( reshape );
  glutKeyboardFunc    ( keyboard );
  glutSpecialFunc     ( arrow_keys );
  glutIdleFunc		  ( display );
  glutMainLoop        ( );          
}




