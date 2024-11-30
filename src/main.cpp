#include <stdlib.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void errorCallbacl(int error, const char *description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Set GLFW error callback
    glfwSetErrorCallback(errorCallbacl);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create windows
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // Make openGl context current
    glfwMakeContextCurrent(window);

    // Initilize GLFW
    // glewExperimental = GL_TRUE;

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        float time = (float)glfwGetTime();
        float red = (std::sin(time * 0.5f) + 1.0f) / 2.0f;
        float green = (std::sin(time * 0.3f) + 1.0f) / 2.0f;
        float blue = (std::sin(time * 0.7f) + 1.0f) / 2.0f;

        // clear color buffer
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(red,green,blue,10.f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "hello cpp" << std::endl;
    return EXIT_SUCCESS;
}