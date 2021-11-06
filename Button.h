#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>            /* ����ͼ�� */
#include <string>
using namespace sf;
using namespace std;

class Button {
public:
	void setTexture(string str);
	void draw();
	void setPosition(float x, float y);
	void setScale(int scale);
	bool onClick(Event event);

	void setFont(Font font);
	void setText(string text);

	bool isActive;//��ť�Ƿ��Ծ״̬
	bool PreBehRel;//�ɿ�֮ǰ�Ƿ���
	RenderWindow* window;
	Sprite buttonSprite;
	Text buttonText;

private:
	Texture buttonTexture;
};