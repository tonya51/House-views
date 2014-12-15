/*
 *
 *
*/

#include <Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RAD60 1.047198

int win; 
GLfloat range=60.0; 

void myinit(void){

	glEnable(GL_BLEND);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-range, range, -range, range, -range, range);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
glShadeModel (GL_FLAT);
    glNewList(1, GL_COMPILE);
		glBegin(GL_POLYGON);
			glVertex3f(5.0, 0.0, -10.0);
			glVertex3f(5.0, 0.0, 10.0);
			glVertex3f(-5.0, 0.0, 10.0);
			glVertex3f(-5.0, 0.0, -10.0);
		glEnd();
	glEndList();
	glNewList(2, GL_COMPILE);
		glBegin(GL_POLYGON);
			glVertex3f(5.0, 0.0, 0.0);
			glVertex3f(-5.0, 0.0, 0.0);
			glVertex3f(0.0, 5*tan(RAD60), 0.0);
		glEnd();
	glEndList();
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //----------or8ogwnio----------
    //katw
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(0.0,-5.0,0.0);
	glCallList(1);
	glPopMatrix();
	//de3ia
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0,-5.0,0.0);
	glCallList(1);
	glPopMatrix();
	//panw
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0,5.0,0.0);
	glCallList(1);
	glPopMatrix();
	//aristera
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0,-5.0,0.0);
	glCallList(1);
	glPopMatrix();
	
	//mprosta
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 10.0);
	glRotatef(90.0,1.0,0.0,0.0);
    glScalef(1.0,1.0,0.5);
    glCallList(1);
	glPopMatrix();
	
	//pisw
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -10.0);
	glRotatef(90.0,1.0,0.0,0.0);
    glScalef(1.0,1.0,0.5);
    glCallList(1);
	glPopMatrix();
	
	//---------- skeph----------
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glTranslatef(-2.5, 5.0+2.5*tan(RAD60), 0.0);
	glRotatef(60.0,0.0,0.0,1.0);
    glCallList(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glTranslatef(2.5, 5.0+2.5*tan(RAD60), 0.0);
	glRotatef(-60.0,0.0,0.0,1.0);
    glCallList(1);
	glPopMatrix();
	
    glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glTranslatef(0.0, 5.0, 10.0);
	glCallList(2);
	glPopMatrix();
	
    glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glTranslatef(0.0, 5.0, -10.0);
	glCallList(2);
	glPopMatrix();
	
//	glutWireCube (25.0);
    glutSwapBuffers();

}

void chooseFromMenu(int option){
	
	int i;
    if(option>=1&&option<=4){
        //range=60.0;
   	    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-range, range, -range, range, -range, range);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        if(option == 1){
	        glTranslatef(0.0,0.0,+10.0);
        }
        else if(option == 2){
	        glTranslatef(0.0,0.0,+10.0);
	        glRotatef(90.0,1.0,0.0,0.0);
        }
	    else if(option == 3){
            glTranslatef(0.0,0.0,+10.0);
	        glRotatef(-90.0,0.0,1.0,0.0);
       }
       else {
	        gluLookAt (25.0, 25.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
       }
       glutPostRedisplay();                     
    }
    else if(option==5){
         glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0, 1.0,1.0, 50.0);
         glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt (20.0, 0.0, 40.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
          
          glutPostRedisplay();
    }
    else{
		glutDestroyWindow(win);
		exit(0);
	}
	
}
void buildMenu(){
	
	int menu;
	menu = glutCreateMenu(chooseFromMenu);
	glutAddMenuEntry("Prosopsh", 1);
	glutAddMenuEntry("Katopsh", 2);
	glutAddMenuEntry("Plagia Dexia", 3);
	glutAddMenuEntry("Isometrikh", 4);
	glutAddMenuEntry("Prooptikh 2 Shmeiwn", 5);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(0,0);
	glutCreateWindow("House 1");
	glutDisplayFunc(display);
//	glutIdleFunc(idle);
	buildMenu();
	glEnable(GL_DEPTH_TEST); 
	myinit();
	glutMainLoop();

}
