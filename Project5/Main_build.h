#pragma once
class Main_build
{
public:
	

	static void drawAlkable(float x,float y,float z,int roof,int window,int door,float r,int door2,float fa,int triangle,int triangle2,int carpet,int room,int madne,int amode3,int amode,int stairs){
	glPushMatrix();
	glTranslatef(0,0,8);
	glRotatef(-90,0,1,0);
	glTranslatef(0,0,-8);

    // الوجه الأمامي
    sub_build::DrawAnotherWall(x - 3, y, z, 3, 2, 0.5, roof);

    sub_build::DrawAnotherDoor(x, y, z - 0.1, 1.5, 2, 0.1, door, r-50, 0);  // باب
	glPushMatrix();
    sub_build::DrawAnotherDoor(x + 3, y, z - 0.1, -1.5, 2, 0.1, door2, fa, 1);  // باب
	glPopMatrix();

    sub_build::DrawAnotherWall(x + 3, y, z, 3, 2, 0.5, roof);

    // الوجه اليميني
    sub_build::DrawAnotherWall(x + 6, y, z, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x + 6, y + 1.5, z - 2, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 6, y + 0.5, z - 2, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 6, y, z - 2, 0.5, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x + 6, y, z - 3, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x + 6, y + 1.5, z - 5, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 6, y + 0.5, z - 5, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 6, y, z - 5, 0.5, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x + 6, y, z - 6, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x + 6, y + 1.5, z - 8, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 6, y + 0.5, z - 8, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 6, y, z - 8, 0.5, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x + 6, y, z - 9, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x + 6, y + 1.5, z - 11, 0.5, 0.5, 1, roof);


	glColor4f(0.5f,0.5f,0.5f,0.3f);
	sub_build::DrawAnotherWall(x+6 , y+0.5 , z-11 , 0.5 , 1 , 1 , window);
  glColor4f(1.0f,1.0f,1.0f,1.0f);


 sub_build::DrawAnotherWall(x+6 , y , z-11 , 0.5 , 0.5 , 1 , roof); 
 sub_build::DrawAnotherWall(x+6 , y , z-12 , 0.5 , 2 , 2 , roof);
 sub_build::DrawAnotherWall(x+6 , y+1.5 , z-14 , 0.5 , 0.5 , 1 , roof);

 glColor4f(0.5f,0.5f,0.5f,0.3f);
 sub_build::DrawAnotherWall(x+6 , y+0.5 , z-14 , 0.5 , 1 , 1 , window);
  glColor4f(1.0f,1.0f,1.0f,1.0f);


 sub_build::DrawAnotherWall(x+6 , y , z-14 , 0.5 , 0.5 , 1 , roof);
 sub_build::DrawAnotherWall(x+6 , y , z-15 , 0.5 , 2 , 2 , roof);
  sub_build::DrawAnotherWall(x-3 , y , z , 0.5 , 2 , 2 , roof);


    // الوجه اليساري
   
    sub_build::DrawAnotherWall(x - 3, y + 1.5, z - 2, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x - 3, y + 0.5, z - 2, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x - 3, y, z - 2, 0.5, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x - 3, y, z - 3, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x - 3, y + 1.5, z - 5, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x - 3, y + 0.5, z - 5, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x - 3, y, z - 5, 0.5, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x - 3, y, z - 6, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x - 3, y + 1.5, z - 8, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x - 3, y + 0.5, z - 8, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x - 3, y, z - 8, 0.5, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x - 3, y, z - 9, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x - 3, y + 1.5, z - 11, 0.5, 0.5, 1, roof);

    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x - 3, y + 0.5, z - 11, 0.5, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x - 3, y, z - 11, 0.5, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x - 3, y, z - 12, 0.5, 2, 2, roof);
    sub_build::DrawAnotherWall(x - 3, y + 1.5, z - 14, 0.5, 0.5, 1, roof);

	glColor4f(0.5f,0.5f,0.5f,0.3f);
	sub_build::DrawAnotherWall(x-3 , y+0.5 , z-14 , 0.5 , 1 , 1 , window);
  glColor4f(1.0f,1.0f,1.0f,1.0f);

 sub_build::DrawAnotherWall(x - 3 , y , z-14 , 0.5 , 0.5 , 1 , roof);
  sub_build::DrawAnotherWall(x-3 , y , z-15 , 0.5 , 2 , 2 , roof);
 


