///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasEntradasDigitais
//AUTOR:      Fábio Almeida
//CIRADO:     25/04/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
LEITURA DAS ENTRADAS DIGITAIS
==============================================================================*/
void entradasDigitais() {

	if(flagEntradaHome) {
		if(debounce(IN1_GPIO_Port, IN1_Pin)) {
			flagEntradaHome = false;
		}
	}
	else {
		if(debounceInverso(IN1_GPIO_Port, IN1_Pin)) {
			flagEntradaHome = true;
		}
	}

	if(flagEntradaFimCurso) {
		if(debounce(IN2_GPIO_Port, IN2_Pin)) {
			flagEntradaFimCurso = false;
		}
	}
	else {
		if(debounceInverso(IN2_GPIO_Port, IN2_Pin)) {
			flagEntradaFimCurso = true;
		}
	}

	if(flagEntradaPulso) {
		if(debouncePulsos(IN3_GPIO_Port, IN3_Pin)) {
			flagEntradaPulso = false;
		}
	}
	else {
		if(debouncePulsosInverso(IN3_GPIO_Port, IN3_Pin)) {
			flagEntradaPulso = true;
		}
	}

	setPin(LED1_GPIO_Port, LED1_Pin, flagEntradaHome);
	setPin(LED2_GPIO_Port, LED2_Pin, flagEntradaFimCurso);
	setPin(LED3_GPIO_Port, LED3_Pin, flagEntradaPulso);
	setPin(LED4_GPIO_Port, LED4_Pin, input(IN4_GPIO_Port, IN4_Pin));
	setPin(LED5_GPIO_Port, LED5_Pin, input(IN5_GPIO_Port, IN5_Pin));
	setPin(LED6_GPIO_Port, LED6_Pin, input(IN6_GPIO_Port, IN6_Pin));
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
