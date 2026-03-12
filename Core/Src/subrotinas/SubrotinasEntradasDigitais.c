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

	if(flagEntradaFimCursoAbrir) {
		if(debounce(IN1_GPIO_Port, IN1_Pin)) {
			flagEntradaFimCursoAbrir = false;
		}
	}
	else {
		if(debounceInverso(IN1_GPIO_Port, IN1_Pin)) {
			flagEntradaFimCursoAbrir = true;
		}
	}

	if(flagEntradaFimCursoFechar) {
		if(debounce(IN2_GPIO_Port, IN2_Pin)) {
			flagEntradaFimCursoFechar = false;
		}
	}
	else {
		if(debounceInverso(IN2_GPIO_Port, IN2_Pin)) {
			flagEntradaFimCursoFechar = true;
		}
	}

	setPin(LED1_GPIO_Port, LED1_Pin, flagEntradaFimCursoAbrir);
	setPin(LED2_GPIO_Port, LED2_Pin, flagEntradaFimCursoFechar);
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
