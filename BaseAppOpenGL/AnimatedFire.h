#pragma once
#include <vector>
#include <glaux.h>
#include "AnimatedTexture.h"

class AnimatedFire
{
public:
	AnimatedFire(const LPSTR& textureFilePath, int widthSegments, int heightSegments);
	void Draw();
private:
	vector<AnimatedTexture*> textures;
};
