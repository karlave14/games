#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

	char hits[100];
        char fails[100];
        int attempt = 6;
        int num_hits=0;
        int num fails=0;
        int size = 0;
void instruction(){
	printf("WELCOME TO HAMGMAN\n");
	printf("*********************\n");
	printf("You have 5 lives\n");
	printf("There are some word that could come out: \n");
        printf("words:\n");
        printf("    Future\n");
        printf("    Rainbow\n");
        printf("    Wedding\n");
        printf("    Strawberry\n");
        printf("    Nostalgia\n");

}
int ramdom(int stop1, int stop2){
	int valor=rand()% stop1 + stop2;
	return valor;
}
	char *get_ramdon(char *arreglo[], int size){
	int index = ramdon(size-1,0);
	char *word=arreglo[index];
return word;
}
void hiting_hits(char letter){
	hits[num_hits]=letter;
	num_hits++;
	if(num_hits==size){
	printf("Congratulations the word is: %s\n", &word);
	exit(0);
	}
}
void hiting_fails(char letter){
	fails[num_hits]=letter;
	num_fails++;
	attempt--;
	printf("You fail, only have %d lives\n", attempt);
	if(attempet==0){
		printf("LOST\n");
		printf("The word was %s\n", word);
	}

}
bool before_hits(char letter){
	int i;
	for(i=0; i<num_hits;i++){
	if(attempt[i]==letter){
		return true;
		}
	}
	return false;
}
void show_word(char letter){
	int hit = false;
	int i;
	for(i=0; i<size;i++){
	if(word[i]==letter){
	hiting_hits(letter);
	printf("%c", letter);
	hit=true;
	}else if(before_hits(word[i])){
		printf(%c,word[i]);
	}else{
		printf("*");
		}
	}

}
int main(int argc, char** argv){
	int arg = argc-1;
	if(arg == 0){
	instruction();
	}else
	int begin = argc;
	srand(time(NULL));
	char *words[]= {"Future","Rainbow","Wedding","Strawberry","Nostalgia"}
	int size=sizeof(word)/(char*);
	int *word = ramdom(word,size);
	//falta cuando ingrese la palabra
	show_word(letter);
	system(pause);
return (0);
}
