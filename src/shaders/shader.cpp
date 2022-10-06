#include "shader.h"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
    //READ SHADERS FROM FILE
    std::string tmpVertShader; //A temporary string to store the entire vertex shader
    std::string tmpFragShader; //A temporary string to store the entire fragment shader

    std::ifstream vertFile(vertexShaderPath); //A input file stream for the vertex shader file
    if (!vertFile)
    {
        std::cout << "ERROR: Could not load Vertex Shader file!" << std::endl;
        
        exit(1); //Returns an error if the file is not found
    }

    std::ifstream fragFile(fragmentShaderPath); //A input file stream for the fragment shader file
    if (!fragFile)
    {
        std::cout << "ERROR: Could not load Fragment Shader file!" << std::endl;

        exit(1); //Returns an error if the file is not found
    }

    //Stringstreams to store the contents of the shader files
    std::stringstream vertShaderStream, fragShaderStream;
    
    //Reads the contents of the files into the stringstreams (rdbuf returns a pointer to the input stream buffer)
    vertShaderStream << vertFile.rdbuf();
    fragShaderStream << fragFile.rdbuf();

    //Close files
    vertFile.close();
    fragFile.close();

    //Convert the stringstreams into strings, then convert those strings into c-style strings
    const char* vertShader = (tmpVertShader = vertShaderStream.str()).c_str();
    const char* fragShader = (tmpFragShader = fragShaderStream.str()).c_str();

    //COMPILE SHADERS
    unsigned vert, frag; //Shader objects
    int compileSuccessFlag; //Flag to tell if compilation was successful
    char compileInfoLog[512]; //Info Log character array for errors

    //////VERTEX SHADER
    vert = glCreateShader(GL_VERTEX_SHADER); //Creates an empty shader object
    glShaderSource(vert, 1, &vertShader, NULL); //Sets the source code within the shader object from the char string loaded earlier
    glCompileShader(vert); //Compiles the shader object

    glGetShaderiv(vert, GL_COMPILE_STATUS, &compileSuccessFlag); //Returns the compile status of the shader

    if (!compileSuccessFlag) //Checks to see if the compilation failed
    {
        glGetShaderInfoLog(vert, 512, NULL, compileInfoLog); //Get the error log for the compilation
        std::cout << "ERROR: Vertex Compilation failed!\n\n" << compileInfoLog << std::endl;
    }

    //////VERTEX SHADER
    frag = glCreateShader(GL_FRAGMENT_SHADER); //Creates an empty shader object
    glShaderSource(frag, 1, &fragShader, NULL); //Sets the source code within the shader object from the char string loaded earlier
    glCompileShader(frag); //Compiles the shader object

    glGetShaderiv(frag, GL_COMPILE_STATUS, &compileSuccessFlag); //Returns the compile status of the shader

    if (!compileSuccessFlag) //Checks to see if the compilation failed
    {
        glGetShaderInfoLog(frag, 512, NULL, compileInfoLog); //Get the error log for the compilation
        std::cout << "ERROR: Vertex Compilation failed!\n\n" << compileInfoLog << std::endl;
    }

    shaderID = glCreateProgram(); //Creates an empty shader program object

    glAttachShader(shaderID, vert); //Attaches the vertex shader object to the shader program
    glAttachShader(shaderID, frag); //Attaches the fragment shader object to the shader program

    glLinkProgram(shaderID); //Links the shader program object to the program
    
    glGetProgramiv(shaderID, GL_LINK_STATUS, &compileSuccessFlag); //Returns the linking status of the shader

    if (!compileSuccessFlag)
    {
        glGetProgramInfoLog(shaderID, 512, NULL, compileInfoLog); //Get the error log for the linking
        std::cout << "ERROR: Failed to link the compiled shaders to the shader program\n\n" << compileInfoLog << std::endl;
    }

    //Delete the shaders to save space (Already linked to our program, so no longer needed)
    glDeleteShader(vert);
    glDeleteShader(frag);
}

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* computeShaderPath)
{
    //READ SHADERS FROM FILE
    std::string tmpVertShader; //A temporary string to store the entire vertex shader
    std::string tmpFragShader; //A temporary string to store the entire fragment shader
    std::string tmpCompShader; //A temporary string to store the entire compute shader

    std::ifstream vertFile(vertexShaderPath); //A input file stream for the vertex shader file
    if (!vertFile)
    {
        std::cout << "ERROR: Could not load Vertex Shader file!" << std::endl;

        exit(1); //Returns an error if the file is not found
    }

    std::ifstream fragFile(fragmentShaderPath); //A input file stream for the fragment shader file
    if (!fragFile)
    {
        std::cout << "ERROR: Could not load Fragment Shader file!" << std::endl;

        exit(1); //Returns an error if the file is not found
    }

    std::ifstream compFile(computeShaderPath); //A input file stream for the fragment shader file
    if (!compFile)
    {
        std::cout << "ERROR: Could not load Compute Shader file!" << std::endl;

        exit(1); //Returns an error if the file is not found
    }

    //Stringstreams to store the contents of the shader files
    std::stringstream vertShaderStream, fragShaderStream, compShaderStream;

    //Reads the contents of the files into the stringstreams (rdbuf returns a pointer to the input stream buffer)
    vertShaderStream << vertFile.rdbuf();
    fragShaderStream << fragFile.rdbuf();
    compShaderStream << compFile.rdbuf();

    //Close files
    vertFile.close();
    fragFile.close();
    compFile.close();

    //Convert the stringstreams into strings, then convert those strings into c-style strings
    const char* vertShader = (tmpVertShader = vertShaderStream.str()).c_str();
    const char* fragShader = (tmpFragShader = fragShaderStream.str()).c_str();
    const char* compShader = (tmpCompShader = compShaderStream.str()).c_str();

    //COMPILE SHADERS
    unsigned vert, frag, comp; //Shader objects
    int compileSuccessFlag; //Flag to tell if compilation was successful
    char compileInfoLog[512]; //Info Log character array for errors

    //////VERTEX SHADER
    vert = glCreateShader(GL_VERTEX_SHADER); //Creates an empty shader object
    glShaderSource(vert, 1, &vertShader, NULL); //Sets the source code within the shader object from the char string loaded earlier
    glCompileShader(vert); //Compiles the shader object

    glGetShaderiv(vert, GL_COMPILE_STATUS, &compileSuccessFlag); //Returns the compile status of the shader

    if (!compileSuccessFlag) //Checks to see if the compilation failed
    {
        glGetShaderInfoLog(vert, 512, NULL, compileInfoLog); //Get the error log for the compilation
        std::cout << "ERROR: Vertex Compilation failed!\n\n" << compileInfoLog << std::endl;
    }

    //////VERTEX SHADER
    frag = glCreateShader(GL_FRAGMENT_SHADER); //Creates an empty shader object
    glShaderSource(frag, 1, &fragShader, NULL); //Sets the source code within the shader object from the char string loaded earlier
    glCompileShader(frag); //Compiles the shader object

    glGetShaderiv(frag, GL_COMPILE_STATUS, &compileSuccessFlag); //Returns the compile status of the shader

    if (!compileSuccessFlag) //Checks to see if the compilation failed
    {
        glGetShaderInfoLog(frag, 512, NULL, compileInfoLog); //Get the error log for the compilation
        std::cout << "ERROR: Vertex Compilation failed!\n\n" << compileInfoLog << std::endl;
    }

    //////COMPUTE SHADER
    comp = glCreateShader(GL_COMPUTE_SHADER); //Creates an empty shader object
    glShaderSource(comp, 1, &compShader, NULL); //Sets the source code within the shader object from the char string loaded earlier
    glCompileShader(comp); //Compiles the shader object

    glGetShaderiv(comp, GL_COMPILE_STATUS, &compileSuccessFlag); //Returns the compile status of the shader

    if (!compileSuccessFlag) //Checks to see if the compilation failed
    {
        glGetShaderInfoLog(comp, 512, NULL, compileInfoLog); //Get the error log for the compilation
        std::cout << "ERROR: Vertex Compilation failed!\n\n" << compileInfoLog << std::endl;
    }

    shaderID = glCreateProgram(); //Creates an empty shader program object

    glAttachShader(shaderID, vert); //Attaches the vertex shader object to the shader program
    glAttachShader(shaderID, frag); //Attaches the fragment shader object to the shader program
    glAttachShader(shaderID, comp); //Attaches the fragment shader object to the shader program

    glLinkProgram(shaderID); //Links the shader program object to the program

    glGetProgramiv(shaderID, GL_LINK_STATUS, &compileSuccessFlag); //Returns the linking status of the shader

    if (!compileSuccessFlag)
    {
        glGetProgramInfoLog(shaderID, 512, NULL, compileInfoLog); //Get the error log for the linking
        std::cout << "ERROR: Failed to link the compiled shaders to the shader program\n\n" << compileInfoLog << std::endl;
    }

    //Delete the shaders to save space (Already linked to our program, so no longer needed)
    glDeleteShader(vert);
    glDeleteShader(frag);
    glDeleteShader(comp);
}

void Shader::ActivateShader()
{
    glUseProgram(shaderID); //Runs the compiled shader
}

void Shader::SetBooleanVariable(const std::string& variableName, bool newValue) const
{
    glUniform1i(glGetUniformLocation(shaderID, variableName.c_str()), (int)newValue); //Accesses a given uniform value from a name, and change its value
}

void Shader::SetIntegerVariable(const std::string& variableName, int newValue) const
{
    glUniform1i(glGetUniformLocation(shaderID, variableName.c_str()), newValue); //Accesses a given uniform value from a name, and change its value
}

void Shader::SetFloatVariable(const std::string& variableName, float newValue) const
{
    glUniform1f(glGetUniformLocation(shaderID, variableName.c_str()), newValue); //Accesses a given uniform value from a name, and change its value
}