#pragma once
class sub_build
{
public:
	static void DrawAnotherWall(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth, GLuint texture,int rat=1)
{
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1*rat, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1*rat, 1*rat); glVertex3f(x + width, y + height, z);
    glTexCoord2d(0, 1*rat); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1*rat, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1*rat, 1*rat); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1*rat); glVertex3f(x, y + height, z - depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1*rat, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1*rat, 1*rat); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(0, 1*rat); glVertex3f(x + width, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x, y, z);
    glTexCoord2d(1*rat, 0); glVertex3f(x, y, z - depth);
    glTexCoord2d(1*rat, 1*rat); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1*rat); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y + height, z);
    glTexCoord2d(1*rat, 0); glVertex3f(x + width, y + height, z - depth);
    glTexCoord2d(1*rat, 1*rat); glVertex3f(x, y + height, z - depth);
    glTexCoord2d(0, 1*rat); glVertex3f(x, y + height, z);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(x + width, y, z);
    glTexCoord2d(1*rat, 0); glVertex3f(x + width, y, z - depth);
    glTexCoord2d(1*rat, 1*rat); glVertex3f(x, y, z - depth);
    glTexCoord2d(0, 1*rat); glVertex3f(x, y, z);
    glEnd();
}





static void DrawAnotherDoor(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth, GLuint texture,GLfloat r,int b)
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
  
}


static void DrawCarpet(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth, GLuint texture)
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

static void drawArchDoor(float x, float y, float z,int a) {
	glPushMatrix();
	glRotatef(90,0,1,0);
  glColor3f(1, 1, 1); // Clear all color so it does not affect the texture
  premitives *pre;
  Point point = Point(x , y , z); // Use the provided x, y, z parameters
  Point r=Point(5,2,-30);
  glEnable(GL_TEXTURE_2D);
  
  // The arch
  // pre = new premitives();
 // pre->DrawHalfCylinderBody(r/*center*/, 4 /*radius front*/, 4 /*radius back*/, 2/*thickness of arch*/, a/*Texture*/);
 
  // Inner left rectangle
  pre = new premitives();
  point = Point(x - 4, y - 5, z + 1); // Adjust coordinates based on parameters
  pre->drawRectangle(point, 10, 2, 'x', a);

  // Inner right rectangle
  pre = new premitives();
  point = Point(x + 4, y - 5, z + 1);
  pre->drawRectangle(point, 10, 2, 'x', a);

  // Outer left rectangle
  pre = new premitives();
  point = Point(x - 5, y - 2.5, z + 1);
  pre->drawRectangle(point, 15, 2, 'x', a);

  // Outer right rectangle
  pre = new premitives();
  point = Point(x + 5, y - 2.5, z + 1);
  pre->drawRectangle(point, 15, 2, 'x', a);

  // Top rectangle
  pre = new premitives();
  point = Point(x, y + 5, z + 1);
  pre->drawRectangle(point, 10, 2, 'y', a);

  // Fill left front
  pre = new premitives();
  point = Point(x - 4.5, y - 2.5, z + 2);
  pre->drawRectangle(point, 1, 15, 'z', a);

  // Fill right front
  pre = new premitives();
  point = Point(x + 4.5, y - 2.5, z + 2);
  pre->drawRectangle(point, 1, 15, 'z', a);

  // Fill top front
  pre = new premitives();
  point = Point(x, y + 4.5, z + 2);
  pre->drawRectangle(point, 8, 1, 'z', a);

  // Fill left back
  pre = new premitives();
  point = Point(x - 4.5, y - 2.5, z);
  pre->drawRectangle(point, 1, 15, 'z', a);

  // Fill right back
  pre = new premitives();
  point = Point(x + 4.5, y - 2.5, z);
  pre->drawRectangle(point, 1, 15, 'z', a);

  // Fill top back
  pre = new premitives();
  point = Point(x, y + 4.5, z);
  pre->drawRectangle(point, 8, 1, 'z', a);

  // Fill left corner front
  glPushMatrix();
  glTranslated(x - 4, y + 4, z + 2);
  glBindTexture(GL_TEXTURE_2D, a);
  glBegin(GL_TRIANGLES);
  glTexCoord2f(0, 0);
  glVertex3d(0, 0, 0);
  glTexCoord2f(0, 1);
  glVertex3d(2.5, 0, 0);
  glTexCoord2f(1, 1);
  glVertex3d(0, -2.5, 0);
  glEnd();
  glPopMatrix();

  // Fill right corner front
  glPushMatrix();
  glTranslated(x + 4, y + 4, z + 2);
  glBindTexture(GL_TEXTURE_2D, a);
  glBegin(GL_TRIANGLES);
  glTexCoord2f(0, 0);
  glVertex3d(0, 0, 0);
  glTexCoord2f(0, 1);
  glVertex3d(-2.5, 0, 0);
  glTexCoord2f(1, 1);
  glVertex3d(0, -2.5, 0);
  glEnd();
  glPopMatrix();

  // Fill left corner back
  glPushMatrix();
  glTranslated(x - 4, y + 4, z);
  glBindTexture(GL_TEXTURE_2D, a);
  glBegin(GL_TRIANGLES);
  glTexCoord2f(0, 0);
  glVertex3d(0, 0, 0);
  glTexCoord2f(0, 1);
  glVertex3d(2.5, 0, 0);
  glTexCoord2f(1, 1);
  glVertex3d(0, -2.5, 0);
  glEnd();
  glPopMatrix();

  // Fill right corner back
  glPushMatrix();
  glTranslated(x + 4, y + 4, z);
  glBindTexture(GL_TEXTURE_2D, a);
  glBegin(GL_TRIANGLES);
  glTexCoord2f(0, 0);
  glVertex3d(0, 0, 0);
  glTexCoord2f(0, 1);
  glVertex3d(-2.5, 0, 0);
  glTexCoord2f(1, 1);
  glVertex3d(0, -2.5, 0);
  glEnd();
  glPopMatrix();
  glPopMatrix();
}



