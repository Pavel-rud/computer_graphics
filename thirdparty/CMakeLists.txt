include(FetchContent)

set(SFML_VERSION "2.6.x")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY  https://github.com/SFML/SFML.git
    GIT_TAG         ${SFML_VERSION}
)

FetchContent_GetProperties(sfml)

if(NOT sfml_POPULATED)
    message("SFML uploading...")

    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

FetchContent_Declare(mwf
    GIT_REPOSITORY https://github.com/TheMusicBoy/MyWindowFramework.git)

FetchContent_GetProperties(mwf)

if(NOT mwf_POPULATE)
    message("MyWindowFramework uploading...")

    FetchContent_Populate(mwf)
    add_subdirectory(${mwf_SOURCE_DIR} ${mwf_BINARY_DIR})
endif()
