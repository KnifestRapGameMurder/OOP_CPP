#include<GL/glew.h>
#include <GLFW/glfw3.h>
//#include<GL/glut.h>

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

#include"Renderer.h"

#include"VertexBuffer.h"
#include"VertexBufferLayout.h"
#include"IndexBuffer.h"
#include"VertexArray.h"
#include"Shader.h"
#include"Texture.h"

int main(void)
{
    GLFWwindow* window;

    

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_COMPAT_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(720, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(2);

    //IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    {
        float positions[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,  //  0
             0.5f, -0.5f, 1.0f, 0.0f,  //  1
             0.5f,  0.5f, 1.0f, 1.0f,  //  2
            -0.5f,  0.5f, 0.0f, 1.0f  //  3
        };

        unsigned int indices[] = {
            0,1,2,
            2,3,0
        };

        VertexArray va;
        VertexBuffer vb(positions, 4 * 2 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb,layout);

        IndexBuffer ib(indices, 6);

        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        Texture texture("res/textures/texture.png");
        texture.Bind();
        shader.SetUniform1i("u_Texture", 0);

        va.Unbind();
        vb.Unbind();
        ib.Unbind();
        shader.Undind();

        Renderer renderer;

        float r = 0.0f;
        float r_increm = 0.05f;
        float g = 0.0f;
        float g_increm = 0.01f;
        float b = 0.0f;
        float b_increm = 0.015f;


        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            renderer.Clear();

            shader.Bind();
            shader.SetUniform4f("u_Color", r, g, b, 1.0f);

            renderer.Draw(va,ib,shader);

            if (r > 1.0f)
                r_increm = -r_increm;
            else if (r < 0.0f)
                r_increm = -r_increm;
            if (g > 1.0f)
                g_increm = -g_increm;
            else if (g < 0.0f)
                g_increm = -g_increm;
            if (b > 1.0f)
                b_increm = -b_increm;
            else if (b < 0.0f)
                b_increm = -b_increm;

            r += r_increm;
            g += g_increm;
            b += b_increm;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        shader.Undind();
    }
    
    glfwTerminate();
    return 0;
}