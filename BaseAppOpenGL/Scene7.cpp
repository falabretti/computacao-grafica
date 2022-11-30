#include "Scene7.h"

CScene7::CScene7()
{
	pCamera = NULL;
	pTexto = NULL;
	pTextures = NULL;
	
	bIsWireframe = false;
	bIsCameraFPS = true;

	iFPS = 0;
	iFrames = 0;
	ulLastFPS = 0;
	szTitle[256] = 0;

	// Cria gerenciador de impressão de texto na tela
	pTexto = new CTexto();

	// Cria camera
	pCamera = new CCamera(0.0f, 1.0f, 20.0f);

	// Cria o Timer
	pTimer = new CTimer();
	pTimer->Init();

	fTimerPosY = 0.0f;
	fRenderPosY = 0.0f;

	// Carrega todas as texturas
	pTextures = new CTexture();
	pTextures->CreateTextureClamp(0, "../Scene7/Objects/front.bmp");
	pTextures->CreateTextureClamp(1, "../Scene7/Objects/back.bmp");
	pTextures->CreateTextureClamp(2, "../Scene7/Objects/down.bmp");
	pTextures->CreateTextureClamp(3, "../Scene7/Objects/up.bmp");
	pTextures->CreateTextureClamp(4, "../Scene7/Objects/left.bmp");
	pTextures->CreateTextureClamp(5, "../Scene7/Objects/right.bmp");


	// Terrain
	pTerrain = NULL;
	pTerrain = new CModel_3DS();
	pTerrain->Load("../Scene7/Objects/Terrain.3ds");


	// Fire
	pFire1 = NULL;
	pFire1 = new CModel_3DS();
	pFire1->Load("../Scene7/Objects/Fire1.3ds");


	// Cars
	pCar1 = NULL;
	pCar1 = new CModel_3DS();
	pCar1->Load("../Scene7/Objects/Car1.3ds");

	pCar2 = NULL;
	pCar2 = new CModel_3DS();
	pCar2->Load("../Scene7/Objects/Car2.3ds");

	pCar3 = NULL;
	pCar3 = new CModel_3DS();
	pCar3->Load("../Scene7/Objects/Car3.3ds");


	// Boxes
	pBoxes1 = NULL;
	pBoxes1 = new CModel_3DS();
	pBoxes1->Load("../Scene7/Objects/Boxes1.3ds");

	pBoxes2 = NULL;
	pBoxes2 = new CModel_3DS();
	pBoxes2->Load("../Scene7/Objects/Boxes2.3ds");

	pBoxes3 = NULL;
	pBoxes3 = new CModel_3DS();
	pBoxes3->Load("../Scene7/Objects/Boxes3.3ds");

	pBoxes4 = NULL;
	pBoxes4 = new CModel_3DS();
	pBoxes4->Load("../Scene7/Objects/Boxes4.3ds");

	pBoxes5 = NULL;
	pBoxes5 = new CModel_3DS();
	pBoxes5->Load("../Scene7/Objects/Boxes5.3ds");


	// Houses
	pHouse1 = NULL;
	pHouse1 = new CModel_3DS();
	pHouse1->Load("../Scene7/Objects/House1.3ds");

	pHouse2 = NULL;
	pHouse2 = new CModel_3DS();
	pHouse2->Load("../Scene7/Objects/House2.3ds");


	// Trees
	pTree1 = NULL;
	pTree1 = new CModel_3DS();
	pTree1->Load("../Scene7/Objects/Tree1.3ds");
}


CScene7::~CScene7(void)
{
	if (pTexto)
	{
		delete pTexto;
		pTexto = NULL;
	}

	if (pTextures)
	{
		delete pTextures;
		pTextures = NULL;
	}

	if (pCamera)
	{
		delete pCamera;
		pCamera = NULL;
	}

	if (pTimer)
	{
		delete pTimer;
		pTimer = NULL;
	}

	// Terrain
	if (pTerrain)
	{
		delete pTerrain;
		pTerrain = NULL;
	}


	// Fire
	if (pFire1)
	{
		delete pFire1;
		pFire1 = NULL;
	}


	// Cars
	if (pCar1)
	{
		delete pCar1;
		pCar1 = NULL;
	}

	if (pCar2)
	{
		delete pCar2;
		pCar2 = NULL;
	}

	if (pCar3)
	{
		delete pCar3;
		pCar3 = NULL;
	}


	// Boxes
	if (pBoxes1)
	{
		delete pBoxes1;
		pBoxes1 = NULL;
	}

	if (pBoxes2)
	{
		delete pBoxes2;
		pBoxes2 = NULL;
	}

	if (pBoxes3)
	{
		delete pBoxes3;
		pBoxes3 = NULL;
	}

	if (pBoxes4)
	{
		delete pBoxes4;
		pBoxes4 = NULL;
	}

	if (pBoxes5)
	{
		delete pBoxes5;
		pBoxes5 = NULL;
	}


	// Houses
	if (pHouse1)
	{
		delete pHouse1;
		pHouse1 = NULL;
	}

	if (pHouse2)
	{
		delete pHouse2;
		pHouse2 = NULL;
	}


	// Trees
	if (pTree1)
	{
		delete pTree1;
		pTree1 = NULL;
	}
}




