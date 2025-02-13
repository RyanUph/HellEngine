#include "hellpch.h"
#include "Floor.h"

namespace HellEngine
{
	Floor::Floor()
	{
	}

	Floor::Floor(glm::vec3 position, float width, float depth, Material* material, bool rotateTexture)
	{
		this->material = material;
		transform.position = position;
		this->width = width;
		this->depth = depth;
		this->rotateTexture = rotateTexture;
		transform.scale = glm::vec3(width, 1, depth);
		this->model = Model::GetByName("UnitPlane.obj");

		glm::vec3 A = position;
		glm::vec3 B = glm::vec3(position.x + width, position.y, position.z);
		glm::vec3 C = glm::vec3(position.x + width, position.y, position.z + depth);
		glm::vec3 D = glm::vec3(position.x, position.y, position.z + depth);
		this->plane = BoundingPlane(A, B, C, D, false, "Floor");
	}

	void Floor::Draw(Shader *shader, bool bindTextures)
	{
		if (bindTextures) 
		{ 
			if (!rotateTexture)
				shader->setInt("TEXTURE_FLAG", 3);
			if (rotateTexture)
				shader->setInt("TEXTURE_FLAG", 4);
		
			shader->setFloat("TEXTURE_SCALE", textureScale);
			material->BindTextures();
		}
		shader->setMat4("model", transform.to_mat4());
		model->Draw(shader);

		if (bindTextures)
		{
			shader->setInt("TEXTURE_FLAG", 0);
			shader->setFloat("TEXTURE_SCALE", textureScale);
		}	
	}

	Floor::~Floor()
	{
	}
}