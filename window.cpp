#include<window.h>
#include<QtOpenGL/QGLWidget>
#include<mygldrawer.h>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <qslider.h>
#include <QGroupBox>
#include <QComboBox>
#include <QTimer>

void Window::cambiarFPS( int fps )
{
    tiempoStr->clear();
    tiempoStr->append("FPS: ");
    tiempoLabel->setText( tiempoStr->append(fpsStr->setNum(fps)));
}

Window::Window()
{
    mygldrawer = new MyGLDrawer(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), mygldrawer, SLOT(update()));
    timer->start(1000);

    connect(mygldrawer, SIGNAL(cambiarFPS(int)), this, SLOT(cambiarFPS(int)));

    tiempoLabel = new QLabel;

    QFont f("Helvetica", 14, QFont::Bold);
    tiempoLabel->setFont(f);

    tiempoStr = new QString;
    fpsStr = new QString;


    for(int i = 0; i < CANT; i++) {

        labelAmplitud[i]= new QLabel(tr("Amplitud 1:"));
        labelIntensidad[i]= new QLabel(tr("Intensidad:"));
        labelFrecuencia[i]= new QLabel(tr("Frecuencia:"));
        labelTurb[i]= new QLabel(tr("Turbulencia:"));;
        labelAngulo[i]= new QLabel(tr("Angulo:"));
        labelDesplU[i]= new QLabel(tr("DesplU:"));
        labelDesplV[i]= new QLabel(tr("DesplV:"));

        turbSlider[i] = new QSlider ();
        turbSlider[i]->setPageStep(1);
        turbSlider[i]->setRange(0,200);
        turbSlider[i]->setValue(1);
        turbSlider[i]->setOrientation(Qt::Horizontal);

        amplitudSlider[i] = new QSlider ();
        amplitudSlider[i]->setPageStep(1);
        amplitudSlider[i]->setRange(0,5000);
        amplitudSlider[i]->setValue(1);
        amplitudSlider[i]->setOrientation(Qt::Horizontal);

        anguloSlider[i] = new QSlider ();
        anguloSlider[i]->setPageStep(1);
        anguloSlider[i]->setRange(0,314);
        anguloSlider[i]->setValue(0);
        anguloSlider[i]->setOrientation(Qt::Horizontal);

        frecuenciaSlider[i] = new QSlider ();
        frecuenciaSlider[i]->setPageStep(1);
        frecuenciaSlider[i]->setRange(0,500);
        frecuenciaSlider[i]->setValue(200);
        frecuenciaSlider[i]->setOrientation(Qt::Horizontal);

        intensidadSlider[i] = new QSlider ();
        intensidadSlider[i]->setPageStep(1);
        intensidadSlider[i]->setRange(0,800);
        intensidadSlider[i]->setValue(100);
        intensidadSlider[i]->setOrientation(Qt::Horizontal);

        desplUSlider[i] = new QSlider ();
        desplUSlider[i]->setPageStep(1);
        desplUSlider[i]->setRange(0,800);
        desplUSlider[i]->setValue(100);
        desplUSlider[i]->setOrientation(Qt::Horizontal);

        desplVSlider[i] = new QSlider ();
        desplVSlider[i]->setPageStep(1);
        desplVSlider[i]->setRange(0,800);
        desplVSlider[i]->setValue(100);
        desplVSlider[i]->setOrientation(Qt::Horizontal);
    }

    usaButtons[0] = new QPushButton(tr("Textura &1"));
    usaButtons[0]->setCheckable(true);
    usaButtons[1] = new QPushButton(tr("Textura &2"));
    usaButtons[1]->setCheckable(true);
    usaButtons[2] = new QPushButton(tr("Textura &3"));
    usaButtons[2]->setCheckable(true);

    for(int i = 0; i < CANT-1; i++) {
        combinaButtons[i] = new QComboBox();
        combinaButtons[i]->insertItem(0,"ADD");
        combinaButtons[i]->insertItem(1,"SUB");
        combinaButtons[i]->insertItem(2,"LERP");
        combinaButtons[i]->insertItem(3,"SOBRE");
        combinaButtons[i]->insertItem(4,"MUL");
        combinaButtons[i]->setCurrentIndex(0);
    }

    QObject::connect(amplitudSlider[0], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarAmplitud1(int)));

    QObject::connect(amplitudSlider[1], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarAmplitud2(int)));

    QObject::connect(amplitudSlider[2], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarAmplitud3(int)));

    QObject::connect(turbSlider[0], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarTurb1(int)));

    QObject::connect(turbSlider[1], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarTurb2(int)));

    QObject::connect(turbSlider[2], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarTurb3(int)));

    QObject::connect(anguloSlider[0], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarAngulo1(int)));

    QObject::connect(anguloSlider[1], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarAngulo2(int)));

    QObject::connect(anguloSlider[2], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarAngulo3(int)));

    QObject::connect(frecuenciaSlider[0], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarFrecuencia1(int)));

    QObject::connect(frecuenciaSlider[1], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarFrecuencia2(int)));

    QObject::connect(frecuenciaSlider[2], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarFrecuencia3(int)));

    QObject::connect( usaButtons[0], SIGNAL(clicked()),
            mygldrawer, SLOT(cambiarUsa1()));

    QObject::connect( usaButtons[1], SIGNAL(clicked()),
            mygldrawer, SLOT(cambiarUsa2()));

    QObject::connect( usaButtons[2], SIGNAL(clicked()),
            mygldrawer, SLOT(cambiarUsa3()));

    QObject::connect(intensidadSlider[0], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarIntensidad1(int)));

    QObject::connect(intensidadSlider[1], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarIntensidad2(int)));

    QObject::connect(intensidadSlider[2], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarIntensidad3(int)));

    QObject::connect(desplUSlider[0], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarDesplazamiento_u1(int)));

    QObject::connect(desplUSlider[1], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarDesplazamiento_u2(int)));

    QObject::connect(desplUSlider[2], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarDesplazamiento_u3(int)));

    QObject::connect(desplVSlider[0], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarDesplazamiento_v1(int)));

    QObject::connect(desplVSlider[1], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarDesplazamiento_v2(int)));

    QObject::connect(desplVSlider[2], SIGNAL(valueChanged(int)),
            mygldrawer, SLOT(cambiarDesplazamiento_v3(int)));

    QObject::connect(combinaButtons[0], SIGNAL(activated(int)),
            mygldrawer, SLOT(cambiarCombina1(int)));

    QObject::connect(combinaButtons[1], SIGNAL(activated(int)),
            mygldrawer, SLOT(cambiarCombina2(int)));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *izqLayout = new QVBoxLayout;


    QHBoxLayout *texturaButtonsLayout1 = new QHBoxLayout;
    QHBoxLayout *texturaButtonsLayout2 = new QHBoxLayout;

    QVBoxLayout *amplitudLayout = new QVBoxLayout;
    QVBoxLayout *turbLayout = new QVBoxLayout;
    QVBoxLayout *anguloLayout = new QVBoxLayout;
    QVBoxLayout *frecuenciaLayout = new QVBoxLayout;
    QVBoxLayout *usaLayout = new QVBoxLayout;
    QVBoxLayout *intensidadLayout = new QVBoxLayout;
    QVBoxLayout *desplULayout = new QVBoxLayout;
    QVBoxLayout *desplVLayout = new QVBoxLayout;

	QGroupBox *usaGroup = new QGroupBox;
	usaGroup->setLayout(usaLayout);
	usaGroup->setTitle(tr("Texturas usadas: "));

	QGroupBox *paramsGroup = new QGroupBox;
	paramsGroup->setLayout(izqLayout);
	paramsGroup->setTitle(tr("Parametros: "));

    setLayout(mainLayout);


	int i;

	i = 0;
    mainLayout->addWidget(paramsGroup,i++);
    mainLayout->addWidget(usaGroup,i++);
    mainLayout->addWidget(mygldrawer,i++);

	i = 0;

	izqLayout->addLayout(intensidadLayout, i++);
    izqLayout->addLayout(amplitudLayout, i++);
    izqLayout->addLayout(turbLayout, i++);
    izqLayout->addLayout(anguloLayout, i++);
    izqLayout->addLayout(frecuenciaLayout, i++);
    izqLayout->addStretch(100);

    i = 0;
    texturaButtonsLayout1->addWidget(usaButtons[0],i++);
    texturaButtonsLayout1->addWidget(combinaButtons[0],i++);

    i = 0;
    texturaButtonsLayout2->addWidget(usaButtons[1],i++);
    texturaButtonsLayout2->addWidget(combinaButtons[1],i++);

    i = 0;
    usaLayout->addLayout(texturaButtonsLayout1,i++);
    usaLayout->addLayout(texturaButtonsLayout2,i++);
    usaLayout->addWidget(usaButtons[2],i++);
    usaLayout->addLayout(desplULayout, i++);
    usaLayout->addLayout(desplVLayout, i++);
    usaLayout->addWidget(tiempoLabel,i++);
    usaLayout->addStretch(100);

	i = 0;


        int a[7];
    for(int i = 0; i< 7; i++) {
        a[i] = 0;
    }


    for ( int j = 0; j< CANT; j++) {
        amplitudLayout->addWidget(labelAmplitud[j],a[0]++);
        amplitudLayout->addWidget(amplitudSlider[j],a[0]++);

        turbLayout->addWidget(labelTurb[j],a[1]++);
        turbLayout->addWidget(turbSlider[j],a[1]++);

        anguloLayout->addWidget(labelAngulo[j],a[2]++);
        anguloLayout->addWidget(anguloSlider[j],a[2]++);

        frecuenciaLayout->addWidget(labelFrecuencia[j],a[3]++);
        frecuenciaLayout->addWidget(frecuenciaSlider[j],a[3]++);

        intensidadLayout->addWidget(labelIntensidad[j],a[4]++);
        intensidadLayout->addWidget(intensidadSlider[j],a[4]++);

        desplULayout->addWidget(labelDesplU[j],a[5]++);
        desplULayout->addWidget(desplUSlider[j],a[5]++);

        desplVLayout->addWidget(labelDesplV[j],a[6]++);
        desplVLayout->addWidget(desplVSlider[j],a[6]++);

    }

    amplitudLayout->addStretch(100);
    turbLayout->addStretch(100);
    anguloLayout->addStretch(100);
    frecuenciaLayout->addStretch(100);
    intensidadLayout->addStretch(100);
    desplULayout->addStretch(100);
    desplVLayout->addStretch(100);

    // para que no minimice la ventana al empezar el programa
    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    setWindowTitle(tr("Marmoles - Entrega 1 : 18/12/2009 - Rodrigo Baravalle"));
}

