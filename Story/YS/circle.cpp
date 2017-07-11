#include<GL/glut.h>
#include <GL/gl.h>
#include<math.h>

void DrawArc(float cx, float cy, float r, int degree1,int degree2) 
{ 
	int num_segments=360;
	glBegin(GL_LINE_STRIP);
	
	for(int i = degree1; i < degree2; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void DrawSegment(float cx, float cy, float r, int degree1,int degree2,int shade) 
{ 
	int num_segments=360;
	if(shade==0)
	  glBegin(GL_LINE_LOOP); 
	if(shade==1)
	  glBegin(GL_POLYGON);
	for(int i = degree1; i < degree2; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void DrawCircle(float cx, float cy, float r,int shade) 
{ 
	int num_segments=360,degree=360;
	if(shade==0)
	  glBegin(GL_LINE_LOOP); 
	if(shade==1)
	  glBegin(GL_POLYGON);
	for(int i = 0; i < degree; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void DrawSector(float cx, float cy, float r, int degree,int shade) 
{ 
	int num_segments=360;
	if(shade==0)
	  glBegin(GL_LINE_LOOP); 
	if(shade==1)
	  glBegin(GL_POLYGON);
	glVertex2f(cx,cy);  
	for(int i = 0; i < degree; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}


