// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include <iostream>

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
	mat3 M, M1, M2;
	M1 = mat3(axis.x*axis.x, axis.x*axis.y, axis.x*axis.z, axis.x*axis.y, axis.y*axis.y, axis.y*axis.z, axis.x*axis.z, axis.y*axis.z, axis.z*axis.z);
	M2 = mat3(0, axis.z, -axis.y, -axis.z, 0, axis.x, axis.y, -axis.x, 0);
	M = cos(degrees / 180 * pi)*mat3(1.0) + (1 - cos(degrees / 180 * pi))*M1 + sin(degrees / 180 * pi)*M2;
  return M;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	//vec3 y = vec3(0, 1, 0);
	vec3 y = up;
	eye = rotate(degrees, y)*eye;
	//up = rotate(degrees, y)*up;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	vec3 x = glm::normalize(glm::cross(eye, up));
	eye = rotate(degrees, x)*eye;
	up = rotate(degrees, x)*up;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
