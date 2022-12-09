#pragma once
#include <glm.hpp>
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(glm::vec3 pos) : pos_(pos) , speed_(5.0f) {}

    void HandleKeyboard(int key, GLfloat delta_time)
    {
        switch (key)
        {
        case GLFW_KEY_W:
            pos_ = pos_ - glm::vec3(0.0f,0.0f, speed_ * delta_time);
            break;
        case GLFW_KEY_S:
            pos_ = pos_ + glm::vec3(0.0f, 0.0f, speed_ * delta_time);
            break;
        case GLFW_KEY_A:
            pos_ = pos_ - glm::vec3(speed_ * delta_time, 0.0f, 0.0f);
            break;
        case GLFW_KEY_D:
            pos_ = pos_ + glm::vec3(speed_ * delta_time, 0.0f, 0.0f);
            break;
        default:
            break;
        }
    }

    glm::vec3 GetPos()
    {
        return pos_;
    }

private:
    glm::vec3 pos_;
    GLfloat speed_;
};