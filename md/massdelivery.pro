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
    ../../huggle3-qt-lx/huggle/wikiedit.cpp \
    ../../huggle3-qt-lx/huggle/mainwindow.cpp \
    ../../huggle3-qt-lx/huggle/core.cpp \
    ../../huggle3-qt-lx/huggle/collectable.cpp \
    ../../huggle3-qt-lx/huggle/iextension.cpp \
    ../../huggle3-qt-lx/huggle/editquery.cpp \
    ../../huggle3-qt-lx/huggle/configuration.cpp \
    ../../huggle3-qt-lx/huggle/apiquery.cpp \
    ../../huggle3-qt-lx/huggle/syslog.cpp \
    ../../huggle3-qt-lx/huggle/wlquery.cpp \
    ../../huggle3-qt-lx/huggle/wikiuser.cpp \
    ../../huggle3-qt-lx/huggle/wikisite.cpp \
    ../../huggle3-qt-lx/huggle/localization.cpp \
    ../../huggle3-qt-lx/huggle/wikipage.cpp \
    ../../huggle3-qt-lx/huggle/webserverquery.cpp \
    ../../huggle3-qt-lx/huggle/revertquery.cpp \
    ../../huggle3-qt-lx/huggle/queryresult.cpp \
    ../../huggle3-qt-lx/huggle/query.cpp \
    ../../huggle3-qt-lx/huggle/history.cpp \
    ../../huggle3-qt-lx/huggle/gc.cpp \
    ../../huggle3-qt-lx/huggle/huggleweb.cpp \
    ../../huggle3-qt-lx/huggle/hugglequeueitemlabel.cpp \
    ../../huggle3-qt-lx/huggle/hugglequeuefilter.cpp \
    ../../huggle3-qt-lx/huggle/hugglequeue.cpp \
    ../../huggle3-qt-lx/huggle/hugglelog.cpp \
    ../../huggle3-qt-lx/huggle/hugglefeedproviderwiki.cpp \
    ../../huggle3-qt-lx/huggle/hugglefeedproviderirc.cpp \
    ../../huggle3-qt-lx/huggle/hugglefeed.cpp \
    deliveryform.cpp \
    ../../huggle3-qt-lx/huggle/message.cpp

HEADERS += \
    massdelivery.h \
    ../../huggle3-qt-lx/huggle/mainwindow.hpp \
    ../../huggle3-qt-lx/huggle/wikiedit.hpp \
    ../../huggle3-qt-lx/huggle/core.hpp \
    ../../huggle3-qt-lx/huggle/collectable.hpp \
    ../../huggle3-qt-lx/huggle/iextension.hpp \
    ../../huggle3-qt-lx/huggle/exception.hpp \
    ../../huggle3-qt-lx/huggle/editquery.hpp \
    ../../huggle3-qt-lx/huggle/configuration.hpp \
    ../../huggle3-qt-lx/huggle/apiquery.hpp \
    ../../huggle3-qt-lx/huggle/syslog.hpp \
    ../../huggle3-qt-lx/huggle/wlquery.hpp \
    ../../huggle3-qt-lx/huggle/wikiuser.hpp \
    ../../huggle3-qt-lx/huggle/wikisite.hpp \
    ../../huggle3-qt-lx/huggle/localization.hpp \
    ../../huggle3-qt-lx/huggle/wikipage.hpp \
    ../../huggle3-qt-lx/huggle/webserverquery.hpp \
    ../../huggle3-qt-lx/huggle/revertquery.hpp \
    ../../huggle3-qt-lx/huggle/queryresult.hpp \
    ../../huggle3-qt-lx/huggle/query.hpp \
    ../../huggle3-qt-lx/huggle/history.hpp \
    ../../huggle3-qt-lx/huggle/gc.hpp \
    ../../huggle3-qt-lx/huggle/huggleweb.hpp \
    ../../huggle3-qt-lx/huggle/hugglequeueitemlabel.hpp \
    ../../huggle3-qt-lx/huggle/hugglequeuefilter.hpp \
    ../../huggle3-qt-lx/huggle/hugglequeue.hpp \
    ../../huggle3-qt-lx/huggle/hugglelog.hpp \
    ../../huggle3-qt-lx/huggle/hugglefeedproviderwiki.hpp \
    ../../huggle3-qt-lx/huggle/hugglefeedproviderirc.hpp \
    ../../huggle3-qt-lx/huggle/hugglefeed.hpp \
    deliveryform.h \
    ../../huggle3-qt-lx/huggle/message.hpp

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

