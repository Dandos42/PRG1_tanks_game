// Tanky.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Tanky.h"
#include <stdio.h>
#include <string.h>
#include "strelba.h"
#include <math.h>


using namespace std;

//deklarace globbalní proměnné
char cti[2048];


int main()
{
	//Vypsání úvodního nápisu
	FILE* uvodni = fopen("uvod.txt", "r");
	if (uvodni == NULL)
	{
		printf("Soubor nenalezen.");
		return 1;
	}

	//Čtení souboru se všemi znaky
	while (fscanf(uvodni, " %2047[^\n]", cti) != EOF)
	{
		printf("%s\n", cti);
	}

	//ověření uzavření souboru
	if (fclose(uvodni) == EOF)
	{
		printf("Soubor se nepodařilo uzavřít.");
		return 1;
	}

	//Hlavička programu
	printf("Vitej ve hre tanky !!\n\n");
	printf("______________________________________________________________________________________________________________________________\n");
	printf("Autori: \t\tDalibor Rada & Daniel Prachar\n");
	printf("Popis programu: \tNa zacatku se vybere pocet hracu a zadaji se jejich jmena, program podle toho nacte herni plan\n");
	printf("______________________________________________________________________________________________________________________________\n");
	printf("\n\n");

	//deklarace
	int i, player_num;
	char names[8][25];
	int hrac;
	int pokracovani;
	int menu_volba;

	//text menu
	printf("************************\n");
	printf("**  ZAHAJENI HRY: 1   **\n");
	printf("**  KONEC: 0          **\n");
	printf("************************\n");
	printf("\n");

	//zadani volby
	printf("Zadej volbu: \n");
	scanf_s("%d", &menu_volba);

	//vypsání menu podle volby
	switch (menu_volba)
	{
		case 1:
		
		//Zadání počtu hráčů
		printf("\nZadej pocet hracu(2|3|4): ");
		scanf("%d", &player_num);

		//Zadání jmén hráců + ošetření správného zadání počtu
		if (player_num <= 4 && player_num > 1)
		{
			for (i = 0; i < player_num; i++) {
				printf("Zadej jmeno %d hrace: ", i + 1);
				scanf_s("%s", names[i], 25);  //jmeno + novy radek
				getchar();               //removes the newline from the keyboard buffer - k cemu to je?
			}
		}
		else
		{
			printf("\nMuzes zadat pouze 2|3|4 hrace!! ty lopato\n\n");
			exit(0);
		}

		printf("\n\n");

		//načtení herního plánu pro dva hráče
		if (player_num == 2)
		{
			//Nadefinování cesty k souboru a ošetření jeho nalezení
			FILE* herni_plan_cti = fopen("herni_plan_2h.txt", "r");
			if (herni_plan_cti == NULL)
			{
				printf("Soubor nenalezen.");
				return 1;
			}

			//Čtení souboru se všemi znaky
			while (fscanf(herni_plan_cti, " %2047[^\n]", cti) != EOF)
			{
				printf("%s\n", cti);
			}



			//ověření uzavření souboru
			if (fclose(herni_plan_cti) == EOF)
			{
				printf("Soubor se nepodařilo uzavřít.");
				return 1;
			}
		}

		//načtení herního plánu pro tři hráče
		else if (player_num == 3)
		{
			//Nadefinování cesty k souboru a ošetření jeho nalezení
			FILE* herni_plan_cti_3 = fopen("herni_plan_3h.txt", "r");
			if (herni_plan_cti_3 == NULL)
			{
				printf("Soubor nenalezen.");
				return 1;
			}

			//Čtení souboru se všemi znaky

			while (fscanf(herni_plan_cti_3, " %2047[^\n]", cti) != EOF)
			{
				printf("%s\n", cti);
			}

			//ověření uzavření souboru
			if (fclose(herni_plan_cti_3) == EOF)
			{
				printf("Soubor se nepodařilo uzavřít.");
				return 1;
			}
		}
		//načtení herního plánu pro čtyři hráče
		else if (player_num == 4)
		{
			//Nadefinování cesty k souboru a ošetření jeho nalezení
			FILE* herni_plan_cti_4 = fopen("herni_plan_4h.txt", "r");
			if (herni_plan_cti_4 == NULL)
			{
				printf("Soubor nenalezen.");
				return 1;
			}

			//Čtení souboru se všemi znaky
			while (fscanf(herni_plan_cti_4, " %2047[^\n]", cti) != EOF)
			{
				printf("%s\n", cti);
			}

			//ověření uzavření souboru
			if (fclose(herni_plan_cti_4) == EOF)
			{
				printf("Soubor se nepodařilo uzavřít.");
				return 1;
			}
		}
		else
		{
			printf("Herní plán se z nějakého důvodu nenačetl :-(");
		}

		printf("\n\n");

		
		printf("\n\n");

			//Vypsání jmén hráčů
			printf("\n\n");
			for (i = 0; i < player_num; i++)
			{
				printf("\n\HRAC:\t%s ", names[i]);
				printf("\n\n");
			}
		
		//střídání střelby hráčů dokud se neukončí
		do
		{
			printf("Zadej cislo hrace, ktery je na tahu:  ");
			scanf("%d", &hrac);

			switch (hrac)
			{
			case 1:
				printf("\n\HRAC:\t%s \n", names[0]);
				strileni();
				printf("\nBohuzel si minul :-(");
				break;

			case 2:
				printf("\n\HRAC:\t%s \n", names[1]);
				strileni();
				printf("\nBohuzel si minul :-(");
				break;

			case 3:
				printf("\n\HRAC:\t%s \n", names[2]);
				strileni();
				printf("\nBohuzel si minul :-(");
				break;

			case 4:
				printf("\n\HRAC:\t%s \n", names[3]);
				strileni();
				printf("\nSkvele tank znicen");
				break;
				default:
					printf("Neco je asi spatne!!!!");

				break;
			}
			printf("\njestli chcete pokracovat ve strelbe napis |1|: ");
			scanf("%d", &pokracovani);
		} 
		while (pokracovani == 1);
		{
			
				printf("\nDoufame, ze jste si hru uzili TYM: dandaja");
				printf("\n\n\n\n\n\n\n\n\n");
				exit(0);
		}

		getchar();   //podrzi mi consoli dokud nedam enter

		printf("\nDoufame, ze jste si hru uzili TYM: dandaja\n");

		printf("KONEC & POHADKY JE KONEC");

		printf("\n\n\n\n\n\n\n\n\n");
		
		break;

		case 0:
		exit(0);
		break;

		default:
			printf("\nMuzes zadat pouze hodnotu 1 nebo 0 ty opice!!\n\n");
			break;
	}
}


		
