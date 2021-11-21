#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>            /* ����ͼ�� */
#include <string>
using namespace sf;
using namespace std;

//��ʾͼ��
void displaySprite(RenderWindow* window, string filePath, float posX, float posY, float scaleX, float scaleY);

//��ʾ����(int lo == 0 ����  == 1 ����  == 2 ����)
void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY);
void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY, int lo);
void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY, float scaleX, float scaleY, int lo);
void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY, float scaleX, float scaleY, int lo, Color color);