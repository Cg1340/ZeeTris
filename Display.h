#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>            /* ����ͼ�� */
#include <string>
using namespace sf;
using namespace std;

//��ʾͼ��
void displaySprite(RenderWindow* window, string filePath, float posX = 0, float posY = 0, float scaleX = 1, float scaleY = 1);

//��ʾ����
void displayText(RenderWindow* window, Font font, wstring textString, int textSize = 30, float posX = 0, float posY = 0, float scaleX = 1, float scaleY = 1);