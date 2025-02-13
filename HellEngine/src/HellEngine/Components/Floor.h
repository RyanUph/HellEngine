#pragma once
#include "Platform/OpenGL/RenderingPrimitive.h"
#include "HellEngine/Material.h"
#include "HellEngine/Model.h"
#include "Platform/OpenGL/BoundingPlane.h"

namespace HellEngine
{
	class Floor : public RenderingPrimitive
	{
	public: // methods
		Floor();
		~Floor();
		Floor(glm::vec3 position, float width, float depth, Material* material, bool rotateTexture);
		void Draw(Shader *shader, bool bindTextures) override;
		bool rotateTexture = false;

	public: // fields
		Model* model;
		Material* material;

	public: // fields
		unsigned int VAO;
		float width;
		float depth;
		float textureScale = 1;
		BoundingPlane plane;
	};
}