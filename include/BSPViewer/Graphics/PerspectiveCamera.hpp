#pragma once

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

class PerspectiveCamera {
private:
    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::quat _rotation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));
    float _pitch = 0.0f;
    float _yaw = 0.0f;
    float _aspectRatio = 1.0f;
    float _fieldOfView = 45.0f;
    float _zNear = 0.1f;
    float _zFar = 100.0f;
	glm::vec3 _forward = _rotation * glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 _right = _rotation * glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 _up = _rotation * glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 _projectionMatrix = glm::perspective(_fieldOfView, _aspectRatio, _zNear, _zFar);
    glm::mat4 _viewMatrix = glm::lookAt(_position, _position + _forward, _up);
public:
	PerspectiveCamera() = default;
	PerspectiveCamera(glm::vec3 position);

	[[nodiscard]] const glm::vec3& getPosition() const;
    void setPosition(glm::vec3 position);

    [[nodiscard]] const glm::quat& getRotation() const;
    void setRotation(glm::quat rotation);

    [[nodiscard]] float getAspectRatio() const;
    void setAspectRatio(float aspectRatio);

    [[nodiscard]] float getFieldOfView() const;
    void setFieldOfView(float fieldOfView);

    [[nodiscard]] float getZNear() const;
    void setZNear(float zNear);

    [[nodiscard]] float getZFar() const;
    void setZFar(float zFar);

    [[nodiscard]] const glm::vec3& getForward() const;
    [[nodiscard]] const glm::vec3& getRight() const;
    [[nodiscard]] const glm::vec3& getUp() const;

    [[nodiscard]] const glm::mat4& getProjectionMatrix() const;
    [[nodiscard]] const glm::mat4& getViewMatrix() const;
};
