#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book{
	int i:1;
	int j:1;
	
	int l:1;
	int m:1;

	int n:29;
	int k;
};

int main(int argc, char **argv){
	printf("%d\n", sizeof(struct Book));

	/*
	FILE *file;
	rsize_t sz;
	char buf[1024] = {0};
	int i;
	if(0 == fopen_s(&file, "D:\\\\a.obj", "r")){

		while(0 == feof(file)){
			fgets(buf, 1024, file);
		}

		fclose(file);
	}*/

	return 0;
}