int CScene7::DrawGLScene(void)	// Função que desenha a cena
{
	// Get FPS
	if (GetTickCount() - ulLastFPS >= 1000)	// When A Second Has Passed...
	{
		ulLastFPS = GetTickCount();				// Update Our Time Variable
		iFPS = iFrames;							// Save The FPS
		iFrames = 0;							// Reset The FPS Counter
	}
	iFrames++;									// FPS counter
	
	pTimer->Update();							// Atualiza o timer

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpa a tela e o Depth Buffer
	glLoadIdentity();									// Inicializa a Modelview Matrix Atual


	// Seta as posições da câmera
	pCamera->setView();

	// Desenha grid 
	//Draw3DSGrid(20.0f, 20.0f);

	// Desenha os eixos do sistema cartesiano
	DrawAxis();

	// Modo FILL ou WIREFRAME (pressione barra de espaço)	
	if (bIsWireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (INÍCIO)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// Sky Box
	CreateSkyBox(0.0f, 150.0f, 0.0f,
		3000.0f, 3000.0f, 3000.0f,
		pTextures);
	

	// Terrain
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	pTerrain->Draw();
	glPopMatrix();


	// Fire
	glPushMatrix();
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	pFire1->Draw();
	glPopMatrix();


	// Car1
	glPushMatrix();
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	pCar1->Draw();
	glPopMatrix();

	// Car2
	glPushMatrix();
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	pCar2->Draw();
	glPopMatrix();

	// Car3
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	pCar3->Draw();
	glPopMatrix();


	// Boxes1
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	pBoxes1->Draw();
	glPopMatrix();

	// Boxes2
	glPushMatrix();
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	pBoxes2->Draw();
	glPopMatrix();

	// Boxes3
	glPushMatrix();
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	pBoxes3->Draw();
	glPopMatrix();

	// Boxes4
	glPushMatrix();
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	pBoxes4->Draw();
	glPopMatrix();

	// Boxes5
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	pBoxes5->Draw();
	glPopMatrix();


	// House1
	glPushMatrix();
	glColor4f(1.0f, 0.0f, 0.5f, 1.0f);
	pHouse1->Draw();
	glPopMatrix();

	// House2
	glPushMatrix();
	glColor4f(0.0f, 0.5f, 0.5f, 1.0f);
	pHouse2->Draw();
	glPopMatrix();

	
	// Tree1
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(9.5f, 0.0f, -2.6f);
	pTree1->Draw();
	glPopMatrix();

	// Tree2
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(-3.5f, 0.0f, -26.6f);
	pTree1->Draw();
	glPopMatrix();

	// Tree3
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(-7.9f, 0.0f, -26.7f);
	pTree1->Draw();
	glPopMatrix();

	// Tree4
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(-9.0f, 0.0f, -10.9f);
	pTree1->Draw();
	glPopMatrix();

	// Tree5
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(-13.9f, 0.0f, -8.8f);
	pTree1->Draw();
	glPopMatrix();

	// Tree6
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(-20.0f, 0.0f, -10.9f);
	pTree1->Draw();
	glPopMatrix();

	// Tree7
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(-13.8f, 0.0f, -0.5f);
	pTree1->Draw();
	glPopMatrix();

	// Tree8
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glTranslatef(-9.9f, 0.0f, 10.7f);
	pTree1->Draw();
	glPopMatrix();


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (FIM)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	fTimerPosY = pTimer->GetTime() / 1000.0f;
	fRenderPosY += 0.2f;

	// Impressão de texto na tela...
	// Muda para modo de projeção ortogonal 2D
	// OBS: Desabilite Texturas e Iluminação antes de entrar nesse modo de projeção
	OrthoMode(0, 0, WIDTH, HEIGHT);


	glPushMatrix();
	glTranslatef(0.0f, HEIGHT - 100, 0.0f);	// Move 1 unidade para dentro da tela (eixo Z)

	// Cor da fonte
	glColor3f(1.0f, 1.0f, 0.0f);


	glRasterPos2f(10.0f, 0.0f);	// Posicionando o texto na tela
	if (!bIsWireframe) {
		pTexto->glPrint("[TAB]  Modo LINE"); // Imprime texto na tela
	}
	else {
		pTexto->glPrint("[TAB]  Modo FILL");
	}


	//// Camera LookAt
	glRasterPos2f(10.0f, 40.0f);
	pTexto->glPrint("Player LookAt  : %f, %f, %f", pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);

	//// Posição do Player
	glRasterPos2f(10.0f, 60.0f);
	pTexto->glPrint("Player Position: %f, %f, %f", pCamera->Position[0], pCamera->Position[1], pCamera->Position[2]);

	//// Imprime o FPS da aplicação e o Timer
	glRasterPos2f(10.0f, 80.0f);
	pTexto->glPrint("Frames-per-Second: %d ---- Timer: %.1f segundos", iFPS, (pTimer->GetTime()/1000));


	glPopMatrix();

	// Muda para modo de projeção perspectiva 3D
	PerspectiveMode();

	return true;
}




void CScene7::MouseMove(void) // Tratamento de movimento do mouse
{
	// Realiza os cálculos de rotação da visão do Player (através das coordenadas
	// X do mouse.
	POINT mousePos;
	int middleX = WIDTH >> 1;
	int middleY = HEIGHT >> 1;

	GetCursorPos(&mousePos);

	if ((mousePos.x == middleX) && (mousePos.y == middleY)) return;

	SetCursorPos(middleX, middleY);

	fDeltaX = (float)((middleX - mousePos.x)) / 10;
	fDeltaY = (float)((middleY - mousePos.y)) / 10;

	// Rotaciona apenas a câmera
	pCamera->rotateGlob(-fDeltaX, 0.0f, 1.0f, 0.0f);
	pCamera->rotateLoc(-fDeltaY, 1.0f, 0.0f, 0.0f);
}

void CScene7::KeyPressed(void) // Tratamento de teclas pressionadas
{

	// Verifica se a tecla 'W' foi pressionada e move o Player para frente
	if (GetKeyState('W') & 0x80)
	{
		pCamera->moveGlob(pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);
	}
	// Verifica se a tecla 'S' foi pressionada e move o Player para tras
	else if (GetKeyState('S') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Forward[0], -pCamera->Forward[1], -pCamera->Forward[2]);
	}
	// Verifica se a tecla 'A' foi pressionada e move o Player para esquerda
	else if (GetKeyState('A') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Right[0], -pCamera->Right[1], -pCamera->Right[2]);
	}
	// Verifica se a tecla 'D' foi pressionada e move o Player para direira
	else if (GetKeyState('D') & 0x80)
	{
		pCamera->moveGlob(pCamera->Right[0], pCamera->Right[1], pCamera->Right[2]);
	}
	// Senão, interrompe movimento do Player
	else
	{
	}



}

