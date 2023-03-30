#include <iostream>
using namespace std;
#include <assert.h>
#include <vector>

class Car
{
protected:
	string _carName;
	string _carModel;
	string _carColour;
public:

	//=================================Contructors=================================================================
	Car()
	{
		cout << "def car const" << endl;
	}


	Car(string carName, string carModel, string carColour)
	{
		//this->_carName = carName;
		setCarName(carName);
		setCarModel(carModel);
		setCarColour(carColour);
	}

	virtual void showCar()
	{
		cout << "      ***Info Car***" << endl;
		cout << "Car Name: " << this->_carName << endl;
		cout << "Car Model: " << this->_carModel << endl;
		cout << "Car Colour: " << this->_carColour << endl;
	}

	virtual ~Car() = 0
	{
		this->_carColour = " ";
		this->_carModel = " ";
		this->_carName = " ";
	}

	//====================================SET Functions===================================================

	void setCarName(string carName)
	{
		if (carName == " ")
		{
			assert(!"Car Name can not be empty");
		}
		this->_carName = carName;

	}

	void setCarModel(string carModel)
	{
		if (carModel == " ")
		{
			assert(!"Car Model can not be empty");
		}
		this->_carModel = carModel;
	}

	void setCarColour(string carColour)
	{
		if (carColour == " ")
		{
			assert(!"Car colour can not be empty");
		}
		this->_carColour = carColour;
	}

	//==========================GET functions============================================

	string getCarName() { return this->_carName; }
	string getCarModel() { return this->_carModel; }
	string getCarColour() { return this->_carColour; }


};










//--------------------------------------------------------------------------

class Automatic :public Car
{
protected:
	int _topSpeed;
	double _speedSeccond; //0-100 suretlenme saniyesi

public:
	Automatic()
	{
		cout << "def automatic const" << endl;
	}

	Automatic(int topSpeed, double speedSeccond)
	{
		setTopSpeed(topSpeed);
		setSpeedSeccond(speedSeccond);
	}
	Automatic(string carName, string carModel, string carColour, int topSpeed, double speedSeccond) :Car(carName, carModel, carColour)
	{
		setTopSpeed(topSpeed);
		setSpeedSeccond(speedSeccond);
	}


	void setTopSpeed(int topSpeed)
	{
		if (topSpeed < 100 || topSpeed>400)
		{
			assert(!"top Speed undefined");
		}
		this->_topSpeed = topSpeed;
	}

	void setSpeedSeccond(double speedSeccond)
	{
		if (speedSeccond < 0)
		{
			assert(!"Seccond can not be negative");
		}
		this->_speedSeccond = speedSeccond;
	}

	int getTopSpeed() { return this->_topSpeed; }
	double getSpeedSeccond() { return this->_speedSeccond; }

	void showAutomaticCar()
	{
		showCar();
		cout << "Top Speed: " << this->_topSpeed << endl;
		cout << "Speed Seccond: " << this->_speedSeccond << endl;

	}

	~Automatic() override
	{

	}

};











class Manual :public Car
{
protected:
	int _shiftCount;

public:

	Manual()
	{
		cout << "def manual construcor" << endl;
	}

	Manual(int shifCount)
	{
		setShiftCount(shifCount);
	}
	Manual(string carName, string carModel, string carColour, int shifCount) :Car(carName, carModel, carColour)
	{
		setShiftCount(shifCount);
	}

	void setShiftCount(int shiftCount)
	{
		if (shiftCount < 2)
		{
			assert(!"shift count can not be smaller 2");
		}
		this->_shiftCount = shiftCount;
	}
	int getShiftCount() { return this->_shiftCount; }

	void showManualCar()
	{
		showCar();
		cout << "Shift count: " << this->_shiftCount << endl;
	}

	~Manual() override
	{

	}

};


int main()
{
	//Car c("Bmw","525","white");
	vector<Automatic> autoCars;
	while (true)
	{

		string name;
		string model;
		string color;
		int topspeed;
		double second;
		cout << "Enter name : ";
		cin >> name;
		if (name == "stop") {
			break;
		}

		cout << "Enter model : ";
		cin >> model;

		cout << "Enter color : ";
		cin >> color;

		cout << "Enter topspeed : ";
		cin >> topspeed;

		cout << "Enter second : ";
		cin >> second;


		Automatic a1(name, model, color, topspeed, second);

		autoCars.push_back(a1);

	}
	for (auto& i : autoCars)
	{
		i.showAutomaticCar();
		cout << "************************" << endl;
	}
	Manual m1("Bmw", "525", "white", 6);
	m1.showManualCar();

	cout << endl;
	m1.showManualCar();




}