    // الوجه الخلفي
    sub_build::DrawAnotherWall(x - 3, y, z - 17, 9.5, 2, 0.5, roof);

    // السطح
	sub_build::DrawAnotherWall(x + 6, y + 2, z, -3, 0, 17, roof);
    sub_build::DrawAnotherWall(x, y + 2, z, -3, 0, 17, roof);
    sub_build::DrawAnotherWall(x, y + 2, z, 0.3, 2, 2, roof);
    sub_build::DrawAnotherWall(x, y + 2, z - 2, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x, y + 2.5, z - 2, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x, y + 3.5, z - 2, 0.3, 0.5, 1, roof);

    sub_build::DrawAnotherWall(x, y + 2, z - 3, 0.3, 2, 2, roof);

    sub_build::DrawAnotherWall(x, y + 2, z - 5, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x, y + 2.5, z - 5, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x, y + 3.5, z - 5, 0.3, 0.5, 1, roof);

    sub_build::DrawAnotherWall(x, y + 2, z - 6, 0.3, 2, 2, roof);

    sub_build::DrawAnotherWall(x, y + 2, z - 8, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x, y + 2.5, z - 8, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x, y + 3.5, z - 8, 0.3, 0.5, 1, roof);
    sub_build::DrawAnotherWall(x, y + 2, z - 9, 0.3, 2, 2, roof);

    sub_build::DrawAnotherWall(x, y + 2, z - 11, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x, y + 2.5, z - 11, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x, y + 3.5, z - 11, 0.3, 0.5, 1, roof);

    sub_build::DrawAnotherWall(x, y + 2, z - 12, 0.3, 2, 0.5, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z, 0.3, 2, 2, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 2, 0.3, 0.5, 1, roof);


	
    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 3.25, y + 2.5, z - 2, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 3, y + 3.5, z - 2, 0.3, 0.5, 1, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 3, 0.3, 2, 2, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 5, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 3.25, y + 2.5, z - 5, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 3, y + 3.5, z - 5, 0.3, 0.5, 1, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 6, 0.3, 2, 2, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 8, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 3.25, y + 2.5, z - 8, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 3, y + 3.5, z - 8, 0.3, 0.5, 1, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 9, 0.3, 2, 2, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 11, 0.3, 0.5, 1, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 3.25, y + 2.5, z - 11, 0, 1, 1, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 3, y + 3.5, z - 11, 0.3, 0.5, 1, roof);

    sub_build::DrawAnotherWall(x + 3, y + 2, z - 12, 0.3, 2, 0.5, roof);

    // المثلث بالسقف
    glPushMatrix();
	glTranslatef(x + 3, y + 4 , z + 8);
    glRotatef(45, 0 , 0 , 1);
	glTranslatef(-x - 3 , y - 4 , z - 8);
    sub_build::DrawAnotherWall(x + 3, y + 4 , z +40, 0.1 , 2, 12.5, roof);
    glPopMatrix();

    glPushMatrix();
	  glTranslatef( x , y + 4 , z + 8);
		glRotatef(-45, 0, 0, 1);
	  glTranslatef( -x , y - 4, z - 8);

    sub_build::DrawAnotherWall(x , y + 4 , z+40 , 0.1 , 2.2 , 12.5 , roof);
    glPopMatrix();

    // واجهة فوقانية
 sub_build::DrawAnotherWall(x, y + 2, z, 0.5, 2, 0.3, roof);

    sub_build::DrawAnotherWall(x + 0.5, y + 2, z, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 0.5, y + 2.5, z, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 0.5, y + 3.5, z, 0.75, 0.5, 0.3, roof);

    sub_build::DrawAnotherWall(x + 1.25, y + 2, z, 0.5, 2, 0.3, roof);

    sub_build::DrawAnotherWall(x + 1.75, y + 2, z, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 1.75, y + 2.5, z, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 1.75, y + 3.5, z, 0.75, 0.5, 0.3, roof);

    sub_build::DrawAnotherWall(x + 2.5, y + 2, z, 0.5, 2, 0.3, roof);

    glBindTexture(GL_TEXTURE_2D, triangle2);
    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(0, 0);
    glVertex3f(x, y + 4, z);
    glTexCoord2f(0.5, 1);
    glVertex3f(x + 1.6, y + 5.6, z);
    glTexCoord2f(1, 0);
    glVertex3f(x + 3.2, y + 4, z);
	glEnd();


	 sub_build::DrawAnotherWall(x, y + 2, z-12, 0.5, 2, 0.3, roof);
    sub_build::DrawAnotherWall(x + 0.5, y + 2, z-12, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 0.5, y + 2.5, z-12, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 0.5, y + 3.5, z-12, 0.75, 0.5, 0.3, roof);

    sub_build::DrawAnotherWall(x + 1.25, y + 2, z-12, 0.5, 2, 0.3, roof);

    sub_build::DrawAnotherWall(x + 1.75, y + 2, z-12, 0.75, 0.5, 0.3, roof);

    glColor4f(0.0f, 0.5f, 0.5f, 0.3f);
    sub_build::DrawAnotherWall(x + 1.75, y + 2.5, z-12, 0.75, 1, 0.3, window);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    sub_build::DrawAnotherWall(x + 1.75, y + 3.5, z-12, 0.75, 0.5, 0.3, roof);

    sub_build::DrawAnotherWall(x + 2.5, y + 2, z-12, 0.5, 2, 0.3, roof);

    glBindTexture(GL_TEXTURE_2D, triangle2);
    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(0, 0);
    glVertex3f(x, y + 4, z-13);
    glTexCoord2f(0.5, 1);
    glVertex3f(x + 1.6, y + 5.6, z-13);
    glTexCoord2f(1, 0);
    glVertex3f(x + 3.2, y + 4, z-13);

    glEnd();
