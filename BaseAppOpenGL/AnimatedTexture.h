#pragma once
#include <vector>
#include <glaux.h>
#include "CTexture.h"

class AnimatedTexture
{
public:

	struct Coordinate {
		float x;
		float y;
	};

	struct TextureCoordinates {
		Coordinate c1;
		Coordinate c2;
		Coordinate c3;
		Coordinate c4;
	};

	AnimatedTexture();
	~AnimatedTexture();
	void Draw();
	void LoadTexture(const LPSTR& filePath, int widthSegments, int heightSegments, int initialTextureIndex);

private:
	CTexture* texture;
	vector<TextureCoordinates> textureCoordinates;
	DWORD lastSecond;
	int textureSegmentCount;
	int textureIndex;
};
