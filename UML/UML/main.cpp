#include<thread>

#include"Car.h"

#include<iostream>
#include<conio.h>

using namespace std::this_thread;

void main()
{
	/*Tank tank(40);
	tank.tank_info();
	tank.fill_tank(20);
	tank.tank_info();

	Engine engine(5, tank);
	engine.start();
	for (int i = 0; i < 1000; i++)
		engine.run();
	tank.tank_info();*/

	Car car;
	
	/*car.set_trans_position('D');
	car.set_PWR_mode();
	car.turn_on_low_beam();
	car.fill_tank(20);
	car.start();*/


	//car.control_panel.idle_thread = new std::thread(&Car::control, car);

	//char key = 0;
	//while (!_kbhit()) {
	//	while (key != 27)
	//	{
	//		
	//		key = _getch();
	//		//std::cout << key << '\t' << (int)key << std::endl;
	//		if (key == 72 && car.get_fuel_level() > 0) {

	//			system("cls");
	//			car.press_gas();
	//			std::cout << car.get_fuel_level() << std::endl;
	//			
	//		}
	//		else if (key == 100) {
	//			car.set_trans_position('R');
	//		}
	//	}
	//	car.off();
	//}
}