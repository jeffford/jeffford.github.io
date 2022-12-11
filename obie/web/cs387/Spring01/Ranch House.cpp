/*******************************************************************
********************************************************************
*This program, "Ranch Home", renders a scene using Opengl and Glut.
*The scene is of a house designed by Matt Snyder in a highschool architecture
*class.  Besides the house, three trees were added to the scene.  
*
*	This program was written by  MATT A. SNYDER for CPSC 387 in 1998
*
*********************************************************************
*		KEYBOARD COMMANDS
*		K = Stops Rotation
*		J = Rotates -Y Axis
*		L = Rotates +Y Axis
*		I = Rotates -X Axis
*		M = Rotates +X Axis
*		O = Rotates -Z Axis
*		N = Rotates +Z Axis
*		Q = Quit Program
*********************************************************************
*   ***NOTE*** The keyboard commands can also be accessed through
*	a menu by right-clicking the mouse
*
*
********************************************************************
********************************************************************/


#include <GL\glut.h>
#define NULL 0

typedef enum { TREE, STEM, LEAF, LEAF_MAT, WOOD_MAT, STEMANDLEAVES,
                LIGHT_PROP, HOUSE_MAT, ROOF_MAT, DOOR_MAT, TRIM_MAT,
				BRICK_MAT,CONCRETE_MAT,GLASS_MAT} DisplayLists;

/*typedef defines an array to hold a 3D point and is used in the vertice list
shown below.  The Vertice List contains all of the coordinates for the walls
of the house*/

typedef GLdouble point3D[3];
	
	point3D Vertices[]={{0.0,0.0,0.0},{25.0,0.0,0.0},{25.0,8.33,0.0},{0.0,8.33,0.0},
	{25.0,0.0,-10.0},{43.0,0.0,-10.0},{43.0,12.0,-10.0},{25.0,12.0,-10.0},
	{43.0,0.0,-12.5},{50.75,0.0,-12.5},{50.75,12.8,-12.5},{43.0,12.8,-12.5},
	{50.75,0.0,-10.0},{70.0,0.0,-10.0},{70.0,12.0,-10.0},{50.75,12.0,-10.0},
	{70.0,0.0,-35.0},{70.0,10.0,-35.0},{70.0,13.5,-25.0},{70.0,17.0,-25.0},
	{25.0,0.0,-35.0},{25.0,10.0,-35.0},{25.0,0.0,-25.0},{25.0,13.5,-25.0},
	{0.0,0.0,-25.0},{0.0,17.0,-25.0},{70.0,0.0,-25.0},{25.0,17.0,-25.0},
	};

/*GLOBAL varaibles
*	NORMAL is used in the EvalNormal function to store the normal
*	vector when computing normals for walls of the house
* theta, axis, and degrees are used to rotate the house*/

	point3D NORMAL;
	static GLfloat theta[]={0.0,0.0,0.0};
	static GLint axis = 0;
	static GLint degrees=1;


/*
*THESE NEXT FUNCTIONS ARE FOR THE SETUP OF MATERIALS, LIGHTING AND 
*EVALUATION OF NORMALS
*
*/


/*in this function the material settings are created first and then
display lists are created that call these material properties, which
in turn these display lists are used when rendering objects*/

