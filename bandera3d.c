#include "bandera3d.h"
#include <stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include <math.h>
#define PI 3.14159265

float radio = 2, calx, caly;
float angleX = 0.0f; // Ángulo de rotación en el eje X
float angleY = 0.0f; // Ángulo de rotación en el eje Y
float angleZ = 0.0f; // Ángulo de rotación en el eje Z


void Cilindro(float altura, float radio, int Cveces) {
    glColor3f(252, 227, 0);
    int i;
    float angle = 2 * PI / Cveces;

    glBegin(GL_TRIANGLE_STRIP);
    for (i = 0; i <= Cveces; i++) {
        float x = radio * cos(i * angle) - 1.34f;
        float z = radio * sin(i * angle) - 0.2;

        glVertex3f(x, altura, z);
        glVertex3f(x, -2.5, z);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    
    for (i = 0; i <= Cveces; i++) {
        float x = radio * cos(i * angle) - 1.34f;
        float z = radio * sin(i * angle) - 0.2;

        glVertex3f(x, altura, z);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    
    for (i = Cveces; i >= 0; i--) {
        float x = radio * cos(i * angle) - 1.34f;
        float z = radio * sin(i * angle) - 0.2;

        glVertex3f(x, -2.5, z);
    }
    glEnd();
}

void Circulo(float radio, int porciones, int pilas) {
    int i, j;
    glColor3f(252, 227, 0);
    for (i = 0; i < porciones; i++) {
        float lat0 = PI * (-0.5 + (float) (i + 1) / porciones);
        float z0 = radio * sin(lat0);
        float zr0 = radio * cos(lat0);

        float lat1 = PI * (-0.5 + (float) i / porciones);
        float z1 = radio * sin(lat1);
        float zr1 = radio * cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= pilas; j++) {
            float lng = 2 * PI * (float) (j - 1) / pilas;
            float x = cos(lng);
            float y = sin(lng);

            glNormal3f(x * zr0 - 1.353f, y * zr0 + 1, z0 - 0.2);
            glVertex3f(x * zr0 - 1.353f, y * zr0 + 1, z0 - 0.2);
            glNormal3f(x * zr1 - 1.353f, y * zr1 + 1, z1 - 0.2);
            glVertex3f(x * zr1 - 1.353f, y * zr1 + 1, z1 - 0.2);
        }
        glEnd();
    }
}

void bandera(){
     glBegin(GL_QUADS); // Especifica que se dibujarán caras cuadradas

    // Cara frontal 
    glColor3f(0.0f, 0.0f, 1.0f);
    //x y z
    glVertex3f(-1.0f, -0.8f, -0.1f);
    glVertex3f(1.6f, -0.8f, -0.1f);
    glVertex3f(1.6f, -0.3f, -0.1f);
    glVertex3f(-1.0f, -0.3f, -0.1f);

    // Cara posterior 

    glVertex3f(-0.8f, -0.8f, -0.2f);
    glVertex3f(1.6f, -0.8f, -0.2f);
    glVertex3f(1.6f, -0.3f, -0.2f);
    glVertex3f(-0.8f, -0.3f, -0.2f);

    // Cara superior 

    glVertex3f(-1.0f, -0.3f, -0.1f);
    glVertex3f(1.6f, -0.3f, -0.1f);
    glVertex3f(1.6f, -0.3f, -0.2f);
    glVertex3f(-1.0f, -0.3f, -0.2f);

    // Cara inferior 
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -0.8f, -0.1f);
    glVertex3f(1.6f, -0.8f, -0.1f);
    glVertex3f(1.6f, -0.8f, -0.2f);
    glVertex3f(-1.0f, -0.8f, -0.2f);

    // Cara derecha

    glVertex3f(1.6f, -0.8f, -0.1f);
    glVertex3f(1.6f, -0.8f, -0.2f);
    glVertex3f(1.6f, -0.3f, -0.2f);
    glVertex3f(1.6f, -0.3f, -0.1f);

    // Cara  

    glVertex3f(-1.0f, -0.8f, -0.1f);
    glVertex3f(-1.0f, -0.8f, -0.2f);
    glVertex3f(-1.0f, -0.3f, -0.2f);
    glVertex3f(-1.0f, -0.3f, -0.1f);

    //--------------------------------------------------------------------------medio
    // Cara frontal (blanco)
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex3f(-1.0f, -0.3f, -0.1f);
    glVertex3f(1.6f, -0.3f, -0.1f);
    glVertex3f(1.6f, 0.2f, -0.1f);
    glVertex3f(-1.0f, 0.2f, -0.1f);

    // Cara posterior 
    glVertex3f(-1.0f, -0.3f, -0.2f);
    glVertex3f(1.6f, -0.3f, -0.2f);
    glVertex3f(1.6f, 0.2f, -0.2f);
    glVertex3f(-1.0f, 0.2f, -0.2f);

    // Cara superior 
    glVertex3f(-1.0f, 0.2f, -0.1f);
    glVertex3f(1.6f, 0.2f, -0.1f);
    glVertex3f(1.6f, 0.2f, -0.1f);
    glVertex3f(-1.0f, 0.2f, -0.1f);

    // Cara inferior 
    glVertex3f(-1.0f, -0.3f, -0.1f);
    glVertex3f(1.6f, -0.3f, -0.1f);
    glVertex3f(1.6f, -0.3f, -0.2f);
    glVertex3f(-1.0f, -0.3f, -0.2f);

    // Cara derecha 
    glVertex3f(1.6f, -0.3f, -0.1f);
    glVertex3f(1.6f, -0.3f, -0.2f);
    glVertex3f(1.6f, 0.2f, -0.2f);
    glVertex3f(1.6f, 0.2f, -0.1f);

    // Cara izquierda 

    glVertex3f(-1.0f, -0.3f, -0.1f);
    glVertex3f(-1.0f, -0.3f, -0.2f);
    glVertex3f(-1.0f, 0.2f, -0.2f);
    glVertex3f(-1.0f, 0.2f, -0.1f);

    //-----------------------------------arriba
    // Cara frontal (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.2f, -0.1f);
    glVertex3f(1.6f, 0.2f, -0.1f);
    glVertex3f(1.6f, 0.7f, -0.1f);
    glVertex3f(-1.0f, 0.7f, -0.1f);

    // Cara posterior 
    glVertex3f(-1.0f, 0.2f, -0.2f);
    glVertex3f(1.6f, 0.2f, -0.2f);
    glVertex3f(1.6f, 0.7f, -0.2f);
    glVertex3f(-1.0f, 0.7f, -0.2f);

    // Cara superior 
    glVertex3f(-1.0f, 0.7f, -0.1f);
    glVertex3f(1.6f, 0.7f, -0.1f);
    glVertex3f(1.6f, 0.7f, -0.2f);
    glVertex3f(-1.0f, 0.7f, -0.2f);

    // Cara inferior 
    glVertex3f(-1.0f, 0.2f, -0.1f);
    glVertex3f(1.6f, 0.2f, -0.1f);
    glVertex3f(1.6f, 0.2f, -0.2f);
    glVertex3f(-1.0f, 0.2f, -0.2f);

    // Cara derecha 
    glVertex3f(1.6f, 0.2f, -0.1f);
    glVertex3f(1.6f, 0.2f, -0.2f);
    glVertex3f(1.6f, 0.7f, -0.2f);
    glVertex3f(1.6f, 0.7f, -0.1f);

    // Cara izquierda 
    glVertex3f(-1.0f, 0.2f, -0.1f);
    glVertex3f(-1.0f, 0.2f, -0.2f);
    glVertex3f(-1.0f, 0.7f, -0.2f);
    glVertex3f(-1.0f, 0.7f, -0.1f);

    glEnd();
}

