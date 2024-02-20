file(GLOB_RECURSE SIGNAL_SOURCES "*.cpp")
add_library(Signal ${SIGNAL_SOURCES})

target_include_directories(Signal PRIVATE ${PROJECT_SOURCE_DIR}/include/Signal)