
#pragma once
#include "Point.h"
class premitives
{
public:

	
static void DrawDome( float rad, int texture=-1, Point center=Point(0,0,0))
{
 glTranslated(center.x,center.y,center.z); 
 float lastcenter=rad*sin(3.14/2);
 float lastr=rad*cos(3.14/2);
 for (float vertical=3.14/2.0; vertical>=-0.1; vertical-=0.1)
 {
  float centeri=rad*sin(vertical);
  float ri=rad*cos(vertical);
  int col = 0;  
  for (float horizin=-0.2; horizin<=2*3.14+0.1; horizin+=0.1)
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


 
 static void DrawBall( float rad, int texture=-1, Point center=Point(0,0,0))
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
			{

				glBindTexture(GL_TEXTURE_2D, texture);
				glBegin(GL_QUADS);
				glTexCoord2d(1-(horizin)/(2*3.14), 0.5+sin(vertical-0.1)/2.0);
				glVertex3f(a.x,a.y,a.z);
				glTexCoord2d(1-(horizin+0.1)/(2*3.14), 0.5+sin(vertical-0.1)/2.0);
				glVertex3f(b.x,b.y,b.z);
				glTexCoord2d(1-(horizin+0.1)/(2*3.14), 0.5+sin(vertical)/2.0);
				glVertex3f(d.x,d.y,d.z);
				glTexCoord2d(1-(horizin)/(2*3.14), 0.5+sin(vertical)/2.0);
				glVertex3f(c.x,c.y,c.z);
				glEnd();
			}
			else
			{
				glBegin(GL_QUADS);
				glVertex3f(a.x,a.y,a.z);
				glVertex3f(b.x,b.y,b.z);
				glVertex3f(d.x,d.y,d.z);
				glVertex3f(c.x,c.y,c.z);
				glEnd();
			}
		}
		lastr=ri;
		lastcenter=centeri;
	}
	glTranslated(-center.x,-center.y,-center.z);

};


static  void DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture){
  glTranslated(Base_center1.x,Base_center1.y, Base_center1.z); // glRotated(90,0,0,1);
  Base_center1=Point(0,0,0);  Point Base_center2=Point (0,height,0);
  if (texture!=-1)    glColor3f(1,1,1);
  float angle=0, x1=Base_rad1, z1=0, x2=Base_rad2, z2=0;  for (angle=0; angle <=2*3.14+0.1; angle+=0.1)
  {   Point a= Point (x1,Base_center1.y,z1);
   Point b= Point (x2,Base_center2.y,z2);   x1=Base_rad1*cos(angle);
   z1=Base_rad1*sin(angle);   x2=Base_rad2*cos(angle);
   z2=Base_rad2*sin(angle);   Point c= Point (x2,Base_center2.y,z2);
   Point d= Point (x1,Base_center1.y,z1);   glBindTexture(GL_TEXTURE_2D,texture);
   glBegin(GL_QUADS);
    glTexCoord2f(angle/(2*3.14),a.z/height);    glVertex3f(a.x,a.y,a.z);
       glTexCoord2f(angle/(2*3.14),b.z/height);
    glVertex3f(b.x,b.y,b.z);   
    glTexCoord2f((angle+0.1)/(2*3.14),c.z/height);    glVertex3f(c.x,c.y,c.z);
       glTexCoord2f((angle+0.1)/(2*3.14),d.z/height);
    glVertex3f(d.x,d.y,d.z);
   glEnd(); }
 glTranslated(-Base_center1.x,-Base_center1.y, -Base_center1.z);
};

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
  