void contenidoEs() {
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES
    glVertex3f(0.21f, -0.19f, -0.078f); //este lo ocupamos para mandar un vertice donde tomaremos un punto 
    //base
    glVertex3f(0.49f, -0.19f, -0.078f);
    //alto
    glVertex3f(0.35f, 0.08f, -0.078f);
    glEnd();

    glColor3f(252, 227, 0);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES
    glVertex3f(0.2f, -0.2f, -0.08f); //este lo ocupamos para mandar un vertice donde tomaremos un punto 
    //base
    glVertex3f(0.5f, -0.2f, -0.08f);
    //alto
    glVertex3f(0.35f, 0.1f, -0.08f);
    glEnd();

    //mar
    glColor3f(0, 0, 255);
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.215f, -0.19f, -0.076f); //abajo

    glVertex3f(0.26f, -0.1f, -0.076f); //abajo al final

    glVertex3f(0.441f, -0.1f, -0.076f); //arriba al final

    glVertex3f(0.484f, -0.19f, -0.076f); //arriba inicio

    glEnd();

    //m5
    glColor3f(0, 153, 0);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES

    glVertex3f(0.39f, -0.14f, -0.074f); //abajo

    glVertex3f(0.455f, -0.14f, -0.074f); //abajo al final

    glVertex3f(0.42f, -0.09f, -0.074f); //arriba al final

    glEnd();

    //m4
    glBegin(GL_TRIANGLES);
    glVertex3f(0.36f, -0.14f, -0.074f); //abajo

    glVertex3f(0.43f, -0.14f, -0.074f); //abajo al final

    glVertex3f(0.395f, -0.08f, -0.074f); //arriba al final

    glEnd();

    //m3
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES

    glVertex3f(0.32f, -0.14f, -0.074f); //abajo

    glVertex3f(0.40f, -0.14f, -0.074f); //abajo al final

    glVertex3f(0.365f, -0.07f, -0.074f); //arriba al final

    glEnd();

    //m2
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES

    glVertex3f(0.29f, -0.14f, -0.074f); //abajo

    glVertex3f(0.37f, -0.14f, -0.074f); //abajo al final

    glVertex3f(0.333f, -0.06f, -0.074f); //arriba al final

    glEnd();

    //m1
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES

    glVertex3f(0.26f, -0.14f, -0.074f); //abajo

    glVertex3f(0.34f, -0.14f, -0.074f); //abajo al final

    glVertex3f(0.303f, -0.05f, -0.074f); //arriba al final

    glEnd();

    //gorrito
    glColor3f(252, 227, 0);
    //PALO 
    glBegin(GL_POLYGON);
    glVertex3f(0.345f, -0.02f, -0.074f); //alto
    glVertex3f(0.355f, -0.02f, -0.074f);
    glVertex3f(0.345f, -0.08f, -0.074f); //ancho abajo
    glVertex3f(0.355f, -0.08f, -0.074f);
    glEnd();

    glColor3f(0.902, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.340f, -0.02f, -0.074f);
    //base
    glVertex3f(0.365f, -0.02f, -0.074f);
    //alto
    glVertex3f(0.350f, 0.01f, -0.074f);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(1.0 , 0.0, 0.0);
    glVertex3f(0.34f, 0.058f, -0.074f);
    glVertex3f(0.36f, 0.058f, -0.074f);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(255.0 , 102.0, 0.0);
    glVertex3f(0.337f, 0.056f, -0.074f);
    glVertex3f(0.363f, 0.056f, -0.074f);
    glEnd();
    
      glBegin(GL_LINES);
    glColor3f(255, 255, 0.0);
    glVertex3f(0.335f, 0.054f, -0.074f);
    glVertex3f(0.366f, 0.054f, -0.074f);
    glEnd();
    
     glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.334f, 0.052f, -0.074f);
    glVertex3f(0.367f, 0.052f, -0.074f);
    glEnd();
    
     glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.333f, 0.05f, -0.074f);
    glVertex3f(0.368f, 0.05f, -0.074f);
    glEnd();
    
    //resplandor
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    radio = 0.03f;
    for (float j = 0; j < 1; j++) {
        for (float i = 0; i < 10; i += 0.5) {
            calx = radio * cos(i) + 0.35f;
            caly = radio * sin(i) - 0.01f;
            glVertex3f(calx, caly, -0.074f);
        }
        radio += 0.01;
    }
    glEnd();
    //arco
    radio = 0.3;
    glBegin(GL_POINTS);
    glPointSize(1);
    glColor3f(0, 0, 0);

    for (float i = 6.62; i > 2.8; i -= 0.001) {
        calx = radio * cos(i) + 0.35f;
        caly = radio * sin(i) + 0.0f;
        glVertex3f(calx, caly, -0.084f);
    }
    glEnd();

}