static void drawAmara(float x, float y, float z,int a){
	glPushMatrix();
	glRotatef(45,0,1,0);
DrawAnotherWall( x-10 , y+1 , z-5 , 1 , 6 , 1,a);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-10 , y+7 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-10 ,y+ 6 , z-5);
	glTexCoord3d(0,1,0);
	glVertex3f(x-11.5 ,y+ 7 ,z -5);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-15 ,y + 7 ,z -5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-15 ,y + 5 , z-5);
	glTexCoord3d(0,1,0);
	glVertex3f(x-12.5 , y+7 , z-5);
	glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord3d(0,0,0);
	glVertex3f(x-10 , y+7 , z-6);
	glTexCoord3d(1,0,0);
	glVertex3f(x-10 , y+6 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-11.5 , y+7 ,z -6);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-15 , y+7 , z-6);
	glTexCoord3d(1,0,0);
	glVertex3f(x-15 ,y+ 5 ,z -6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-12.5 ,y+ 7 ,z -6);
	glEnd();

	DrawAnotherWall(x -15 , y+1 , z-5 , 1 , 6 , 1,a);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-15 , y+7 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-15 , y+5.8 , z-5);
	glTexCoord3d(0,1,0);
	glVertex3f(x-16.5 ,y+ 7 ,z -5);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-20 ,y+ 7 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-20 ,y+ 5 ,z -5);
	glTexCoord3d(0,1,0);
	glVertex3f(x-17.5 ,y+ 7 , z-5);
	glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord3d(0,0,0);
	glVertex3f(x-15 , y+7 , z-6);
	glTexCoord3d(1,0,0);
	glVertex3f(x-15 , y+5.8 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-16.5 , y+7 , z-6);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-20 ,y+ 7 ,z -6);
	glTexCoord3d(1,0,0);
	glVertex3f(x-20 ,y+ 5 ,z -6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-17.5 ,y+ 7 , z-6);
	glEnd();

	DrawAnotherWall(x -20 ,y+ 1 , z-5 , 1 , 6 , 1,a);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-20 , y+7 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-20 , y+5.8 , z-5);
	glTexCoord3d(0,1,0);
	glVertex3f(x-21.5 ,y+ 7 , z-5);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-25 ,y+ 7 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-25, y+5 , z-5);
	glTexCoord3d(0,1,0);
	glVertex3f(x-22.5 ,y+ 7 ,z -5);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-20 , y+7 ,z -6);
	glTexCoord3d(1,0,0);
	glVertex3f(x-20 ,y+ 5.8 ,z -6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-21.5 ,y+ 7 ,z -6);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord3d(0,0,0);
	glVertex3f(x-25 , y+7 , z-6);
	glTexCoord3d(1,0,0);
	glVertex3f(x-25, y+5 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-22.5 , y+7 ,z -6);
	glEnd();
	DrawAnotherWall( x-25 , y+1 , z-5 , 1 , 6 , 1,a);
	DrawAnotherWall( x-9 , y+7 , z-5 , -16 , 1 , 1,a);
			glBegin(GL_QUADS);
			glTexCoord3d(0,0,0);
	glVertex3f(x-10 , y+6 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-10 ,y+ 6 , z-6);
	glTexCoord3d(1,1,0);
	glVertex3f(x-11.5 , y+7 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-11.5 , y+7 , z-5);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord3d(0,0,0);
	glVertex3f(x-15 , y+5 ,z -5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-15 ,y+ 5 , z-6);
	glTexCoord3d(1,1,0);
	glVertex3f(x-12.5 ,y+ 7 ,z -6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-12.5 , y+7 ,z -5);
	glEnd();
		glBegin(GL_QUADS);
		glTexCoord3d(0,0,0);
	glVertex3f(x-15 , y+5.8 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-15 , y+5.8 , z-6);
	glTexCoord3d(1,1,0);
	glVertex3f(x-16.5 ,y+ 7 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-16.5 , y+7 , z-5);
	glEnd();
		glBegin(GL_QUADS);
		glTexCoord3d(0,0,0);
	glVertex3f(x-20 ,y+ 5 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-20 ,y+ 5 ,z -6);
	glTexCoord3d(1,1,0);
	glVertex3f(x-17.5 , y+7 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-17.5 , y+7 , z		-5);
	glEnd();
		glBegin(GL_QUADS);
		glTexCoord3d(0,0,0);
	glVertex3f(x-20 , y+5.8 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-20 , y+5.8 ,z -6);
	glTexCoord3d(1,1,0);
	glVertex3f(x-21.5 , y+7 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-21.5 , y+7 , z-5);
	glEnd();
			glBegin(GL_QUADS);
			glTexCoord3d(0,0,0);
	glVertex3f(x-25, y+5 , z-5);
	glTexCoord3d(1,0,0);
	glVertex3f(x-25, y+5 , z-6);
	glTexCoord3d(1,1,0);
	glVertex3f(x-22.5 , y+7 , z-6);
	glTexCoord3d(0,1,0);
	glVertex3f(x-22.5 , y+7 , z-5);
	glEnd();
	glPopMatrix();
}

