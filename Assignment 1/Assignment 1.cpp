#include <iostream>
#include <string>
#include<queue>
using namespace std;

class Car
{
private:
	int Speed;
	int Year_Model;
	string Car_Brand;
	string Car_Type;
	string Car_Plate;
public:
	Car()
	{
		Speed = 0;
		Year_Model = 0;
		Car_Brand = "";
		Car_Type = "";
		Car_Plate = "";
	}
	Car(string CarBrand, int Max_Speed, int YearModel)
	{
		Car_Brand = CarBrand;
		Speed = Max_Speed;
		Year_Model = YearModel;
	}
	void setspeed(int Max_Speed)
	{
		Speed = Max_Speed;
	}
	int getspeed()
	{
		return Speed;
	}
	void setCarBrand(string CarBrand)
	{
		Car_Brand = CarBrand;
	}
	string getCarBrand()
	{
		return Car_Brand;
	}
	void setYearModel(int YearModel)
	{
		Year_Model = YearModel;
	}
	int getYearModel()
	{
		return Year_Model;
	}
	void setCarType(string CarType)
	{
		Car_Type = CarType;
	}
	string getCarType()
	{
		return Car_Type;
	}
	void setCarPlate(string CarPlate)
	{
		Car_Plate = CarPlate;
	}
	string getCarplate()
	{
		return Car_Plate;
	}
};
class Road
{
private:
	char Road_Type;
	int Speed_Limit, CountA, CountB, CountC;
public:
	Road()
	{
		CountA = 0;
		CountB = 0;
		CountC = 0;
		Speed_Limit = 0;
		Road_Type = ' ';
	}
	Road(char RoadType, int SpeedLimit)
	{
		Road_Type = RoadType;
		Speed_Limit = SpeedLimit;
		CountA = 0;
		CountB = 0;
		CountC = 0;
	}
	void setRoadType(char RoadType)
	{
		Road_Type = RoadType;
	}
	char getRoadType()
	{
		return Road_Type;
	}
	void setSpeedLimit(int SpeedLimit)
	{
		Speed_Limit = SpeedLimit;
	}
	int getSpeedLimit()
	{
		return Speed_Limit;
	}
	void setCountA(int Counta)
	{
		CountA = Counta;
	}
	int getCountA()
	{
		return CountA;
	}
	void setCountB(int Countb)
	{
		CountB = Countb;
	}
	int getCountB()
	{
		return CountB;
	}
	void setCountC(int Countc)
	{
		CountC = Countc;
	}
	int getCountC()
	{
		return CountC;
	}
	bool Radar(int car_speed, char Road_Type)
	{
		if (car_speed > Speed_Limit)
		{
			return true;
		}
		return false;

	}
	void allow(string Car_type)
	{
		if (Road_Type == 'A')
		{
			if (Car_type != "Private" && Car_type != "motorcycle")
			{
				cout << Car_type << " is not allowed in " << Road_Type << endl;

			}
			else
			{
				CountA++;
				cout << Car_type << " is allowed in " << Road_Type << endl;
			}
		}

		if (Road_Type == 'B')
		{
			CountB++;
			cout << Car_type << " is allowed in " << Road_Type << endl;
		}

		if (Road_Type == 'C')
		{
			if (Car_type == "truck")
			{
				CountC++;
				cout << Car_type << " is allowed in " << Road_Type << endl;
			}
			else
			{
				cout << Car_type << " is not allowed in " << Road_Type << endl;
			}
		}
	}
	int age(int Year_Model)
	{
		return 2022 - Year_Model;
	}
};
int main()
{
	Road silk = Road('B', 120);

	Car car = Car("Volkswagen", 140, 2004);

	car.setCarPlate("BFW198");
	car.setCarType("Private");
	if (silk.Radar(car.getspeed(), silk.getRoadType()) == true)
	{
		cout << "This car will be fined\n";
		cout << "Year Model of the car is " << car.getYearModel() << endl;
		cout << "Car plate is " << car.getCarplate() << endl;
		cout << "Car Type is " << car.getCarType() << endl;
		cout << "Car Brand is " << car.getCarBrand() << endl;
	}

	queue<Car> Abdo;
	Car G = Car("Porche", 90, 2017);
	G.setCarType("Private");
	Abdo.push(G);
	Car L = Car("kawasaki", 145, 2003);
	L.setCarType("motorcycle");
	Abdo.push(L);
	Car M = Car("Mercedes", 120, 1999);
	M.setCarType("truck");
	Abdo.push(M);
	Road Gazear = Road('A', 100);
	Road Aswan = Road('B', 100);
	Road Taef = Road('C', 100);
	while (Abdo.size() > 0)
	{
		Car elrejoula = Abdo.front();
		Abdo.pop();
		bool r1 = Gazear.Radar(elrejoula.getspeed(), Gazear.getRoadType());
		Gazear.allow(elrejoula.getCarType());
		int a1 = Gazear.age(elrejoula.getYearModel());

		bool r2 = Aswan.Radar(elrejoula.getspeed(), Aswan.getRoadType());
		Aswan.allow(elrejoula.getCarType());
		int a2 = Aswan.age(elrejoula.getYearModel());

		bool r3 = Taef.Radar(elrejoula.getspeed(), Taef.getRoadType());
		Taef.allow(elrejoula.getCarType());
		int a3 = Taef.age(elrejoula.getYearModel());



	}
	double highestRoad = max({ Gazear.getCountA(), Aswan.getCountB(), Taef.getCountC() });

	double efficiencyRoadA = ((Gazear.getCountA() / highestRoad) * 100);

	double efficiencyRoadB = ((Aswan.getCountB() / highestRoad) * 100);

	double efficiencyRoadC = ((Taef.getCountC() / highestRoad) * 100);

	cout << "efficiencyA = " << efficiencyRoadA << "%\nefficiencyB = " << efficiencyRoadB << "%\nefficiencyC = " << efficiencyRoadC << "%" << endl;




	return 0;
}