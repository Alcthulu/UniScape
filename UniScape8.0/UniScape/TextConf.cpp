#include "TextConf.h"
#include "Sounds.h"

//forums.codeguru.com/showthread.php?539241-RESOLVED-can-anyone-tell-me-all-colors-const-for-SetConsoleTextAttribute()-function
void SetColor(int textC, int backC) {
	WORD color = ((backC & 0x0F) << 4) + (textC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void slowPrint(string toPrint, int speed){
	for (unsigned int i = 0; i < toPrint.size(); i++) {
		if(i%8==0)
		cout << toPrint[i]; Sleep(speed);
	}
}
