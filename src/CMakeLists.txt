add_subdirectory(window)
add_subdirectory(cells)
add_subdirectory(shaders)

SET(SOURCES
src/main.cpp
${WINDOW}
${CELLS}
${SHADERS}
PARENT_SCOPE)