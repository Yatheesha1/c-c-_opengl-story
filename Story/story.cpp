//g++ 'story.cpp' -lGL -lGLU -lglut -pthread -std=c++11

#include<GL/glut.h>
#include <GL/gl.h>
#include<math.h>
#include<unistd.h>
#include<string.h>
#include "YS/circle.cpp"
#include <thread>


int a,sequence=0,count=0;
 const char *st[]={"Love And Time.",
                    "This Is A. Short Story About Love And Time",
	                "Once upon A Time. In An Island. There Lived All The Feelings And Emotions.",
	                "Happyness.",
	                "Sadness.",
	                "Knowledge",
	                "and all others.",
	                "Including Love.",
	                "One Day it was Announced To Them That. The Island Would Sink.","So All Constructed Boats And Left. Except For Love.",
	                "Love Wanted To Hold Out. Until The Last Possible Moment.",
	                "When The Island Had Almost Sunk. Love Decided To Ask For Help.",
	                "Richness Was Passing By Love In A Boat.",
	                "Love Said. Richness Can You Take Me With You.",
	                "Richness Replied. Sorry Love. I Can't. There's A Lot Gold & Silver.","In My Boat. And So There Is No Place For You",
	                "Sadness Was Close By. So Love Asked.",
	                "Sadness Take Me Along With You. Oh. Love. ",
	                "I'm So Sad. That I Need ToBe By Myself. Sadness Said In Sullen Voice.",
	                "Happyness Passed By Love Too. But She Was. So Preoccupied."," With Her Happyness That She Did Not Even Hear When Love Called Her.",
	                "Suddenly There Was A Voice. Come Love I Will Take You.",
	                "It Was An Elder. An Overjoyed Love Jumped Up Into The Boat.","And In The Process Forgot To Ask Where They Were Going.",
	                "When They Arrived At Dry Land. The Elder Went Her Own Way.",
	                "Realizing How Much Was Owned To The Elder.",
	                "Love Asked The Knowledge Another Elder. Who Helped Me.",
	                "It Was Time. Knowledge  Answered.",
	                "Time. Thought Love.",
	                "Then. As If Reading The Face Of Love. Knowledge Smiled And Answered.",
	                "Because. Only Time Is Capable Of Understanding. How  Valuable Love Is."};

void speaktext(const char *s)
{
   char speak[100];
   strcpy(speak, "espeak \"");
   strcat(speak,s);
   strcat(speak,"\" -g 2 -ven-us+f2");
   system(speak);
}

