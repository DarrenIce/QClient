#include "throwpkm.h"

ThrowPkm::ThrowPkm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ThrowPkm::~ThrowPkm()
{
}
void ThrowPkm::throwpkm(User* uptr, std::vector<Pokemon*> &vec)
{
	int size = vec.size();
	int pm[3] = { 0 };
	if (size == 1)
	{
		pm[0] = 0;
		pm[1] = -1;
		pm[2] = -1;
	}
	else if (size == 2)
	{
		pm[0] = 0;
		pm[1] = 1;
		pm[2] = -1;
	}
	else if (size == 3)
	{
		pm[0] = 0;
		pm[1] = 1;
		pm[2] = 2;
	}
	else
	{
		std::vector<int> temp;
		for (int i = 0; i < size; i++)
		{
			temp.push_back(i);
		}
		random_shuffle(temp.begin(), temp.end());
		pm[0] = temp.at(0);
		pm[1] = temp.at(1);
		pm[2] = temp.at(2);
	}

}
