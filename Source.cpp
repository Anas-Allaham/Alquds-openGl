
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "camera.h"
#include <fstream>
#include "Model_3DS.h"
#include "Point.h"
#include<iostream>


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application	

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default
int amod;
int wall;
int carpet;
float r=0;
float a=0;
int window;
int block;
int roof;
int shbak;
int door;
int b=0;
int door2;
int triangle,room,amode,madne;
int triangle2,amode3;

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

Camera MyCamera;
	Model_3DS *person;









	

static void DrawDome( float rad, int texture=-1, Point center=Point(0,0,0))
{
 glTranslated(center.x,center.y,center.z); 
 float lastcenter=rad*sin(3.14/2);
 float lastr=rad*cos(3.14/2);
 for (float vertical=3.14/2.0; vertical>=0; vertical-=0.1)
 {
  float centeri=rad*sin(vertical);
  float ri=rad*cos(vertical);
  int col = 0;  
  for (float horizin=0; horizin<=2*3.14+0.1; horizin+=0.1)
  { 
	  Point a= Point (  ri*cos(horizin) , centeri , ri*sin(horizin));
   Point b= Point (  ri*cos(horizin+0.1) , centeri , ri*sin(horizin+0.1));  
   Point c= Point (  lastr*cos(horizin) , lastcenter , lastr*sin(horizin));
   Point d= Point (  lastr*cos(horizin+0.1) , lastcenter , lastr*sin(horizin+0.1));
   if (texture!=-1)
   {   glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);  
	glTexCoord2d(1-(horizin)/(2*3.14), 0.5+sin(vertical-0.1)/2.0);
    glVertex3f(a.x,a.y,a.z);    glTexCoord2d(1-(horizin+0.1)/(2*3.14)+5, 0.5+sin(vertical-0.1)/2.0);
    glVertex3f(b.x,b.y,b.z);    glTexCoord2d(1-(horizin+0.1)/(2*3.14)+5, 0.5+sin(vertical)/2.0+5);
    glVertex3f(d.x,d.y,d.z);    glTexCoord2d(1-(horizin)/(2*3.14), 0.5+sin(vertical)/2.0+5);
    glVertex3f(c.x,c.y,c.z);    glEnd();
   }   else
   {    glBegin(GL_QUADS);
    glVertex3f(a.x,a.y,a.z); 
	glVertex3f(b.x,b.y,b.z);
    glVertex3f(d.x,d.y,d.z); 
	glVertex3f(c.x,c.y,c.z);
    glEnd();   }
  }  lastr=ri;
  lastcenter=centeri;
 }
 glTranslated(-center.x,-center.y,-center.z);
};



static  void DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture)
{
  //glTranslated(Base_center1.x,Base_center1.y, Base_center1.z); 

//  Base_center1=Point(0,0,0);
  Point Base_center2=Point (0,0,height); 
  if (texture!=-1)
    glColor3f(1,1,1);
  float angle=0, x1=Base_rad1, y1=0, x2=Base_rad2, y2=0;
  for (angle=0; angle <=2*3.14+0.1; angle+=0.1)  
  {
   Point a= Point (x1,y1,Base_center1.z); 
   Point b= Point (x2,y2,Base_center2.z);
   x1=Base_rad1*cos(angle);  
   y1=Base_rad1*sin(angle);
   x2=Base_rad2*cos(angle);
   y2=Base_rad2*sin(angle);
   Point c= Point (x2,y2,Base_center2.z);
   Point d= Point (x1,y1,Base_center1.z);
   glBindTexture(GL_TEXTURE_2D,texture); 
   glBegin(GL_QUADS);
    glTexCoord2f(angle/(2*3.14),a.z/height);
    glVertex3f(a.x,a.y,a.z);   
    glTexCoord2f(angle/(2*3.14),b.z/height);
	glVertex3f(b.x,b.y,b.z);
    glTexCoord2f((angle+0.1)/(2*3.14),c.z/height);
    glVertex3f(c.x,c.y,c.z);   
    glTexCoord2f((angle+0.1)/(2*3.14),d.z/height);   
	glVertex3f(d.x,d.y,d.z);
   glEnd();
  }}
