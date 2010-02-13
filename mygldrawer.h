#include<QtOpenGL/QGLWidget>
#include <Cg/cg.h>
#include <Cg/cgGL.h>
#include <GL/glut.h>

#define CANT_T_PARAMETERS 3
#define CANT_C_PARAMETERS 2
#define CANT_F_PARAMETERS 5
#define CANT_V_PARAMETERS 3


class MyGLDrawer : public QGLWidget
{
	Q_OBJECT

	public:
        MyGLDrawer() {};
        ~MyGLDrawer() {};
        QSize minimumSizeHint() const;
        QSize sizeHint() const;

	public slots:
        void cambiarAmplitud1(int);
        void cambiarAmplitud2(int);
        void cambiarAmplitud3(int);

        void cambiarTurb1(int);
        void cambiarTurb2(int);
        void cambiarTurb3(int);

        void cambiarAngulo1(int);
        void cambiarAngulo2(int);
        void cambiarAngulo3(int);

        void cambiarFrecuencia1(int);
        void cambiarFrecuencia2(int);
        void cambiarFrecuencia3(int);

        void cambiarUsa1();
        void cambiarUsa2();
        void cambiarUsa3();

        void cambiarIntensidad1(int);
        void cambiarIntensidad2(int);
        void cambiarIntensidad3(int);

        void cambiarDesplazamiento_u1(int);
        void cambiarDesplazamiento_u2(int);
        void cambiarDesplazamiento_u3(int);

        void cambiarDesplazamiento_v1(int);
        void cambiarDesplazamiento_v2(int);
        void cambiarDesplazamiento_v3(int);

        void cambiarCombina1(int);
        void cambiarCombina2(int);
		
	private:
		void initializeGL();
		void resizeGL(int width, int height);
		void paintGL();
		void keyboard(unsigned char c, int x, int y);
        void _cargar_texturas();
        void _checkForCgError(const char *);

};
