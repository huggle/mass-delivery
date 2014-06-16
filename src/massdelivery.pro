TEMPLATE = lib
TARGET = MassDelivery
QT += declarative xml webkit core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = org.huggle.extension.qt

# Input
SOURCES += \
    massdelivery.cpp \
    ../../wikiedit.cpp \
    ../../mainwindow.cpp \
    ../../wikiutil.cpp \
    ../../warnings.cpp \
    ../../resources.cpp \
    ../../querypool.cpp \
    ../../core.cpp \
    ../../collectable.cpp \
    ../../iextension.cpp \
    ../../editquery.cpp \
    ../../configuration.cpp \
    ../../apiquery.cpp \
    ../../syslog.cpp \
    ../../wlquery.cpp \
    ../../wikiuser.cpp \
    ../../wikisite.cpp \
    ../../localization.cpp \
    ../../wikipage.cpp \
    ../../webserverquery.cpp \
    ../../revertquery.cpp \
    ../../queryresult.cpp \
    ../../query.cpp \
    ../../history.cpp \
    ../../gc.cpp \
    ../../huggleweb.cpp \
    ../../hugglequeueitemlabel.cpp \
    ../../hugglequeuefilter.cpp \
    ../../hugglequeue.cpp \
    ../../hugglelog.cpp \
    ../../hugglefeedproviderwiki.cpp \
    ../../hugglefeedproviderirc.cpp \
    ../../hugglefeed.cpp \
    deliveryform.cpp \
    ../../message.cpp

HEADERS += \
    massdelivery.h \
    ../../mainwindow.hpp \
    ../../wikiedit.hpp \
    ../../core.hpp \
    ../../warnings.hpp \
    ../../resources.hpp \
    ../../wikiutil.hpp \
    ../../querypool.hpp \
    ../../collectable.hpp \
    ../../iextension.hpp \
    ../../wikiutil.hpp \
    ../../exception.hpp \
    ../../editquery.hpp \
    ../../configuration.hpp \
    ../../apiquery.hpp \
    ../../syslog.hpp \
    ../../wlquery.hpp \
    ../../wikiuser.hpp \
    ../../wikisite.hpp \
    ../../localization.hpp \
    ../../wikipage.hpp \
    ../../webserverquery.hpp \
    ../../revertquery.hpp \
    ../../queryresult.hpp \
    ../../query.hpp \
    ../../history.hpp \
    ../../gc.hpp \
    ../../huggleweb.hpp \
    ../../hugglequeueitemlabel.hpp \
    ../../hugglequeuefilter.hpp \
    ../../hugglequeue.hpp \
    ../../hugglelog.hpp \
    ../../hugglefeedproviderwiki.hpp \
    ../../hugglefeedproviderirc.hpp \
    ../../hugglefeed.hpp \
    deliveryform.h \
    ../../message.hpp

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    maemo5 | !isEmpty(MEEGO_VERSION_MAJOR) {
        installPath = /usr/lib/qt4/imports/$$replace(uri, \\., /)
    } else {
        installPath = $$[QT_INSTALL_IMPORTS]/$$replace(uri, \\., /)
    }
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

FORMS += \
    deliveryform.ui

