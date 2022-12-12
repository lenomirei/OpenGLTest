#pragma once
#include <glm.hpp>
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(glm::vec3 pos) : pos_(pos) , speed_(5.0f) ,front_(glm::vec3(0.0f,0.0f,-1.0f)) {}

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

    void HandleMouse(GLfloat pitch, GLfloat yaw)
    {
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        front_ = glm::normalize(front);
    }

    glm::vec3 GetPos()
    {
        return pos_;
    }

    glm::vec3 GetFront()
    {
        return front_;
    }

private:
    glm::vec3 pos_;
    glm::vec3 front_;
    GLfloat speed_;
};