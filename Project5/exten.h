#include "Point.h"




#pragma once
class exten
{
public:

	
static void drawRectangle(Point center, double side1, double side2, char ignoredDimension, int tex) {

	switch (ignoredDimension)
	{
	case 'x':
		glBindTexture(GL_TEXTURE_2D, tex);
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3d(center.x, center.y + (side1 / 2), center.z + (side2 / 2));
		glTexCoord2d(0, 1);
		glVertex3d(center.x, center.y + (side1 / 2), center.z - (side2 / 2));
		glTexCoord2d(0, 0);
		glVertex3d(center.x, center.y - (side1 / 2), center.z - (side2 / 2));
		glTexCoord2d(1, 0);
		glVertex3d(center.x, center.y - (side1 / 2), center.z + (side2 / 2));
		glEnd();
		break;
	case 'y':
		glBindTexture(GL_TEXTURE_2D, tex);
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3d(center.x + (side1 / 2), center.y, center.z + (side2 / 2));
		glTexCoord2d(1, 0);
		glVertex3d(center.x + (side1 / 2), center.y, center.z - (side2 / 2));
		glTexCoord2d(0, 0);
		glVertex3d(center.x - (side1 / 2), center.y, center.z - (side2 / 2));
		glTexCoord2d(0, 1);
		glVertex3d(center.x - (side1 / 2), center.y, center.z + (side2 / 2));
		glEnd();
		break;
	case 'z':
		glBindTexture(GL_TEXTURE_2D, tex);
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3d(center.x + (side1 / 2), center.y + (side2 / 2), center.z);
		glTexCoord2d(1, 0);
		glVertex3d(center.x + (side1 / 2), center.y - (side2 / 2), center.z);
		glTexCoord2d(0, 0);
		glVertex3d(center.x - (side1 / 2), center.y - (side2 / 2), center.z);
		glTexCoord2d(0, 1);
		glVertex3d(center.x - (side1 / 2), center.y + (side2 / 2), center.z);
		glEnd();
		break;
	default:
		break;
	}
}
 static void DrawHalfCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture)
{
	glTranslated(Base_center1.x, Base_center1.y, Base_center1.z);
	Base_center1 = Point(0, 0, 0);
	Point Base_center2 = Point(0, 0, height);
	if (texture != -1)
		glColor3f(1, 1, 1);
	float angle = 0, x1 = Base_rad1, y1 = 0, x2 = Base_rad2, y2 = 0;
	for (angle = 0; angle <= 3.14 + 0.05 ; angle += 0.05)
	{
		Point a = Point(x1, y1, Base_center1.z);
		Point b = Point(x2, y2, Base_center2.z);
		x1 = Base_rad1*cos(angle);
		y1 = Base_rad1*sin(angle);
		x2 = Base_rad2*cos(angle);
		y2 = Base_rad2*sin(angle);
		Point c = Point(x2, y2, Base_center2.z);
		Point d = Point(x1, y1, Base_center1.z);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);

		glTexCoord2f(angle / 3.14, a.z / height);
		glVertex3f(a.x, a.y, a.z);

		glTexCoord2f(angle / 3.14, b.z / height);
		glVertex3f(b.x, b.y, b.z);

		glTexCoord2f((angle + 0.1) / 3.14, c.z / height);
		glVertex3f(c.x, c.y, c.z);

		glTexCoord2f((angle + 0.1) / 3.14, d.z / height);
		glVertex3f(d.x, d.y, d.z);

		glEnd();
	}
	glTranslated(-Base_center1.x, -Base_center1.y, -Base_center1.z);

}
  

 static void Draw_Skybox(float x, float y, float z, float width, float height, float length,int SKYFRONT,int SKYBACK,int SKYRIGHT,int SKYLEFT,int SKYUP,int SKYDOWN)
{
	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, SKYFRONT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, SKYBACK);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, SKYLEFT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, SKYUP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, SKYDOWN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glDisable(GL_TEXTURE_2D);
}


 static bool is_safe(Model_3DS *person){
	if(!(person->pos.x<=48 && person->pos.z>=-35 && person->pos.x>=-46 && person->pos.z<=39)){return 0;}
	return 1;
}
 static void stair(Model_3DS *&person,Camera &MyCamera,bool &isfps){
	 if((person->pos.x<=4&&person->pos.x>=2&&person->pos.z<=10&&person->pos.z>=1)){
		  MyCamera.Position.y=2.25-isfps;
		}
	  else if((person->pos.x<=6&&person->pos.x>=4&&person->pos.z<=10&&person->pos.z>=1)){
		  MyCamera.Position.y=2.5-isfps;
		}
	  else if((person->pos.x<=8&&person->pos.x>=6&&person->pos.z<=10&&person->pos.z>=1)){
		  MyCamera.Position.y=2.75-isfps;
		}
	  else if((person->pos.x<=2&&person->pos.x>=-48&&(person->pos.z<=25)&&(person->pos.z>=-15))){
		  MyCamera.Position.y=3-isfps;
		}
	  else  MyCamera.Position.y=2-isfps;
 }

 static void bird0(int & i,int bird){
  i+=1.2;
  glPushMatrix();
  glRotatef(i,0,1,0);
  glBindTexture(GL_TEXTURE_2D,bird);
  glBegin(GL_QUADS);
   glTexCoord2d(1,0);
   glVertex3f(12, 15, 10); 
   glTexCoord2d(1,1);
   glVertex3f(12, 16, 10); 
   glTexCoord2d(0,1);
   glVertex3f(12,16 ,14); 
   glTexCoord2d(0,0);
   glVertex3f(12, 15, 14); 
   glEnd();
  glPopMatrix();
}
static void bird1(int &j,int bird){
  j+=1;
  glPushMatrix();
  glRotatef(j,0,1,0);
  glBindTexture(GL_TEXTURE_2D,bird);
    glBegin(GL_QUADS);
   glTexCoord2d(1,0);
   glVertex3f(9, 12, 10); 
   glTexCoord2d(1,1);
   glVertex3f(9, 13, 10); 
   glTexCoord2d(0,1);
   glVertex3f(9,13 ,14); 
   glTexCoord2d(0,0);
   glVertex3f(9, 12, 14); 
   glEnd();
  glPopMatrix();
}
static void bird2(int &s,int bird){
  s+=1.5;
  glPushMatrix();
  glRotatef(s,0,1,0);
  glBindTexture(GL_TEXTURE_2D,bird);
   glBegin(GL_QUADS);
   glTexCoord2d(1,0);
   glVertex3f(10, 15, 14); 
   glTexCoord2d(1,1);
   glVertex3f(10, 16, 14); 
   glTexCoord2d(0,1);
   glVertex3f(10,16 ,18); 
   glTexCoord2d(0,0);
   glVertex3f(10, 15, 18); 
   glEnd();
  glPopMatrix();
}
static void bird3(int &d,int bird){
  d+=2;
  glPushMatrix();
  glRotatef(d,0,1,0);
  glBindTexture(GL_TEXTURE_2D,bird);
   glBegin(GL_QUADS);
   glTexCoord2d(1,0);
   glVertex3f(10, 12, 10); 
   glTexCoord2d(1,1);
   glVertex3f(10, 13, 10); 
   glTexCoord2d(0,1);
   glVertex3f(10,13 ,14); 
   glTexCoord2d(0,0);
   glVertex3f(10, 12, 14); 
   glEnd();
  glPopMatrix();
}
static void bird4(int &f, int bird){
  f+=2.6;
  glPushMatrix();
  glRotatef(f,0,1,0);
  glBindTexture(GL_TEXTURE_2D,bird);
  glBegin(GL_QUADS);
   glTexCoord2d(1,0);
   glVertex3f(12, 15, 15); 
   glTexCoord2d(1,1);
   glVertex3f(12, 16, 15); 
   glTexCoord2d(0,1);
   glVertex3f(12,16 ,19); 
   glTexCoord2d(0,0);
   glVertex3f(12, 15, 19); 
   glEnd();
  glPopMatrix();
}

};

