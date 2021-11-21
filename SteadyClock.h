#pragma once
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

class SteadyClock
{
public:
	void restart();//���¿�ʼ
	void pause();//��ʱ����ͣ
	void start();//��ʱ����ͣ
	long long getPauseTime();//��ȡ��ͣ��ʱ�䣨���룩
	long long getTime();//��ȡʱ�䣨���룩

private:
	steady_clock::time_point startPoi;
	steady_clock::time_point pausePoi;
	vector<long long> pauseTime;
};