add_subdirectory(window)
add_subdirectory(cells)

SET(SOURCES
src/main.cpp
${WINDOW}
${CELLS}
PARENT_SCOPE)