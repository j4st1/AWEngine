#include "AWEngineObject.hpp"

char* AWEngineObject::read_file(const char* filename) {
    FILE* file = fopen(filename, "rb"); // Открытие в бинарном режиме
    if (!file) {
        perror("ERROR to open");
        return NULL;
    }

    // Перейти в конец файла, чтобы узнать размер
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file); // Получить размер файла
    rewind(file); // Вернуться в начало файла

    // Выделить память для содержимого файла
    char* buffer = (char*)malloc((file_size + 1) * sizeof(char));
    if (!buffer) {
        perror("ERROR to allocate memory");
        fclose(file);
        return NULL;
    }

    // Чтение файла
    size_t read_size = fread(buffer, 1, file_size, file);
    if (read_size != file_size) {
        perror("ERROR reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer[read_size] = '\0'; // Завершающий символ

    fclose(file);

    return buffer;
}

std::vector<std::string> AWEngineObject::split(std::string& str, char split_char) {
  const char* cur = str.c_str();
  const char* str_end = str.c_str() + str.size();
  std::vector<std::string> tokens;

  while (cur < str_end)
  {
    const char* start = cur;
    while (start < str_end and *start == split_char)
        start++;

    const char* end = start + 1;
    while (end < str_end and *end != split_char)
        end++;

    cur = end + 1;
    tokens.push_back(std::string(start, end - start));
  }

  //for(int i = 0; i < tokens.size(); i++){ std::cout << tokens[i] << std::endl; }
  return tokens;
}

void AWEngineObject::obj_parser(){
    obj_src = read_file(path_to_object);

    std::stringstream ss(obj_src);
    std::string tmp;
    std::vector<std::string> tokens;
    std::vector<std::string> tokens_f;

    while(std::getline(ss, tmp, '\n')){

        tokens = split(tmp, ' ');

        //for(int i = 0; i < tokens.size(); i++) std::cout << tokens[i] << " ";

        if(tokens[0] == "v"){
            v.push_back(std::stof(tokens[1]));
            v.push_back(std::stof(tokens[2]));
            v.push_back(std::stof(tokens[3]));
        }

        if(tokens[0] == "vt"){
            vt.push_back(std::stof(tokens[1]));
            vt.push_back(std::stof(tokens[2]));
        }

        if(tokens[0] == "vn"){
            vn.push_back(std::stof(tokens[1]));
            vn.push_back(std::stof(tokens[2]));
            vn.push_back(std::stof(tokens[3]));
        }

        if(tokens[0] == "f"){
            for(int i = 1; i < tokens.size(); i++){
                tokens_f = split(tokens[i], '/');
                f.push_back(std::stoi(tokens_f[0]) - 1);

                tokens_f.clear();
                tokens_f.shrink_to_fit();
            }
        }

        tokens.clear();
        tokens.shrink_to_fit();
    }

    /*std::cout << "V : " << std::endl;
    for(int i = 0; i < v.size(); i++) { std::cout << v[i] << " "; }

    std::cout << std::endl;

    std::cout << "VT : " << std::endl;
    for(int i = 0; i < vt.size(); i++) { std::cout << vt[i] << " "; }

    std::cout << std::endl;

    std::cout << "VN : " << std::endl;
    for(int i = 0; i < vn.size(); i++) { std::cout << vn[i] << " "; }

    std::cout << std::endl;

    std::cout << "F : " << std::endl;
    for(int i = 0; i < f.size(); i++) { std::cout << f[i] << " "; }

    std::cout << std::endl;

    std::cout << "Parse obj is done" << std::endl;*/
}   

void AWEngineObject::create_shader_program(){

    vertex_src = read_file(path_to_vertex_shdr_src);
    fragment_src = read_file(path_to_fragment_shdr_src);

    //std::cout << vertex_src << std::endl;
    //std::cout << fragment_src << std::endl;

    shader_program = glCreateProgram();
    
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_src, nullptr);
    glCompileShader(vertex_shader);

    // vertex shader compilation test
    int success;
    char func_info_log[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, nullptr, func_info_log);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << func_info_log << "\n";
    }

    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_src, nullptr);
    glCompileShader(fragment_shader);

    // fragment shader compilation test
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, nullptr, func_info_log);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << func_info_log << "\n";
    }

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    // Link
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, nullptr, func_info_log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << func_info_log << "\n";
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    glGenVertexArrays(1, &VAO);
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
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    std::cout << "Create shader_program is done" << std::endl;
}

void AWEngineObject::set_camera_pos(glm::vec3 cam_pos, glm::vec3 cam_target){
    camera_pos = cam_pos;
    camera_target = cam_target;
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    camera_direction = glm::normalize(camera_pos - camera_target);
    camera_right = glm::normalize(glm::cross(up, camera_direction));
    camera_up = glm::cross(camera_direction, camera_right);
    camera_front = glm::vec3(0.0f, 1.0f, 0.0f);

    view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    std::cout << "Camera configure is done" << std::endl;
}

void AWEngineObject::camera_movement(float* speed, GLFWwindow* window){
    camera_speed = *speed;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { 
        camera_pos += camera_speed * camera_front;
        //std::cout << "moving forward" << std::endl;
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { 
        camera_pos -= camera_speed * camera_front; 
        //std::cout << "moving back" << std::endl; 
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { 
        camera_pos -= glm::normalize(glm::cross(camera_front, camera_up)) * camera_speed; 
        //std::cout << "moving left" << std::endl; 
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { 
        camera_pos += glm::normalize(glm::cross(camera_front, camera_up)) * camera_speed; 
        //std::cout << "moving right" << std::endl; 
    }
}

/*void AWEngineObject::render_object(){

	// Атрибуты текстурных координат
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);

    std::cout << "Render obj is done" << std::endl;
}*/

void AWEngineObject::draw_object(){
    glUseProgram(shader_program);

    view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    int view_ptr = glGetUniformLocation(shader_program, "view");
    glUniformMatrix4fv(view_ptr, 1, GL_FALSE, glm::value_ptr(view));

    int model_ptr = glGetUniformLocation(shader_program, "model");
    glUniformMatrix4fv(model_ptr, 1, GL_FALSE, glm::value_ptr(model));

    int projection_ptr = glGetUniformLocation(shader_program, "projection");
    glUniformMatrix4fv(projection_ptr, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);
}

void AWEngineObject::disable_object(){
    if (shader_program && VBO && EBO && VAO) {
        glDeleteProgram(shader_program);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glDeleteVertexArrays(1, &VAO);
    }

    std::cout << "Disable obj is done" << std::endl;
}