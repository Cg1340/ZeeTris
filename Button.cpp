#include "Button.h"

void Button::setTexture(string str) {
	buttonTexture.loadFromFile(str);
	buttonSprite.setTexture(buttonTexture);
}

void Button::draw() {
	isActive = true;//��Ҫ��ʾ����Ϊ��Ծ״̬
	(*window).draw(buttonSprite);
}

void Button::setPosition(float x, float y) {
	buttonSprite.setPosition(x, y);
}

void Button::setScale(int scale) {
	buttonSprite.setScale(scale, scale);
}

bool Button::onClick(Event event) {

	if (!isActive) //�����ť���ǻ�Ծ״̬������ʾ��������Ӧ
		return false;
	bool flag = false;

	FloatRect box = buttonSprite.getGlobalBounds();//��ȡ��ť����Ч�����Χ
	if (Mouse::getPosition(*window).x >= box.left && Mouse::getPosition(*window).x <= (box.left + box.width) && Mouse::getPosition(*window).y >= box.top && Mouse::getPosition(*window).y <= (box.top + box.height)) {
		if (event.type == Event::MouseButtonReleased || event.type == Mouse::Left && PreBehRel)
		{
			PreBehRel = false;//Ҫ�Ȱ������ɿ��ŷ���true
			flag = true;
		}
		else
			flag = false;

		if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)
		{
			this->buttonSprite.setColor(Color(125, 125, 0, 255));//��ť����ʱ����ɫ�Ͳ�͸����
			this->PreBehRel = true;
		}
		else
			this->buttonSprite.setColor(Color(125, 125, 0, 100));//���ָ�Ű�ť��δ����ʱ����ɫ�Ͳ�͸����
	}
	else
		this->buttonSprite.setColor(Color(255, 255, 255, 255));//Ĭ��״̬�İ�ť��ɫ
	return flag;
}

void Button::setFont(Font font) {
	buttonText.setFont(font);
}

void Button::setText(string text) {

}