void SetupMaterials(void){
  GLfloat wood_ambuse[] =   { 0.4, 0.25, 0.1, 1.0 };
  GLfloat wood_specular[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat wood_shininess[] = { 0 };

  GLfloat leaf_ambuse[] =   { 0.0, 0.8, 0.0, 1.0 };
  GLfloat leaf_specular[] = { 0.0, 0.8, 0.0, 1.0 };
  GLfloat leaf_shininess[] = { 10 };

  GLfloat house_ambuse[] =   { 0.4, 0.2, 0.05, 1.0 };
  GLfloat house_specular[] = { 0.3, 0.15, 0.05, 1.0 };
  GLfloat house_shininess[] = { 0 };

  GLfloat roof_ambient[]={0.1,0.1,0.1,1.0};
  GLfloat roof_diffuse[]={0.2,0.2,0.2,1.0};
  GLfloat roof_specular[]={0.1,0.1,0.1,1.0};
  GLfloat roof_shininess[]={0};

  GLfloat door_ambuse[]={0.55,0.55,0.55,1.0};
  GLfloat door_specular[]={0.1,0.1,0.1,1.0};
  GLfloat door_shininess[]={0};

  GLfloat trim_ambient[]={0.3,0.15,0.01,1.0};
  GLfloat trim_diffuse[]={0.8,0.8,0.8,1.0};
  GLfloat trim_specular[]={0.0,0.0,0.0,1.0};
  GLfloat trim_shininess[]={0};

  GLfloat brick_ambient[]={0.5,0.05,0.05,1.0};
  GLfloat brick_diffuse[]={0.2,0.1,0.1,1.0};
  GLfloat brick_specular[]={0.0,0.0,0.0,1.0};
    
  GLfloat concrete_ambient[]={0.2,0.2,0.2,1.0};
  GLfloat concrete_diffuse[]={0.6,0.6,0.6,1.0};
  GLfloat concrete_specular[]={0.0,0.0,0.0,1.0};
  
  GLfloat glass_ambient[]={0.1,0.1,0.1,0.35};
  GLfloat glass_diffuse[]={0.5,0.5,0.5,0.35};
  GLfloat glass_specular[]={0.8,0.8,0.8,0.35};

  GLfloat brass_ambient[]={0.33,0.26,0.23,1.0};
  GLfloat brass_diffuse[]={0.5,0.11,0.0,1.0};
  GLfloat brass_specular[]={0.95,0.73,0.0,1.0};

/* *****NOTE***** ambuse was used in some places instead of 
* seperate ambient and diffuse settings*/

  glNewList(WOOD_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wood_ambuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wood_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, wood_shininess);
  glEndList();

  glNewList(LEAF_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, leaf_ambuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, leaf_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, leaf_shininess);
  glEndList();

  glNewList(HOUSE_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, house_ambuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, house_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, house_shininess);
  glEndList();

  glNewList(ROOF_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, roof_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, roof_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, roof_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, roof_shininess);
  glEndList();

  glNewList(DOOR_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, door_ambuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, door_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, door_shininess);
  glEndList();

  glNewList(TRIM_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT, trim_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, trim_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, trim_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, trim_shininess);
  glEndList();

  glNewList(BRICK_MAT, GL_COMPILE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, brick_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, brick_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brick_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);
  glEndList();

  glNewList(CONCRETE_MAT, GL_COMPILE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, concrete_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, concrete_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, concrete_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);
  glEndList();

  glNewList(GLASS_MAT, GL_COMPILE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, glass_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, glass_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glass_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 4);
  glEndList();
}


/*The setup for light places it behind the viewer.  this seemed to
*be the position that yeilded the best lighting effects.  */

void SetupLight(){
	
	GLfloat light0_ambient[]={0.2,0.2,0.2,1.0};
	GLfloat light0_diffuse[]={0.9,0.9,0.9,1.0};
	GLfloat light0_specular[]={0.9,0.9,0.9,1.0};
	GLfloat light0_position[]={65.0,20.0,100.0,1.0};

	/*This display list is called in the Init() function*/	

	glNewList(LIGHT_PROP, GL_COMPILE);
      glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
      glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
      glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	  glEnable(GL_LIGHT0);
	glEndList();
}


/*This function finds the normal for two vectors.  This function is used
*by polygon when stating normals for the vertices.  */

void EvalNormal(point3D v,point3D a, point3D b){
		
		NORMAL[0]=((a[1]-v[1])*(b[2]-v[2])-(b[1]-v[1])*(a[2]-v[2]));
		NORMAL[1]=((a[0]-v[0])*(b[2]-v[2])-(b[0]-v[0])*(a[2]-v[2]));
		NORMAL[2]=((a[0]-v[0])*(b[1]-v[1])-(b[0]-v[0])*(a[1]-v[1]));
	}

	
/*
*THIS NEXT SECTION SETS UP FUNCTIONS USEFUL FOR DRAWING THE
*NEEDED OBJECTS IN THE LATER DRAW FUNCTIONS
*/
	
	
/*Polygon accepts 4 coordinates from the vertice list and
*draws a polygon (wall of the house).  The vertice position
*is shown on the attached vetice list diagram*/

void Polygon(int a, int b, int c, int d){

	glBegin(GL_POLYGON);
	EvalNormal(Vertices[a], Vertices[b], Vertices[c]);
	glNormal3dv(NORMAL);
	glVertex3dv(Vertices[a]);
	EvalNormal(Vertices[b], Vertices[c], Vertices[d]);
	glNormal3dv(NORMAL);
	glVertex3dv(Vertices[b]);
	EvalNormal(Vertices[c], Vertices[d], Vertices[a]);
	glNormal3dv(NORMAL);
	glVertex3dv(Vertices[c]);
	EvalNormal(Vertices[d], Vertices[a], Vertices[b]);
	glNormal3dv(NORMAL);
	glVertex3dv(Vertices[d]);
	glEnd();
}


/*The following code for the fractal tree is peices of others code and
*some of my own meshed together.  four other sources were used in making 
*this tree come to life*/

void FractalTree(int level)
{
/*The current setting for level is 5 which allows for a max
*of 4 recursions*/

	if (level == 4) {
 /*when the maximum level occurs, this piece of code is activated
 * and draws the final branch with leaves*/

	  glPushMatrix();
        glRotatef(rand()*180, 0, 1, 0);/*By having this rand here, a kind*/
        glCallList(STEMANDLEAVES);/*of wind blowing effect is created when redrawn*/
      glPopMatrix();
	  }

/*This code begins the branching of the tree in 
*three different directions and continues branching
*3 times until the max level of recursion is reached*/

	else {
    glCallList(STEM);
    glPushMatrix();
      glRotatef(180, 0, 1, 0);
      glTranslatef(0, 1, 0);
      glScalef(0.7, 0.7, 0.7);
		
	    glPushMatrix();    
          glRotatef(120,0,1,0);
	   	  glRotatef(40,0,0,1);
		  FractalTree(level + 1);
        glPopMatrix();

        glPushMatrix();
          glRotatef(0,0,1,0);
		  glRotatef(50,0,0,1);
	  	  FractalTree(level + 1);
        glPopMatrix();

        glPushMatrix();
          glRotatef(240,0,1,0);
		  glRotatef(30,0,0,1);
		  FractalTree(level + 1);
        glPopMatrix();

    glPopMatrix();
  }
}


/*The lists for the trees use cylinders for the branches 
and two triangles for the leaves.  The leaf idea was borrowed
from code off the net.  Check the bibliography for more info*/

void CreateTreeLists(void)
{
  GLUquadricObj *branch = gluNewQuadric();
  int i;

  glNewList(STEM, GL_COMPILE);
    glPushMatrix();
      glRotatef(-90, 1, 0, 0);
      gluCylinder(branch, 0.1, 0.08, 1, 10, 2 );
    glPopMatrix();
  glEndList();

  glNewList(LEAF, GL_COMPILE);  
    glBegin(GL_TRIANGLES);
      glNormal3f(-0.1, 0, 0.25);  
      glVertex3f(0, 0, 0);
      glVertex3f(0.25, 0.25, 0.1);
      glVertex3f(0, 0.5, 0);

      glNormal3f(0.1, 0, 0.25);
      glVertex3f(0, 0, 0);
      glVertex3f(0, 0.5, 0);
      glVertex3f(-0.25, 0.25, 0.1);
    glEnd();
  glEndList();

/*In the following code,I'm not sure what excatly happens with
* the pushattrib().  i do know that half the tree turns green if you
*comment it out.  This code was also borrowed from the same souce
*as the leaf display lists*/
  
  glNewList(STEMANDLEAVES, GL_COMPILE);
    
	glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
      glCallList(STEM);
      glCallList(LEAF_MAT);
      
	  for(i = 0; i < 3; i++) {
        glTranslatef(0, 0.333, 0);
        glRotatef(90, 0, 1, 0);
        
		glPushMatrix();
          glRotatef(0, 0, 1, 0);
          glRotatef(50, 1, 0, 0);
          glCallList(LEAF);
        glPopMatrix();
        
		glPushMatrix();
          glRotatef(180, 0, 1, 0);
          glRotatef(60, 1, 0, 0);
          glCallList(LEAF);
        glPopMatrix();
	  }
    
	glPopAttrib();
    glPopMatrix();
  glEndList();
}
	

/*Build the tree by calling above tree related functions*/

void CreateTree(void){
  glNewList(TREE, GL_COMPILE);
    
	glPushMatrix();
      glCallList(WOOD_MAT);
      glTranslatef(0, -1, 0);
      FractalTree(0);
    glPopMatrix();
  glEndList();  
}


/*Trim does excatly what it says, by using the given coordinates 
*it draws the left, top, and right side trim of the door or 
*window. the coordinates are for the lower left corner of the door. 
*  ***NOTE*** When using this function, place the 
*coordinates out from the wall a little for better  
*3D effect*/

void Trim(GLdouble x,GLdouble y, GLdouble z, GLdouble width, GLdouble height)
{
	  /*When width/2 or height/2 is used, it is simply compesating
	  for the origin being at the center of the freshly drawn trim*/

	glCallList(TRIM_MAT);
	  glPushMatrix(); //Draw first part of Trim
	  glTranslatef(x,y+(height/2),z);//position trim at coordinate given
	  glScalef(2.5,height*10.0,4.0);
	  glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix(); //Draw top Trim
	  glTranslatef(x,y+height,z);
	  glRotatef(-90.0,0.0,0.0,1.0);
	  glTranslatef(0.0,(width/2),0.0);
	  glScalef(2.5,width*10.0,4.0);
 	  glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix(); //Draw right trim
	  glTranslatef(x+width,y+(height/2),z);
	  glScalef(2.5,height*10.0,4.0);
	  glutSolidCube(0.1);
	glPopMatrix();
}


/*NewDoor accepts a point for the bottom left corner of where
* the door is to be drawn. It also takes in the height and width 
* of the door.  Here 1.0 is used instead of 0.1 in the call
*glutSolidCube because of computational reasons*/

void NewDoor(GLdouble x,GLdouble y, GLdouble z, GLdouble width, GLdouble height)	
{
	Trim(x,y,z,width,height);//Draw trim for the new door
	glCallList(DOOR_MAT);
	
	glPushMatrix(); //Draw actual door
	  glTranslatef(x+(width/2),y+(height/2),z);
	  glScalef(width,height,0.2);
	  glutSolidCube(1.0);
	glPopMatrix();
}


/*GarageDoor is very similar to newdoor, but because the door
*lies on the side of the house, a rotation is needed.  The house
*is actually rotated clockwise so that one corner of the garage is 
*still at the origin.  So instead of doing a rotation and a 
*translate, we do one rotation.  This can be done since the door
*is placed in the middle of the wall, and is in a sense pushed
*through the inner wall so that it shows on the exterior.
*this function also draws the partitions in the grage door*/

void GarageDoor(GLdouble x,GLdouble y, GLdouble z, GLdouble width, GLdouble height)
{
	glPushMatrix();
	  glRotatef(90.0,0.0,1.0,0.0);//position house so door can be drawn
	  NewDoor(x,y,z,width,height);//Draw trim for garage
	  glCallList(CONCRETE_MAT);
	
	  for(GLfloat up=1.75;up<7.0;up+=1.75){
		  
		  glPushMatrix();
		    glTranslatef(12.6,up,-0.1);
		    glScalef(228.0,2.0,2.0);
		    glutSolidCube(0.1);
		  glPopMatrix();
	  }
	glPopMatrix();
}


/* NewWindow utilizes Trim to draw three sections of the final
* window trim.  the rest is drawn by the code below along with 
*the actual window pane.  GL_BLEND is enabled so that the alpha
* channel is activated for the windows and a transparent effect
*is obtained*/

void NewWindow(GLdouble x,GLdouble y, GLdouble z, GLdouble width, GLdouble height)	
{
	
	Trim(x,y,z,width,height);	
	
	glCallList(TRIM_MAT);

	glPushMatrix(); //Draw bottom trim
	  glTranslatef(x,y,z);
	  glRotatef(-90.0,0.0,0.0,1.0);
	  glTranslatef(0.0,(width/2),0.0);
	  glScalef(2.5,width*10,4.0);
	  glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix(); //Draw inner trim
	  glTranslatef(x+(width/2),(y+(height/2)),z);
	  glScalef(2.0,(height*10.0)-2.5,2.0);
	  glutSolidCube(0.1);
	glPopMatrix();

	glEnable(GL_BLEND);
	glCallList(GLASS_MAT);//Draw Window Pane
	
	glPushMatrix(); 
	  glTranslatef(x+(width/2),y+(height/2),z);
	  glScalef(width,height,0.05);
	  glutSolidCube(1.0);
	glPopMatrix();
	
	glDisable(GL_BLEND);
}


/*This function is used later by the drawDeck function.  Draw6Rungs
*does six rungs in the same plane which are then rotated and translated
*into the needed position by DrawDeck.  Six was the choice number since 
*both sides of the deck are divisible by six.  12 was the original number
*but was too many was actually seen as a wall instead of single rungs*/

void Draw6Rungs(){
	
	glPushMatrix();
	  glCallList(WOOD_MAT);
	    
	  for(int rung=1;rung<12;rung+=2){
		
		glPushMatrix();
		  glTranslatef(rung,2.0,0.0);
		  glScalef(2.0,30.0,2.0);
		  glutSolidCube(0.1);
		glPopMatrix();
	  }
	glPopMatrix();
}	


/*Texture proved to be a monumental task in itself
*so istead of a grass texture lawn, a simple green
*polygon seemed best suited for the job.  This function
*simpy creates a cube, scales it, and then translates it down
*so the the top of the "grass" is tangent to the bottom
*of the house.*/

void DrawLawn(){
	glCallList(LEAF_MAT);
	
	glPushMatrix();
	  glTranslatef(35.0,-2.0,-17.5);
	  glScalef(100.0,4.0,100.0);
	  glutSolidCube(1.0);
	glPopMatrix();
}


/*This function makes reference to the above tree code and creates
*three trees, each by calling CreateTree and then translating and 
*scaling the tree.  two are placed in the front yard while the other
*is placed in the back*/

void DrawTrees(){
	
	glPushMatrix();
	  glTranslatef(35.0,10.0,10.0);
	  glScalef(10.0,10.0,10.0);
	  CreateTree();
	glPopMatrix();
	
	glPushMatrix();
	  glTranslatef(10.0,8.0,-39.0);
	  glScalef(9.0,8.0,8.0);
	  CreateTree();
	glPopMatrix();
}


/*DrawHouse uses the polygon function above and maps the walls vertices
* to faces.  The are all rendered counterclockwise when viewing the front
*face*/

void DrawHouse(){
	
	glCallList(HOUSE_MAT);
		
	Polygon(1,2,3,0);
	Polygon(1,4,7,2);
	Polygon(4,5,6,7);
	Polygon(5,8,11,6);
	Polygon(8,9,10,11);
	Polygon(12,15,10,9);
	Polygon(12,13,14,15);
	Polygon(13,26,19,14);
	Polygon(26,16,17,18);
	Polygon(20,21,17,16);
	Polygon(22,23,21,20);
	Polygon(27,19,18,23);
	Polygon(24,25,27,22);
	Polygon(3,25,24,0);
}


/*DrawRoof draws the roof in five sections. 
* The back roof is one peice while the front roof is four.
*This is due to the nature of glutSolidCube and the shape 
*of the roof.  The calculations for the rotates and translates
*were a pain.  In fact my calculations ended up being good 
*estimates at best and the rest was done by visual trial and error.
*And again, this function simply uses translates, rotates, 
*and glutSolidCube to render the roof*/

void DrawRoof(){
	
	glCallList(ROOF_MAT);
	
	glPushMatrix();//BackRoof
	  glTranslatef(47.6,11.6,-30.5);
	  glRotatef(-19.0,1.0,0.0,0.0);
	  glScaled(47.0,0.2,11.6378);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//FrontLeftMostRoof
	  glTranslatef(12.5,12.65,-12.2303);
	  glRotatef(19.0,1.0,0.0,0.0);
	  glScaled(27.0,0.2,28.4607);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//SecondSectioninFromLeftonFront
	  glTranslated(35.0,14.4,-17.2303);
	  glRotatef(19.0,1.0,0.0,0.0);
	  glScaled(18.0,0.2,17.808);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//LastSectiononFront
	  glTranslated(60.525,14.4,-17.2303);
	  glRotatef(19.0,1.0,0.0,0.0);
	  glScaled(21.75,0.2,17.808);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//ThirdSectionFromLeftonFront
	  glTranslated(46.825,14.8,-18.5303);
	  glRotatef(19.0,1.0,0.0,0.0);
	  glScaled(6.0,0.2,15.155);
	  glutSolidCube(1.0);
	glPopMatrix();

}


/*Calls NewWindow function and gives coordinates for all
*windows on the house.  The windows on the side of the house
*required a simple rotation and translate*/

void DrawWindows(){
	
	NewWindow(31.5,4.75,-9.8,2.83,4.0);
	NewWindow(52.5,3.0,-9.9,2.33,6.0);
	NewWindow(63.0,3.0,-9.9,4.0,6.0);
	NewWindow(2.0,13.9,-25.4,10.0,2.8);
	
	//Skylighting
	for(GLfloat slide=11.2;slide<66.0;slide+=11.2){
		NewWindow(2.0+slide,13.9,-25.4,10.0,2.8);
	}

	//Draw windows on RIGHT side of house
	glPushMatrix();
	  glTranslatef(70.2,0.0,-10.0);
	  glRotatef(90.0,0.0,1.0,0.0);
	  NewWindow(3.5,3.0,0.0,4.0,6.0);
	  NewWindow(18.75,3.0,0.0,4.0,6.0);
	  glRotatef(-90.0,0.0,1.0,0.0);
	  glTranslatef(-70.2,0.0,10.0);
	glPopMatrix();
	
	//Draw windows on back side of house
	NewWindow(63.0,3.0,-35.4,4.0,6.0);
	NewWindow(52.1,4.5,-35.4,2.8,4.0);
	NewWindow(25.5,2.1,-35.4,8.0,6.6);
	NewWindow(41.0,2.1,-35.4,8.0,6.6);
}


/*Draws front, back, and the garage doors*/

void DrawDoors(){
	
	NewDoor(47.25,2.0,-12.1,3.0,6.66);//front door
	NewDoor(13.0,0.0,-25.4,3.5,6.66);//backdoor
	GarageDoor(1.0,0.0,0.0,23.0,7.0);//garage door
}


/*Draws the two steps at front door.  Uses simple pops, pushes
* and rotates, scales, and translates*/

void DrawFrontStep(){
	
	glCallList(CONCRETE_MAT);
	
	glPushMatrix();
	  glTranslated(46.87,1.0,-11.25);
	  glScaled(7.75,2.0,2.5);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	  glTranslated(46.87,0.5,-9.25);
	  glScaled(9.75,1.0,2.0);
	  glutSolidCube(1.0);
	glPopMatrix();
}


/*Draws the deck on the back of the house.  The matrices below
*are allowed to accumalate when drawing the rungs*/

void DrawDeck(){
	
	glCallList(WOOD_MAT);
	
	glPushMatrix();
	  glTranslatef(38.0,2.0,-41.0);
	  glScalef(26.0,1.0,12.0);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	  glTranslatef(25.0,2.0,-35.0);
	  glRotatef(90.0,0.0,1.0,0.0);
	  Draw6Rungs();
	  
	  glPushMatrix();
	   glTranslatef(0.0,0.0,26.0);
 	   Draw6Rungs();
	  glPopMatrix();
	  
	  glTranslatef(12.3,0.0,0.0);
	  glRotatef(-90.0,0.0,1.0,0.0);
	  glTranslatef(1.0,0.0,0.0);
	  Draw6Rungs();
	  glTranslatef(13.0,0.0,0.0);
	  Draw6Rungs();
	glPopMatrix();

	//Draw railing across rungs
	glPushMatrix();
	  glTranslatef(25.3,5.45,-41.7);
	  glScalef(0.6,0.25,11.8);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	  glTranslatef(38.0,5.45,-47.3);
	  glScalef(26.0,0.25,0.6);
	  glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	  glTranslatef(51.3,5.45,-41.7);
	  glScalef(0.6,0.25,11.8);
	  glutSolidCube(1.0);
	glPopMatrix();
}


/*Draws the chimney and the flu.*/

void DrawChimney(){
	
	glCallList(BRICK_MAT);
	
	glPushMatrix();
	  glTranslatef(37.25,10.0,-35.0);
	  glScalef(4.5,20.0,6.0);
	  glutSolidCube(1.0);
	glPopMatrix();

	glCallList(ROOF_MAT);
	
	glPushMatrix();
	  glTranslated(37.25,20.01,-35.0);
	  glScalef(4.0,0.3,5.5);
	  glutSolidCube(1.0);
	glPopMatrix();
}


/*This reshape function is the one from the text book
*slightly modified to accomdate my scene*/

void Reshape(int w, int h){
	
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if (w<=h)
		glOrtho(-10.0,80.0,-45.0*(GLfloat)h/(GLfloat)w,
		45.0*(GLfloat)h/(GLfloat)w,-80.0,80.0);
	
	else
		glOrtho(-10.0*(GLfloat)w/(GLfloat)h,80.0*(GLfloat)w/(GLfloat)h,
		-45.0,45.0,-80.0,80.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


/*The init function.  it sets up all the settings for the rendering*/

void Init()
{	
	SetupMaterials();//build material display lists
	CreateTreeLists();//build tree display lists
    SetupLight();//calls function to organize light properties
		
	glEnable(GL_NORMALIZE);//normalize points and vectors
    glEnable(GL_LIGHTING);//use light in the program
	glEnable(GL_CULL_FACE);//remove hidden surfaces
	glEnable(GL_DEPTH_TEST);//tells comp. to figure out what's in front of what
	
	glDepthFunc(GL_LESS);//not exactly sure, most code i looked at used it though
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//transparency setting

	glClearColor(0.5, 0.5, 0.5, 1.0);//set background to gray
	
	glCallList(LIGHT_PROP);//Build my light
}


/* the display function that puts the whole thing together and rotates
*the scene according to the settings made by SpinHouse*/

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/*CLEAR SCREEN*/
	
	glPushMatrix();
	  glLoadIdentity();//Load identity matrix
	  glTranslatef(35.0,0.0,-17.5);//move center of house to origin
	  glRotatef(theta[0], 0.0, 1.0, 0.0); //Rotate around y-axis
	  glRotatef(theta[1], 1.0, 0.0, 0.0); //Rotate around x-axis
	  glRotatef(theta[2], 0.0,0.0,1.0); //Rotate around z-axis
	  glTranslatef(-35.0,0.0,17.5);//move house back
	
	  DrawHouse();
	  DrawRoof();
	  DrawDoors();
	  DrawWindows();
	  DrawChimney();
	  DrawTrees();
	  DrawDeck();
	  DrawFrontStep();
	  DrawLawn();
	
	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
}


/*When Idle, this function keeps the rotation going*/

void SpinHouse(){
	
	theta[axis]+=degrees;
	if(theta[axis]>360.0) theta[axis]-=360.0;
	
	Display();
}


/*This function recieves input from the keyboard
* and tells display what aixs to rotate on in what
*direction.  It also has a quite command*/

void Keyboard(unsigned char key, int x, int y){
	
	if(key=='k') glutIdleFunc(NULL);
	if(key=='j') degrees=-1,axis=0,glutIdleFunc(SpinHouse);
	if(key=='i') degrees=-1,axis=1,glutIdleFunc(SpinHouse);
	if(key=='l') degrees=1,axis=0,glutIdleFunc(SpinHouse);
	if(key=='m') degrees=1, axis=1,glutIdleFunc(SpinHouse);
	if(key=='o') degrees=-1, axis=2,glutIdleFunc(SpinHouse);
	if(key=='n') degrees=1, axis=2,glutIdleFunc(SpinHouse);
	if(key=='q') exit(0);
}


/*Menu that sends the menu command to the keyboard function*/

void House_Menu(int id){
	
	char key;

	switch(id){
	case 3:
		key='k';
		break;
	case 4:
		key='j';
		break;
	case 5:
		key='i';
		break;
	case 6:
		key='l';
		break;
	case 7:
		key='m';
		break;
	case 8:
		key='o';
		break;
	case 9:
		key='n';
		break;
	case 10:
		key='q';
		break;
	}
	Keyboard(key,0,0);
}


/*The BIG MOMMA!*/

void main(int argc, char** argv)
{
	
	int h_menu;
	
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//setup buffers
	glutInitWindowSize(400,400); /* 400x 400 pixel window*/
	glutInitWindowPosition(0,0); /*place window at top left of display*/
	glutCreateWindow("Ranch Home"); /*window title*/
	
	Init();//initialize settings
	
	//CallBack Functions
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
 	glutIdleFunc(SpinHouse);/*Turns the house into a merry-go round*/
	glutKeyboardFunc(Keyboard);
	
	//Menu called when right mouse button clicked
	h_menu=glutCreateMenu(House_Menu);
		glutAddMenuEntry("Ranch Home, created by",0);
		glutAddMenuEntry("Matt Snyder 1998",1);
		glutAddMenuEntry("KEYBOARD COMMANDS:",2);
		glutAddMenuEntry("K = Stops Rotation",3);
		glutAddMenuEntry("J = Rotates -Y Axis",4);
		glutAddMenuEntry("L = Rotates +Y Axis",6);
		glutAddMenuEntry("I = Rotates -X Axis",5);
		glutAddMenuEntry("M = Rotates +X Axis",7);
		glutAddMenuEntry("O = Rotates -Z Axis",8);
		glutAddMenuEntry("N = Rotates +Z Axis",9);
		glutAddMenuEntry("(Q)UIT",10);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop(); /*enter event loop */
}