void Printtext(float r,float g,float b,const char *string,int x,int y)
{
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void tree(int x,int y)
{
    glColor3f(0.5019,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(350+x,325+y);
    glVertex2f(350+x,395+y);
    glVertex2f(365+x,395+y);
    glVertex2f(365+x,325+y);
    glEnd();

    glColor3f(0.0,0.5,0.0);
	DrawCircle(330+x,400+y,40,1);
	DrawCircle(390+x,400+y,40,1);

	glColor3f(0.0,0.5,0.0);
	DrawCircle(340+x,440+y,35,1);
	DrawCircle(380+x,440+y,35,1);

	glColor3f(0.0,0.5,0.0);
	DrawCircle(360+x,465+y,30,1);
}
void sea()
{
	//sea
   glColor3f(0.0,0.7,0.7);
   glBegin(GL_POLYGON);
   glVertex2f(0,0);
   glVertex2f(1100,0);
   glColor3f(0.0,0.0,1.0);   
   glVertex2f(1100,350);
   glVertex2f(0,350);
   glEnd();
}

void drawtree()
{
	 //tree
   tree(20,-30);
   tree(80,-10);
   tree(400,-70);
   tree(200,-150);
   tree(300,-50);
}

void island()
{
	//island
   glColor3f(0.6,0.4,0.2);
   DrawSegment(540, 550, 400,220,320,1);
   DrawCircle(280, 310, 50,1);
   DrawCircle(790, 300, 60,1);
   DrawSegment(540, 110, 350,30,150,1);
}

void sky()
{
	   //sky
   glColor3f(0.0,0.8,1.0);
   glBegin(GL_POLYGON);
   glVertex2f(0,350);
   glVertex2f(1100,350);
   glColor3f(0.0,0.5,0.9);
   glVertex2f(1100,700);
   glVertex2f(0,700);
   glEnd();
}

void ship()
{	
  glColor3f(0.4,0.4,0.4);
  glBegin(GL_POLYGON);
  glVertex2f(48,388);
  glVertex2f(48,420);
  glVertex2f(52,422);
  glVertex2f(53,388);
  glEnd();	

  glColor3f(0.8,0.6,0.6);
  glBegin(GL_POLYGON);
  glVertex2f(28,378);
  glVertex2f(28,390);
  glVertex2f(100,390);
  glVertex2f(100,378);
  glEnd();	
   	
  glColor3f(0.6,0.6,0.6);
  glBegin(GL_POLYGON);
  glVertex2f(28,368);
  glVertex2f(28,380);
  glVertex2f(220,380);
  glVertex2f(224,368);
  glEnd();	
  
  for(int i=36;i<200;i+=16)
  {
	  glColor3f(0.9,0.9,0.9);
      glBegin(GL_POLYGON);
      glVertex2f(i,370);
      glVertex2f(i,378);
      glVertex2f(i+8,378);
      glVertex2f(i+8,370);
      glEnd();
  }	
	
  glColor3f(0.4,0.4,0.4);
  glBegin(GL_POLYGON);
  glVertex2f(30,340);
  glVertex2f(20,370);
  glVertex2f(230,370);
  glVertex2f(210,340);
  glEnd();
  glutPostRedisplay();
  glutSwapBuffers();
  
}

void start()
{
   Printtext(.9,.5,.5,"WELCOME",480,400);  
   Printtext(.9,.5,.5,"CG PROJECT",470,350);
   Printtext(.9,.5,.5,"4SF15CS404,4SF15CS415",410,300);
   glutPostRedisplay();
   glutSwapBuffers();
}

void sequence1()
{
   glColor3f(0,1,0);
   Printtext(.9,.5,.5,st[count],470,350);
   glutPostRedisplay();
   glutSwapBuffers();
   speaktext(st[count]);
   count=1;
   speaktext(st[count]);
   count=2;
}


void sequence2()
{      
   glutPostRedisplay();
   glutSwapBuffers();
   //sleep(2);
   speaktext(st[count]);
   count=3;
   
}
void happy(int x,int y)
{ 
 glColor3f(1.0,.6,0.0);
 glLineWidth(3.0);
 DrawCircle(700+x,250+y,50,0);
 DrawArc(700+x,250+y,30,230,310);
 DrawArc(700+x,300+y,75,245,295);
 glPointSize(10.0);
 glBegin(GL_POINTS);
 glVertex2f(685+x,265+y);
 glVertex2f(715+x,265+y);
 glEnd();
 glutPostRedisplay();
 glutSwapBuffers();

}

void sad(int x,int y)
{ 
 glColor3f(1.0,.6,0.0);
 glLineWidth(3.0);
 DrawCircle(550+x,250+y,50,0);
 DrawArc(550+x,200+y,30,50,130);
 DrawArc(550+x,150+y,75,67,113);
 glPointSize(10.0);
 glBegin(GL_POINTS);
 glVertex2f(535+x,265+y);
 glVertex2f(565+x,265+y);
 glEnd();
 glutPostRedisplay();
 glutSwapBuffers();
}

void knowledge(int x,int y)
{ 
 glColor3f(1.0,.6,0.0);
 glPointSize(2.0);
 DrawCircle(700+x,250+y,50,0);
 DrawArc(700+x,250+y,30,230,310);
 glPointSize(10.0);
 glBegin(GL_POINTS);
 glVertex2f(715+x,265+y);
 glVertex2f(685+x,265+y);
 glPointSize(7.0);
 glColor3f(0.0,.6,1.0);
 glVertex2f(670+x,300+y);
 glVertex2f(690+x,290+y);
 glVertex2f(710+x,290+y);
 glVertex2f(730+x,300+y);
 glVertex2f(710+x,310+y);
 glVertex2f(690+x,310+y);
 glEnd();
 glPointSize(2.0);
 glColor3f(1.0,.6,0.0);
 glBegin(GL_LINE_STRIP);
 glVertex2f(660+x,220+y);
 glVertex2f(620+x,210+y);
 glVertex2f(655+x,275+y);
 
 glEnd();
 glutPostRedisplay();
 glutSwapBuffers();
 
}

void heart(int x,int y)
{
 //heart
 glLineWidth(2.0);
 glColor3f(0.9,0.0,0.0);
 glBegin(GL_POLYGON);
 glVertex2f(550+x,315+y);
 glVertex2f(530+x,340+y);
 glVertex2f(550+x,350+y);
 glVertex2f(570+x,340+y);
 glEnd();
 DrawCircle(560+x,350+y,14,1);
 DrawCircle(540+x,350+y,14,1);
 glutPostRedisplay();
 glutSwapBuffers();
	
}

void richness(int x,int y)
{ 
 glColor3f(1.0,.6,0.0);
 glPointSize(2.0);
 DrawCircle(700+x,250+y,50,0);
 DrawArc(700+x,250+y,30,230,310);
 glPointSize(10.0);
 
 glBegin(GL_POINTS);
 glVertex2f(715+x,265+y);
 glVertex2f(685+x,265+y);
 glEnd();
 glPointSize(2.0);
 glColor3f(1.0,.6,0.0);
 
 glBegin(GL_LINE_STRIP);
 glVertex2f(740+x,220+y);
 glVertex2f(760+x,210+y);
 glVertex2f(695+x,175+y);
 glEnd();
 
 glBegin(GL_LINE_STRIP);
 glVertex2f(660+x,220+y);
 glVertex2f(620+x,210+y);
 glVertex2f(705+x,175+y);
 glEnd();
 
 glColor3f(1.0,.84,0.0);
 DrawCircle(700+x,170+y,10,1);
 DrawCircle(710+x,170+y,10,1);
 DrawCircle(690+x,160+y,10,1);
 glutPostRedisplay();
 glutSwapBuffers();
}

void love(int x,int y)
{ 
 glColor3f(1.0,.6,0.0);
 glLineWidth(2.0);
 DrawCircle(550+x,350+y,50,0);
 DrawArc(550+x,350+y,30,225,315);
 glPointSize(10.0);
 glBegin(GL_POINTS);
 glVertex2f(535+x,365+y);
 glVertex2f(565+x,365+y);
 glEnd();
 heart(x-50,y+20);
 heart(x+50,y+20);
 glutPostRedisplay();
 glutSwapBuffers();
}

void time(int x,int y)
{ 
 glColor3f(1.0,.6,0.0);
 glLineWidth(2.0);
 DrawCircle(550+x,350+y,50,0);
 DrawArc(550+x,350+y,30,220,330);
 glPointSize(10.0);
 glBegin(GL_POINTS);
 glVertex2f(535+x,365+y);
 glVertex2f(565+x,365+y);
 glEnd();
 glBegin(GL_LINE_STRIP);
 glVertex2f(550+x,350+y);
 glVertex2f(550+x,395+y);
 glVertex2f(540+x,390+y);
 glVertex2f(560+x,390+y);
 glVertex2f(550+x,395+y);
 glEnd();
 
 glBegin(GL_LINE_STRIP);
 glVertex2f(550+x,350+y);
 glVertex2f(585+x,350+y);
 glVertex2f(580+x,360+y);
 glVertex2f(580+x,340+y);
 glVertex2f(585+x,350+y);
 glEnd();
 glutPostRedisplay();
 glutSwapBuffers();
}

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(1.0);
gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void background()
{
    glClear(GL_COLOR_BUFFER_BIT);
	sea();
    island();
    sky(); 
    drawtree();
    glutPostRedisplay();
    glutSwapBuffers();
}

void display()
{ 
	
  background();  
  if(sequence==0)
  {
    start() ;
    sequence=1;
    count=0;
    sleep(3);
  }  
  else if(sequence==1)
  {
	sleep(2);
    sequence1();
    sequence=2;
    sleep(3);
  }  
  else if(sequence==2)
  {
    sequence2();
    sequence=3;
    sleep(5);
  } 
  else if(sequence==3)
  {
    happy(0,0);
    sleep(1);
    speaktext(st[count]);
    count=4;
    sequence=4;
    sleep(1);
  }
  else if(sequence==4)
  {
    sad(0,0);
    sleep(1);
    speaktext(st[count]);
    count=5;
    sequence=5;
    sleep(1);
  }  
  else if(sequence==5)
  {
    knowledge(0,0);
    sleep(1);
    speaktext(st[count]);
    count=6;
    sleep(1);
    speaktext(st[count]);
    count=7;
    sequence=6;
  } 
  else if(sequence==6)
  {
    love(-250,-100);
    speaktext(st[count]);
    count=8;
    sequence=7;
    sleep(1);
  } 
  else if(sequence==7)
  {
	background();
	speaktext(st[count]);
    count=9;
    ship();
    speaktext(st[count]);
    count=10;
    sleep(1);
    sequence=8;
    //sleep(2);
  } 
  else if(sequence==8)
  {
	love(-250,-100);
	speaktext(st[count]);
	sleep(1);
    count=11;
    sequence=9;
  } 
  else if(sequence==9)
  {
	love(-250,-100);
    speaktext(st[count]);
    sleep(1);
    sequence=10;
    count=12;
  } 
  else if(sequence==10)
  {
	ship();
	richness(-600,200);
	love(-250,-100);
    speaktext(st[count]);
    sleep(1);
    count=13;
    sequence=11;
  } 
  else if(sequence==11)
  {
	ship();
	richness(-600,200);
	love(-250,-100);
    speaktext(st[count]);
    sleep(1);
    sequence=12;
    count=14;
  }
  else if(sequence==12)
  {
	ship();
	richness(-600,200);
	love(-250,-100);
    speaktext(st[count]);
    count=15;
    speaktext(st[count]);
    sequence=13;
    count=16;
  }
  else if(sequence==13)
  {
	background();
	ship();
	sad(-450,200);
	love(-250,-100);
    speaktext(st[count]);
    sequence=14;
    count=17;
  }
  else if(sequence==14)
  {
	ship();
	sad(-450,200);
	love(-250,-100);
    speaktext(st[count]);
    sequence=15;
    count=18;
  }
  else if(sequence==15)
  {
	ship();
	sad(-450,200);
	love(-250,-100);
    speaktext(st[count]);
    sequence=16;
    count=19;
  }
  else if(sequence==16)
  {
	background();
	ship();
	happy(-450,200);
	love(-250,-100);
    speaktext(st[count]);
    count=20;
    speaktext(st[count]);
    sequence=17;
    count=21;
  }
  else if(sequence==17)
  {
    background();
	ship();
	love(-250,-100);
    speaktext(st[count]);
    sequence=18;
    count=22;
  }
  else if(sequence==18)
  {
	ship();
	love(-250,-100);
    speaktext(st[count]);
    count=23;
    speaktext(st[count]);
    sequence=19;
    count=24;
  }
  else if(sequence==19)
  {
	ship();
	love(-250,-100);
    speaktext(st[count]);
    sequence=20;
    count=25;
  }
  else if(sequence==20)
  {
	ship();
	love(-250,-100);
    speaktext(st[count]);
    sequence=21;
    count=26;
  }
  else if(sequence==21)
  {
	background();
	ship();
	love(-250,-100);
	knowledge(-200,0);
    speaktext(st[count]);
    sequence=22;
    count=27;
  }
  else if(sequence==22)
  {
	ship();
	love(-250,-100);
	knowledge(-200,0);
	time(-450,100); 
    speaktext(st[count]);
    sequence=23;
    count=28;
  }
  else if(sequence==23)
  {
	ship();
	love(-250,-100);
	time(-450,100); 
    speaktext(st[count]);
    sequence=24;
    count=29;
  }
  else if(sequence==24)
  {
	ship();
	knowledge(-200,0);
	love(-250,-100); 
    speaktext(st[count]);
    sequence=25;
    count=30;
  }
  else if(sequence==25)
  {
	love(-250,-100);
	knowledge(-200,0);
	time(-250,50); 
    speaktext(st[count]);
    sequence=26;
    count=31;
  }
  else
  {
	Printtext(.9,.5,.5,"THE END",505,200);
  }
  glutPostRedisplay();
  glutSwapBuffers();
}

void thread_method() 
{
	sleep(3);
    system("aplay music.wav");
    exit(0);
}
void displaymain()
{
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Circle");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	std::thread t2(displaymain);
	std::thread t1(thread_method);
	t2.join();
	t1.join();
	return 0;
}
