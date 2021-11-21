#include "SteadyClock.h"

void SteadyClock::restart() {
	this->startPoi = steady_clock::now();
	pauseTime.resize(0);
}

void SteadyClock::pause() {
	//��¼��ͣ��ʱ���
	this->pausePoi = steady_clock::now();
}

void SteadyClock::start() {
	long long res = duration_cast<std::chrono::milliseconds>(steady_clock::now() - this->pausePoi).count();
	//��vector����һ������
	this->pauseTime.push_back(res);
}

long long SteadyClock::getPauseTime() {
	long long res = duration_cast<std::chrono::milliseconds>(steady_clock::now() - this->pausePoi).count();
	return res >= 0 ? res : -res;
}

long long SteadyClock::getTime() {
	long long res = duration_cast<std::chrono::milliseconds>(steady_clock::now() - this->startPoi).count();
	if (pauseTime.size() != 0) {
		for (vector<long long>::iterator i = pauseTime.begin(); i != pauseTime.end(); i++) {
			res = res - *i;
		}
	}
	return res >= 0 ? res : -res;
}