set(INCROOT ${PROJECT_SOURCE_DIR}/include/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)

set(PROJECT_HEADER_FILES
# Header files

)

set(PROJECT_SOURCE_FILES
# Source files
    ${SRCROOT}/main.cpp
)

add_subdirectory(FileSys)
add_subdirectory(GUI)
add_subdirectory(Models)
add_subdirectory(Plot)

add_executable(cg-executable
    ${PROJECT_HEADER_FILES}
    ${PROJECT_SOURCE_FILES}
)

target_include_directories(cg-executable PUBLIC ${INCROOT})

target_link_libraries(cg-executable PUBLIC mwf_lib)