//الارضية
	sub_build::DrawCarpet(x-3 , y+0.2 , z  , 9 , 0 , 17 , stairs);


// السقف الفوقاني والعواميد
sub_build::DrawAnotherWall(x - 3, y + 1.9, z, 9.5, 0.1, -2, roof);

// الحيط المزخرف في السقف
sub_build::DrawAnotherWall(x - 3, y + 2, z, 3, 0.5, 0.3, room);
sub_build::DrawAnotherWall(x - 3, y + 2, z - 0.1, 0.3, 0.5, 12, room);
sub_build::DrawAnotherWall(x - 3, y + 2, z - 12, 3, 0.5, 0.5, room);
sub_build::DrawAnotherWall(x - 3, y + 2.5, z, 3, 0, 12.5, roof);

// القبة
Point a = Point(x + 1.6, y + 5.3, z - 15);
sub_build::DrawAnotherWall(x, y + 2, z - 12.5, 0.3, 3.5, 5, roof);
sub_build::DrawAnotherWall(x + 3, y + 2, z - 12.5, 0.3, 3.5, 5, roof);
sub_build::DrawAnotherWall(x, y + 2, z - 17.5, 3.3, 3.5, 0.3, roof);
sub_build::DrawAnotherWall(x, y + 2, z - 12.5, 3.3, 3.5, 0.3, roof);
premitives::DrawDome(3, madne, a);

// العوامييد
sub_build::DrawAnotherWall(x - 2.25, y, z + 1, 0.3, 2, 0.3, amode3);
sub_build::DrawAnotherWall(x - 1.5, y, z + 1, 0.3, 2, 0.3, amode3);
sub_build::DrawAnotherWall(x - 0.75, y, z + 1, 0.3, 2, 0.3, amode3);
sub_build::DrawAnotherWall(x + 3.75, y, z + 1, 0.3, 2, 0.3, amode3);
sub_build::DrawAnotherWall(x + 4.5, y, z + 1, 0.3, 2, 0.3, amode3);
sub_build::DrawAnotherWall(x + 5.25 , y , z + 1 , 0.3 , 2 , 0.3 , amode3);

