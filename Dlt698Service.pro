#-------------------------------------------------
#
# Project created by QtCreator 2020-09-22T14:47:00
#
#-------------------------------------------------

QT       -= gui

TARGET = Dlt698Service
TEMPLATE = lib

DEFINES += DLT698SERVICE_LIBRARY

SOURCES += dlt698service.cpp \
    dlt698servicefactory.cpp \
    servicereportnotificationrecordlist.cpp \
    dlt698callservice.cpp \
    servicerequest.cpp \
    serviceresponse.cpp \
    servicelinkrequest.cpp \
    servicereportnotificationnormallist.cpp \
    builder/client/clientbuilder.cpp \
    builder/client/get/getrequestbuilder.cpp \
    builder/client/report/reportresponsebuilder.cpp \
    builder/client/report/reportresponserecordlistbuilder.cpp \
    builder/server/report/reportnotificationbuilder.cpp \
    builder/server/serverbuilder.cpp \
    builder/apdubuilder.cpp \
    builder/server/report/reportnotificationrecordlistbuilder.cpp \
    builder/link/linkapdubuilder.cpp \
    builder/link/linkrequestbuilder.cpp \
    builder/link/linkresponsebuilder.cpp \
    builder/client/connect/connectrequestbuilder.cpp \
    builder/server/connnect/connectresponsebuilder.cpp \
    builder/client/report/reportresponselistbuilder.cpp \
    builder/server/report/reportnotificationlistbuilder.cpp

HEADERS += dlt698service.h\
        dlt698service_global.h \
    dlt698servicefactory.h \
    servicereportnotificationrecordlist.h \
    dlt698callservice.h \
    servicerequest.h \
    serviceresponse.h \
    servicelinkrequest.h \
    servicereportnotificationnormallist.h \
    builder/client/clientbuilder.h \
    builder/client/get/getrequestbuilder.h \
    builder/client/report/reportresponsebuilder.h \
    builder/client/report/reportresponserecordlistbuilder.h \
    builder/server/report/reportnotificationbuilder.h \
    builder/server/serverbuilder.h \
    builder/apdubuilder.h \
    builder/server/report/reportnotificationrecordlistbuilder.h \
    builder/link/linkapdubuilder.h \
    builder/link/linkrequestbuilder.h \
    builder/link/linkresponsebuilder.h \
    builder/client/connect/connectrequestbuilder.h \
    builder/server/connnect/connectresponsebuilder.h \
    builder/client/report/reportresponselistbuilder.h \
    builder/server/report/reportnotificationlistbuilder.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/release/ -lDlt698Proctol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/debug/ -lDlt698Proctol
else:unix: LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/ -lDlt698Proctol

INCLUDEPATH += $$PWD/../Dlt698Proctol
DEPENDPATH += $$PWD/../Dlt698Proctol
