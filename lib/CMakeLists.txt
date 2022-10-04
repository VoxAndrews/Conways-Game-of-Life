add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(glad)

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
    glad/include
    glfw/include
    glm
)