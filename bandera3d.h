#ifndef BANDERA3D_H
#define BANDERA3D_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif 
/**
* Se encarga de inicializar (si es necesario) su invocacion
* esta llamada se realizara una sola vez al inicio de la ejecucion
*/
void inicializar_bandera3d(void);
/**
* Dibuja su entrega de bandera nacional de el salvador en 3d  mediante la invocacion del callback
de glut tal y como se mostro en clase. 
*/
void dibujar_bandera3d();

/**
* retorne su numero de carnet en la invocacion, en base a esto se asignara su nota de forma automatica 
*/
const char* get_carnet(void);

/**
* se encarga de rotar la bandera, cursor arriba y abajo para el eje x, 
* cursor derecha o izquierda para eje y, 
* j y k para eje z. 
*/
void rotar_bandera_3d(unsigned char,int,int);

#endif /* BANDERA_H */
