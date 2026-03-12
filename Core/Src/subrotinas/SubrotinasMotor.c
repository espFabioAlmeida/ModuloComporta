///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasMotor
//AUTOR:      Fábio Almeida
//CIRADO:     12/03/2026
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
ACIONAMENTO MOTOR
==============================================================================*/
void acionamentoMotor() {

	if(flagEntradaFimCursoAbrir && sentidoMotor == MOTOR_ABRIR) {
		sentidoMotor = MOTOR_DESLIGADO;
	}

	if(flagEntradaFimCursoFechar && sentidoMotor == MOTOR_FECHAR) {
		sentidoMotor = MOTOR_DESLIGADO;
	}

	if(sentidoMotor == MOTOR_DESLIGADO) {
		off(RELE1_GPIO_Port, RELE1_Pin);
		off(RELE2_GPIO_Port, RELE2_Pin);
		return;
	}

	if(sentidoMotor == MOTOR_ABRIR) {
		off(RELE2_GPIO_Port, RELE2_Pin);
		on(RELE1_GPIO_Port, RELE1_Pin);
		return;
	}

	if(sentidoMotor == MOTOR_FECHAR) {
		off(RELE1_GPIO_Port, RELE1_Pin);
		on(RELE2_GPIO_Port, RELE2_Pin);
		return;
	}

	off(RELE1_GPIO_Port, RELE1_Pin);
	off(RELE2_GPIO_Port, RELE2_Pin);
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