void banderas() {
    //derecha 

    glColor3f(252, 227, 0);
    //palo 1
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.395f, 0.02f, -0.074f); //abajo

    glVertex3f(0.575f, 0.14f, -0.074f); //abajo al final

    glVertex3f(0.57f, 0.135f, -0.074f); //arriba al final

    glVertex3f(0.39f, 0.01f, -0.074f); //arriba inicio

    glEnd();

    //punta
    glColor3f(252, 227, 0);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES
    glVertex3f(0.54f, 0.10f, -0.074f); //este lo ocupamos para mandar un vertice donde tomaremos un punto 
    //base
    glVertex3f(0.53f, 0.12f, -0.074f);
    //alto
    glVertex3f(0.58f, 0.14f, -0.074f);

    glEnd();


    glColor3f(0, 0, 1);
    //bandera 1
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.53f, 0.105f, -0.074f); //arriba al final

    glVertex3f(0.39f, 0.015f, -0.074f); //arriba inicio

    glVertex3f(0.435f, -0.078f, -0.074f); //abajo

    glVertex3f(0.50f, -0.045f, -0.074f); //abajo al final
    glEnd();

    glColor3f(1, 1, 1);
    //bandera 1 blanco
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.49f, 0.08f, -0.073f); //arriba al final

    glVertex3f(0.44f, 0.045f, -0.073f); //arriba inicio

    glVertex3f(0.415f, -0.038f, -0.073f); //abajo

    glVertex3f(0.435f, -0.078f, -0.073f);

    glVertex3f(0.46f, -0.055f, -0.073f);

    glEnd();


    glColor3f(252, 227, 0);
    //palo 2
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.435f, -0.08f, -0.074f); //abajo

    glVertex3f(0.598f, 0.015f, -0.074f); //abajo al final

    glVertex3f(0.60f, 0.010f, -0.074f); //arriba al final

    glVertex3f(0.43f, -0.09f, -0.074f); //arriba inicio

    glEnd();

    //punta
    glColor3f(252, 227, 0);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES
    glVertex3f(0.565f, -0.02f, -0.074f); //este lo ocupamos para mandar un vertice donde tomaremos un punto 
    //base
    glVertex3f(0.555f, -0.00f, -0.074f);
    //alto
    glVertex3f(0.60f, 0.015f, -0.074f);

    glEnd();

    glColor3f(0, 0, 1);
    //bandera 2
    glBegin(GL_POLYGON); //dibujaremos lineas
    glVertex3f(0.44f, -0.08f, -0.074f); //arriba inicio

    glVertex3f(0.565f, -0.013f, -0.074f); //arriba al final

    glVertex3f(0.55f, -0.110f, -0.074f); //arriba al final

    glVertex3f(0.495f, -0.19f, -0.074f); //arriba inicio
    glEnd();

    glColor3f(1, 1, 1);
    //bandera 2 blanco
    glBegin(GL_POLYGON); //dibujaremos lineas
    glVertex3f(0.48f, -0.06f, -0.073f); //arriba inicio

    glVertex3f(0.525f, -0.035f, -0.073f); //arriba al final

    glVertex3f(0.51f, -0.120f, -0.073f);

    glVertex3f(0.484f, -0.17f, -0.073f); //arriba al final

    glVertex3f(0.46f, -0.12f, -0.073f); //arriba inicio

    glEnd();


    //izquierda 

    glColor3f(252, 227, 0);
    //palo 1
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.305f, 0.02f, -0.074f); //abajo

    glVertex3f(0.15f, 0.14f, -0.074f); //abajo al final

    glVertex3f(0.145f, 0.135f, -0.074f); //arriba al final

    glVertex3f(0.33f, 0.01f, -0.074f); //arriba inicio

    glEnd();

    //punta
    glColor3f(252, 227, 0);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES
    glVertex3f(0.18f, 0.1f, -0.074f); //este lo ocupamos para mandar un vertice donde tomaremos un punto 
    //base
    glVertex3f(0.195f, 0.12f, -0.074f);
    //alto
    glVertex3f(0.145f, 0.14f, -0.074f);

    glEnd();

    glColor3f(0, 0, 1);
    //bandera 1
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.31f, 0.02f, -0.074f); //arriba al final

    glVertex3f(0.185f, 0.105f, -0.074f); //arriba inicio

    glVertex3f(0.195f, -0.042f, -0.074f); //abajo

    glVertex3f(0.26f, -0.085f, -0.074f); //abajo al final
    glEnd();


    glColor3f(1, 1, 1);
    //bandera 1
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.27f, 0.046f, -0.073f); //arriba al final

    glVertex3f(0.22f, 0.082f, -0.073f); //arriba inicio

    glVertex3f(0.24f, -0.058f, -0.073f);

    glVertex3f(0.26f, -0.085f, -0.074f);

    glVertex3f(0.28f, -0.045f, -0.073f); //abajo al final
    glEnd();

    glColor3f(252, 227, 0);
    //palo 2
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.265f, -0.09f, -0.074f); //abajo

    glVertex3f(0.1f, 0.02f, -0.074f); //abajo al final

    glVertex3f(0.11f, 0.010f, -0.074f); //arriba al final

    glVertex3f(0.27f, -0.09f, -0.074f); //arriba inicio

    glEnd();

    //punta
    glColor3f(252, 227, 0);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES
    glVertex3f(0.13f, -0.015f, -0.074f); //este lo ocupamos para mandar un vertice donde tomaremos un punto 
    //base
    glVertex3f(0.145f, 0.005f, -0.074f);
    //alto
    glVertex3f(0.095f, 0.02f, -0.074f);

    glEnd();

    glColor3f(0, 0, 1);
    //bandera 1
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.258f, -0.09f, -0.074f); //arriba al final

    glVertex3f(0.135f, -0.005f, -0.074f); //arriba inicio

    glVertex3f(0.14f, -0.1f, -0.074f); //abajo

    glVertex3f(0.205f, -0.19f, -0.074f); //abajo al final
    glEnd();


    glColor3f(1, 1, 1);
    //bandera 1
    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.22f, -0.06f, -0.073f); //arriba al final

    glVertex3f(0.175f, -0.032f, -0.073f); //arriba inicio

    glVertex3f(0.19f, -0.12f, -0.073f);

    glVertex3f(0.22f, -0.16f, -0.073f); //abajo

    glVertex3f(0.24f, -0.13f, -0.073f); //abajo al final
    glEnd();


    glColor3f(0, 0, 1);

    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.35f, 0.08f, -0.081f);

    glVertex3f(0.33f, 0.1f, -0.081f);

    glVertex3f(0.35f, 0.16f, -0.081f);

    glVertex3f(0.37f, 0.1f, -0.078f);
    glEnd();
    //blanco
    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON); //dibujaremos lineas

    glVertex3f(0.35f, 0.08f, -0.081f);

    glVertex3f(0.36f, 0.1f, -0.081f);

    glVertex3f(0.365f, 0.155f, -0.081f);

    glVertex3f(0.345f, 0.1f, -0.078f);
    glEnd();

    //punta
    glColor3f(252, 227, 0);
    glBegin(GL_TRIANGLES); //en el begin agregamos el modo en este caso agg un primitivo llamado GL_TRIANGLES
    glVertex3f(0.34f, 0.15f, -0.08f); //este lo ocupamos para mandar un vertice donde tomaremos un punto 
    //base
    glVertex3f(0.36f, 0.15f, -0.08f);
    //alto
    glVertex3f(0.35f, 0.18f, -0.08f);

    glEnd();
    
    
    //bandera izquierda abajo
     glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.34f, -0.20f, -0.075f);
    glVertex3f(0.31f, -0.225f, -0.075f);    
     glVertex3f(0.25f, -0.225f, -0.075f);
     glVertex3f(0.21f, -0.20f, -0.075f);
    glEnd();
    
    //bandera derecha abajo
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.36f, -0.20f, -0.075f);
    glVertex3f(0.39f, -0.225f, -0.075f);    
     glVertex3f(0.45f, -0.225f, -0.075f);
     glVertex3f(0.49f, -0.20f, -0.075f);
    glEnd();

    
       
    //bandera izquierda abajo
     glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.31f, -0.20f, -0.074f);
    glVertex3f(0.29f, -0.21f, -0.074f);    
     glVertex3f(0.27f, -0.21f, -0.074f);
     glVertex3f(0.25f, -0.20f, -0.074f);
    glEnd();
    
    //bandera izquierda abajo
     glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.39f, -0.20f, -0.074f);
    glVertex3f(0.41f, -0.21f, -0.074f);    
     glVertex3f(0.45f, -0.21f, -0.074f);
     glVertex3f(0.47f, -0.20f, -0.074f);
    glEnd();
    
    
    //cosa de enmedio
    //bandera izquierda abajo
     glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.34f, -0.20f, -0.074f);
    glVertex3f(0.31f, -0.24f, -0.074f); 
    glVertex3f(0.35f, -0.26f, -0.074f);
     glVertex3f(0.39f, -0.24f, -0.074f);
     glVertex3f(0.36f, -0.20f, -0.074f);
    glEnd();
    
     glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.345f, -0.20f, -0.073f);
    glVertex3f(0.33f, -0.24f, -0.073f); 
    glVertex3f(0.35f, -0.25f, -0.073f);
     glVertex3f(0.37f, -0.24f, -0.073f);
     glVertex3f(0.355f, -0.20f, -0.073f);
    glEnd();


}