void DrawAnotherWall(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth, GLuint texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z - depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x + width, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y + height, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y, z);
    glEnd();
}
void DrawAnotherDoor(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth, GLuint texture,GLfloat r,int b)
{
	
if(b==0)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glRotatef(r,0,1,0);
	glTranslatef(-x,-y,-z);
	 glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z - depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x + width, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y + height, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y, z);
    glEnd();
	glPopMatrix();
}
else {
	glPushMatrix();

	glTranslatef(x+3,y,z);	
	glRotatef(r,0,1,0);
	glTranslatef(-x-3,-y,-z);

	 glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z - depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x + width, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y + height, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1, 1); glVertex3f(x, y, z - depth);
    glTexCoord2d(0, 1); glVertex3f(x, y, z);
    glEnd();
	glPopMatrix();

}
  
}


void DrawCarpet(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth, GLuint texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);


    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y + height, z);
    glTexCoord2d(6, 0); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(6,6); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 6); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(6, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(6, 6); glVertex3f(x, y, z - depth);
    glTexCoord2d(0, 6); glVertex3f(x, y, z);
    glEnd();
}
GLfloat LightPos[] = {3,0,0,1};
GLfloat LightAmb[] = {1,1,1,1};
GLfloat LightDiff[] = {0.6,0.6,0.6,1};
GLfloat LightSpec[] = {-0.2,-0.2,-0.2,1};
GLfloat MatAmb[] = {1,0,0,1};
GLfloat MatDiff[] = {0.2,0.6,0.9,1};
GLfloat MatSpec[] = {0,0,0,1};
GLfloat MatShn[] = {200};


