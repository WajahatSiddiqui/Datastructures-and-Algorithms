#include <stdio.h>
#include <string.h>


char *fill_with_stars(char *str) {
	printf("%s\n", str);
	while (*str != '\0') {
		//printf("%c ", *str);
		*str = '*';
		printf("%c", *str);
		str++;
	}
	printf("%s\n ", str);
	return str;
}
int main() {
	char str[] = "01234";
	short *ptr = (short*) (str);
	//printf("%x\n", ptr[0]);
	char *stars = fill_with_stars(str);
	printf("fill with stars: %s\n", stars);
	return 0;
}