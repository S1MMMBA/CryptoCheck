cmake_minimum_required(VERSION 3.5)

project(CryptoCheck VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(BEE2 bee2 "libs")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        BlockCrypt.h
        BlockCrypt.cpp
        CommonFunc.h
        CommonFunc.cpp
        DataCrypt.h
        DataCrypt.cpp
        DataCryptCBC.h
        DataCryptCBC.cpp
        DataCryptCFB.h
        DataCryptCFB.cpp
        DataCryptCTR.h
        DataCryptCTR.cpp
        ProduceMAC.h
        ProduceMAC.cpp
        InstallMAC.h
        InstallMAC.cpp
        InstallKeyMAC.h
        InstallKeyMAC.cpp
        Hash.h
        Hash.cpp
        DiskCrypt.h
        DiskCrypt.cpp
        DiskCrypt2.h
        DiskCrypt2.cpp
        SaveFormatCrypt.h
        SaveFormatCrypt.cpp
        ExpandKey.h
        ExpandKey.cpp
        ModifyKey.h
        ModifyKey.cpp
        Hash_34_101_77.h
        Hash_34_101_77.cpp
        HashProg_34_101_77.h
        HashProg_34_101_77.cpp
        AuthCrypt_34_101_77.h
        AuthCrypt_34_101_77.cpp
        ProduceMAC_HMAC_47.h
        ProduceMAC_HMAC_47.cpp
        RandomGenCTR_47.h
        RandomGenCTR_47.cpp
        RandomGenHMAC_47.h
        RandomGenHMAC_47.cpp
        GenPassHOTP.h
        GenPassHOTP.cpp
        GenPassTOTP.h
        GenPassTOTP.cpp
        GenPassOCRA.h
        GenPassOCRA.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CryptoCheck
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CryptoCheck APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CryptoCheck SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CryptoCheck
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#target_link_libraries(CryptoCheck ${BEE2})
target_include_directories(CryptoCheck PRIVATE "include/")

target_link_libraries(CryptoCheck PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${BEE2})

set_target_properties(CryptoCheck PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS CryptoCheck
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CryptoCheck)
endif()
