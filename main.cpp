#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

static bool shouldClose = false;

void resize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        shouldClose = true;
}


int main(int argc, char **argv)
{
     if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);

    GLFWwindow* window = glfwCreateWindow(900, 600, "Title", NULL, NULL);
    

    while (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, resize);
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL();


    glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (shouldClose)
            break;
    }


    glfwTerminate();
    return -1;
}
