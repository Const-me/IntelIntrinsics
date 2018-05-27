cmake_minimum_required( VERSION 3.5 )
project( cpp-demo LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

add_executable( cpp-demo
    intDivide.cpp
    quaternionMul.cpp
    CppDemo.cpp
)

file( GLOB IDIV_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/IDiv/*.* )
source_group( "IDiv" FILES ${IDIV_SOURCES} )

file( GLOB INTRINSICS_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Intrinsics/*.* )
source_group( "Intrinsics" FILES ${INTRINSICS_SOURCES} )

file( GLOB INTRINSICS_IMPL_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Intrinsics/Implementation/*.* )
source_group( "Intrinsics/Implementation" FILES ${INTRINSICS_IMPL_SOURCES} )