void hojasiz() {
    //--------------------------------------------hojas
    //izquierda 
    //hoja 1
    glColor3f(0, 153, 0);
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.27f, -0.29f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.20f, -0.31f, -0.078f);

    //izquierda
    glVertex3f(0.27f, -0.33f, -0.078f);

    //vertice
    glVertex3f(0.31f, -0.295f, -0.078f);

    //derecha
    glVertex3f(0.30f, -0.25f, -0.078f);

    glVertex3f(0.25f, -0.22f, -0.078f);

    glEnd();
    //---------------------------------------hoja 2
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.19f, -0.25f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.10f, -0.26f, -0.078f);

    //izquierda
    glVertex3f(0.19f, -0.30f, -0.078f);

    //vertice
    glVertex3f(0.24f, -0.27f, -0.078f);

    //derecha
    glVertex3f(0.23f, -0.22f, -0.078f);

    glVertex3f(0.18f, -0.18f, -0.078f);

    glEnd();


    //---------------------------------------hoja 3
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.14f, -0.21f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.05f, -0.21f, -0.078f);

    //izquierda
    glVertex3f(0.10f, -0.25f, -0.078f);

    //vertice
    glVertex3f(0.17f, -0.23f, -0.078f);

    //derecha
    glVertex3f(0.17f, -0.17f, -0.078f);

    glVertex3f(0.13f, -0.13f, -0.078f);

    glEnd();

    //---------------------------------------hoja 4
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.09f, -0.15f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.02f, -0.11f, -0.078f);

    //izquierda
    glVertex3f(0.05f, -0.18f, -0.078f);

    //vertice
    glVertex3f(0.11f, -0.19f, -0.078f);

    //derecha
    glVertex3f(0.13f, -0.12f, -0.078f);

    glVertex3f(0.1f, -0.08f, -0.078f);

    glEnd();

    //---------------------------------------hoja 5
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.06f, -0.06f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.00f, -0.01f, -0.078f);

    //izquierda
    glVertex3f(0.02f, -0.09f, -0.078f);

    //vertice
    glVertex3f(0.08f, -0.10f, -0.078f);

    //derecha
    glVertex3f(0.1f, -0.07f, -0.078f);

    glVertex3f(0.1f, -0.00f, -0.078f);

    glEnd();

    //---------------------------------------hoja 6
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.05f, 0.01f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.01f, 0.07f, -0.078f);

    //izquierda
    glVertex3f(0.01f, 0.00f, -0.078f);

    //vertice
    glVertex3f(0.05f, -0.04f, -0.078f);

    //derecha
    glVertex3f(0.09f, 0.00f, -0.078f);

    glVertex3f(0.1f, 0.06f, -0.078f);

    glEnd();


    //---------------------------------------hoja 7
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.06f, 0.1f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.03f, 0.16f, -0.078f);

    //izquierda
    glVertex3f(0.01f, 0.09f, -0.078f);

    //vertice
    glVertex3f(0.055f, 0.05f, -0.078f);

    //derecha
    glVertex3f(0.1f, 0.08f, -0.078f);

    glVertex3f(0.1f, 0.15f, -0.078f);

    glEnd();
    
    
    //chonga
     glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);

    glVertex3f(0.33f, -0.265f, -0.077f);
 
    glVertex3f(0.34f, -0.31f, -0.077f);
   
    glVertex3f(0.3f, -0.31f, -0.077f);

    glVertex3f(0.29f, -0.29f, -0.077f);
    
    glVertex3f(0.3f, -0.26f, -0.077f);

    glEnd();
    
      //chonga
     glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    //arriba derecha
    glVertex3f(0.32f, -0.27f, -0.076f);
    //punta derecha baj
    glVertex3f(0.33f, -0.3f, -0.076f);
   
    glVertex3f(0.31f, -0.3f, -0.076f);

    glVertex3f(0.30f, -0.29f, -0.076f);
    //punta izquierda
    glVertex3f(0.31f, -0.27f, -0.076f);

    glEnd();
    
    
}

