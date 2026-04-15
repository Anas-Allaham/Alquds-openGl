#pragma once
#include<iostream>;
class CAM
{
public:
	
	static void Key(bool* keys, float speed, int &x,Camera &MyCamera,float &r,int &b, int &door,float &a,int &door2,bool&flag)
{
	if (keys['S'])
		MyCamera.RotateX(-1 * speed);
	if (keys['W'])
		MyCamera.RotateX(1 * speed);
	if (keys['D'])
		MyCamera.RotateY(-1 * (speed+2));
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);
	if (keys['A'])
		MyCamera.RotateY(1 * (speed+1));
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
			keys['M']=0;
		b=0;
		sub_build::DrawAnotherDoor(0 , 0 , -20 , 1.5 , 2 , 0.1 , door , r,b);//باب
		}
		}
		
		if (keys['N'])
		{
			if(a<90 && a>=-1){
		b=1;
			a=a+0.8;
			keys['N']=0;

		sub_build::DrawAnotherDoor(0,0,-20,-1.5,2,0.1,door2,a,b);//باب
		}
		}


		if (keys['K']){
			if(r>=-90.9 && r<=0){
			r=r+1;
			keys['K']=0;

			b=0;
		sub_build::DrawAnotherDoor(0 , 0 , -20 , 1.5 , 2 , 0.1 , door , r,b);//باب
	}
		}
		if (keys['J']){
			if(a<=90.9 && a>=0){
		a=a-1;
		keys['J']=0;

		b=1;
		sub_build::DrawAnotherDoor(0 , 0 , -20, -1.5 , 2 , 0.1 , door2 , a,b);//باب
		}
	}
		if(keys['G']){
			flag=!flag;
			keys['G']=0;
		}
		if(keys['P']){
			Sleep(3000);
		}
}

	static void MYCAM(float speed,float rat,bool *&keys,bool &isfps,Model_3DS *&person,bool &w,Camera &MyCamera,float &rx,int cnt,float &a,float& r,int &b,int door2,int door){


		if (keys['M'])
		{
		if(r<=0.9 &&r>-90){
			r=r-0.8f;
			keys['M']=0;
		b=0;
		sub_build::DrawAnotherDoor(0 , 0 , -20 , 1.5 , 2 , 0.1 , door , r,b);//باب
		}
		}
		
		if (keys['N'])
		{
			if(a<90 && a>=-1){
		b=1;
			a=a+0.8;
			keys['N']=0;

		sub_build::DrawAnotherDoor(0,0,-20,-1.5,2,0.1,door2,a,b);//باب
		}
		}


		if (keys['K']){
			if(r>=-90.9 && r<=0){
			r=r+1;
			keys['K']=0;

			b=0;
		sub_build::DrawAnotherDoor(0 , 0 , -20 , 1.5 , 2 , 0.1 , door , r,b);//باب
	}
		}
		if (keys['J']){
			if(a<=90.9 && a>=0){
		a=a-1;
		keys['J']=0;

		b=1;
		sub_build::DrawAnotherDoor(0 , 0 , -20, -1.5 , 2 , 0.1 , door2 , a,b);//باب
		}
	}

	if(keys[VK_SHIFT])speed*=2.0;
	if(isfps){
		if(keys[VK_UP])
		{
			if(!(exten::is_safe(person))){MyCamera.MoveForward(-2*speed);	person->pos.x=MyCamera.Position.x;person->pos.y=MyCamera.Position.y-2;	person->pos.z=MyCamera.Position.z;keys[VK_UP]=0;return;}
			MyCamera.MoveForward(speed);
			person->pos.x=MyCamera.Position.x;
			person->pos.y=MyCamera.Position.y-2;
			person->pos.z=MyCamera.Position.z;
		}

		if(keys[VK_DOWN]){

			if(!(exten::is_safe(person))){	MyCamera.MoveForward(2*speed);	person->pos.x=MyCamera.Position.x;		person->pos.y=MyCamera.Position.y-2;	person->pos.z=MyCamera.Position.z;	keys[VK_DOWN]=0;return;}
			MyCamera.MoveForward(-speed);
			person->pos.x=MyCamera.Position.x;person->pos.y=MyCamera.Position.y-2;
			person->pos.z=MyCamera.Position.z;}
			if(keys[VK_LEFT]){
				if(!(exten::is_safe(person))){keys[VK_LEFT]=0;MyCamera.MoveRight(2*speed);	person->pos.x=MyCamera.Position.x;person->pos.y=MyCamera.Position.y-2;person->pos.z=MyCamera.Position.z;}
				MyCamera.MoveRight(-speed);
			person->pos.x=MyCamera.Position.x;
			person->pos.y=MyCamera.Position.y-2;
			person->pos.z=MyCamera.Position.z;
		}
		if(keys[VK_RIGHT]){
			if(!(exten::is_safe(person))){keys[VK_RIGHT]=0;MyCamera.MoveRight(-2*speed);	person->pos.x=MyCamera.Position.x;person->pos.y=MyCamera.Position.y-2;person->pos.z=MyCamera.Position.z;}
			MyCamera.MoveRight(speed);
		person->pos.x=MyCamera.Position.x;person->pos.y=MyCamera.Position.y-2;
		person->pos.z=MyCamera.Position.z;
		}
		if(keys['A']){person->rot.y+=speed;rx+=speed;
		MyCamera.RotateY(1 * speed);}
		if(keys['D']){person->rot.y-=speed;rx-=speed;
		MyCamera.RotateY(1 * -speed);}

	}else{
		if(keys[VK_UP]){			if(!(exten::is_safe(person))){		MyCamera.MoveForward(-2*speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);keys[VK_UP]=0;return;}
		MyCamera.MoveForward(speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);}
		if(keys[VK_DOWN]){			if(!(exten::is_safe(person))){		MyCamera.MoveForward(2*speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);keys[VK_DOWN]=0;return;}
		MyCamera.MoveForward(-speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);}
		if(keys[VK_LEFT]){			if(!(exten::is_safe(person))){		MyCamera.MoveRight(2*speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);keys[VK_LEFT]=0;return;}
		MyCamera.MoveRight(-speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);}
		if(keys[VK_RIGHT]){			if(!(exten::is_safe(person))){		MyCamera.MoveRight(-2*speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);keys[VK_RIGHT]=0;return;}
		MyCamera.MoveRight(speed);person->pos.x=MyCamera.Position.x+4*sin(rat*rx);person->pos.z=MyCamera.Position.z+4*cos(rat*rx);}
		if(keys['A']){person->rot.y+=speed;rx+=speed;MyCamera.Position.x=person->pos.x-4*sin(rat*rx)	;	MyCamera.Position.z=person->pos.z-4*cos(rat*rx);MyCamera.RotateY(speed);}
		if(keys['D']){person->rot.y-=speed;rx-=speed;MyCamera.Position.x=person->pos.x-4*sin(rat*rx)	;	MyCamera.Position.z=person->pos.z-4*cos(rat*rx);MyCamera.RotateY(-speed);}

		

	}//0.0045//0.0008

}


	static 	void setupLights(Camera &MyCamera,int cnt) {
		float r=float(cnt)/1000.0;
    glEnable(GL_LIGHTING);

    // Light 1
	
	glEnable(GL_LIGHT0);
    GLfloat light0Position[] = { 0, 100, 0,1.0f };
    GLfloat light0Ambient[] = { r, r, r, r };
   // GLfloat light0Diffuse[] = { 0.0f, 0.0f, 1.0f, 0.8f };  // Blue light
    GLfloat light0Diffuse[] = { 0.3f, 0.0f, 0.3, 1 };  // Blue light

    GLfloat light0Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 128);

    // Light 2
 //   glEnable(GL_LIGHT1);
	//GLfloat light1Position[] = { MyCamera.Position.x,  MyCamera.Position.y,  MyCamera.Position.z, 20.0f };//-42//3//73//20
 //   GLfloat light1Ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
 //   GLfloat light1Diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // Blue light
 //   GLfloat light1Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
 //   glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
 //   glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
 //   glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diffuse);
 //   glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
	////glMateriali(GL_FRONT, GL_SHININESS, 128);
}

	static void DrawGround(void)
{
GLfloat fExtent = 100.0f;
GLfloat fStep = 1.0f;
GLfloat y = -0.4f;
GLint iLine;
glBegin(GL_LINES);
for(iLine = -fExtent; iLine <= fExtent; iLine += fStep)
{
glVertex3f(iLine, y, fExtent); // Draw Z lines
glVertex3f(iLine, y, -fExtent);
glVertex3f(fExtent, y, iLine);
glVertex3f(-fExtent, y, iLine);
}
glEnd();
}


	static void tps(float rat ,Camera &MyCamera,bool &isfps,Model_3DS *&person,float &rx,bool *&keys){

	if(isfps==0){
		MyCamera.Position.x=person->pos.x-4*sin(rat*rx)	;	
		MyCamera.Position.z=person->pos.z-4*cos(rat*rx)	;	
		 MyCamera.Position.y=2;
		// cout<<MyCamera.Position.x<<" "<<person->pos.x<<endl<<MyCamera.Position.z<<" * "<<person->pos.z<<endl;
	}else{
		MyCamera.Position.z=person->pos.z;
		MyCamera.Position.x=person->pos.x;
		MyCamera.Position.y=1;

	}
			keys['T']=0;
}

	static void Enable(bool *keys,bool &isfps,Camera &MyCamera,Model_3DS *&person,float &rx,bool &w,bool ,int cnt,bool &flag,float &a,float& r,int &b,int door2,int door){
	if(keys['G'])flag=!flag,keys['G']=0;

	if(keys['T']){
		isfps=!isfps;
		keys['T']=0;
		tps(0.0174,MyCamera,isfps,person,rx,keys);
		}
	MYCAM(0.5,0.0174,keys,isfps,person,w,MyCamera,rx,cnt,a,r,b,door2,door);
		person->Draw();

		if(keys['U']||(cnt%1000==0)) {    if(person->pos.x>=25&&person->pos.x<=46&&person->pos.z<=15&&person->pos.z>=5){
     PlaySound(TEXT("tzker2"),NULL,SND_ASYNC);    keys['U']=0;}
    else if( person->pos.x>=-47&&person->pos.x<=-23&&person->pos.z<=20&&person->pos.z>=0){     PlaySound(TEXT("tzker"),NULL,SND_ASYNC);
            keys['U']=0;    }
    else    {
      PlaySound(TEXT("bird"),NULL,SND_ASYNC);      keys['U']=0;
    } 
  }
	}

	static void TurnLight(bool *keys,Camera &MyCamera,int &cnt){
	
	//if(keys['F'] ) {
		glEnable(GL_LIGHT0);		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	//	glEnable(GL_LIGHT1);
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
		cnt%=2000;
		std::cout<<(cnt>=1000 ?((1000)-(cnt%1000)) : cnt)<<std::endl;

		setupLights(MyCamera,(cnt>=1000 ?((1000)-(cnt%1000)) : cnt));


// } else if(keys['P'] ) {
  //glDisable(GL_LIGHT0);
  //glDisable(GL_LIGHTING);
  //glDisable(GL_COLOR_MATERIAL);

 //}


	

}


};

