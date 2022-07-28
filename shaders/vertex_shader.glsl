#version 330 core

layout (location = 0) in vec3 PositionAttribute;

uniform mat4 uProjectionMatrix;
uniform mat4 uViewMatrix;

void main() {
    gl_Position = uProjectionMatrix * uViewMatrix * vec4(PositionAttribute, 1.0);
}