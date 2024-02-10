file(GLOB_RECURSE MARKETDATA_SOURCES "*.cpp")
add_library(MarketData ${MARKETDATA_SOURCES})

target_include_directories(MarketData PRIVATE ${PROJECT_SOURCE_DIR}/include/MarketData)