static void drawSchool(float x, float y, float z,int school,int sour,int window,int door,int block,int krse){

	DrawAnotherWall( x , y , z , 1, 3, 0.5,school);

	DrawAnotherWall( x+1 , y , z , 1, 0.5, 0.5,school);
	DrawAnotherWall( x+1 , y+0.5 , z , 1, 2, 0.3,window);
	DrawAnotherWall( x+1 , y+2.5 , z , 1, 0.5, 0.5,school);


	DrawAnotherWall( x+2 , y , z , 3.5, 3, 0.5,school);

	DrawAnotherWall(x+ 5.5 , y , z , 1, 0.5, 0.5,school);
	DrawAnotherWall(x+ 5.5 , y+0.5 , z , 1, 2, 0.3,window);
	DrawAnotherWall( x+5.5 , y+2.5 , z , 1, 0.5, 0.5,school);

	DrawAnotherWall( x+6.5 , y , z , 1, 3, 0.5,school);


	DrawAnotherWall(x+ 0.5 , y , z-7 , 1, 3, 0.5,school);
	DrawAnotherWall( x+1 , y , z-7, 1, 0.5, 0.5,school);
	DrawAnotherWall( x+1 , y+0.5 , z-7.2 , 1, 2, 0.3,window);
	DrawAnotherWall( x+1 , y+2.5 , z-7 , 1, 0.5, 0.5,school);


	DrawAnotherWall(x+ 2 , y , z-7 , 3.5, 3, 0.5,school);

	DrawAnotherWall(x+ 5.5 , y , z-7 , 1, 0.5, 0.5,school);
	DrawAnotherWall(x+ 5.5 , y+0.5 , z-7.2 , 1, 2, 0.3,window);
	DrawAnotherWall(x+ 5.5 , y+2.5 ,z -7 , 1, 0.5, 0.5,school);

	DrawAnotherWall( x+6.5 , y ,z -7 , 1, 3, 0.5,school);

	DrawAnotherWall( x , y , z , 0.5, 3, 3,school);
	DrawAnotherWall( x , y+2 , z-3 , 0.5, 1, 1,school);
	DrawAnotherWall( x , y , z-3 , 0.5, 2, 1,door);
	DrawAnotherWall( x , y , z-4 , 0.5, 3, 3.5,school);

	DrawAnotherWall( x+7 , y , z-0.5 , 0.5, 3, 7,school);

	Point b=Point(x+4,y+2.7,z-3.8);
	premitives::DrawDome(4,block,b);

	 
	DrawAnotherWall( x+2.25, y+0.5 , z+1 , 3 , 0.2 , 1,krse);
	DrawAnotherWall( x+2.5, y , z+1, 0.1 , 0.5 , 0.1,krse);
	DrawAnotherWall( x+2.5, y , z+0.2 , 0.1 , 0.5 , 0.1,krse);
	DrawAnotherWall( x+5, y , z+0.2 , 0.1 , 0.5 , 0.1,krse);
	DrawAnotherWall( x+5, y , z+1 , 0.1 , 0.5 , 0.1,krse);
	DrawAnotherWall( x+2.25, y+0.5 , z+0.2 , 3 , 0.8 , 0.2,krse);



	DrawAnotherWall( x+2.25, y+0.7 ,z +1 , 0.1 , 0.1 , 0.1,krse);
	DrawAnotherWall( x+2.25, y+0.8 , z+1 , 0.1 , 0.1 , 0.8,krse);
	DrawAnotherWall( x+5.15, y+0.7 , z+1 , 0.1 , 0.1 , 0.1,krse);
	DrawAnotherWall( x+5.15, y+0.8 , z+1 , 0.1 , 0.1 , 0.8,krse);

}

