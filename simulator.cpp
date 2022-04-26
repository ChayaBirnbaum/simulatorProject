#include "simulator.h"

simulator::simulator() {
	for (int i = 0; i < 5; i++) {
		arrCamera[i] = new camera('a' + i);
	}
}

void simulator::begin() {
	int a = 0;
	std::thread threades[5];
	for (int i = 0; i < 5; i++)
	{
		threades[i] = std::thread(&camera::run, (*(arrCamera[i])));
	}
	char x;
	std::cout << "Press any key to stop\n";
	std::cin >> x;
	for (int i = 0; i < 5; i++)
	{
		(*(arrCamera[i])).stop();

		threades[i].detach();// זה הורג את התהליכון! צריך לחכות לו
	}
	//????יש לחכות שהתהליכונים יגמרו - איך עושים את זה
}

simulator::~simulator() {
	for (int i = 0; i < 5; i++) {
		if (arrCamera[i] != NULL)
			delete(arrCamera[i]);
	}
}