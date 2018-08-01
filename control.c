#include <stdio.h>
#include <stdlib.h>
//#include <wiringPi.h>
 
int main (void){
	printf ("Programa iniciado...\n");

	/*if (wiringPiSetup () == -1)
	return 1 ;

	pinMode (7, OUTPUT); // pin 4 salida - bomba
	pinMode (0, OUTPUT); // pin 17 salida - servomotor
	pinMode (2, OUTPUT); // pin 27 salida - ventilador
	pinMode (3, OUTPUT); // pin 22 salida - led

	pinMode (21, INPUT); // pin 5 entrada - fotocelda digital
	pinMode (22, INPUT); // pin 6 entrada - sensor temperatura
	pinMode (23, INPUT); // pin 13 entrada - sensor humedad*/

	unsigned short int contador = 0;	

	while(1){	
		
		// VERIFICA EL VALOR DE LA FOTOCELDA
		/*if (digitalRead(21)==1){
			digitalWrite(0, 1);
		}else{
			digitalWrite(0, 0);
		}

		// VERIFICA EL VALOR DEL SENSOR DE TEMPERATURA
		if (digitalRead(22)==1){
			digitalWrite(2, 1);
		}else{
			digitalWrite(2, 0);
		}

		// VERIFICA EL VALOR DEL SENSOR DE HUMEDAD
		if (digitalRead(23)==1){
			digitalWrite(3, 1);
		}else{
			digitalWrite(3, 0);
		}*/

		contador+=1;
		if (contador==120){
			//digitalWrite(7, 1);	
			printf("prende bomba por 10 segundos...\n");
			delay(10000);
			//digitalWrite(7, 0);	
			printf("apaga bomba\n");
			contador = 0;
		}
		delay(500);
	}
}