// Um programa OpenGL que exemplifica a visualização de objetos 3D com a inserção de uma fonte de luz.
// Este código está baseado nos códigos:
// ==> "Iluminacao.c" de Isabel H. Manssour (https://www.inf.pucrs.br/~manssour/OpenGL/Iluminacao.html).
// ==> "Interacao.c" de Isabel H. Manssour (https://www.inf.pucrs.br/~manssour/OpenGL/Eventos.html).
// ==> "braco.h" de Agostinho de Medeiros Brito Júnior (https://www.dca.ufrn.br/~ambj/opengl/transformacoes.html).


#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

#define MESH 0
#define TEAPOT 1
#define CUBE 2
#define SPHERE 3
#define CONE 4
#define TORUS 5
#define ICOSAHEDRON 6
#define OCTAHEDRON 7
#define TETRAHEDRON 8
#define DODECAHEDRON 9
// numero de cores que podem ser selecionadas
#define NUM_CORES 6

// declaração de variáveis globais
static int shape = 1, translationX = 0, translationY = 0, rotationX = 0, rotationY = 0, rotationZ = 0;
GLfloat angle, f_aspect;

static int projOrtho = 0; // controla tipo de projecao 
static GLubyte corObjeto[3] = {255, 0, 0}; // armazena valores RGB da cor de objeto selecionada com o mouse
static GLubyte corFundo[3] = {0, 0, 0}; // armazena valores RGB da cor de fundo selecionada com o mouse

void colorirQuadradoCor(int i) {
	switch(i){
		case 1: 
			glColor3f(0.0, 1.0, 0.0); // verde
			break;
		case 2: 
			glColor3f(1.0, 0.0, 0.0); // vermelho
			break;
		case 3: 
			glColor3f(0.0, 0.0, 1.0); // azul
			break;
		case 4: 
			glColor3f(0.8, 0.6, 0.1); // laranja
			break;
		case 5: 
			glColor3f(0.6, 0.6, 0.6); // cinza
			break;
		case 6: 
			glColor3f(1.0, 1.0, 0.0); // amarelo	
			break;
	}
}

void drawQuadradoCor() {
	for(int i  = 1; i <= NUM_CORES; i++){

		colorirQuadradoCor(i);

		glPushMatrix();
		glTranslatef(10 * i, 75, 0); //desloca para a posicao que o quadrado sera desenhado
		glBegin(GL_QUADS);
			glVertex3f(-5, 5, 0);
			glVertex3f(-5, -5, 0);
			glVertex3f(5, -5, 0);
			glVertex3f(5, 5, 0);
		glEnd();
		glPopMatrix();
	}
}

// função para desenhar uma malha de triângulos 3D
void drawTriangleMesh(char file_name[])
{

	/*************** implementar *************/

}


// função para desenhar objetos
void draw(){

	switch(shape){
		
		case TEAPOT:
			glutSolidTeapot(50.0f);
			break;

		case CUBE:
			glutSolidCube(50.0f);
			break;

		case SPHERE:
			glutSolidSphere(50.0, 50.0, 50.0);
			break;

		case CONE:
			glutSolidCone(50.0, 50.0, 50.0, 50.0);
			break;

		case TORUS:
			glutSolidTorus(10.0, 50.0, 50.0, 50.0);
			break;

		case ICOSAHEDRON:
			glScalef(50.0, 50.0, 50.0);
			glutSolidIcosahedron();
			break;

		case OCTAHEDRON:
			glScalef(50.0, 50.0, 50.0);
			glutSolidOctahedron();
			break;

		case TETRAHEDRON:
			glScalef(50.0, 50.0, 50.0);			
			glutSolidTetrahedron();
			break;

		case DODECAHEDRON:
			glScalef(50.0, 50.0, 50.0);
			glutSolidDodecahedron();
			break;

		case MESH:
			drawTriangleMesh("dragon.obj");
			break;
		default:
			break;
	}		
				

}

// função callback chamada para fazer o desenho
void display(void)
{
	// limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// cor do objeto
	glColor3f(corObjeto[0]/255.0, corObjeto[1]/255.0, corObjeto[2]/255.0);

	glPushMatrix();

	        // cria matrizes de transformação
		glRotatef ((GLfloat) rotationX, 1.0, 0.0, 0.0);
		glRotatef ((GLfloat) rotationY, 0.0, 1.0, 0.0);
		glRotatef ((GLfloat) rotationZ, 0.0, 0.0, 1.0);	

		glTranslatef ((GLfloat) translationX, 0.0, 0.0);
		glTranslatef (0.0, (GLfloat) translationY, 0.0);

		// desenha o objeto
		draw();


	glPopMatrix();
 	
 	glDisable(GL_LIGHTING); // desabilita luz para desenhar os quadrados de selecao de cor
	drawQuadradoCor();		// desenha quadrados de selecao de cor
	glEnable(GL_LIGHTING);  // habilita luz novamente


	glutSwapBuffers();
}



