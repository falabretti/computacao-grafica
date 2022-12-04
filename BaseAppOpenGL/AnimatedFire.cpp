#include "AnimatedFire.h"

AnimatedFire::AnimatedFire(const LPSTR& textureFilePath, int widthSegments, int heightSegments)
{
	textures.reserve(8);

	for (int idx = 0; idx < 8; idx++)
	{
		AnimatedTexture* texture = new AnimatedTexture();
		texture->LoadTexture(textureFilePath, widthSegments, heightSegments, idx);
		textures.push_back(texture);
	}
}

void AnimatedFire::Draw()
{
	glPushMatrix();
	textures[0]->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	textures[1]->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	textures[2]->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	textures[3]->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(20, 1, 0, 0);
	textures[4]->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-20, 1, 0, 0);
	textures[5]->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(20, 1, 0, 0);
	textures[6]->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(-20, 1, 0, 0);
	textures[7]->Draw();
	glPopMatrix();
}
