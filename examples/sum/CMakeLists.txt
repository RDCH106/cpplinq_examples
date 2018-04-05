# Compile example 1 project
get_filename_component(PROJ_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" PROJ_NAME ${PROJ_NAME})
project(${PROJ_NAME})

include_directories( ${CPPLINQ_EXAMPLES_EXTRA_INCS} )

file(GLOB SRC
    "*.h"
	"*.hpp"
    "*.cpp"
)

add_executable(${PROJ_NAME} ${SRC})

target_link_libraries(${PROJ_NAME} ${CPPLINQ_EXAMPLES_EXTRA_LIBS})

install(TARGETS ${PROJ_NAME} DESTINATION "${CMAKE_INSTALL_PREFIX}/${PROJ_NAME}/bin")
