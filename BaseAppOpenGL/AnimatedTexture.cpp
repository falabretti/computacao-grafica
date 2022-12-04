#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture() {
	texture = new CTexture();
	lastSecond = 0;
	textureIndex = 0;
	textureSegmentCount = 0;
}

AnimatedTexture::~AnimatedTexture()
{
	if (texture) {
		delete texture;
		texture = nullptr;
	}
}

void AnimatedTexture::LoadTexture(const LPSTR& filePath, int widthSegments, int heightSegments, int initialTextureIndex) {
	texture->CreateTextureTGA(0, filePath);

	const float segmentWidth = 1.0f / widthSegments;
	const float segmentHeight = 1.0f / heightSegments;

	textureSegmentCount = widthSegments * heightSegments;
	textureCoordinates.reserve(textureSegmentCount);

	for (float j = 1 - segmentHeight; j >= 0; j -= segmentHeight) {
		for (float i = 0; i <= 1 - segmentWidth ; i += segmentWidth) {
			Coordinate c1 = { i, j };
			Coordinate c2 = { i + segmentWidth, j };
			Coordinate c3 = { i + segmentWidth, j + segmentHeight };
			Coordinate c4 = { i, j + segmentHeight };
			textureCoordinates.push_back({ c1, c2, c3, c4 });
		}
	}

	textureIndex = initialTextureIndex % textureSegmentCount;
}

void AnimatedTexture::Draw()
{
	if (GetTickCount64() - lastSecond >= 75)
	{
		lastSecond = GetTickCount64();
		textureIndex = (textureIndex + 1) % textureSegmentCount;
	}

	glDisable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.95f);

	glColor4f(1, 1, 1, 1.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);

	texture->ApplyTexture(0);

	glPushMatrix();
	glBegin(GL_QUADS);

	TextureCoordinates coordinates = textureCoordinates[textureIndex];

	glTexCoord2f(coordinates.c1.x, coordinates.c1.y); glVertex3f(-5.0, 0.0, 0.0);
	glTexCoord2f(coordinates.c2.x, coordinates.c2.y); glVertex3f(5.0, 0.0, 0.0);
	glTexCoord2f(coordinates.c3.x, coordinates.c3.y); glVertex3f(5.0, 10.0, 0.0);
	glTexCoord2f(coordinates.c4.x, coordinates.c4.y); glVertex3f(-5.0, 10.0, 0.0);

	glEnd();
	glPopMatrix();

	glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glEnable(GL_CULL_FACE);
}
