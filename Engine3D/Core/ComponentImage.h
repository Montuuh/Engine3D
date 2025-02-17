#ifndef _COMPONENT_IMAGE_H_
#define _COMPONENT_IMAGE_H_

#include "Component.h"
#include "ComponentTransform2D.h"
#include "ModuleTextures.h"

#include "glew.h"

#include "Math/float2.h"
#include "Math/float4.h"
#include "Math/float4x4.h"
#include "Globals.h"
#include <string.h>
#include <vector>

class ComponentMesh;
struct TextureObject;

class ComponentImage : public Component {
public:
	ComponentImage(GameObject* parent);
	~ComponentImage();

	bool Update(float dt) override;
	void OnGui() override;

	inline TextureObject GetTexture() const { return texture; };
	inline float GetOpacity() { return imageColor.w; }
	inline void SetTexture(const TextureObject& newTexture) { texture = newTexture; };
	void SetTextureById(const int id);
	void SetOpacity(float alpha);


	float4x4 GetTransform();
	void OnLoad(const JSONReader& reader) override;
	void OnSave(JSONWriter& writer) const override;

	ComponentMesh* plane = nullptr;
	float4 imageColor = { 1.000f,1.000f, 1.000f, 1.000f };
private:
	std::string texturePath;
	uint textureBufferId = 0;


	//std::string textureName;
	//uint textureId = 0, width = 0, height = 0;


	float4x4 transform;

	TextureObject texture;
};

#endif

