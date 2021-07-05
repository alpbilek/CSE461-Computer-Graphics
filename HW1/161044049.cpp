#include <stdio.h>  
#include <GL/gl.h>  
#include <GL/glut.h>  
#include <math.h>

// Function Prototemp_ypes
void specialKeys();

double y_axis=0; 
double x_axis=0;
double z_axis=0;
double temp_x=0;
double temp_y=0; 
double temp_z=0; 
double sx=0;
double sy=0; 

void draw()
{
//Multi-colored side - FRONT
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (1, 0.1, 0.0);
    glVertex3f (1, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    /*wall1*/
     glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (1, 0.575, 0.5);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /*bottom*/
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (1, 0.1, 0);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0);
    glEnd();

    /* wall2*/
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* rightwall*/
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.0);
    glVertex3f (1, 0.575, 0.0);
    glVertex3f (1, 0.575, 0.5);
    glEnd();

    /* left roof*/
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f (1, 0.575, 0.0);
    glVertex3f (1, 0.575, 0.5);
    glVertex3f (1, 0.8, 0.25);
    glEnd();

    /* right roof*/
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* roof */
    glColor3f (.55, 0.35, .2);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (1, 0.575, 0.0);
    glVertex3f (1, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*back roof */
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (1, 0.575, 0.5);
    glVertex3f (1, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* door */
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.47, 0.105, 0.0);
    glVertex3f (0.65, 0.105, 0.0);
    glVertex3f (0.65, 0.46, 0.0);
    glVertex3f (0.47, 0.46, 0.0);
    glEnd();

    /* window 1 */
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25, 0.0);
    glVertex3f (0.83, 0.25, 0.0);
    glVertex3f (0.83, 0.4, 0.0);
    glVertex3f (0.72, 0.4, 0.0);
    glEnd();

    /* window 2 */
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25, 0.0);
    glVertex3f (0.38, 0.25, 0.0);
    glVertex3f (0.38, 0.4, 0.0);
    glVertex3f (0.27, 0.4, 0.0);
    glEnd();
}
 void show(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef( 15, 0.0, 1.0, 0.0 ); 
    glTranslatef( temp_x, 0.0, 0.0 );      
    glTranslatef( 0.0, temp_y, 0.0 );
    glTranslatef( 0.0, 0.0, temp_z);	
    glRotatef( x_axis, 1.0, 0.0, 0.0 );
    glRotatef( y_axis, 0.0, 1.0, 0.0 );
    glRotatef( z_axis, 0.0, 0.0, 1.0); 
    glScalef( sx, sy, 2.0 );  
    glRotatef( 15, 0.0, 1.0, 0.0 ); 
    glRotatef( 25, 1.0, 0.0, 0.0 ); 
    glRotatef( 5, 0.0, 0.0, 1.0 );
    draw();
    glFlush();
    glutSwapBuffers();
}

void specialKeys( int key, int x, int y ) {
    if (key == GLUT_KEY_RIGHT){                  //Translatation along forward x-axis 
        temp_x+=0.1; 
    }
    else if (key == GLUT_KEY_LEFT){       //Translatation along backward x-axis
        temp_x-=0.1; 
    }
    else if (key == GLUT_KEY_UP){         //Translatation along upward y-axis
        temp_y+=0.1;
    }
    else if (key == GLUT_KEY_DOWN){              //Translatation along downward y-axis
        temp_y-=0.1; 
    }
    glutPostRedisplay();
}
 
void win_init()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("161044049_Assignment_1");
	glEnable(GL_DEPTH_TEST);
}
void keyboard( unsigned char key, int x, int y )
{

    switch(key){
        case 'a' ://Scaling-down
            sx-=0.2;
            sy-=0.2;
            break;
        case 'd'://Scaling-UP
            sx+= 0.2;
            sy+= 0.2;   
            break;
        case 'w'://Rotation about Z axis
            z_axis += 3;
            break;
        case 's': //Rotation about Z axis
            z_axis -= 3;
            break;
        case 'q'://Rotation about Y axis
            y_axis += 3;
            break;
        case 'e'://Rotation about Y axis
            y_axis -= 3;
            break;
        case 'z'://Rotation about X axis
            x_axis += 3;
            break;
        case 'x'://Rotation about X axis
            x_axis -= 3;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    win_init();
    glutDisplayFunc(show);
    glutKeyboardFunc(keyboard);  
    glutSpecialFunc(specialKeys);
    glutMainLoop();  
   return 0;
 }
