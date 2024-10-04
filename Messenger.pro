QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# 프로젝트에 포함할 include 경로 설정
INCLUDEPATH += src/controller \
               src/controller/header \
               src/controller/source \
               src/view

# 소스 파일
SOURCES += \
    main.cpp \
    src/controller/source/chatlistwindow.cpp \
    src/controller/source/contactlistwindow.cpp \
    src/controller/source/loginwindow.cpp \
    src/controller/source/mainwindow.cpp

# 헤더 파일
HEADERS += \
    src/controller/header/chatlistwindow.h \
    src/controller/header/contactlistwindow.h \
    src/controller/header/loginwindow.h \
    src/controller/header/mainwindow.h

# UI forms 파일
FORMS += \
    src/view/chatlistwindow.ui \
    src/view/contactlistwindow.ui \
    src/view/loginwindow.ui \
    src/view/mainwindow.ui


# MOC 파일을 저장할 디렉토리 (선택사항)
# MOC_IDR = moc
