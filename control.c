#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
 
int main (void){
	printf ("Programa iniciado...\n");

	if (wiringPiSetup () == -1)
	return 1 ;

	pinMode (1, PWM_OUTPUT) ; // GPIO 12 salida - bomba PWM	
	pinMode (0, OUTPUT); // GPIO 11 salida - servomotor
	pinMode (2, OUTPUT); // GPIO 13 salida - ventilador
	pinMode (3, OUTPUT); // GPIO 15 salida - led

	pinMode (21, INPUT); // GPIO 29 entrada - fotocelda digital
	pinMode (22, INPUT); // GPIO 31 entrada - sensor temperatura
	pinMode (23, INPUT); // GPIO 33 entrada - sensor humedad

	unsigned short int contador = 0;	

	while(1){	
		
		// VERIFICA EL VALOR DE LA FOTOCELDA
		if (digitalRead(21)==1){
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
		}

		contador+=1;
		if (contador==120){ // este contador cuenta el minuto para activar, el valor de 120 depende del delay que se ponga (500 ms)
			// EL VALOR DEL ANGULO DEPENDE DEL VALOR QUE SE ENVIE AL PWM (0-1024)
			pwmWrite(1, 1024) ; // GIRA TODO
			delay(10000);
			pwmWrite(1, 0) ; // REGRESA TODO
			contador = 0;
		}
		delay(500);
	}
}