// اخر العامود
sub_build::DrawAnotherWall(x - 2.40, y, z + 1, 0.6, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x - 2.35, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x - 2.30, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

sub_build::DrawAnotherWall(x - 1.65, y, z + 1, 0.6, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x - 1.60, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x - 1.55, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

sub_build::DrawAnotherWall(x - 0.90, y, z + 1, 0.6, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x - 0.85, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x - 0.80, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

sub_build::DrawAnotherWall(x + 3.60, y, z + 1, 0.6, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x + 3.65, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x + 3.70, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

sub_build::DrawAnotherWall(x + 4.35, y, z + 1, 0.6, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x + 4.40, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x + 4.45, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

sub_build::DrawAnotherWall(x + 5.1, y, z + 1, 0.6, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x + 5.15, y + 0.06, z + 1, 0.5, 0.06, 0.3, roof);
sub_build::DrawAnotherWall(x + 5.20, y + 0.12, z + 1, 0.4, 0.06, 0.3, roof);

	//العواميد في الجامع الشريف القبلي المحرف
 sub_build::DrawAnotherWall(x + 4.5, y, z - 3.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x + 4.5, y, z - 6.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x + 4.5, y, z - 9.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x + 4.5, y, z - 12.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x + 4.5, y, z - 15.75, 0.3, 2, 0.3, amode);

 sub_build::DrawAnotherWall(x - 1.5, y, z - 3.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x - 1.5, y, z - 6.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x - 1.5, y, z - 9.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x - 1.5, y, z - 12.75, 0.3, 2, 0.3, amode);
 sub_build::DrawAnotherWall(x - 1.5, y, z - 15.75, 0.3, 2, 0.3, amode);
 glPopMatrix();
}



static void draw_Kobet_AN(int x,int z,int frq,int jdar,int car, int he,int Dome,int krse ,float Z=1.1,int X=1){ 
	int y=x,p=x;  premitives::eighth_AN(x,0+Z,1,car,X);
  premitives::eighth_AN(x,z+Z,1,-1,X); int prex=-p,prey=0;
 int cx=0,cy=0,incx=p+p,incy=0;
 for(int i=0;i<8;i++){         
 glBindTexture(GL_TEXTURE_2D, jdar);
 glPolygonMode(GL_FRONT,GL_LINES); glBegin(GL_POLYGON);
 glVertex3f(prex+X, 0+Z,prey); glVertex3f(prex+incx+X,0+Z, prey+incy);
 glVertex3f(prex+incx+X,z+Z,prey+incy); glVertex3f(prex+X, z+Z,prey);
 glEnd();
 glBegin(GL_QUADS);  glTexCoord2f(0, 0);
  glVertex3d(prex+incx+X,0+Z,prey+incy);  glTexCoord2f(frq, 0);
  glVertex3d(prex+X,0+Z,prey);
  glTexCoord2f(frq, 1);  glVertex3d(prex+X,z-1.6+Z,prey);
  glTexCoord2f(0, 1);
  glVertex3d(prex+incx+X,z-1.6+Z,prey+incy);
  glEnd();
   glBindTexture(GL_TEXTURE_2D, he);
   glBegin(GL_QUADS);  glTexCoord2f(0.2, 0.2);
  glVertex3d(prex+incx+X,z-1.6+0.02+Z,prey+incy);  glTexCoord2f(frq-0.2, 0.2);
  glVertex3d(prex+X,z-1.6+0.02+Z,prey);
  glTexCoord2f(frq-0.2, 0.7);  glVertex3d(prex+X,z+Z,prey);
  glTexCoord2f(0.2, 0.7);
  glVertex3d(prex+incx+X,z+Z,prey+incy);
  glEnd();

 prex=prex+incx;
  prey=prey+incy;   if(cx)incx+=p;
        else incx-=p;        if(incx==-2*p)cx=1;
        if(cy==0)incy+=p;        else incy-=p;
        if(incy==2*p)cy=1;        if(incy==-2*p)cy=0;
 } Point ball(-35,8.2,10);
 premitives::DrawDome(8,Dome,ball);


 sub_build::DrawAnotherWall( -42, 1 , 10 , -3, 0.5 ,2.5, krse );
 sub_build::DrawAnotherWall( -42.5, 1.5 , 10 , -2.5, 0.5 ,2.5, krse );
 sub_build::DrawAnotherWall( -43, 2 , 10 , -2, 0.5 ,2.5, krse ); 
 sub_build::DrawAnotherWall( -43.5 , 2.5, 10 , -1.5, 0.5 ,2.5, krse );
 sub_build::DrawAnotherWall( -43.5 , 3, 10 , -0.1, 1 ,0.2, krse );
 sub_build::DrawAnotherWall( -43.5 , 3, 7.7 , -0.1, 1 ,0.2, krse );
 sub_build::DrawAnotherWall( -43.5 , 4, 10 , -2, 0.1 ,0.2, krse );
 sub_build::DrawAnotherWall( -43.5 , 4, 7.7 , -2, 0.1 ,0.2, krse );

 };






};

