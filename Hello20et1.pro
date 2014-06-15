TEMPLATE        = app
TARGET          = UTProfiler

QT +=widgets xml sql


FORMS += \
    feneditdoss.ui \
    choixuv.ui \
    browserwidget.ui \
    qsqlconnectiondialog.ui \
    catalogue.ui \
    recupdonnees.ui \
    fencompletion.ui \
    editeruv.ui

OTHER_FILES += \
    xmlDossier.xml \
    Hello20et1.pro.user


HEADERS += \
    CursusEditor.h \
    CursusSelector.h \
    dataBaseA.h \
    dataBaseB.h \
    dossier.h \
    feneditdoss.h \
    fenetre_principale.h \
    UV.h \
    choixuv.h \
    browser.h \
    connectionwidget.h \
    qsqlconnectiondialog.h \
    uvDataBaseConnect.h \
    catalogue.h \
    interfacePersistenceDonnees.h \
    dataBasePostgres.h \
    recupdonnees.h \
    completion.h \
    fencompletion.h \
    inscription.h \
    dossierXMLreader.h \
    persistenceDonnees.h \
    editeruv.h

SOURCES += \
    CursusEditor.cpp \
    CursusSelector.cpp \
    dataBaseA.cpp \
    dataBaseB.cpp \
    dossier.cpp \
    feneditdoss.cpp \
    fenetre_principale.cpp \
    main.cpp \
    UV.cpp \
    choixuv.cpp \
    browser.cpp \
    qsqlconnectiondialog.cpp \
    connectionwidget.cpp \
    uvDataBaseConnect.cpp \
    catalogue.cpp \
    interfacePersistenceDonnees.cpp \
    recupdonnees.cpp \
    completion.cpp \
    fencompletion.cpp \
    inscription.cpp \
    dossierXMLreader.cpp \
    persistenceDonnees.cpp \
    editeruv.cpp

build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}

# install
target.path = $$[QT_INSTALL_EXAMPLES]/sql/sqlbrowser
INSTALLS += target


wince*: {
    DEPLOYMENT_PLUGIN += qsqlite
}
