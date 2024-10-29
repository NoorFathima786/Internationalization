cmake_minimum_required(VERSION 3.16)

project(DemoInternationalization VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS LinguistTools Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appDemoInternationalization
    main.cpp
)

qt_add_qml_module(appDemoInternationalization
    URI DemoInternationalization
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES stringids.h
)

#qt_add_translations(appDemoInternationalization TS_FILES ${TS_FILES} LRELEASE_OPTIONS -idbased)

# Inform cmake to generate translation files
list(APPEND
    TS_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_en.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_da.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_de.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_es.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_fi.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_fr.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_it.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_nl.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_no.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_pt.ts
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_sv.ts)

qt_add_translations(appDemoInternationalization TS_FILES ${TS_FILES})

file(GLOB_RECURSE tsfiles ${CMAKE_CURRENT_SOURCE_DIR}/translations/*.ts)
add_custom_target(ts_files ALL SOURCES ${tsfiles} DEPENDS update_translations)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDemoInternationalization PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDemoInternationalization
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDemoInternationalization
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appDemoInternationalization
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(ANDROID)
    set_property(TARGET appDemoInternationalization PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android)

    file(GLOB_RECURSE package_files
        ${CMAKE_CURRENT_SOURCE_DIR}/android/*.xml
        ${CMAKE_CURRENT_SOURCE_DIR}/android/*.gradle
        ${CMAKE_CURRENT_SOURCE_DIR}/android/*.properties
        ${CMAKE_CURRENT_SOURCE_DIR}/android/*.png)

    add_custom_target(android_package_source_dir SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/android/AndroidManifest.xml
        ${CMAKE_CURRENT_SOURCE_DIR}/android/build.gradle
        ${CMAKE_CURRENT_SOURCE_DIR}/android/gradle.properties
        ${CMAKE_CURRENT_SOURCE_DIR}/android/gradle/wrapper/gradle-wrapper.jar
        ${CMAKE_CURRENT_SOURCE_DIR}/android/gradle/wrapper/gradle-wrapper.properties
        ${CMAKE_CURRENT_SOURCE_DIR}/android/gradlew
        ${CMAKE_CURRENT_SOURCE_DIR}/android/gradlew.bat
        ${package_files})
endif()
