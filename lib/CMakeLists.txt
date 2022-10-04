add_subdirectory(glfw)


target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
    glfw/include
)