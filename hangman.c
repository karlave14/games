#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// mostrar instrucciones
void instruction()
{

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

// palabra al azar
int ramdom(int stop1)
{
	int valor = rand() % stop1;
	return valor;
}

char *get_ramdon(char *arreglo[], int size)
{

	int index = ramdom(size);
	char *word = arreglo[index];
	return word;
}

void hiting_hits(char *word, int *num_hits)
{

	// Aunmenta en uno la cantidad de aciertos a través del puntero.
	*num_hits = *num_hits + 1;

	//  Si la cantidad de aciertos es igual a la
	// 	cantidad de letras de la palabra:
	// 	mostrar al jugador que ya ganó.
	
	if (*num_hits == strlen(word))
	{
		printf("Congratulations the word is: %s\n", word);
		exit(0);
	}
}

//tablero de palabra, para mostrarla
void show_word(char *word, char letter, int *num_hits, char *hidden_word, int *attempts)
{

	printf("You entered the letter: %c\n", letter);
	// Sumar uno a los intentos
	
	int hit = 0;
	int i;
	for (i = 0; i < strlen(word); i++)
	{

		if (word[i] == letter && hidden_word[i] == '*')
		{
			hiting_hits(word, num_hits);
			hidden_word[i] = letter;
			hit = 1;
		}

	}

	if (hit == 0) {
		*attempts = *attempts + 1;
	}
	printf("\n");
}

//funcion principal
int main(int argc, char **argv)
{

	int in_game = 1; // 1 en juego, 0 finalizado
	int lives = 5;
	int attempt = 0;
	int num_hits = 0;
	int size = 0;
	char letter;

	int arg = argc - 1;
	if (arg == 0)
	{
		instruction();
	}
	else
	{
		int begin = argc;
		srand(time(NULL));

		char *word_list[] = {"future", "rainbow", "wedding", "strawberry", "nostalgia"};
		int size = sizeof(word_list) / sizeof(char *);
		char *word = get_ramdon(word_list, size);

		// printf("la palabra es: %s\n", word);

		// Convertir la palabra a asteriscos

		char hidden[strlen(word)];
		int j;
		for (j = 0; j < strlen(word); j++)
		{
			hidden[j] = '*';
		}

		
		// Vidas
		// Que no repita letra -- listo
		// Que no haya adivinado la palabra
		
		while (in_game == 1)
		{

			if (attempt == lives)
			{	
				in_game = 0;
				printf("You've lost the game. :(\n");
				printf("The correct word is: %s\n.", word);
				printf("You only guessed %d letters\n.", num_hits);

			}
			else
			{
				printf("Enter a letter: ");
				scanf(" %c", &letter);
				show_word(word, letter, &num_hits, hidden, &attempt);

				printf("\n%s\n\n", hidden);

				printf("lives left: %d/%d\n", (lives-attempt), lives);
			}
		}
	}

	// system(pause);
	return (0);
}

