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
			sz = fread_s(buf, 1024, sizeof(char), 1024, file);
			printf("%s", buf);
			sz = fread_s(buf, 12, sizeof(char), 3, file);
			printf("%.1f", atof(buf));
			fseek(file, 1, SEEK_CUR);
			sz = fread_s(buf, 12, sizeof(char), 3, file);
			printf(" %.1f", atof(buf));
			fseek(file, 1, SEEK_CUR);
			sz = fread_s(buf, 12, sizeof(char), 3, file);
			printf(" %.1f\n", atof(buf));
			fseek(file, 2, SEEK_CUR);

			memset(buf, 0, 12);
		}

		fclose(file);
	}

	return 0;
}