void CScene7::KeyDownPressed(WPARAM	wParam) // Tratamento de teclas pressionadas
{
	switch (wParam)
	{
	case VK_TAB:
		bIsWireframe = !bIsWireframe;
		break;

	case VK_SPACE:
		pTimer->Init();
		break;

	case VK_RETURN:
		break;

	}

}

//	Cria um grid horizontal ao longo dos eixos X e Z
void CScene7::Draw3DSGrid(float width, float length)
{

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.3f, 0.0f);
	glPushMatrix();
	for (float i = -width; i <= length; i += 1)
	{
		for (float j = -width; j <= length; j += 1)
		{
			// inicia o desenho das linhas
			glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(i, 0.0f, j + 1);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(i + 1, 0.0f, j + 1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(i + 1, 0.0f, j);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(i, 0.0f, j);
			glEnd();
		}
	}
	glPopMatrix();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void CScene7::DrawCube(float pX, float pY, float pZ,
	float rX, float rY, float rZ, float angle,
	float sX, float sY, float sZ,
	int texID)
{

	// Seta a textura ativa
	if (texID >= 0)
		pTextures->ApplyTexture(texID);

	glPushMatrix();
	glTranslatef(pX, pY, pZ);
	glRotatef(angle, rX, rY, rZ);
	glScalef(sX, sY, sZ);

	glBegin(GL_QUADS);
	// face frente
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.5f);

	// face trás
	glTexCoord2d(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	
	// face direita
	glTexCoord2d(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// face esquerda
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	// face baixo
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);

	// face cima
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  -0.5f);

	glEnd();

	glPopMatrix();
}


void CScene7::DrawAxis()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	// Eixo X
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);

	// Eixo Y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glVertex3f(0.0f, -1000.0f, 0.0f);

	// Eixo Z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glVertex3f(0.0f, 0.0f, -1000.0f);
	glEnd();
	glPopMatrix();
}


void CScene7::CreateSkyBox(float x, float y, float z,
	float width, float height, float length,
	CTexture* pTextures)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix();

	// Centraliza o Skybox em torno da posição especificada(x, y, z)
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;


	// Aplica a textura que representa a parte da frente do skybox (BACK map)
	pTextures->ApplyTexture(0);

	// Desenha face BACK do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (FRONT map)
	pTextures->ApplyTexture(1);

	// Desenha face FRONT do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (DOWN map)
	pTextures->ApplyTexture(2);

	// Desenha face BOTTOM do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (UP map)
	pTextures->ApplyTexture(3);

	// Desenha face TOP do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y + height, z + length);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (LEFT map)
	pTextures->ApplyTexture(4);

	// Desenha face LEFT do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (RIGHT map)
	pTextures->ApplyTexture(5);

	// Desenha face RIGHT do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	glPopMatrix();
}
