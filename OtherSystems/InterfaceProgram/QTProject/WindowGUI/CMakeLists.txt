set(CMAKE_AUTOMOC ON)    # 启用 qt moc 的支持
set(CMAKE_AUTORCC ON)    # 启用 qrc 资源文件的支持
set(CMAKE_AUTOUIC ON)    # 启用 qt uic 的支持

find_package(Qt6 COMPONENTS     #查找Qt6的如下库
        Core
        Gui
        Widgets
        Network
        REQUIRED)

aux_source_directory(. DIR_LIB_SRCS)
# 生成链接库
add_library(WindowGUI ${DIR_LIB_SRCS})

target_link_libraries(WindowGUI     #链接Qt6的如下二进制库
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        )