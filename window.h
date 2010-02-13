#include <QtGui/QWidget>
#include<QtOpenGL/QGLWidget>
#include <qlineedit.h>
#include <QtGui/QLabel>
#include <qtimer.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <QComboBox>
#include <QTimer>

// cantidad de texturas en la base
#define CANT 3

class Window : public QWidget
    {
        Q_OBJECT

    public:
        Window();

    public slots:
        void cambiarFPS( int );

    private:	
        QGLWidget *mygldrawer;

        
        QLabel *labelAmplitud[CANT];
        QLabel *labelIntensidad[CANT];
        QLabel *labelFrecuencia[CANT];
        QLabel *labelTurb[CANT];
        QLabel *labelAngulo[CANT];
        QLabel *labelDesplU[CANT];
        QLabel *labelDesplV[CANT];


        QSlider *amplitudSlider[CANT];
        QSlider *turbSlider[CANT];
        QSlider *anguloSlider[CANT];
        QSlider *frecuenciaSlider[CANT];
        QSlider *intensidadSlider[CANT];
        QSlider *desplUSlider[CANT];
        QSlider *desplVSlider[CANT];

        QPushButton *usaButtons[CANT];

        QComboBox *combinaButtons[CANT-1];

        QTimer *timer;
        QLabel *tiempoLabel;
        QString *tiempoStr;
        QString *fpsStr;

    };
