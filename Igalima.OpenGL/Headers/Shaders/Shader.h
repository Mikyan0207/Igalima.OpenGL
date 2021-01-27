#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <iostream>
#include <fstream>

class Shader
{
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	Shader(const Shader&) = default;
	Shader(Shader&&) noexcept = default;
	~Shader();

public:
	Shader& operator=(const Shader&) = default;
	Shader& operator=(Shader&&) noexcept = default;

public:
	void Use();
	void Delete();

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetMat4(const std::string& name, const glm::mat4& matrix);
	void SetVec3(const std::string& name, const glm::vec3& vec3);

private:
	void CheckErrors(const uint32_t& shaderId);
	void LoadShader(const std::string& path, const uint32_t& type);
	void Link();

public:
	uint32_t ProgramId;
	uint32_t VertexShaderId;
	uint32_t FragmentShaderId;
};