HEADERS = window.h \
    mygldrawer.h
SOURCES = main.cpp \
    window.cpp \
    mygldrawer.cpp
QT += opengl
INCLUDEPATH += "./" \
    "/usr/local/Cg/include"
LIBS += -L"/usr/local/Cg/lib" \
    -lCg \
    -lCgGL \
    -lglut

# install
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    combinacionBumps.pro
INSTALLS += target \
    sources
OTHER_FILES += fragment.cg \
    vertex.cg
