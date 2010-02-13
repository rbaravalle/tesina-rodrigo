#include<stdio.h>
#include<stdlib.h>
#include <math.h>     /* for sqrt, sin, cos, and fabs */
#include <assert.h>   /* for assert */

#include<mygldrawer.h>
#include<QtOpenGL/QGLWidget>

#include <spotnoise.h>

#include <QTimer>

//***************//
// CODIGO OPENGL //  
//***************//

#define NX 256
#define NY 256

#define tamanio (NX*NY)

int winW = 700; /* window width */
int winH = 700; /* window height */

static CGcontext   myCgContext;

static CGprogram   myCgFragmentProgram,
                    myCgVertexProgram;

static CGprofile   myCgFragmentProfile,
                   myCgVertexProfile;

static const char *myProgramName = "01_vertex_program",
                *vertex_program_name = "vertex.cg",
                *fragment_program_name = "fragment.cg";

enum {
  TO_TEXTURA_0 = 0,
  TO_TEXTURA_1 = 1,
  TO_TEXTURA_2 = 2
};

static GLubyte texturas[CANT_T_PARAMETERS][tamanio];
GLuint texObj[CANT_T_PARAMETERS];

CGparameter texturesParameters[CANT_T_PARAMETERS];
CGparameter combinaParameters[CANT_C_PARAMETERS];
CGparameter fragmentParameters[CANT_F_PARAMETERS];
CGparameter vertexParameters[CANT_V_PARAMETERS];


const char* tNamesParameters[] = { 
	          "textura0",
   	          "textura1",
	          "textura2", };

const char* cNamesParameters[] = {
              "combina1",
              "combina2",
};

// Nombres de los parametros en el fragment shader
const char* fNamesParameters[] = { 
	          "usa",
	          "amplitud",
	          "turb",
	          "escala_u",
	          "intensidad", };

// Nombres de los parametros en el vertex shader
const char* vNamesParameters[] = { 
	          "angulos",
              "desplazamiento_u",
              "desplazamiento_v" };

// parametros dinamicos de las texturas, valores por default
float fArrayParameters[][CANT_T_PARAMETERS] = {
    {1,1,1}, // usa
    {1,1,1}, // amplitud
    {0,0,0}, // turb
    {200,200,200}, // escala_u
    {1,1,1}, // intensidad
};
float vArrayParameters[][CANT_V_PARAMETERS] = {
    {1,0.5,0}, // angulos
    {0,0,0}, // desplazamiento_u
    {0,0,0}, // desplazamiento_v
    {1,1,1}, // escala_v
};
int cArrayParameters[CANT_C_PARAMETERS] = {
    0,0, // funciones de combinacion    
};

int cuadros = 0;
int fps = 0;

//*******************//
// FIN CODIGO OPENGL //
//*******************//


// RUTINAS DE LA CLASE

// contador de fps
void MyGLDrawer::update()
{
    fps = cuadros;
    cuadros = 0;
    emit cambiarFPS(fps);
}

void MyGLDrawer::_checkForCgError(const char *situation)
{
  CGerror error;
  const char *string = cgGetLastErrorString(&error);

  if (error != CG_NO_ERROR) {
    printf("%s: %s: %s\n",
      myProgramName, situation, string);
    if (error == CG_COMPILER_ERROR) {
      printf("%s\n", cgGetLastListing(myCgContext));
    }
    exit(1);
  }
}

void MyGLDrawer::_cargar_texturas()
{
    for(int i = 0; i< tamanio; i++)
    {
        texturas[0][i] = (GLubyte)text0[i];
    }

}

void MyGLDrawer::cambiarUsa1()
{
    fArrayParameters[0][0] =  fArrayParameters[0][0] == 1 ? 0 : 1;
}

void MyGLDrawer::cambiarUsa2()
{
    fArrayParameters[0][1] =  fArrayParameters[0][1] == 1 ? 0 : 1;
}

void MyGLDrawer::cambiarUsa3()
{
    fArrayParameters[0][2] =  fArrayParameters[0][2] == 1 ? 0 : 1;
}

void MyGLDrawer::cambiarAmplitud1(int amplitudParam)
{
    fArrayParameters[1][0] = (float)amplitudParam/100;
}

void MyGLDrawer::cambiarAmplitud2(int amplitudParam)
{
    fArrayParameters[1][1] = (float)amplitudParam/100;
}

void MyGLDrawer::cambiarAmplitud3(int amplitudParam)
{
    fArrayParameters[1][2] = (float)amplitudParam/100;
}

