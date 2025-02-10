cmake_minimum_required(VERSION 3.26)
project(PaintApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/msys64/mingw64/bin")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(PaintApp main.cpp
        QtPaintApp.h
        QtPaintApp.cpp
        paint_surface.cpp
        shapes/Shape.h
        shapes/Shape.cpp
        shapes/Rectangle.h
        shapes/Rectangle.cpp
        shapes/factory/Factory.h
        shapes/factory/ShapeFactory.h
        shapes/Triangle.cpp
        shapes/Triangle.h
        shapes/Triangle.h
        tools/Tool.h
        tools/DrawTool.h
        shapes/Ellipse.cpp
        shapes/Ellipse.h
        shapes/Manipulator.cpp
        shapes/Manipulator.h
        tools/DrawTool.cpp
        tools/ManipulatorTool.cpp
        tools/ManipulatorTool.h
        tools/ManipulatorTool.h
        shapes/ShapeGroup.cpp
        shapes/ShapeGroup.h
        shapes/factory/PrototypeShapeFactory.h
        commands/Command.h
        commands/DrawCommand.cpp
        commands/DrawCommand.h
        commands/CommandManager.cpp
        commands/CommandManager.h
        commands/CommandManager.h
        commands/MoveCommand.cpp
        commands/MoveCommand.h
        commands/ResizeCommand.cpp
        commands/ResizeCommand.h
        Canvas.cpp
        Canvas.h
        Color.h
        PointF.h
        painter/Painter.h
        painter/PainterImpl.h
        painter/QtPainterImpl.h
        painter/QtPainterImpl.cpp
        painter/Painter.cpp)

target_link_libraries(PaintApp
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
