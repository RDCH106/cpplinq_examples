cmake_minimum_required (VERSION 2.8.12)

# Project step I: Check dependencies
# ------------------------------------------------------------------------------------------------------
include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)


# Project step II: Set up project name
# ------------------------------------------------------------------------------------------------------
set(PROJ_MAIN_NAME cpplinq_examples)

# Required libraries, flags, and include files for compiling and linking against CPPLINQ (all targets)
set(CPPLINQ_EXAMPLES_EXTRA_LIBS "")
set(CPPLINQ_EXAMPLES_EXTRA_DEFS "")
set(CPPLINQ_EXAMPLES_EXTRA_INCS "")

# Project step III: Add CPPLINQ VAR
# ------------------------------------------------------------------------------------------------------
list(APPEND CPPLINQ_EXAMPLES_EXTRA_INCS "${CMAKE_CURRENT_SOURCE_DIR}/CppLinq")
MESSAGE("Using CPPLINQ from: ${CPPLINQ_EXAMPLES_EXTRA_INCS}")

# Project step IV: Add samples
# ------------------------------------------------------------------------------------------------------
add_subdirectory(examples)