static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture)
{
	glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D,texture);

		//back
		glBegin(GL_QUADS);
		glTexCoord2d(0.25, 0.33);
		glVertex3d(0, 0, 0);
		glTexCoord2d(0.5, 0.33);
		glVertex3d(length, 0, 0);
		glTexCoord2d(0.5, 0.67);
		glVertex3d(length, hight, 0);
		glTexCoord2d(0.25, 0.67);
		glVertex3d(0, hight, 0);
		glEnd();


		//front
		glBegin(GL_QUADS);
		glTexCoord2d(1, 0.33);
		glVertex3d(0, 0, depth);
		glTexCoord2d(0.75, 0.33);
		glVertex3d(length, 0, depth);
		glTexCoord2d(0.75, 0.67);
		glVertex3d(length, hight, depth);
		glTexCoord2d(1, 0.67);
		glVertex3d(0, hight, depth);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0.33);
		glVertex3d(0, 0, depth);
		glTexCoord2d(0.25, 0.33);
		glVertex3d(0, 0, 0);
		glTexCoord2d(0.25, 0.67);
		glVertex3d(0, hight, 0);
		glTexCoord2d(0, 0.67);
		glVertex3d(0, hight, depth);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glTexCoord2d(0.75, 0.33);
		glVertex3d(length, 0, depth);
		glTexCoord2d(0.5, 0.33);
		glVertex3d(length, 0, 0);
		glTexCoord2d(0.5, 0.67);
		glVertex3d(length, hight, 0);
		glTexCoord2d(0.75, 0.67);
		glVertex3d(length, hight, depth);
		glEnd();



		//top
		glBegin(GL_QUADS);
		glTexCoord2d(0.25 , 0.67);
		glVertex3d(0, hight, 0);
		glTexCoord2d(0.5, 0.67);
		glVertex3d(length, hight, 0);
		glTexCoord2d(0.5, 1);
		glVertex3d(length, hight, depth);
		glTexCoord2d(0.25, 1);
		glVertex3d(0, hight, depth);
		glEnd();


		//bottom
		glBegin(GL_QUADS);
		glTexCoord2d(0.25, 0.33);
		glVertex3d(0, 0, 0);
		glTexCoord2d(0.5, 0.33);
		glVertex3d(length, 0, 0);
		glTexCoord2d(0.5,0);
		glVertex3d(length, 0, depth);
		glTexCoord2d(0.25, 0);
		glVertex3d(0, 0, depth);
		glEnd();
		
	glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);
};

static void eighth_AN(float x, float z,float t,int car=-1 ,int X=0){ if(car==-1){
	  
   
  glPolygonMode(GL_FRONT,GL_LINES);  glBegin(GL_POLYGON);
  glVertex3f(t*x+X, z,0); glVertex3f(2*x*t+X, z,t*x);
 glVertex3f(2*x*t+X, z,x*3*t); glVertex3f(x*t+X, z,x*4*t);
 glVertex3f(-x*t+X, z,x*4*t); glVertex3f(-2*x*t+X, z,x*3*t);
 glVertex3f(-2*x*t+X, z,x*t); glVertex3f(-x*t+X, z,0);
 glEnd(); return;
 }  glBindTexture(GL_TEXTURE_2D, car);
  glPolygonMode(GL_FRONT,GL_LINES);  glBegin(GL_POLYGON);
  float r=5;    glTexCoord2f(0.75*r, 0);
 glVertex3f(t*x+X, z,0);    glTexCoord2f(1*r, 0.25*r);
 glVertex3f(2*x*t+X, z,t*x);
    glTexCoord2f(1*r, 0.75*r);
 glVertex3f(2*x*t+X, z,x*3*t);    glTexCoord2f(0.75*r, r*1);
 glVertex3f(x*t+X, z,x*4*t);
    glTexCoord2f(0.25*r, 1*r);
 glVertex3f(-x*t+X, z,x*4*t);    glTexCoord2f(0, 0.75*r);
 glVertex3f(-2*x*t+X, z,x*3*t);
    glTexCoord2f(0, 0.25*r);
 glVertex3f(-2*x*t+X, z,x*t);    glTexCoord2f(0.25*r,0);
 glVertex3f(-x*t+X, z,0);
 glEnd(); 
}


static void drawQuarterCircle(float cx, float cy, float r, float startAngle, float endAngle, int numSegments) { 
  glBegin(GL_POLYGON);
  glVertex3f(-r,r,0);
  glVertex3f(0,r,0);
    for (int i = 0; i <= numSegments; ++i) {
      float theta = startAngle + (endAngle - startAngle) * static_cast<float>(i) / numSegments;
        float x = r * cos(theta) + cx;
        float y = r * sin(theta) + cy;
     
 glVertex3f(x, y,0);
  //glVertex3f(-2*r,-30,0);
  };
   glEnd();
}



