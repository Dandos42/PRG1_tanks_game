#include "Tanky.h"
#include <stdio.h>
#include <string.h>
#include "strelba.h"
#include <math.h>

//definice konstanty
#define PI 3.1415



int strileni()
{
	//Zadání síly støely
	float sila = printf("\nZadej silu strely(1-100):\n");
	scanf_s("%f", &sila);

	if (sila >= 1 && sila <= 100)
	{
		//Zadání úhlu støely
		float uhel_strely = printf("\nZadej uhel strely ve stupnich (0-180):\n");
		scanf_s("%f", &uhel_strely);
		
		if (uhel_strely >= 0 && uhel_strely <=180)
		{


			//Výpoèet x a y souøadnice bodu
			float uhel = uhel_strely * (PI / 180);
			float vxi = sila * cos(uhel);
			float vyi = sila * sin(uhel);

			//vypis souèadnic
			printf("\nSouradnice bodu x: %f\n", vxi);
			printf("Souradnice body y: %f\n", vyi);

			//vypoèet celkové vzdálenosti, výšky, èasu, gravitace
			float tpul = (0 - vyi) / -9.8;
			float celk_cas = tpul * 2;
			float celkova_vzdalenost = vxi * celk_cas;

			printf("Celkova vzdalenost v m: %f \n", celkova_vzdalenost);
			//float height = (vyi * tHalf) + (0.5 * -9.8 * (tHalf * tHalf));

			return 0;
		}
		else
		{
			printf("\nZadal si spatnou hodnotu uhlu\n");
		}


	}
	else
	{
		printf("\nZadal si spatnou hodnotu sily\n");
	}
	

}





