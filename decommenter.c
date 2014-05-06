//Author: Michael Harrison
//Decommenter
//Remove /* */ style comments from a file

#include <stdio.h>

int comment(int last, int current);

int main (int argc, char **argv) {
    int last, current, next;
	FILE *read = fopen("in.c","r");
	FILE *write = fopen("out.txt","w");
    while(current!=EOF){
        while((!comment(last,(current=getc(read))))&& (current!=EOF)){
			if (current!='/'){
                putc(current,write);
                last=current;
			}
			else {
				if ((next=getc(read))=='*'){
					last=current;
					ungetc(next,read);
					fflush(read);
				}
				else{
					ungetc(next,read);
					fflush(read);
					putc(current,write);
					last=current;
				}
			}
        }
        while(((current=getc(read))!=EOF)&&(!comment(last,current))){
            last=current;
		}
    }
    fclose(read);
	fclose(write);
	return 0;
}

int comment(int last, int current){
	if (last == '/' && current == '*')
		return 1;
	else if (last == '*' && current == '/')
		return 1;
	else
		return 0;
}
