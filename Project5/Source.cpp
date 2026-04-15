
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
#include "Primitives.h"
#include<iostream>
#include "vector"
#include"exten.h"
#include"sub_build.h"
#include"CAM.h"
#include"Main_build.h"
#include<iostream>
#include <Windowsx.h>
using namespace std;

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
int stairs;
float a=0;
int window;
int block;
int roof;
int window3;
int shbak;
int car;
int he;
int jdar;
int build1;
int build2;
int dome;
int krse;
int door;
int b=0;
int doorBuild;
int door2;
int school;
int sour;
int ground,ground2,saria,anas,slsle;
int skyBox;
int triangle,room,amode,madne;
int triangle2,amode3;
bool isfps=0;
int cnt=1000;
int yPos,xPos,scrollDelta;
int bird;

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

Camera MyCamera,FREE_CAM;
Model_3DS *person;
Model_3DS *Bench;
Model_3DS *tre;


int t;

	// skybox
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;
float ax=0,az=0,rx=0,rz=0;

GLUquadric *quadric = gluNewQuadric();



bool www=0,w=0,w2,w3,w4;

int image3;

vector<Model_3DS *> tree;
vector<Model_3DS *> tree1;


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.1f, 0.1f, 0.1f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
/*
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpec);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMateriali(GL_FRONT, GL_SHININESS, 128);*/



	Model_3DS *y;
  GLTexture Bark, Leaf;
  Leaf.LoadBMP("p_T/leave.bmp");
    Bark.LoadBMP("p_T/bark.bmp");
  

  for (int i=0;i<30;i++){
      glPushMatrix(); 
    y = new Model_3DS ( );  
    y->Load("Tree.3ds");
    y->pos.x= t;
    y->pos.y=0;
    y->pos.z=0.5;
    y->scale=0.001;
    t+=1.6;
    tree.push_back(y);
    y->Materials[0].tex=Bark;
      y->Materials[1].tex=Leaf;
    glPopMatrix();
  }
  
  for (int i=0;i<30;i++){
    glPushMatrix(); 
    y = new Model_3DS ( );
    

    y->Load("Tree.3ds");
    y->pos.x= 17;
    y->pos.y=r;
    y->pos.z=0.5;
    y->scale=0.001;
    r+=1.6;
    tree1.push_back(y);
    y->Materials[0].tex=Bark;
      y->Materials[1].tex=Leaf;
      glPopMatrix();
  }



	person=new Model_3DS();
	person->Load("Boy N311013.3DS");
	glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*******************/
  	/*tree=new Model_3DS();
	tree->Load("tree.3DS");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLTexture leaf,trunk;
	leaf.LoadBMP("window.bmp");
	trunk.LoadBMP("trunk.bmp");
	tree->Materials[0].tex=trunk;
	tree->Materials[1].tex=leaf;
	*/
  /**********************/
		GLTexture hair,body,cblackLoth,cloth,PE_black;
	hair.LoadBMP("ext/HairTexTwinTail_Black.bmp");
	body.LoadBMP("ext/body.bmp");
	cblackLoth.LoadBMP("ext/cblack loth_02_m.bmp");
	cloth.LoadBMP("ext/cloth_02_m.bmp");
	PE_black.LoadBMP("ext/PE_Black.bmp");
	person->Materials[0].tex=hair;
	person->Materials[1].tex=body;
	person->Materials[2].tex=cblackLoth;
	person->Materials[3].tex=cloth;
	person->Materials[4].tex=PE_black;
	/**********************/
    amod=LoadTexture("ext/Amod.bmp",255);
	wall=LoadTexture("ext/Wall.bmp",255);
	roof=LoadTexture("ext/Roof2.bmp",255);		
	door=LoadTexture("ext/door.bmp",255);
	door2=LoadTexture("ext/door2.bmp",255);		
	room=LoadTexture("ext/room3.bmp",255);		
	triangle=LoadTexture("ext/triangle.bmp",255);		
	amode=LoadTexture("ext/3amod.bmp",255);
	triangle2=LoadTexture("ext/triangle2.bmp",255);	
	krse=LoadTexture("ext/krse.bmp",255);		

	 amode3=LoadTexture("ext/amode3.bmp",255);
	madne=LoadTexture("ext/madne.bmp",255);
	sour=LoadTexture("ext/sour.bmp",255);
	ground=LoadTexture("ext/ground2.bmp",255);
	window3=LoadTexture("ext/window3.bmp",255);
	ground2=LoadTexture("ext/earth.bmp",255);
	saria=LoadTexture("ext/saria.bmp",255);
	anas=LoadTexture("ext/anas.bmp",255);
	slsle=LoadTexture("ext/slsle.bmp",255);
	school=LoadTexture("ext/school.bmp",255);
	build1=LoadTexture("ext/build1.bmp",255);
	build2=LoadTexture("ext/build2.bmp",255);

	shbak=LoadTexture("ext/shbak.bmp",255);
	he=LoadTexture("ext/he.bmp",255);
	dome=LoadTexture("ext/dome.bmp",255);
	jdar=LoadTexture("ext/jdar.bmp",255);
	carpet=LoadTexture("ext/carpets1.bmp",255);
	stairs=LoadTexture("ext/stairs.bmp",255);
	window=LoadTexture("ext/Window.bmp",220);
	block=LoadTexture("ext/Block.bmp",255);
	doorBuild=LoadTexture("ext/doodBuild.bmp",255);
	bird=LoadTexture("bird.bmp",255);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);




		skyBox = LoadTexture("ext/skybox_test.bmp", 255);
		// skybox
	SKYFRONT = LoadTexture("p_T/front.bmp", 255);
	SKYBACK = LoadTexture("p_T/back.bmp", 255);
	SKYLEFT = LoadTexture("p_T/left.bmp", 255);
	SKYRIGHT = LoadTexture("p_T/right.bmp", 255);
	SKYUP = LoadTexture("p_T/up.bmp", 255);
	SKYDOWN = LoadTexture("ext/earth.bmp", 255);

	glEnable(GL_TEXTURE_2D);

	MyCamera = Camera();
	MyCamera.Position.x = 0;
	MyCamera.Position.z=-6;
	MyCamera.Position.y=2;
	MyCamera.RotateY(180);

	FREE_CAM = Camera();
	FREE_CAM.Position.x = 0;
	FREE_CAM.Position.z=-6;
	FREE_CAM.Position.y=2;
	FREE_CAM.RotateY(180);
	keys['T']=1;

 
	return TRUE;										// Initialization Went OK
}




