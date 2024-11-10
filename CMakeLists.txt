cmake_minimum_required(VERSION 3.16)

project(ColorPickerSandbox
    VERSION 0.2
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 6.8 REQUIRED COMPONENTS Quick )

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(Sandbox
    main.cpp
)

qt_add_qml_module(Sandbox
    URI Sandbox
    VERSION 1.0
    QML_FILES
        Main.qml
)

add_subdirectory(Origin)
add_subdirectory(ColorPicker)

set_target_properties(Sandbox PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.sandbox.colorPicker
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(Sandbox
    PRIVATE
    Qt6::Quick
    Origin
    ColorPicker
)

include(GNUInstallDirs)
install(TARGETS Sandbox
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
