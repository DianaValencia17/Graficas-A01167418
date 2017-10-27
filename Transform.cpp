#include "Transform.h"


Transform::Transform()
{
	_modelMatrix = glm::mat4(1.0f);
	_position = glm::vec3(0.0, 0.0, 0.0);
	_rotation = glm::radians(glm::vec3(0.0, 0.0, 0.0));
	_scale = glm::vec3(1.1, 1.1, 1.1);

}

glm::mat4 Transform::GetModelMatrix()
{
	return glm::mat4(_modelMatrix);
}

glm::vec3 Transform::GetPosition()
{
	return glm::vec3(_position);
}

glm::quat Transform::GetRotation()
{
	return glm::quat(_rotation);
}

glm::vec3 Transform::GetScale()
{
	return glm::vec3(_scale);
}

void Transform::SetPosition(float x, float y, float z)
{
	_position = (glm::vec3(x, y, z)); 
	UpdateModelMatrix();
}

void Transform::SetRotation(float x, float y, float z)
{
	_rotation = (glm::radians(glm::vec3(x, y, z)));
	UpdateModelMatrix();
}

void Transform::SetScale(float x, float y, float z)
{
	_scale = (glm::vec3(x, y, z));
	UpdateModelMatrix();
}

void Transform::UpdateModelMatrix()
{
	_modelMatrix = glm::mat4_cast(_rotation);
	
	_modelMatrix[0] = _modelMatrix[0] * _scale.x;
	_modelMatrix[1] = _modelMatrix[1] * _scale.y;
	_modelMatrix[2] = _modelMatrix[2] * _scale.z;

	_modelMatrix[3][0] = _modelMatrix[3][0] * _position.x;
	_modelMatrix[3][1] = _modelMatrix[3][1] * _position.y;
	_modelMatrix[3][2] = _modelMatrix[3][2] * _position.z;


}

