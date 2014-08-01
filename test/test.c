#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *file;
	rsize_t sz;
	char buf[1024] = {0};
	int i;
	if(0 == fopen_s(&file, "D:\\\\a.obj", "r")){

		while(0 == feof(file)){
			fgets(buf, 1024, file);
		}

		fclose(file);
	}

	return 0;
}