void MyGLDrawer::cambiarTurb1(int turbParam)
{
    fArrayParameters[2][0] = (float)turbParam/100;
}

void MyGLDrawer::cambiarTurb2(int turbParam)
{
    fArrayParameters[2][1] = (float)turbParam/100;
}

void MyGLDrawer::cambiarTurb3(int turbParam)
{
    fArrayParameters[2][2] = (float)turbParam/100;
}

void MyGLDrawer::cambiarFrecuencia1(int frec)
{
    fArrayParameters[3][0] = (float)frec;
}

void MyGLDrawer::cambiarFrecuencia2(int frec)
{
    fArrayParameters[3][1] = (float)frec;}

void MyGLDrawer::cambiarFrecuencia3(int frec)
{
    fArrayParameters[3][2] = (float)frec;
}

void MyGLDrawer::cambiarIntensidad1(int intens)
{
    fArrayParameters[4][0] = (float)intens/100;
}

void MyGLDrawer::cambiarIntensidad2(int intens)
{
    fArrayParameters[4][1] = (float)intens/100;
}

void MyGLDrawer::cambiarIntensidad3(int intens)
{
    fArrayParameters[4][2] = (float)intens/100;
}


////////

void MyGLDrawer::cambiarAngulo1(int angParam)
{
    vArrayParameters[0][0] = (float)angParam/100;
}

void MyGLDrawer::cambiarAngulo2(int angParam)
{
    vArrayParameters[0][1] = (float)angParam/100;
}

void MyGLDrawer::cambiarAngulo3(int angParam)
{
    vArrayParameters[0][2] = (float)angParam/100;
}

void MyGLDrawer::cambiarDesplazamiento_u1(int d)
{
    vArrayParameters[1][0] = (float)d/100;
}

void MyGLDrawer::cambiarDesplazamiento_u2(int d)
{
    vArrayParameters[1][1] = (float)d/100;
}

void MyGLDrawer::cambiarDesplazamiento_u3(int d)
{
    vArrayParameters[1][2] = (float)d/100;
}

void MyGLDrawer::cambiarDesplazamiento_v1(int d)
{
    vArrayParameters[2][0] = (float)d/100;
}

void MyGLDrawer::cambiarDesplazamiento_v2(int d)
{
    vArrayParameters[2][1] = (float)d/100;
}

void MyGLDrawer::cambiarDesplazamiento_v3(int d)
{
    vArrayParameters[2][2] = (float)d/100;
}


void MyGLDrawer::cambiarCombina1(int d)
{
    cArrayParameters[0] = d;
}

void MyGLDrawer::cambiarCombina2(int d)
{
    cArrayParameters[1] = d;
}



// tamanio de la pantalla
QSize MyGLDrawer::minimumSizeHint() const
 {
     return QSize(600, 600);
 }

QSize MyGLDrawer::sizeHint() const
 {
     return QSize(600, 600);
 }

