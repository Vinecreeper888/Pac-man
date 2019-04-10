#include<ctype.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define M_PI 3.1415926
#define false 0
#define true 1
const int BOARD_X = 31; const int BOARD_Y = 28;
int board_array[BOARD_X][BOARD_Y] = {{8,5,5,5,5,5,5,5,5,5,5,5,5,1,1,5,5,5,5,5,5,5,5,5,5,5,5,7},
{6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6}, {6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6}, {6,0,2,11,11,4,0,2,11,11,11,4,0,2,4,0,2,11,11,11,4,0,2,11,11,4,0,6}, {6,0,9,3,3,10, 0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,9,3,3,10,0,6}, {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6}, {6,0,8,1,1,7,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,8,1,1,7,0,6}, {6,0,9,3,3,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,3,3,10,0,6}, {6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6}, {9,5,5,5,5,7,0,2,11,1,1,7,0,2,4,0,8,1,1,11,4,0,8,5,5,5,5,10}, {0,0,0,0,0,6,0,2,11,3,3,10,0,9,10,0,9,3,3,11,4,0,6,0,0,0,0,0}, {0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0}, {0,0,0,0,0,6,0,2,4,0,8,5,5,1,1,5,5,7,0,2,4,0,6,0,0,0,0,0}, {5,5,5,5,5,10,0,9,10,0,6,0,0,0,0,0,0,6,0,9,10,0,9,5,5,5,5,5}, {0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0}, {5,5,5,5,5,7,0,8,7,0,6,0,0,0,0,0,0,6,0,8,7,0,8,5,5,5,5,5}, {0,0,0,0,0,6,0,2,4,0,9,5,5,5,5,5,5,10,0,2,4,0,6,0,0,0,0,0}, {0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0}, {0,0,0,0,0,6,0,2,4,0,8,1,1,1,1,1,1,7,0,2,4,0,6,0,0,0,0,0}, {8,5,5,5,5,10,0,9,10,0,9,3,3,11,11,3,3,10,0,9,10,0,9,5,5,5,5,7}, {6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6}, {6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6}, {6,0,9,3,11,4,0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,2,11,3,10,0,6}, {6,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,6}, {2,1,7,0,2,4,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,2,4,0,8,1,4}, {2,3,10,0,9,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,10,0,9,3,4}, {6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6}, {6,0,8,1,1,1,1,11,11,1,1,7,0,2,4,0,8,1,1,11,11,1,1,1,1,7,0,6}, {6,0,9,3,3,3,3,3,3,3,3,10,0,9,10,0,9,3,3,3,3,3,3,3,3,10,0,6}, {6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6}, {9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10}};

int pebble_array[BOARD_X][BOARD_Y] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, {0,3,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,3,0}, {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0}, {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, {0,3,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,3,0}, {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0}, {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0}, {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0}, {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0}, {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
GLubyte list[5];
int tp_array[31][28];
int pebbles_left;
double speed1 = 0.1; 
double angle1 = 90; 
double a=13.5, b=23;
bool animate = false;
int lives=3;
int points=0;
void keys();
unsigned char ckey='w';
void mykey(unsigned char key,int x,int y); 
bool Open(int a,int b);

int num_ghosts = 4;
class Ghost
{
	private:
	public:
	bool edible;
	int edible_max_time;
	int edible_timer; 
	bool eaten;
	bool transporting; 
	float color[3];
	double speed; 
	double max_speed; 
	bool in_jail;
	int jail_timer; 
	double angle; 
	double x, y;
	Ghost(double, double);
	~Ghost(void);
	void Move(); //Move the Monster
	void Update(void); //Update Monster State
	void Chase(double, double, bool*); //Chase Pacman
	bool Catch(double, double); //collision detection
	void Reinit(void);
	void Vulnerable(void);
	void Draw(void); //Draw the Monster 
	void game_over(void);
};

void Pac(void)
{
	//Draw Pacman
	glColor3f(0,1,1);
	glPushMatrix();
	glTranslatef(a,-b,0);
	glTranslatef(0.5,0.6,0);
	glTranslatef((float)BOARD_X/-2.0f,(float)BOARD_Y/2.0f,0.5); 
	glutSolidSphere(0.5,15,10);
	glPopMatrix();
}



void init()
{
/* float color[4];
Enable Lighting. glEnable(GL_LIGHT0); glEnable(GL_LIGHTING);
Ambient And Diffuse Lighting
glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); glEnable(GL_COLOR_MATERIAL);
color[0] = 1.0f; color[1] = 1.0f; color[2] = 0.0f; color[3] = 0.0f; glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
color[0] = 1.0f; color[1] = 0.0f; color[2] = 1.0f; color[3] = 1.0f; glLightfv(GL_LIGHT0, GL_AMBIENT, color);*/

glEnable(GL_NORMALIZE);
glMatrixMode(GL_PROJECTION); glLoadIdentity();
gluPerspective(60,1.33,0.005,100);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(-1.5, 0, 40, -1.5, 0, 0, 0.0f,1.0f,0.0f);
}

Ghost *ghost[4]; 
Ghost::~Ghost(void){}
Ghost::Ghost(double tx, double ty)
{
	tx = x;
	ty = y;
	angle = 90;
	speed = max_speed=1;
	     
	color[0] = 1;
	color[1] = 0;
	color[2] = 0;
	eaten = false; 
	edible_max_time =300; 
	edible = false;
	in_jail = true;
	jail_timer = 30;
}

void Ghost::Reinit(void)
{
	edible = false;
	in_jail = true; 
	angle = 90;
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize(1200, 780);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Pac GL 3D");
	init();
	//glutDisplayFunc(RenderScene);
	//create_list_lib();
	//glutKeyboardFunc(mykey);
	//glutSpecialFunc(specialDown);
	//glutSpecialUpFunc(specialUp);
	glEnable(GL_DEPTH_TEST);
	int start_x[4] = {11,12,15,16};
	for (int ISO = 0; ISO < num_ghosts; ISO++)
	{
		ghost[ISO] = new Ghost(start_x[ISO],14);
		//ghost[ISO] -> x = start_x[ISO];
	}
	float ghost_colors[4][3] = {{255,0,0},{120,240,120},{255,200,200},{255,125,0}};
	int ISO;

	for (ISO = 0; ISO < num_ghosts; ISO++)
	{
		ghost[ISO]->x = start_x[ISO];
		ghost[ISO]->y = 14;
		ghost[ISO]->eaten = false;
		ghost[ISO]->max_speed = 0.1 - 0.01*(float)ISO;
		ghost[ISO]->speed = ghost[ISO]->max_speed;
		//colorize ghosts
		for (int j = 0; j < 3; j++)
			ghost[ISO]->color[j] = ghost_colors[ISO][j]/255.0f;
	}
	for ( ISO = 0; ISO < BOARD_X; ISO++)
	{
		for (int j = 0; j < BOARD_Y; j++)
		{
			tp_array[ISO][j] = pebble_array[ISO][j];
		}
	}
	pebbles_left = 244;
	glShadeModel(GL_SMOOTH);
	glutMainLoop();
	return 0;
}