void Key(bool* keys, float speed, int x)
{
	if (keys['S'])
		MyCamera.RotateX(-1 * speed);
	if (keys['W'])
		MyCamera.RotateX(1 * speed);
	if (keys['D'])
		MyCamera.RotateY(-1 * speed);
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);
	if (keys['A'])
		MyCamera.RotateY(1 * speed);
	if (keys[VK_UP])
		MyCamera.MoveForward(1 * speed);
		
	if (keys[VK_DOWN])
		MyCamera.MoveForward(-1 * speed);
	if (keys[VK_RIGHT]){
		MyCamera.MoveRight(1 * speed);
	}
	if (keys[VK_LEFT])
		MyCamera.MoveRight(-1 * speed);

	
	if (keys['O'])
		MyCamera.MoveUpward(1 * speed);
	if (keys['L'])
		MyCamera.MoveUpward(-1 * speed);
		if (keys['M'])
		{

		if(r<=0.9 &&r>-90){
			r=r-0.8f;
			keys['N']=0;
		b=0;
		
	DrawAnotherDoor(0 , 0 , -0.1 , 1.5 , 2 , 0.5 , door , r,b);//باب
		}
		}
		
				if (keys['N'])
		{
			if(a<90 && a>=-1){
		b=1;
			a=a+0.8;

		DrawAnotherDoor(x,0,-0.1,-1.5,2,0.5,door2,a,b);//باب
		}
		}


		if (keys['K']){
			if(r>=-90.9 && r<=0){
		r=r+1;
	 keys['K']=0;

		b=0;
		DrawAnotherDoor(0 , 0 , -0.1 , 1.5 , 2 , 0.5 , door , r,b);//باب
	}
		}
		if (keys['J']){
			if(a<=90.9 && a>=0){
		a=a-1;
		keys['J']=0;

		b=1;
		DrawAnotherDoor(x , 0 , -0.1 , -1.5 , 2 , 0.5 , door2 , a,b);//باب
		}
	}
}
void UpdateModel(bool* keys, float speed, Model_3DS* model)
{
    if (keys[VK_UP] || keys[VK_DOWN] || keys[VK_RIGHT] || keys[VK_LEFT])
    {
        model->pos.x += keys[VK_RIGHT] ? speed : (keys[VK_LEFT] ? -speed : 0);
        model->pos.z += keys[VK_UP] ? speed : (keys[VK_DOWN] ? -speed : 0);
    }
}
void Update()
{
    MyCamera.Render();
    Key(keys, 0.02,0);  // Update camera position
    
    UpdateModel(keys, 0.02, person);  // Update model position
}

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.1f, 0.1f, 0.1f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_TEXTURE_2D);

	person=new Model_3DS();
	person->Load("Boy N311013.3DS");
	glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*******************/
	GLTexture hair,body,cblackLoth,cloth,PE_black;
	hair.LoadBMP("HairTexTwinTail_Black.bmp");
	body.LoadBMP("body.bmp");
	cblackLoth.LoadBMP("cblack loth_02_m.bmp");
	cloth.LoadBMP("cloth_02_m.bmp");
	PE_black.LoadBMP("PE_Black.bmp");


	/**********************/
	person->Materials[0].tex=hair;
	person->Materials[1].tex=body;
	person->Materials[2].tex=cblackLoth;
	person->Materials[3].tex=cloth;
	person->Materials[4].tex=PE_black;


	/**********************/
    amod=LoadTexture("Amod.bmp",255);
	wall=LoadTexture("Wall.bmp",255);
	roof=LoadTexture("Roof2.bmp",255);		
	door=LoadTexture("door.bmp",255);
	door2=LoadTexture("door2.bmp",255);		
	room=LoadTexture("room3.bmp",255);		
	triangle=LoadTexture("triangle.bmp",255);		
	amode=LoadTexture("3amod.bmp",255);
	triangle2=LoadTexture("triangle2.bmp",255);		
	 amode3=LoadTexture("amode3.bmp",255);
	madne=LoadTexture("madne.bmp",255);


	shbak=LoadTexture("shbak.bmp",255);
	carpet=LoadTexture("carpets1.bmp",255);
	window=LoadTexture("Window.bmp",255);
	block=LoadTexture("Block.bmp",255);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

	glEnable(GL_TEXTURE_2D);

	MyCamera = Camera();
	MyCamera.Position.x = 0;
	MyCamera.Position.y = 0;
	MyCamera.Position.z = +15;

 
	return TRUE;										// Initialization Went OK
}


	void drawAlkable(float x,float y,float z){

  
    // الوجه الأمامي
    DrawAnotherWall(x - 3, y, z, 3, 2, 0.5, roof);

    DrawAnotherDoor(x, y, z - 0.1, 1.5, 2, 0.5, door, r, 0);  // باب
    DrawAnotherDoor(x + 3, y, z - 0.1, -1.5, 2, 0.5, door2, a, 1);  // باب
    DrawAnotherWall(x + 3, y, z, 3, 2, 0.5, roof);

    // الوجه اليميني
    DrawAnotherWall(x + 6, y, z, 0.5, 2, 2, roof);
    DrawAnotherWall(x + 6, y + 1.5, z - 2, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 6, y + 0.5, z - 2, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 6, y, z - 2, 0.5, 0.5, 1, roof);
    DrawAnotherWall(x + 6, y, z - 3, 0.5, 2, 2, roof);
    DrawAnotherWall(x + 6, y + 1.5, z - 5, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 6, y + 0.5, z - 5, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 6, y, z - 5, 0.5, 0.5, 1, roof);
    DrawAnotherWall(x + 6, y, z - 6, 0.5, 2, 2, roof);
    DrawAnotherWall(x + 6, y + 1.5, z - 8, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 6, y + 0.5, z - 8, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 6, y, z - 8, 0.5, 0.5, 1, roof);
    DrawAnotherWall(x + 6, y, z - 9, 0.5, 2, 2, roof);
    DrawAnotherWall(x + 6, y + 1.5, z - 11, 0.5, 0.5, 1, roof);


	glColor4f(0.5f,0.5f,0.5f,0.3f);
	DrawAnotherWall(x+6 , y+0.5 , z-11 , 0.5 , 1 , 1 , window);
  glColor4f(1.0f,1.0f,1.0f,1.0f);


 DrawAnotherWall(x+6 , y , z-11 , 0.5 , 0.5 , 1 , roof); 
 DrawAnotherWall(x+6 , y , z-12 , 0.5 , 2 , 2 , roof);
 DrawAnotherWall(x+6 , y+1.5 , z-14 , 0.5 , 0.5 , 1 , roof);

 glColor4f(0.5f,0.5f,0.5f,0.3f);
 DrawAnotherWall(x+6 , y+0.5 , z-14 , 0.5 , 1 , 1 , window);
  glColor4f(1.0f,1.0f,1.0f,1.0f);


 DrawAnotherWall(x+6 , y , z-14 , 0.5 , 0.5 , 1 , roof);
 DrawAnotherWall(x+6 , y , z-15 , 0.5 , 2 , 2 , roof);
  DrawAnotherWall(x-3 , y , z , 0.5 , 2 , 2 , roof);


    // الوجه اليساري
   
    DrawAnotherWall(x - 3, y + 1.5, z - 2, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x - 3, y + 0.5, z - 2, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x - 3, y, z - 2, 0.5, 0.5, 1, roof);
    DrawAnotherWall(x - 3, y, z - 3, 0.5, 2, 2, roof);
    DrawAnotherWall(x - 3, y + 1.5, z - 5, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x - 3, y + 0.5, z - 5, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x - 3, y, z - 5, 0.5, 0.5, 1, roof);
    DrawAnotherWall(x - 3, y, z - 6, 0.5, 2, 2, roof);
    DrawAnotherWall(x - 3, y + 1.5, z - 8, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x - 3, y + 0.5, z - 8, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x - 3, y, z - 8, 0.5, 0.5, 1, roof);
    DrawAnotherWall(x - 3, y, z - 9, 0.5, 2, 2, roof);
    DrawAnotherWall(x - 3, y + 1.5, z - 11, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x - 3, y + 0.5, z - 11, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x - 3, y, z - 11, 0.5, 0.5, 1, roof);
    DrawAnotherWall(x - 3, y, z - 12, 0.5, 2, 2, roof);
    DrawAnotherWall(x - 3, y + 1.5, z - 14, 0.5, 0.5, 1, roof);

	glColor4f(0.5f,0.5f,0.5f,0.3f);
	DrawAnotherWall(x-3 , y+0.5 , z-14 , 0.5 , 1 , 1 , window);
  glColor4f(1.0f,1.0f,1.0f,1.0f);

 DrawAnotherWall(x-3 , y , z-14 , 0.5 , 0.5 , 1 , roof);


    // الوجه الخلفي
    DrawAnotherWall(x - 3, y, z - 17, 9.5, 2, 0.5, roof);

    // السطح
	DrawAnotherWall(x + 6, y + 2, z, -3, 0, 17, roof);
    DrawAnotherWall(x, y + 2, z, -3, 0, 17, roof);
    DrawAnotherWall(x, y + 2, z, 0.3, 2, 2, roof);
    DrawAnotherWall(x, y + 2, z - 2, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x, y + 2.5, z - 2, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x, y + 3.5, z - 2, 0.3, 0.5, 1, roof);

    DrawAnotherWall(x, y + 2, z - 3, 0.3, 2, 2, roof);

    DrawAnotherWall(x, y + 2, z - 5, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x, y + 2.5, z - 5, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x, y + 3.5, z - 5, 0.3, 0.5, 1, roof);

    DrawAnotherWall(x, y + 2, z - 6, 0.3, 2, 2, roof);

    DrawAnotherWall(x, y + 2, z - 8, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x, y + 2.5, z - 8, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x, y + 3.5, z - 8, 0.3, 0.5, 1, roof);
    DrawAnotherWall(x, y + 2, z - 9, 0.3, 2, 2, roof);

    DrawAnotherWall(x, y + 2, z - 11, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x, y + 2.5, z - 11, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x, y + 3.5, z - 11, 0.3, 0.5, 1, roof);

    DrawAnotherWall(x, y + 2, z - 12, 0.3, 2, 0.5, roof);

    DrawAnotherWall(x + 3, y + 2, z, 0.3, 2, 2, roof);

    DrawAnotherWall(x + 3, y + 2, z - 2, 0.3, 0.5, 1, roof);


	
    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 3.25, y + 2.5, z - 2, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 3, y + 3.5, z - 2, 0.3, 0.5, 1, roof);

    DrawAnotherWall(x + 3, y + 2, z - 3, 0.3, 2, 2, roof);

    DrawAnotherWall(x + 3, y + 2, z - 5, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 3.25, y + 2.5, z - 5, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 3, y + 3.5, z - 5, 0.3, 0.5, 1, roof);

    DrawAnotherWall(x + 3, y + 2, z - 6, 0.3, 2, 2, roof);

    DrawAnotherWall(x + 3, y + 2, z - 8, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 3.25, y + 2.5, z - 8, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 3, y + 3.5, z - 8, 0.3, 0.5, 1, roof);

    DrawAnotherWall(x + 3, y + 2, z - 9, 0.3, 2, 2, roof);

    DrawAnotherWall(x + 3, y + 2, z - 11, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 3.25, y + 2.5, z - 11, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 3, y + 3.5, z - 11, 0.3, 0.5, 1, roof);

    DrawAnotherWall(x + 3, y + 2, z - 12, 0.3, 2, 0.5, roof);

    // المثلث بالسقف
    glPushMatrix();
	glTranslatef(x + 3, y + 4 , z + 8);
    glRotatef(45, 0 , 0 , 1);
	glTranslatef(-x - 3 , y - 4 , z - 8);
    DrawAnotherWall(x + 3, y + 4 , z , 0.1 , 2, 12.5, roof);
    glPopMatrix();

    glPushMatrix();
	  glTranslatef( x , y + 4 , z + 8);
		glRotatef(-45, 0, 0, 1);
	  glTranslatef( -x , y - 4, z - 8);

    DrawAnotherWall(x , y + 4 , z , 0.1 , 2.2 , 12.5 , roof);
    glPopMatrix();

    // واجهة فوقانية
 DrawAnotherWall(x, y + 2, z, 0.5, 2, 0.3, roof);

    DrawAnotherWall(x + 0.5, y + 2, z, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 0.5, y + 2.5, z, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 0.5, y + 3.5, z, 0.75, 0.5, 0.3, roof);

    DrawAnotherWall(x + 1.25, y + 2, z, 0.5, 2, 0.3, roof);

    DrawAnotherWall(x + 1.75, y + 2, z, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 1.75, y + 2.5, z, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 1.75, y + 3.5, z, 0.75, 0.5, 0.3, roof);

    DrawAnotherWall(x + 2.5, y + 2, z, 0.5, 2, 0.3, roof);

    glBindTexture(GL_TEXTURE_2D, triangle2);
    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(0, 0);
    glVertex3f(x, y + 4, z);
    glTexCoord2f(0.5, 1);
    glVertex3f(x + 1.6, y + 5.6, z);
    glTexCoord2f(1, 0);
    glVertex3f(x + 3.2, y + 4, z);
	glEnd();


	 DrawAnotherWall(x, y + 2, z-12, 0.5, 2, 0.3, roof);
    DrawAnotherWall(x + 0.5, y + 2, z-12, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 0.5, y + 2.5, z-12, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 0.5, y + 3.5, z-12, 0.75, 0.5, 0.3, roof);

    DrawAnotherWall(x + 1.25, y + 2, z-12, 0.5, 2, 0.3, roof);

    DrawAnotherWall(x + 1.75, y + 2, z-12, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    DrawAnotherWall(x + 1.75, y + 2.5, z-12, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    DrawAnotherWall(x + 1.75, y + 3.5, z-12, 0.75, 0.5, 0.3, roof);

    DrawAnotherWall(x + 2.5, y + 2, z-12, 0.5, 2, 0.3, roof);

    glBindTexture(GL_TEXTURE_2D, triangle2);
    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(0, 0);
    glVertex3f(x, y + 4, z-12);
    glTexCoord2f(0.5, 1);
    glVertex3f(x + 1.6, y + 5.6, z-12);
    glTexCoord2f(1, 0);
    glVertex3f(x + 3.2, y + 4, z-12);

    glEnd();
//الارضية
	DrawCarpet(x-3 , y , z  , 9 , 0 , 17 , carpet);


// السقف الفوقاني والعواميد
DrawAnotherWall(x - 3, y + 1.9, z, 9.5, 0.1, -2, roof);

// الحيط المزخرف في السقف
DrawAnotherWall(x - 3, y + 2, z, 3, 0.5, 0.3, room);
DrawAnotherWall(x - 3, y + 2, z - 0.1, 0.3, 0.5, 12, room);
DrawAnotherWall(x - 3, y + 2, z - 12, 3, 0.5, 0.5, room);
DrawAnotherWall(x - 3, y + 2.5, z, 3, 0, 12.5, roof);

// القبة
Point a = Point(x + 1.6, y + 5.3, z - 15);
DrawAnotherWall(x, y + 2, z - 12.5, 0.3, 3.5, 5, roof);
DrawAnotherWall(x + 3, y + 2, z - 12.5, 0.3, 3.5, 5, roof);
DrawAnotherWall(x, y + 2, z - 17.5, 3.3, 3.5, 0.3, roof);
DrawAnotherWall(x, y + 2, z - 12.5, 3.3, 3.5, 0.3, roof);
DrawDome(3, madne, a);

// العوامييد
DrawAnotherWall(x - 2.25, y, z + 1, 0.3, 2, 0.3, amode3);
DrawAnotherWall(x - 1.5, y, z + 1, 0.3, 2, 0.3, amode3);
DrawAnotherWall(x - 0.75, y, z + 1, 0.3, 2, 0.3, amode3);
DrawAnotherWall(x + 3.75, y, z + 1, 0.3, 2, 0.3, amode3);
DrawAnotherWall(x + 4.5, y, z + 1, 0.3, 2, 0.3, amode3);
DrawAnotherWall(x + 5.25 , y , z + 1 , 0.3 , 2 , 0.3 , amode3);

// اخر العامود
DrawAnotherWall(x - 2.40, y, z + 1, 0.6, 0.06, 0.3, roof);
DrawAnotherWall(x - 2.35, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
DrawAnotherWall(x - 2.30, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

DrawAnotherWall(x - 1.65, y, z + 1, 0.6, 0.06, 0.3, roof);
DrawAnotherWall(x - 1.60, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
DrawAnotherWall(x - 1.55, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

DrawAnotherWall(x - 0.90, y, z + 1, 0.6, 0.06, 0.3, roof);
DrawAnotherWall(x - 0.85, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
DrawAnotherWall(x - 0.80, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

DrawAnotherWall(x + 3.60, y, z + 1, 0.6, 0.06, 0.3, roof);
DrawAnotherWall(x + 3.65, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
DrawAnotherWall(x + 3.70, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

DrawAnotherWall(x + 4.35, y, z + 1, 0.6, 0.06, 0.3, roof);
DrawAnotherWall(x + 4.40, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
DrawAnotherWall(x + 4.45, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

DrawAnotherWall(x + 5.1, y, z + 1, 0.6, 0.06, 0.3, roof);
DrawAnotherWall(x + 5.15, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
DrawAnotherWall(x + 5.20, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

	//العواميد في الجامع الشريف القبلي المحرف
 DrawAnotherWall(x + 4.5, y, z - 3.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x + 4.5, y, z - 6.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x + 4.5, y, z - 9.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x + 4.5, y, z - 12.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x + 4.5, y, z - 15.75, 0.3, 2, 0.3, amode);

 DrawAnotherWall(x - 1.5, y, z - 3.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x - 1.5, y, z - 6.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x - 1.5, y, z - 9.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x - 1.5, y, z - 12.75, 0.3, 2, 0.3, amode);
 DrawAnotherWall(x - 1.5, y, z - 15.75, 0.3, 2, 0.3, amode);


}


int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    //Update();  // Call the update function
	//person->pos.y=0;
	//person->scale=1;
	//person->Draw();
	/*************************/
	  MyCamera.Render();
	  int x=8;
    Key(keys, 0.02,x);
	
	 glLightfv(GL_LIGHT1,GL_POSITION,LightPos);
 glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb);
 glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiff);
 glLightfv(GL_LIGHT1,GL_SPECULAR,LightSpec);
 
 glEnable(GL_LIGHT1);	
 glEnable(GL_LIGHTING);
 glMaterialfv(GL_FRONT,GL_AMBIENT,MatAmb);
 glMaterialfv(GL_FRONT,GL_DIFFUSE,MatDiff);
 glMaterialfv(GL_FRONT,GL_SPECULAR,MatSpec);
 glMaterialfv(GL_FRONT,GL_SHININESS,MatShn);
 glEnable(GL_COLOR_MATERIAL);

		//drawAlkable(x,0,0);
	
	DrawAnotherWall( 0 , 0 , 0 , 1, 3, 0.5,wall);


	DrawAnotherWall( 1 , 0 , 0 , 1, 0.5, 0.5,block);
	DrawAnotherWall( 1 , 0.5 , 0 , 1, 2, 0.3,window);
	DrawAnotherWall( 1 , 2.5 , 0 , 1, 0.5, 0.5,block);


	DrawAnotherWall( 2 , 0 , 0 , 3.5, 3, 0.5,wall);

	DrawAnotherWall( 5.5 , 0 , 0 , 1, 0.5, 0.5,block);
	DrawAnotherWall( 5.5 , 0.5 , 0 , 1, 2, 0.3,window);
	DrawAnotherWall( 5.5 , 2.5 , 0 , 1, 0.5, 0.5,block);


	DrawAnotherWall( 6.5 , 0 , 0 , 1, 3, 0.5,wall);


	DrawAnotherWall( 2 , 0.75 , 0 , 3.5, 0.5, -0.5,block);


				 Point b=Point(4,3.2,-3.5);
				 DrawDome(4,block,b);
		return TRUE;
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
													if (!HIWORD(wParam))					// Check Minimization State
													{
														active = TRUE;						// Program Is Active
													}
													else
													{
														active = FALSE;						// Program Is No Longer Active
													}

													return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
													switch (wParam)							// Check System Calls
													{
													case SC_SCREENSAVE:					// Screensaver Trying To Start?
													case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
														return 0;							// Prevent From Happening
													}
													break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
													PostQuitMessage(0);						// Send A Quit Message
													return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
													keys[wParam] = TRUE;					// If So, Mark It As TRUE
													return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
													keys[wParam] = FALSE;					// If So, Mark It As FALSE
													return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
													ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
													return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)	
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Example", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

