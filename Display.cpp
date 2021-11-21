#include "Display.h"

//��ʾͼ��
void displaySprite(RenderWindow* window, string filePath, float posX, float posY, float scaleX, float scaleY) {
	Texture texture;
	texture.loadFromFile(filePath);
	Sprite sprite(texture);
	sprite.setPosition(posX, posY);
	sprite.setScale(scaleX, scaleY);
	window->draw(sprite);
}

//��ʾ����(int lo == 0 ����  == 1 ����  == 2 ����)
void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY) {
	Text text;
	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(textSize);
	FloatRect box = text.getGlobalBounds();
	text.setPosition(posX, posY);
	text.setFillColor(Color::White);
	window->draw(text);
}

void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY, int lo) {
	Text text;
	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(textSize);
	FloatRect box = text.getGlobalBounds();
	text.setPosition(posX - (box.width / 2 * lo), posY);
	text.setFillColor(Color::White);
	window->draw(text);
}

void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY, float scaleX, float scaleY, int lo) {
	Text text;
	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(textSize);
	FloatRect box = text.getGlobalBounds();
	text.setPosition(posX - (box.width / 2 * lo), posY);
	text.setScale(scaleX, scaleY);
	text.setFillColor(Color::White);
	window->draw(text);
}

void displayText(RenderWindow* window, Font font, wstring textString, int textSize, float posX, float posY, float scaleX, float scaleY, int lo, Color color) {
	Text text;
	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(textSize);
	FloatRect box = text.getGlobalBounds();
	text.setPosition(posX - (box.width / 2 * lo), posY);
	text.setScale(scaleX, scaleY);
	text.setFillColor(color);
	window->draw(text);
}