////////////////////////////////////////////////////////////////////////////////


float prex=0,prey=0;
////////////////////////////////////////////////////////////////////////////////
bool flag=0;
	  int x=8;	

	  int i1,i2,i3,i4,i5;


	  	void drawtrees(){

	sub_build::DrawAnotherWall(-2,-1,-5,20,1,0,slsle);
  sub_build::DrawAnotherWall(-2,-1,6,20,1,0,slsle);
  sub_build::DrawAnotherWall(-2,-1,6,0,1,11,slsle);
  sub_build::DrawAnotherWall(18,-1,6,0,1,11,slsle);

  for(int i=0;i<3;i++){
  for(int i=0;i<7;i++){
  glPushMatrix();
  glRotated(-90,1,0,0);
  tree[i]->Draw();
  glPopMatrix();
  }
  glTranslated(0,0,1.6);

  }

  for(int i=0;i<2;i++){ 
  for(int i=0;i<7;i++){
  glPushMatrix();
  glRotated(-90,1,0,0);
  tree1[i]->Draw();
  glPopMatrix();
  }
  glTranslated(-2
    ,0,0);
  }
  
}



int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	person->pos.y=	MyCamera.Position.y-2;
	person->scale=1.0/2.0;
	/*************************/


	  if(flag)	  MyCamera.Render() , CAM::Enable(keys,isfps,MyCamera,person,rx,w,w,cnt,flag,a,r,b,door2,door);
	  else 	  FREE_CAM.Render() , CAM::Key(keys,0.3,x,FREE_CAM,r,b,door,a,door2,flag);
	  exten::stair(person,MyCamera,isfps);
	  
	  CAM::TurnLight(keys,MyCamera,cnt);
	
	 exten::Draw_Skybox(0, 0, 0, 100, 100, 100,SKYFRONT,SKYBACK,SKYRIGHT,SKYLEFT,SKYUP,SKYDOWN);
	 CAM::DrawGround();	
	 exten::bird0(i1,bird);
	 exten::bird1(i2,bird);
	 exten::bird2(i3,bird);
	 exten::bird3(i4,bird);
	 exten::bird4(i5,bird);

	 
	Main_build::drawAlkable(0,0,-20,roof,window,door,r,door2,a,triangle,triangle2,carpet,room,madne,amode3,amode,stairs);
	sub_build::drawSchool(35,0,-10,school,sour,window,door,block,krse);
	sub_build::drawSour(0,0,0,sour,ground2,roof,ground);
	Main_build::draw_Kobet_AN(5,6,7,jdar,carpet,he,dome,krse,1.1,-35);
	sub_build::drawHouse(-40,0,37,build1,window3,doorBuild);
	sub_build::drawHouse(-25,0,37,build1,window3,doorBuild);
	sub_build::drawArchDoor(-5.5,3,0,saria);
	sub_build::drawAmara(10,0,-10,anas);
	premitives::draw12(-5,5,20,5,3,0.2,saria,he,saria);
	glPushMatrix();
	glTranslated(-25,1,-24);
	glScaled(1,1,1);
	drawtrees();
	glTranslated(25,-1,24);

	glPopMatrix();



	return ++cnt,TRUE;
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


		  case WM_MOUSEMOVE:
        // Handle mouse movement
         xPos = GET_X_LPARAM(lParam);
         yPos = GET_Y_LPARAM(lParam);
		 
    //    std::cout << "Mouse Position: (" << xPos << ", " << yPos << ")" << std::endl;
        break;
    
		
    case WM_MOUSEWHEEL:
        // Handle mouse scroll
         scrollDelta = GET_WHEEL_DELTA_WPARAM(wParam);
       // std::cout << "Scroll Delta: " << scrollDelta << std::endl;
        break;
    

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

int main()
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





