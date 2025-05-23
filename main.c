#include <stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "bandera3d.h"

int main(int argc, char** argv) {
    printf("Examen parcial de %s \n",get_carnet());
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(700, 700);
    glutCreateWindow(get_carnet());
    glClearColor(0.8, 0, 0, 1);
    inicializar_bandera3d();
    glutDisplayFunc(dibujar_bandera3d);
    glutKeyboardFunc(rotar_bandera_3d);
    glutMainLoop();
    printf("=== fin === %s",get_carnet());
    return (EXIT_SUCCESS);
}