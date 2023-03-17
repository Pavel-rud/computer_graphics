set(INCROOT ${PROJECT_SOURCE_DIR}/include/Models/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Models/)

set(SRC
    ${INCROOT}/Signal.h
    ${SRCROOT}/Signal.cpp
)

add_library(cg-models ${SRC})

set_target_properties(cg-models PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(cg-models PUBLIC ${PROJECT_SOURCE_DIR}/include)