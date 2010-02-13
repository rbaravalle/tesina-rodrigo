#include <QtGui/QWidget>
#include<QtOpenGL/QGLWidget>
#include <qlineedit.h>
#include <QtGui/QLabel>
#include <qtimer.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <QComboBox>

// cantidad de texturas en la base
#define CANT 3

class Window : public QWidget
    {
        Q_OBJECT

    public:
        Window();

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

    };
