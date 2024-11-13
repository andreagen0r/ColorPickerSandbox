cmake_minimum_required(VERSION 3.16)

project(ColorPickerSandbox
    VERSION 0.2
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 6.8 REQUIRED COMPONENTS Quick )

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(sandbox
    main.cpp
)

qt_add_qml_module(sandbox
    URI Sandbox
    VERSION 1.0
    QML_FILES
        Main.qml
)

add_subdirectory(Origin/Controls)
add_subdirectory(ColorPicker)

set_target_properties(sandbox PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.sandbox.colorPicker
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(sandbox
    PRIVATE
    Qt6::Quick
    Originplugin
    ColorPickerModuleplugin
)

include(GNUInstallDirs)
install(TARGETS sandbox
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