void hojasder() {
    //--------------------------------------------hojas
    //izquierda 
    //hoja 1
    glColor3f(0, 153, 0);
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.42f, -0.29f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.47f, -0.33f, -0.078f);

    //derecha
    glVertex3f(0.41f, -0.33f, -0.078f);

    //vertice
    glVertex3f(0.38f, -0.295f, -0.078f);

    //izquierda
    glVertex3f(0.39f, -0.26f, -0.078f);

    glVertex3f(0.45f, -0.22f, -0.078f);

    glEnd();
    //---------------------------------------hoja 2
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.49f, -0.26f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.55f, -0.29f, -0.078f);

    //derecha
    glVertex3f(0.49f, -0.31f, -0.078f);

    //vertice
    glVertex3f(0.45f, -0.275f, -0.078f);

    //izquierda
    glVertex3f(0.46f, -0.22f, -0.078f);

    glVertex3f(0.51f, -0.20f, -0.078f);


    glEnd();


    //---------------------------------------hoja 3
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.55f, -0.22f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.65f, -0.22f, -0.078f);

    //derecha
    glVertex3f(0.56f, -0.27f, -0.078f);

    //vertice
    glVertex3f(0.51f, -0.245f, -0.078f);

    //izquierda
    glVertex3f(0.51f, -0.19f, -0.078f);

    glVertex3f(0.56f, -0.15f, -0.078f);


    glEnd();

    //---------------------------------------hoja 4
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.60f, -0.16f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.69f, -0.14f, -0.078f);

    //derecha
    glVertex3f(0.63f, -0.20f, -0.078f);

    //vertice
    glVertex3f(0.57f, -0.198f, -0.078f);

    //izquierda
    glVertex3f(0.565f, -0.14f, -0.078f);

    glVertex3f(0.60f, -0.08f, -0.078f);

    glEnd();

    //---------------------------------------hoja 5
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.64f, -0.08f, -0.078f);
    //punta izquierda o baja
    glVertex3f(0.70f, -0.06f, -0.078f);

    //derecha
    glVertex3f(0.67f, -0.115f, -0.078f);

    //vertice
    glVertex3f(0.615f, -0.128f, -0.078f);

    //izquierda
    glVertex3f(0.595f, -0.07f, -0.078f);

    glVertex3f(0.61f, -0.01f, -0.078f);

    glEnd();

    //---------------------------------------hoja 6
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.65f, 0.01f, -0.078f);
    //punta  o baja
    glVertex3f(0.70f, 0.05f, -0.078f);

    //derecha
    glVertex3f(0.69f, -0.015f, -0.078f);

    //vertice
    glVertex3f(0.645f, -0.05f, -0.078f);

    //izquierda
    glVertex3f(0.60f, 0.0f, -0.078f);

    glVertex3f(0.605f, 0.06f, -0.078f);

    glEnd();


    //---------------------------------------hoja 7
    glBegin(GL_POLYGON);

    //punto mas alto
    glVertex3f(0.64f, 0.1f, -0.078f);
    //punta  o baja
    glVertex3f(0.67f, 0.14f, -0.078f);

    //derecha
    glVertex3f(0.68f, 0.085f, -0.078f);

    //vertice
    glVertex3f(0.645f, 0.04f, -0.078f);

    //izquierda
    glVertex3f(0.60f, 0.07f, -0.078f);

    glVertex3f(0.595f, 0.14f, -0.078f);


    glEnd();
    
        //chonga derecha
     glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);

    glVertex3f(0.35f, -0.265f, -0.077f);
    //punta izquierda
    glVertex3f(0.34f, -0.31f, -0.077f);
   
    glVertex3f(0.38f, -0.31f, -0.077f);

    glVertex3f(0.39f, -0.29f, -0.077f);
    
    glVertex3f(0.38f, -0.26f, -0.077f);

    glEnd();
    
      //chonga
     glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    //arriba derecha
    glVertex3f(0.36f, -0.27f, -0.076f);
    //punta derecha baj
    glVertex3f(0.35f, -0.3f, -0.076f);
   
    glVertex3f(0.37f, -0.3f, -0.076f);

    glVertex3f(0.38f, -0.29f, -0.076f);
    //punta izquierda
    glVertex3f(0.37f, -0.27f, -0.076f);

    glEnd();
    
      //chonga derecha
     glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.33f, -0.3f, -0.075f);
    glVertex3f(0.33f, -0.32f, -0.075f);
    glVertex3f(0.35f, -0.32f, -0.075f);
    glVertex3f(0.35f, -0.3f, -0.075f);

    glEnd();
    
    //izquierda
    //chonga 
     glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.33f, -0.31f, -0.075f);
    glVertex3f(0.33f, -0.32f, -0.075f);    
     glVertex3f(0.32f, -0.35f, -0.075f);
     glVertex3f(0.31f, -0.32f, -0.075f);
    glVertex3f(0.3f, -0.35f, -0.075f);
    glEnd();
    
    //chonga 
     glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.35f, -0.31f, -0.075f);
    glVertex3f(0.35f, -0.32f, -0.075f);    
     glVertex3f(0.36f, -0.35f, -0.075f);
     glVertex3f(0.37f, -0.32f, -0.075f);
    glVertex3f(0.38f, -0.35f, -0.075f);
   

    glEnd();
}

