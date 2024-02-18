#include <GL/glew.h> // path here is the path FROM the compiler include directory
#include <GLFW/glfw3.h>
#include <iostream>

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // must be called AFTER a context has been created
    if (glewInit() != GLEW_OK) {
        std::cout << "Not ok" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;
    // Drawing a basic triangle
    //================================================================
    float positions[6] = { // each line is a vertex, xy coordinate
       -0.5f,   -0.5f,
        0.0f,    0.5f,
        0.5f,   -0.5f
    };

    unsigned int buffer; // it wants an int to write its data into
    glGenBuffers(1, &buffer); // puts in the ID of the generated buffer, the function returns void so we have to have somewhere to store it
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // bind (select) the buffer, now we are ready to work with the buffer
                // target           size            where       what to do
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glEnableVertexAttribArray(0); // this is needed to actually activate the previous code
    //================================================================


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        

        glDrawArrays(GL_TRIANGLES, 0, 3); // the draw call
        




        /* Swap front and back buffers */
        glfwSwapBuffers(window);





        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}