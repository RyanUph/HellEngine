#pragma once

#include "HellEngine/Model.h"
#include "HellEngine/Material.h"
#include "Platform/OpenGL/Shader.h"
#include "Platform/OpenGL/BoundingPlane.h"

namespace HellEngine {
	class Wall
	{
	public: // methods
		Wall(float x, float z, Axis axis, float width, Material* material);
		~Wall();
		void Draw(Shader* shader, bool bindTextures);
		void CalculateModelMatrix();
		glm::mat4 GetModelMatrix();
	
	public: // fields
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec3 scale;
		glm::mat4 modelMatrix;
		float angle;
		Axis axis;
		BoundingPlane boundingPlane;
		float width;
		Material* material;

	private: // methods
		void SetupPlane();

	public: // static fields
		static Model *model;
		//static unsigned int modelMatricesVBO;
	};
}