void inicializar_bandera3d(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia los búferes de color y profundidad
     glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Establece el color de fondo (negro)
     glEnable(GL_DEPTH_TEST); // Habilita el test de profundidad para el efecto 3D
}


void dibujar_bandera3d() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia los búferes de color y profundidad

    glMatrixMode(GL_PROJECTION); // Selecciona la matriz de proyección
    glLoadIdentity(); // Carga la matriz de identidad
    gluPerspective(45.0f, 1.0f, 1.0f, 10.0f); // Establece una proyección en perspectiva
    glMatrixMode(GL_MODELVIEW); // Selecciona la matriz de transformación de modelo-vista
    glLoadIdentity(); // Carga la matriz de identidad
    glTranslatef(0.0f, 0.0f, -5.0f); // Aplica traslaciones en los ejes X, Y y Z
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Aplica rotación en el eje X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Aplica rotación en el eje Y
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // Aplica rotación en el eje Z

    //dibujamos bandera
    bandera();
    
    //para agregar el escudo utilizamos otra vez la projeccion para amoldar el tamanio
    glMatrixMode(GL_PROJECTION); // Selecciona la matriz de proyección
    glLoadIdentity(); // Carga la matriz de identidad
    gluPerspective(55.0f, 1.0f, 1.0f, 10.0f); // Establece una proyección en perspectiva
    glMatrixMode(GL_MODELVIEW); // Selecciona la matriz de transformación de modelo-vista
    glLoadIdentity(); // Carga la matriz de identidad
    glTranslatef(0.0f, 0.0f, -5.0f); // Aplica traslaciones en los ejes X, Y y Z
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Aplica rotación en el eje X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Aplica rotación en el eje Y
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // Aplica rotación en el eje Z

    // Dibuja el rectángulo 2D
    glMatrixMode(GL_PROJECTION); // Selecciona la matriz de proyección
    
    //llamamos el contenido del escudo
    contenidoEs();
    //las banderas de afuera
    banderas();
    //los laureles izquierdos
    hojasiz();
    //laureles derechos
    hojasder();
    //llamamos el cilindo para el asta de la bandera
    Cilindro(0.90, 0.1, 20);
    //generamos la punta de la asta
    Circulo(0.15, 100, 100);
    
    glFlush(); // Envia los comandos de dibujo a la GPU
}

void update() {
    glutPostRedisplay(); // Marca la ventana para ser redibujada
}

void rotar_bandera_3d(unsigned char tecla, int x, int y) {
    switch (tecla) {
        case 'a':
            angleY -= 5.0f; // izquierda
            break;
        case 'd':
            angleY += 5.0f; // derecha
            break;
        case 's':
            angleX -= 5.0f; // Decrementa el ángulo de rotación en el eje X
            break;
        case 'w':
            angleX += 5.0f; // Incrementa el ángulo de rotación en el eje X
            break;

    }

    update();
}
//regresa carnet
const char* get_carnet(void) {
    char *name = "MP19034";
    
}