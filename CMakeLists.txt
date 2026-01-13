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

add_executable(PaintApp src/main.cpp
        src/QtPaintApp.h
        src/QtPaintApp.cpp
        src/paint_surface.cpp
        src/shapes/Shape.h
        src/shapes/Shape.cpp
        src/shapes/Rectangle.h
        src/shapes/Rectangle.cpp
        src/shapes/factory/Factory.h
        src/shapes/factory/ShapeFactory.h
        src/shapes/Triangle.cpp
        src/shapes/Triangle.h
        src/shapes/Triangle.h
        src/tools/Tool.h
        src/tools/DrawTool.h
        src/shapes/Ellipse.cpp
        src/shapes/Ellipse.h
        src/shapes/Manipulator.cpp
        src/shapes/Manipulator.h
        src/tools/DrawTool.cpp
        src/tools/ManipulatorTool.cpp
        src/tools/ManipulatorTool.h
        src/tools/ManipulatorTool.h
        src/shapes/ShapeGroup.cpp
        src/shapes/ShapeGroup.h
        src/shapes/factory/PrototypeShapeFactory.h
        src/commands/Command.h
        src/commands/DrawCommand.cpp
        src/commands/DrawCommand.h
        src/commands/CommandManager.cpp
        src/commands/CommandManager.h
        src/commands/CommandManager.h
        src/commands/MoveCommand.cpp
        src/commands/MoveCommand.h
        src/commands/ResizeCommand.cpp
        src/commands/ResizeCommand.h
        src/Canvas.cpp
        src/Canvas.h
        src/Color.h
        src/PointF.h
        src/painter/Painter.h
        src/painter/PainterImpl.h
        src/painter/QtPainterImpl.h
        src/painter/QtPainterImpl.cpp
        src/painter/Painter.cpp)

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
