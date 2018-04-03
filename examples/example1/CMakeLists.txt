# Compile example 1 project
set(PROJ_NAME example1)
project(${PROJ_NAME})

include_directories( ${CPPLINQ_EXAMPLES_EXTRA_INCS} )

add_executable(${PROJ_NAME} example1.cpp)

target_link_libraries(${PROJ_NAME} ${CPPLINQ_EXAMPLES_EXTRA_LIBS})

install(TARGETS ${PROJ_NAME} DESTINATION "${CMAKE_INSTALL_PREFIX}/${PROJ_NAME}/bin")