static void draw12(float x,float y, float z,float rat,float h,float rad,int ro,int he,int saria){ 
	float r=rat/12.0;
 glBegin(GL_POLYGON); 
 for(int i=0;i<12;i++){  
float nx=rat*cos(i*PI/6),ny=rat*sin(i*PI/6);
  float ang=i*PI/6; 
  glVertex3f(x+nx,y+0,z+ny);
 } glEnd();
  for(int i=0;i<12;i++){
  float nx=(rat-r)*cos(i*PI/6),ny=(rat-r)*sin(i*PI/6);  
  glBegin(GL_QUADS);
   
  glVertex3f(x+nx,y+0,z+ny);
   glVertex3f(x+nx,y-(3*r),z+ny);  
   glVertex3f(x+(rat-r)*cos((i+1)*PI/6),y-(3*r),z+(rat-r)*sin((i+1)*PI/6));
   glVertex3f(x+(rat-r)*cos((i+1)*PI/6),y+0,z+(rat-r)*sin((i+1)*PI/6));
   glEnd();
///  return;
  ///////////
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, he);    
 glBegin(GL_QUADS);
 {
  glTexCoord2f(0, 0); 
  glVertex3f(x+nx,y+0,z+ny);
  glTexCoord2f(1, 0);       
  glVertex3f(x+nx,y-(3*r),z+ny);
  glTexCoord2f(1, 1);       
  glVertex3f(x+(rat-r)*cos((i+1)*PI/6),y-(3*r),z+(rat-r)*sin((i+1)*PI/6));
  glTexCoord2f(0, 1);
   glVertex3f(x+(rat-r)*cos((i+1)*PI/6),y+0,z+(rat-r)*sin((i+1)*PI/6)); 
 }
 glEnd();
  ////////////
  nx=(rat-r-r)*cos(i*PI/6),ny=(rat-r-r)*sin(i*PI/6);
  glBegin(GL_QUADS);  
   glVertex3f(x+nx,y+0,z+ny);  
   glVertex3f(x+nx,y-(3*r),z+ny);
   glVertex3f(x+(rat-r-r)*cos((i+1)*PI/6),y-(3*r),z+(rat-r-r)*sin((i+1)*PI/6));
   glVertex3f(x+(rat-r-r)*cos((i+1)*PI/6),y+0,z+(rat-r-r)*sin((i+1)*PI/6));
  glEnd();  
   glBegin(GL_QUADS);  
   glVertex3f(x+(rat-r)*cos(i*PI/6),y-(3*r),z+(rat-r)*sin(i*PI/6));
    glVertex3f(x+(rat-r)*cos((i+1)*PI/6),y-(r*3),z+(rat-r)*sin((i+1)*PI/6)); 
	glVertex3f(x+(rat-r-r)*cos((i+1)*PI/6),y-(r*3),z+(rat-r-r)*sin((i+1)*PI/6));
    glVertex3f(x+nx,y-(3*r),z+ny);
   glEnd();
  
 } 
   glBegin(GL_LINE_LOOP);
   for(int i=0;i<12;i++){
  float nx=rat*cos(i*PI/6),ny=rat*sin(i*PI/6); 
  float ang=i*PI/6;
  glVertex3f(x+nx,y-(3*r),z+ny);
}
 glEnd();
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<12;i++){
  float nx=(rat-r-r)*cos(i*PI/6),ny=(rat-r-r)*sin(i*PI/6);  float ang=i*PI/6;
  glVertex3f(x+nx,y-(r*3),z+ny); }
 glEnd(); 
 for(int i=0;i<12;i++)
 {  float nx=rat*cos(i*PI/6),ny=rat*sin(i*PI/6);
    glBegin(GL_QUADS);
	glVertex3f(x+nx,y-(3*r),z+ny);
   glVertex3f(x+(rat-r-r)*cos((i)*PI/6),y-(3*r),z+(rat-r-r)*sin((i)*PI/6));
   glVertex3f(x+(rat-r-r)*cos((i+1)*PI/6),y-(3*r),z+(rat-r-r)*sin((i+1)*PI/6));
   glVertex3f(x+rat*cos((i+1)*PI/6),y-(3*r),z+rat*sin((i+1)*PI/6));
  glEnd();  
 }
  for(int i=0;i<12;i++){
  float nx=(rat-r-(2*r/10))*cos(i*PI/6),ny=(rat-r-(2*r/10))*sin(i*PI/6); 
  glPushMatrix();
  premitives::DrawCylinderBody( Point(x+nx,y-(h+(3*r)),z+ny),rad,rad,h,ro);
  glPopMatrix();
 }
 glBegin(GL_POLYGON);
 for(int i=0;i<6;i++){
  float nx=(rat-r-r-r)*cos(i*PI/3),ny=(rat-r-r-r)*sin(i*PI/3); 
  float ang=i*PI/3;
  glVertex3f(x+nx,y+rat/8,z+ny); }
 glEnd();
 glBegin(GL_POLYGON); 
 for(int i=0;i<6;i++)
 { 
  float nx=(rat-r-r-r)*cos(i*PI/3),ny=(rat-r-r-r)*sin(i*PI/3);
  float ang=i*PI/3; 
  glVertex3f(x+nx,y,z+ny);
  if(i){
  glBegin(GL_QUADS);  
   glVertex3d(x+nx,y,z+ny);  
   glVertex3d(x+nx,y+rat/8,z+ny);
   glVertex3d(x+(rat-r-r-r)*cos((i-1)*PI/3),y+rat/8,z+(rat-r-r-r)*sin((i-1)*PI/3)); 
   glVertex3d(x+(rat-r-r-r)*cos((i-1)*PI/3),y,z+(rat-r-r-r)*sin((i-1)*PI/3));
  glEnd();
    }
 }
 glEnd();

 premitives::DrawDome(3,saria,Point(x,y+0.6,z));
}


};

