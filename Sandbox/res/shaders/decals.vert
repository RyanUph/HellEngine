#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;
layout(location = 3) in vec3 aTangent;
layout(location = 4) in vec3 aBitangent;
layout(location = 5) in ivec4 aBoneID;
layout(location = 6) in vec4 aBoneWeight;
layout(location = 7) in mat4 instancedModelMatrix;

uniform mat4 pv;
uniform mat4 model;
uniform bool animated;
uniform bool instanced;
uniform mat4 jointTransforms[50];	// hardcoded maximum bones 50

out vec3 FragPos;
out vec2 TexCoords;
out vec3 Normal;
out mat3 TBN;

void main()
{
	// Instancing?
	mat4 modelMatrix = model;
	if (instanced)
		modelMatrix = instancedModelMatrix;

	vec4 worldPos;
	vec4 totalLocalPos = vec4(0.0);
	vec4 totalNormal = vec4(0.0);
	mat3 normalMatrix = transpose(inverse(mat3(modelMatrix)));


	worldPos = modelMatrix * vec4(aPos, 1.0);
	Normal = aNormal;

	vec3 T = normalize(vec3(modelMatrix * vec4(aTangent, 0.0)));
	vec3 B = normalize(vec3(modelMatrix * vec4(aBitangent, 0.0)));
	vec3 N = normalize(vec3(modelMatrix * vec4(Normal, 0.0)));
	TBN = mat3(T, B, N);

	Normal = normalMatrix * Normal;


	TexCoords = aTexCoords;
	FragPos = worldPos.xyz;
	gl_Position = pv * worldPos;
}
//Normal = mat3(model) * aNormal;		// PBR 


