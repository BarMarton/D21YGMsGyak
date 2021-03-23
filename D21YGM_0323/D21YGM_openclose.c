#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#define O_RDWR 02 
#define FILE "D21YGM.txt"

int main()
{
	int fileHandle = open(FILE, O_RDWR);
	if(fileHandle == -1) printf("Sikertelen fájl megnyitás!\n");
	else printf("Sikeres fájl megnyitás!\n");

	char content[128];
	int read_content = read(fileHandle, content, sizeof(content));

	content[read_content] = '\0';
	printf("Beolvasott:\n%s\nÖsszesen: %i byte\n", content, read_content);

	lseek(fileHandle, 0, SEEK_SET);
	printf("A pointer a fájl elejére állítva!\n");

	char text[] = "Fájlba írás rendszerhívással";
	int wrt = write(fileHandle, text, sizeof(text));
	printf("A fájlba irva:\n%s\nösszesen: %i byte\n", text, wrt);
	close(fileHandle);
	return 0;
}