static void drawHouse(float x, float y, float z, int a,int window3,int doorBuild){
	glPushMatrix();
	glTranslated(x+7.5,y,z); 
	glRotatef(-90,0,1,0);
	glTranslatef(-x-7.5,-y,-z);
	DrawAnotherWall( x , y , z , 1, 3, 0.5,a);

	DrawAnotherWall( x+1 , y , z , 1, 0.5, 0.5,a);
	DrawAnotherWall( x+1 , y+0.5 , z , 1, 2, 0.3,window3);
	DrawAnotherWall( x+1 , y+2.5 , z , 1, 0.5, 0.5,a);


	DrawAnotherWall( x+2 , y , z , 3.5, 3, 0.5,a);

	DrawAnotherWall(x+ 5.5 , y , z , 1, 0.5, 0.5,a);
	DrawAnotherWall(x+ 5.5 , y+0.5 , z , 1, 2, 0.3,window3);
	DrawAnotherWall( x+5.5 , y+2.5 , z , 1, 0.5, 0.5,a);

	DrawAnotherWall( x+6.5 , y , z , 1, 3, 0.5,a);


	DrawAnotherWall(x+ 0.5 , y , z-7 , 1, 3, 0.5,a);
	DrawAnotherWall( x+1 , y , z-7, 1, 0.5, 0.5,a);
	DrawAnotherWall( x+1 , y+0.5 , z-7.2 , 1, 2, 0.3,window3);
	DrawAnotherWall( x+1 , y+2.5 , z-7 , 1, 0.5, 0.5,a);


	DrawAnotherWall(x+ 2 , y , z-7 , 3.5, 3, 0.5,a);

	DrawAnotherWall(x+ 5.5 , y , z-7 , 1, 0.5, 0.5,a);
	DrawAnotherWall(x+ 5.5 , y+0.5 , z-7.2 , 1, 2, 0.3,window3);
	DrawAnotherWall(x+ 5.5 , y+2.5 ,z -7 , 1, 0.5, 0.5,a);

	DrawAnotherWall( x+6.5 , y ,z -7 , 1, 3, 0.5,a);

	DrawAnotherWall( x , y , z , 0.5, 3, 3,a);
	DrawAnotherWall( x , y+2 , z-3 , 0.5, 1, 1,a);
	DrawAnotherWall( x , y , z-3 , 0.5, 2, 1,doorBuild);
	DrawAnotherWall( x , y , z-4 , 0.5, 3, 3.5,a);

	DrawAnotherWall( x+7 , y , z-0.5 , 0.5, 3, 7,a);

	DrawAnotherWall( x , y+3 , z , 7.5, 0.2, 7.5,a);
	glPopMatrix();
}



