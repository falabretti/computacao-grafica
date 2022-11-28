#pragma once
#include "SceneBaseClass.h"
#include "CTexture.h"
#include "CTimer.h"
#include "CTexto.h"
#include "CCamera.h"
#include "VertexData.h"


class CScene3 : public CSceneBaseClass
{
public:
	CScene3();
	~CScene3(void);


	virtual void MouseMove(void);					// Tratamento de movimento do mouse
	virtual void KeyPressed(void);					// Tratamento de teclas pressionadas
	virtual void KeyDownPressed(WPARAM	wParam);	// Tratamento de teclas pressionadas
	virtual int DrawGLScene(void);					// Função que desenha a cena

	void Draw3DSGrid(float width, float length);
	void DrawAxis();

	void DrawCube(float pX = 0.0f, float pY = 0.0f, float pZ = 0.0f,
		float rX = 0.0f, float rY = 0.0f, float rZ = 0.0f, float angle = 0.0f,
		float sX = 1.0f, float sY = 1.0f, float sZ = 1.0f,
		int texID = -1);


private:

	bool	keys[256];		// Array usado para rotinas do teclado
	bool	active;			// Window Active Flag Set To TRUE By Default
	bool	fullscreen;		// Exibir janela em modo fullscreem (TRUE) ou em janela (FALSE)


	CCamera* pCamera;	// Gerencia câmera OpenGL
	float fDeltaY;				// Rotação da câmera OpenGL no eixo Y
	float fDeltaX;				// Rotação da câmera OpenGL no eixo X

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


	unsigned char R;
	unsigned char G;
	unsigned char B;


	// ARCO
	CVector3 vertices[40] = {
			{-146,    0,      87},
			{ -73,    0,	  87},
			{ -73,    0,	-104},
			{ -65,    0,	-138},
			{ -44,    0,	-163},
			{ -16,    0,	-176},
			{  15,    0,	-178},
			{  44,    0,	-167},
			{  65,    0,	-143},
			{  73,    0,	-104},
			{  73,    0,	  87},
			{ 141,    0,	  87},
			{ 141,    0,	-104},
			{ 125,    0,	-173},
			{  84,    0,	-216},
			{  28,    0,	-235},
			{ -33,    0,	-232},
			{ -89,    0,	-207},
			{-130,    0,	-164},
			{-146,    0,	-104},
			{-146,   71,	  87},
			{ -73,   71,	  87},
			{ -73,   71,	-104},
			{ -65,   71,	-138},
			{ -44,   71,	-163},
			{ -16,   71,	-176},
			{  15,   71,	-178},
			{  44,   71,	-167},
			{  65,   71,	-143},
			{  73,   71,	-104},
			{  73,   71,	  87},
			{ 141,   71,	  87},
			{ 141,   71,	-104},
			{ 125,   71,	-173},
			{  84,   71,	-216},
			{  28,   71,	-235},
			{ -33,   71,	-232},
			{ -89,   71,	-207},
			{-130,   71,	-164},
			{-146,   71,	-104}
	};

	// INDICES DO ARCO
	CIndex4 index_vertices[38] = {
			{ 0,  1, 21, 20}, // 0
			{ 1,  2, 22, 21}, // 1
			{ 2,  3, 23, 22}, // 2
			{ 3,  4, 24, 23}, // 3
			{ 4,  5, 25, 24}, // 4
			{ 5,  6, 26, 25}, // 5
			{ 6,  7, 27, 26}, // 6 
			{ 7,  8, 28, 27}, // 7 
			{ 8,  9, 29, 28}, // 8 
			{ 9, 10, 30, 29}, // 9 
			{10, 11, 31, 30}, // 10
			{11, 12, 32, 31}, // 11
			{12, 13, 33, 32}, // 12
			{13, 14, 34, 33}, // 13
			{14, 15, 35, 34}, // 14
			{15, 16, 36, 35}, // 15
			{16, 17, 37, 36}, // 16
			{17, 18, 38, 37}, // 17
			{18, 19, 39, 38}, // 18
			{19,  0, 20, 39}, // 19
			{11, 10,  9, 12}, // 20
			{13, 12,  9,  8}, // 21
			{14, 13,  8,  7}, // 22
			{15, 14,  7,  6}, // 23
			{16, 15,  6,  5}, // 24
			{17, 16,  5,  4}, // 25
			{18, 17,  4,  3}, // 26
			{19, 18,  3,  2}, // 27
			{19,  2,  1,  0}, // 28
			{29, 30, 31, 32}, // 29
			{29, 32, 33, 28}, // 30
			{28, 33, 34, 27}, // 31
			{27, 34, 35, 26}, // 32
			{26, 35, 36, 25}, // 33
			{25, 36, 37, 24}, // 34
			{24, 37, 38, 23}, // 35
			{23, 38, 39, 22}, // 36
			{21, 22, 39, 20}  // 37
	};

	// INDICES DO ARCO
	CColor3 faceColor[38];




};