void MyGLDrawer::initializeGL()
{   

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();

    glClearColor(0.3, 0.3, 0.3, 0.0);

    glEnable(GL_DEPTH_TEST);

    _cargar_texturas();

    glutInitWindowSize(700, 700);


    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures( CANT_T_PARAMETERS, texObj );


    ///////////
    for(int i = 0; i < CANT_T_PARAMETERS; i++) {
        glBindTexture(GL_TEXTURE_2D, texObj[i]);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_LUMINANCE,
            NX, NY, GL_LUMINANCE, GL_UNSIGNED_BYTE, texturas[i]);
    }

    ///////////

    ///////////
    myCgContext = cgCreateContext();
    _checkForCgError("creating context");
    cgGLSetDebugMode(CG_FALSE);
    cgSetParameterSettingMode(myCgContext, CG_DEFERRED_PARAMETER_SETTING);

    myCgVertexProfile = cgGLGetLatestProfile(CG_GL_VERTEX);
    cgGLSetOptimalOptions(myCgVertexProfile);
    _checkForCgError("selecting vertex profile");

    myCgVertexProgram =
        cgCreateProgramFromFile(
          myCgContext,              /* Cg runtime context */
          CG_SOURCE,                /* Program in human-readable form */
          vertex_program_name,
          myCgVertexProfile,        /* Profile: latest fragment profile */
          "main",                   /* Entry function name */
          NULL); /* No extra compiler options */
    _checkForCgError("creating vertex program from string");
    cgGLLoadProgram(myCgVertexProgram);
    _checkForCgError("loading vertex program");

    myCgFragmentProfile = cgGLGetLatestProfile(CG_GL_FRAGMENT);
    cgGLSetOptimalOptions(myCgFragmentProfile);
    _checkForCgError("selecting fragment profile");

    /* Specify fragment program with a string. */
    myCgFragmentProgram =
        cgCreateProgramFromFile(
          myCgContext,              /* Cg runtime context */
          CG_SOURCE,                /* Program in human-readable form */
          fragment_program_name,
          myCgFragmentProfile,      /* Profile: latest fragment profile */
          "main",                   /* Entry function name */
          NULL); /* No extra compiler options */

    _checkForCgError("creating fragment program from string");
    cgGLLoadProgram(myCgFragmentProgram);
    _checkForCgError("loading fragment program");

    // binding con parametros del fragment shader
    for (int i = 0; i < CANT_T_PARAMETERS; i++) {
	    texturesParameters[i] = cgGetNamedParameter(myCgFragmentProgram, (char*)tNamesParameters[i]);

        _checkForCgError("could not get texture parameter");

        cgGLSetTextureParameter(texturesParameters[i], texObj[i]);

        _checkForCgError("setting textura texture");

    }

    // binding con parametros del fragment shader
    for (int i = 0; i < CANT_F_PARAMETERS; i++) {
	    fragmentParameters[i] = cgGetNamedParameter(myCgFragmentProgram, (char*)fNamesParameters[i]);

        _checkForCgError("could not get fragment parameter");
    }

    // binding con parametros del fragment shader (combinacion de texturas)
    for (int i = 0; i < CANT_C_PARAMETERS; i++) {
	    combinaParameters[i] = cgGetNamedParameter(myCgFragmentProgram, (char*)cNamesParameters[i]);

        _checkForCgError("could not get combina parameter");
    }

    // binding con parametros del vertex shader
    for (int i = 0; i < CANT_V_PARAMETERS; i++) {
	    vertexParameters[i] = cgGetNamedParameter(myCgVertexProgram, (char*)vNamesParameters[i]);

        _checkForCgError("could not get vertex parameter");
    }

    /////////

    _checkForCgError("setting parametros parameter");

}

void MyGLDrawer::paintGL()
{
    cuadros++;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i< CANT_T_PARAMETERS; i++) {
        cgGLEnableTextureParameter(texturesParameters[i]);
        _checkForCgError("enabling textures");
    }

    cgGLEnableProfile(myCgVertexProfile);
    _checkForCgError("enabling vertex profile");

    cgGLBindProgram(myCgFragmentProgram);
    _checkForCgError("binding fragment program");

    cgGLEnableProfile(myCgFragmentProfile);
    _checkForCgError("enabling fragment profile");

    glClearColor(0.0, 0.0, 0.0, 0);

    for(int i = 0; i < CANT_F_PARAMETERS; i++) {
        cgGLSetParameterArray1f(fragmentParameters[i],
                                         0,
                                         CANT_T_PARAMETERS,
                                         fArrayParameters[i]);
    }

    for(int i = 0; i < CANT_V_PARAMETERS; i++) {
        cgGLSetParameterArray1f(vertexParameters[i],
                                         0,
                                         CANT_T_PARAMETERS,
                                         vArrayParameters[i]);
    }

    for(int i = 0; i < CANT_C_PARAMETERS; i++) {
        cgGLSetParameter1f(combinaParameters[i],                                       
                                         cArrayParameters[i]);
    }

    cgUpdateProgramParameters(myCgVertexProgram);
    cgUpdateProgramParameters(myCgFragmentProgram);


    for (int i = 0; i  < CANT_T_PARAMETERS; i++) {
        glBindTexture(GL_TEXTURE_2D, texObj[i]);

        glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
                glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
                glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
                glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
        glEnd();
    }

    //glFlush();

    cgGLDisableProfile(myCgVertexProfile);
    _checkForCgError("disabling vertex profile");

    cgGLDisableProfile(myCgFragmentProfile);
    _checkForCgError("disabling fragment profile");

}

void MyGLDrawer::resizeGL(int width, int height)
{
    double aspectRatio = (float) width / (float) height;
    double fieldOfView = 75.0; /* Degrees */
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fieldOfView, aspectRatio,
    0.1,    /* Z near */
    100.0); /* Z far */
    glMatrixMode(GL_MODELVIEW);

    glViewport(0, 0, width, height);
}

