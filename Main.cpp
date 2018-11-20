// Um programa OpenGL que exemplifica a visualização de objetos 3D com a inserção de uma fonte de luz.
// Este código está baseado nos códigos:
// ==> "Iluminacao.c" de Isabel H. Manssour (https://www.inf.pucrs.br/~manssour/OpenGL/Iluminacao.html).
// ==> "Interacao.c" de Isabel H. Manssour (https://www.inf.pucrs.br/~manssour/OpenGL/Eventos.html).
// ==> "braco.h" de Agostinho de Medeiros Brito Júnior (https://www.dca.ufrn.br/~ambj/opengl/transformacoes.html).

#include <bits/stdc++.h>
#include <GL/glut.h>
#include "Testes.h"

using namespace std;

// programa principal
int main(int argc, char** argv) {
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