// inicializa parâmetros de rendering
void init(void)
{ 
	GLfloat luz_ambiente[4]={0.2, 0.2, 0.2, 1.0}; 
	GLfloat luz_difusa[4]={0.7, 0.7, 0.7, 1.0};	 // "cor" 
	GLfloat luz_especular[4]={1.0, 1.0, 1.0, 1.0};    // "brilho" 
	GLfloat posicao_luz[4]={0.0, 50.0, 50.0, 1.0};

	// capacidade de brilho do material
	GLfloat especularidade[4]={1.0, 1.0, 1.0, 1.0}; 
	GLint espec_material = 60;

 	// especifica que a cor de fundo da janela será preta
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

	// define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS, espec_material);

	// ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);

	// define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz );

	// habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);

	// habilita o uso de iluminação
	glEnable(GL_LIGHTING);  

	// habilita a luz de número 0
	glEnable(GL_LIGHT0);

	// habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	// habilita normalização dos vetores após as transformações
	glEnable(GL_RESCALE_NORMAL);

    	angle=45;

}

// função usada para especificar o volume de visualização
void visualization(void)
{
	// especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);

	// inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// especifica a projeção perspectiva ou ortografica
	if(projOrtho)
		glOrtho(-80, 80, -80, 80, 0.4, 500);
	else
    	gluPerspective(angle, f_aspect, 0.4, 500);

	// especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);

	// inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// especifica posição do observador e do alvo
    	gluLookAt(0, 0, 200, 0, 0, 0, 0, 1, 0);

}

// função callback chamada quando o tamanho da janela é alterado 
void reshape(GLsizei w, GLsizei h)
{
	// para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// especifica o tamanho da viewport
        glViewport(0, 0, w, h);
 
	// calcula a correção de aspecto
	f_aspect = (GLfloat)w/(GLfloat)h;

	// especifica volume da visualização
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();

}

// função callback chamada para gerenciar eventos do mouse
void mouse(int button, int state, int x, int y)
{
	// Muda cor do objeto ao selecionar cor com o mouse
	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN) {  
			int h = glutGet(GLUT_WINDOW_HEIGHT); // pega altura da janela
			// glReadPixels pega cor do pixel da posicao x, y clickada com o mouse
			// os parametros x e y começam no canto inferior esquerdo da tela, h- y faz começar no canto superior esquerdo
			// 1, 1 representam largura e altura do pixel clicado
			// variavel corObjeto armazena os valores r, g, b de 0-255
			glReadPixels(x, h-y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE , corObjeto);	
		}
	}
	// Muda cor do fundo ao selecionar cor com o mouse
	if (button == GLUT_RIGHT_BUTTON){
		if (state == GLUT_DOWN) {  
			int h = glutGet(GLUT_WINDOW_HEIGHT); 
			glReadPixels(x, h-y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE , corFundo);
			glClearColor(corFundo[0]/255.0, corFundo[1]/255.0, corFundo[2]/255.0, 255.0);	
		}
	}

	// especifica volume da visualização
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();
}


// teclado
void keyboard (unsigned char key, int x, int y){

	switch (key) {

		//muda projecao
		case 'o':
			projOrtho = 1;
			break;
		case 'p':
			projOrtho = 0;
			break;

		// rotação em torno do eixo X
		case 'x':
			rotationX = (rotationX + 5) % 360;
			break;

		case 'X':
			rotationX = (rotationX - 5) % 360;
			break;

		// rotação em torno do eixo Y
		case 'y':
			rotationY = (rotationY + 5) % 360;
			break;

		case 'Y':
			rotationY = (rotationY - 5) % 360;		
			break;

		// rotação em torno do eixo Z
		case 'z':
			rotationZ = (rotationZ + 5) % 360;
			break;

		case 'Z':
			rotationZ = (rotationZ - 5) % 360;		
			break;


		// mudança de objetos
		case '0':
			shape = MESH;
			break;

		case '1': 
			shape = TEAPOT;
			break;
		
		case '2': 
			shape = CUBE;
			break;

		case '3': 
			shape = SPHERE;
			break;
		
		case '4':
			shape = CONE;
			break;
		
		case '5': 
			shape = TORUS;
			break;

		case '6': 
			shape = ICOSAHEDRON;
			break;

		case '7':
			shape = OCTAHEDRON;
			break;

		case '8': 
			shape = TETRAHEDRON;
			break;

		case '9': 
			shape = DODECAHEDRON;
			break;
		
		// fecha a janela 
		case 27:
			exit(0);
			break;

		default:
			break;
	}

	// especifica volume da visualização
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();
}


// teclas especiais
void specialkey (int key, int x, int y){

	switch (key) {
		// translação na direção do eixo X
		case GLUT_KEY_RIGHT:
			translationX = (translationX + 5);
			break;

		case GLUT_KEY_LEFT:
			translationX = (translationX - 5);		
			break;

		// rotação na direção do eixo Y
		case GLUT_KEY_UP:
			translationY = (translationY + 5);
			break;

		case GLUT_KEY_DOWN:
			translationY = (translationY - 5);		
			break;

		default:
			break;
	}

	// especifica volume da visualização
	visualization();

	// exibe objetos na tela
	glutPostRedisplay();

}


// programa principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Visualizacao 3D");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);	
	glutMouseFunc(mouse);
	//glutPassiveMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkey);
	glutMainLoop();

	return 0;
}



