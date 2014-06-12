TEMPLATE        = app
TARGET          = sqlbrowser

QT +=widgets xml sql


FORMS += \
    feneditdoss.ui \
    choixuv.ui \
    browserwidget.ui \
    qsqlconnectiondialog.ui \
    form_ajout_uv.ui \
    form_edit_uv.ui \
    form_suppr_uv.ui \
    form_choix_uv.ui \
    form_catalogue.ui

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
    interfacePersistenceDonnees.h

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
    interfacePersistenceDonnees.cpp

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