static void drawSour(float x , float y , float z,int sour,int ground2,int roof,int ground){
	DrawAnotherWall(x+ 48 , y , z+40 , 0.5, 10, 7.5,sour);
 DrawAnotherWall( x+48 , y , z+32.5 , 0.5, 12, 5,sour); DrawAnotherWall( x+48 , y , z+27.5 , 0.5, 10, 7.5,sour);
 DrawAnotherWall(x+ 48 , y , z+20 , 0.5, 12, 5,sour); DrawAnotherWall( x+48 , y , z+15 , 0.5, 10, 7.5,sour);
 DrawAnotherWall( x+48 , y , z+7.5 , 0.5, 12, 5,sour); DrawAnotherWall( x+48 , y , z+2.5 , 0.5, 10, 7.5,sour);
 DrawAnotherWall( x+48 , y , z-5 , 0.5 , 12, 5 ,sour); DrawAnotherWall( x+48 , y , z-10 ,0.5 , 10, 7.5,sour);
 DrawAnotherWall( x+48 , y , z-17.5 ,0.5 , 12, 5,sour); DrawAnotherWall( x+48 , y , z-22.5 ,0.5 , 10, 7.5,sour);
 DrawAnotherWall( x+48 , y , z-30 ,0.5 , 12, 5,sour);
 //////////////////////////////////////////
 DrawAnotherWall(x+48 , y, z-35, -5, 12, 0.5,sour);
 DrawAnotherWall(x+43 , y, z-35, -7.5, 10, 0.5,sour); DrawAnotherWall(x+35.5 , y, z-35, -5, 12, 0.5,sour);
 DrawAnotherWall(x+30.5 , y, z-35, -7.5, 10, 0.5,sour); DrawAnotherWall(x+23 , y, z-35, -5, 12, 0.5,sour);
 DrawAnotherWall(x+18 , y, z-35, -7.5, 10, 0.5,sour); DrawAnotherWall(x+11.5 , y, z-35, -5, 12, 0.5,sour);
 DrawAnotherWall(x+6.5 , y, z-35, -7.5, 10, 0.5,sour); DrawAnotherWall(x-1 , y, z-35, -5, 12, 0.5,sour);
 DrawAnotherWall(x-6 , y, z-35, -7.5, 10, 0.5,sour); DrawAnotherWall(x-13.5 , y, z-35, -5, 12, 0.5,sour);
 DrawAnotherWall(x-18.5 , y, z-35, -7.5, 10, 0.5,sour); DrawAnotherWall(x-26 , y, z-35, -5, 12, 0.5,sour);
 DrawAnotherWall(x-31 , y, z-35, -7.5, 10, 0.5,sour); DrawAnotherWall(x-38.5 , y, z-35, -8, 12, 0.5,sour);
 //////////////////////////////////////////
 DrawAnotherWall( x-47 , y , z+40 , 0.5, 10, 7.5,sour); DrawAnotherWall( x-47 , y , z+32.5 , 0.5, 12, 5,sour);
 DrawAnotherWall( x-47 , y , z+27.5 , 0.5, 10, 7.5,sour); DrawAnotherWall( x-47 , y , z+20 , 0.5, 12, 5,sour);
 DrawAnotherWall( x-47 , y , z+15 , 0.5, 10, 7.5,sour); DrawAnotherWall( x-47 , y , z+7.5 , 0.5, 12, 5,sour);
 DrawAnotherWall( x-47 , y , z+2.5 , 0.5, 10, 7.5,sour);
 DrawAnotherWall( x-47 , y , z-5 , 0.5 , 12, 5 ,sour); DrawAnotherWall( x-47 , y , z-10 ,0.5 , 10, 7.5,sour);
 DrawAnotherWall( x-47 , y , z-17.5 ,0.5 , 12, 5,sour); DrawAnotherWall( x-47 , y , z-22.5 ,0.5 , 10, 7.5,sour);
 DrawAnotherWall( x-47 , y , z-30 ,0.5 , 12, 5,sour);
 //////////////////////////////////////// 
 DrawAnotherWall(x+48 , y, z+40, -5, 12, 0.5,sour);
 DrawAnotherWall(x+43 , y, z+40, -7.5, 10, 0.5,sour); DrawAnotherWall(x+35.5 , y, z+40, -5, 12, 0.5,sour);
 DrawAnotherWall(x+30.5 , y, z+40, -7.5, 10, 0.5,sour); DrawAnotherWall(x+23 , y, z+40, -5, 12, 0.5,sour);
 DrawAnotherWall(x+18 , y, z+40, -7.5, 10, 0.5,sour); DrawAnotherWall(x+11.5 , y, z+40, -5, 12, 0.5,sour);
 DrawAnotherWall(x+6.5 , y, z+40, -7.5, 10, 0.5,sour); DrawAnotherWall(x-1 , y, z+40, -5, 12, 0.5,sour);
 DrawAnotherWall(x-6 , y, z+40, -7.5, 10, 0.5,sour); DrawAnotherWall(x-13.5 , y, z+40, -5, 12, 0.5,sour);
 DrawAnotherWall(x-18.5 , y, z+40, -7.5, 10, 0.5,sour); DrawAnotherWall(x-26 , y, z+40, -5, 12, 0.5,sour);
 DrawAnotherWall(x-31 , y, z+40, -7.5, 10, 0.5,sour); DrawAnotherWall(x-38.5 , y, z+40, -8, 12, 0.5,sour); 
  DrawAnotherWall( x-47 , y , z+40 , 95, 0.1, 95,ground);
  DrawAnotherWall( x-48 , y , z+25 , 50, 1 , 40,ground2,23);
 DrawAnotherWall( x+2 , y , z+10 , 2 , 0.25 , 9,roof); DrawAnotherWall( x+2 , y+0.25 , z+10 , 1.5 , 0.25 , 9,roof);
 DrawAnotherWall( x+2 , y+0.5 , z+10 , 1 , 0.25 , 9,roof); DrawAnotherWall( x+2 , y+0.75 , z+10 , 0.5 , 0.25 , 9,roof);
}


};

