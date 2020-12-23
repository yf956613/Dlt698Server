#-------------------------------------------------
#
# Project created by QtCreator 2020-09-19T10:10:32
#
#-------------------------------------------------

QT       -= gui

TARGET = Dlt698Proctol
TEMPLATE = lib

DEFINES += DLT698PROCTOL_LIBRARY

SOURCES += \
    apdu/dlt698apdu.cpp \
    apdu/dlt698ctrldomain.cpp \
    apdu/dlt698lendomain.cpp \
    apdu/dlt698srvaddr.cpp \
    client/connect/dlt698connectmechanisminfo.cpp \
    client/connect/dlt698connectrequest.cpp \
    client/report/dlt698reportresponse.cpp \
    client/report/dlt698reportresponserecordlist.cpp \
    client/dlt698clientapdu.cpp \
    common/dlt698datetime.cpp \
    common/dlt698datetimes.cpp \
    common/dlt698functionconformance.cpp \
    common/dlt698piid.cpp \
    common/dlt698piidacd.cpp \
    common/dlt698protocolconformance.cpp \
    common/dlt698randnum.cpp \
    common/dlt698ti.cpp \
    common/dlt698timetag.cpp \
    link/dlt698linkapdu.cpp \
    link/dlt698linkrequest.cpp \
    link/dlt698linkresponse.cpp \
    server/connect/dlt698connectresponse.cpp \
    server/connect/dlt698connectresponseinfo.cpp \
    server/get/dlt698getresponsenormal.cpp \
    server/get/dlt698getresponsenormallist.cpp \
    server/get/dlt698getresponserecord.cpp \
    server/get/dlt698getresponserecordlist.cpp \
    server/report/dlt698reportnotification.cpp \
    server/dlt698data.cpp \
    server/dlt698followreport.cpp \
    server/dlt698serverapdu.cpp \
    dlt698proctol.cpp \
    dltobject.cpp \
    dltstringbuffer.cpp \
    datatype/data.cpp \
    datatype/datafactory.cpp \
    client/get/getrequestnormal.cpp \
    datatype/struct.cpp \
    datatype/oad.cpp \
    client/get/getrequest.cpp \
    common/dar.cpp \
    server/resultnormal.cpp \
    server/resultrecord.cpp \
    datatype/road.cpp \
    datatype/csd.cpp \
    datatype/rcsd.cpp \
    datatype/oi.cpp \
    server/get/getresponse.cpp \
    client/get/getrequestnormallist.cpp \
    client/report/reportresponselist.cpp

HEADERS += \
    apdu/dlt698apdu.h \
    apdu/dlt698ctrldomain.h \
    apdu/dlt698lendomain.h \
    apdu/dlt698srvaddr.h \
    client/connect/dlt698connectmechanisminfo.h \
    client/connect/dlt698connectrequest.h \
    client/report/dlt698reportresponse.h \
    client/report/dlt698reportresponserecordlist.h \
    client/dlt698clientapdu.h \
    common/dlt698datetime.h \
    common/dlt698datetimes.h \
    common/dlt698functionconformance.h \
    common/dlt698piid.h \
    common/dlt698piidacd.h \
    common/dlt698protocolconformance.h \
    common/dlt698randnum.h \
    common/dlt698ti.h \
    common/dlt698timetag.h \
    link/dlt698linkapdu.h \
    link/dlt698linkrequest.h \
    link/dlt698linkresponse.h \
    server/connect/dlt698connectresponse.h \
    server/connect/dlt698connectresponseinfo.h \
    server/get/dlt698getresponsenormal.h \
    server/get/dlt698getresponsenormallist.h \
    server/get/dlt698getresponserecord.h \
    server/get/dlt698getresponserecordlist.h \
    server/report/dlt698reportnotification.h \
    server/dlt698data.h \
    server/dlt698followreport.h \
    server/dlt698serverapdu.h \
    dlt698datatypes.h \
    dlt698proctol.h \
    dlt698proctol_global.h \
    dltobject.h \
    dltstringbuffer.h \
    datatype/data.h \
    datatype/datafactory.h \
    client/get/getrequestnormal.h \
    datatype/basic.h \
    datatype/array.h \
    datatype/struct.h \
    datatype/oad.h \
    client/get/getrequest.h \
    common/dar.h \
    server/resultnormal.h \
    server/resultrecord.h \
    datatype/road.h \
    datatype/csd.h \
    datatype/rcsd.h \
    datatype/oi.h \
    datatype/row.h \
    server/get/getresponse.h \
    client/get/getrequestnormallist.h \
    client/report/reportresponselist.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
