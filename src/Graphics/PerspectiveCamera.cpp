#include "BSPViewer/Graphics/PerspectiveCamera.hpp"

PerspectiveCamera::PerspectiveCamera(glm::vec3 position) {
	_position = position;
	_forward = _rotation * glm::vec3(0.0f, 0.0f, -1.0f);
	_right = _rotation * glm::vec3(1.0f, 0.0f, 0.0f);
	_up = _rotation * glm::vec3(0.0f, 1.0f, 0.0f);
    _projectionMatrix = glm::perspective(_fieldOfView, _aspectRatio, _zNear, _zFar);
    _viewMatrix = glm::lookAt(_position, _position + _forward, _up);
}

const glm::vec3& PerspectiveCamera::getPosition() const {
    return _position;
}

void PerspectiveCamera::setPosition(glm::vec3 position) {
    _position = position;
    _viewMatrix = glm::lookAt(_position, _position + _forward, _up);
}

const glm::quat& PerspectiveCamera::getRotation() const {
    return _rotation;
}

void PerspectiveCamera::setRotation(glm::quat rotation) {
    _rotation = rotation;
    _forward = _rotation * glm::vec3(0.0f, 0.0f, -1.0f);
	_right = _rotation * glm::vec3(1.0f, 0.0f, 0.0f);
	_up = _rotation * glm::vec3(0.0f, 1.0f, 0.0f);
    _viewMatrix = glm::lookAt(_position, _position + _forward, _up);
}

float PerspectiveCamera::getAspectRatio() const {
    return _aspectRatio;
}

void PerspectiveCamera::setAspectRatio(float aspectRatio) {
    _aspectRatio = aspectRatio;
    _projectionMatrix = glm::perspective(_fieldOfView, _aspectRatio, _zNear, _zFar);
}

float PerspectiveCamera::getFieldOfView() const {
    return _fieldOfView;
}

void PerspectiveCamera::setFieldOfView(float fieldOfView) {
    _fieldOfView = fieldOfView;
    _projectionMatrix = glm::perspective(_fieldOfView, _aspectRatio, _zNear, _zFar);
}

float PerspectiveCamera::getZNear() const {
    return _zNear;
}

void PerspectiveCamera::setZNear(float zNear) {
    _zNear = zNear;
    _projectionMatrix = glm::perspective(_fieldOfView, _aspectRatio, _zNear, _zFar);
}

float PerspectiveCamera::getZFar() const {
    return _zFar;
}

void PerspectiveCamera::setZFar(float zFar) {
    _zFar = zFar;
    _projectionMatrix = glm::perspective(_fieldOfView, _aspectRatio, _zNear, _zFar);
}

const glm::vec3& PerspectiveCamera::getForward() const {
    return _forward;
}

const glm::vec3& PerspectiveCamera::getRight() const {
    return _right;
}

const glm::vec3& PerspectiveCamera::getUp() const {
    return _up;
}

const glm::mat4& PerspectiveCamera::getProjectionMatrix() const {
    return _projectionMatrix;
}

const glm::mat4& PerspectiveCamera::getViewMatrix() const {
    return _viewMatrix;
}
