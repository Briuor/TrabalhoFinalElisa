#ifndef TESTES_H
#define TESTES_H

typedef struct {
  double x, y, z;
} vertice;

typedef struct {
  int a, b, c;
} face;

void colorirQuadradoCor(int i);
void drawQuadradoCor();
void drawSetas();
void drawTriangleMesh(char file_name[]);
void draw();
void display(void);
void init(void);
void visualization(void);
void reshape(GLsizei w, GLsizei h);
int verificaSetaClicada(int x, int y);
//void mouseMotion(int x, int y);
void mouse(int button, int state, int x, int y);
void keyboard (unsigned char key, int x, int y);
void specialkey (int key, int x, int y);

vertice getVertice(char str[]);
face getFace(char str[]);
void limpar();
void transformar();
void escreverArquivo();
void lerArquivo();


#endif
