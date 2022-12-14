#pragma once
#include "SceneBaseClass.h"
#include "CTexture.h"
#include "CTimer.h"
#include "CTexto.h"
#include "CCamera.h"
#include "CModel_3DS.h"
#include "AnimatedFire.h"

class CScene7 : public CSceneBaseClass
{
public:
	CScene7();
	~CScene7(void);


	virtual void MouseMove(void);					// Tratamento de movimento do mouse
	virtual void KeyPressed(void);					// Tratamento de teclas pressionadas
	virtual void KeyDownPressed(WPARAM	wParam);	// Tratamento de teclas pressionadas
	virtual int DrawGLScene(void);					// Fun??o que desenha a cena

	void Draw3DSGrid(float width, float length);
	void DrawAxis();

	void DrawCube(float pX = 0.0f, float pY = 0.0f, float pZ = 0.0f,
		float rX = 0.0f, float rY = 0.0f, float rZ = 0.0f, float angle = 0.0f,
		float sX = 1.0f, float sY = 1.0f, float sZ = 1.0f,
		int texID = -1);

	void CreateSkyBox(float x, float y, float z,
		float width, float height, float length,
		CTexture* pTextures);

private:

	bool	keys[256];		// Array usado para rotinas do teclado
	bool	active;			// Window Active Flag Set To TRUE By Default
	bool	fullscreen;		// Exibir janela em modo fullscreem (TRUE) ou em janela (FALSE)


	CCamera* pCamera;	// Gerencia c?mera OpenGL
	float fDeltaY;				// Rota??o da c?mera OpenGL no eixo Y
	float fDeltaX;				// Rota??o da c?mera OpenGL no eixo X

	CTexto* pTexto;	// Objeto que gerencia texto
	CTexture* pTextures;	// Objeto que gerencia texturas
	CTimer* pTimer;	// Objeto que gerencia o timer


	int		iFPS;			// FPS and FPS Counter
	int		iFrames;		// FPS and FPS Counter
	DWORD	ulLastFPS;		// FPS and FPS Counter
	char	szTitle[256];	// FPS and FPS Counter


	bool bIsWireframe;	// Modos Wireframe/Solid
	bool bIsCameraFPS;	// Ativa modo de camera First Person Shooter (true) ou Third Person Shooter (false)

	float fRenderPosY;
	float fTimerPosY;


	// Terrain
	CModel_3DS* pTerrain;

	// Fire
	AnimatedFire* pFire;

	// Cars
	CModel_3DS* pCar1;
	CModel_3DS* pCar2;
	CModel_3DS* pCar3;

	// Boxes
	CModel_3DS* pBoxes1;
	CModel_3DS* pBoxes2;
	CModel_3DS* pBoxes3;
	CModel_3DS* pBoxes4;
	CModel_3DS* pBoxes5;

	// Houses
	CModel_3DS* pHouse1;
	CModel_3DS* pHouse2;

	// Trees
	CModel_3DS* pTree1;
	CModel_3DS* pTree2;
	CModel_3DS* pTree3;
	CModel_3DS* pTree4;
	CModel_3DS* pTree5;
	CModel_3DS* pTree6;
	CModel_3DS* pTree7;
	CModel_3DS* pTree8;
};
