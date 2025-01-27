#include "engine/AWEngine.hpp"

int main() {

    GLFW_INIT_LIB

    AWEngineWindow engine_window;

    GLAD_INIT_LIB

    glEnable(GL_DEPTH_TEST);

    // Test object
    glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
    float camera_speed = 1.0f;
    AWEngineObject cube("obj/cube.obj");
    cube.set_camera_pos(camera_pos, camera_target);

    // Main loop
    while (!glfwWindowShouldClose(engine_window.window)) {
        glClearColor(0.757f, 0.635f, 0.553f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cube.draw_object();
        cube.camera_movement(&camera_speed, engine_window.window);

        AWEnginePowerOFF(engine_window.window);

        glfwSwapBuffers(engine_window.window);
        glfwPollEvents();
    }
    // End Main loop

    // Free memory
    cube.disable_object();
    
    glfwTerminate();

    return 0;
}


/*  glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, v.size() * sizeof(float), v.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, f.size() * sizeof(unsigned int), f.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/

    /*    std::stringstream ss(obj_src);
    std::string token;
    std::vector<std::string> vtmp;
    std::vector<std::string> ftmp;

    while(std::getline(ss, token, '\n')){
        vtmp = split(token, ' ');

        if(vtmp[0] == "v"){
            v.push_back(std::stof(vtmp[1]));
            v.push_back(std::stof(vtmp[2]));
            v.push_back(std::stof(vtmp[3]));
        }

        if(vtmp[0] == "vt"){
            vt.push_back(std::stof(vtmp[1]));
            vt.push_back(std::stof(vtmp[2]));
            vt.push_back(std::stof(vtmp[3]));
        }

        if(vtmp[0] == "vn"){
            vn.push_back(std::stof(vtmp[1]));
            vn.push_back(std::stof(vtmp[2]));
            vn.push_back(std::stof(vtmp[3]));
        }

        if(vtmp[0] == "f"){
            for(int i = 1; i < vtmp.size(); i++){
                ftmp = split(vtmp[i], '/');
                f.push_back(std::stoi(ftmp[0]) - 1);
                
                ftmp.clear();
                ftmp.shrink_to_fit();
            }
        }

        vtmp.clear();
        vtmp.shrink_to_fit();*/