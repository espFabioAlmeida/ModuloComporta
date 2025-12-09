///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasControlePosicao
//AUTOR:      Fábio Almeida
//CIRADO:     09/12/2025
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
ACIONAMENTO MOTOR
==============================================================================*/
void acionamentoMotor(uint8_t motor) {

	if(motor == MOTOR_DESLIGADO) {
		off(RELE1_GPIO_Port, RELE1_Pin);
		off(RELE2_GPIO_Port, RELE2_Pin);
		return;
	}

	if(motor == MOTOR_AVANCA) {
		off(RELE2_GPIO_Port, RELE2_Pin);
		on(RELE1_GPIO_Port, RELE1_Pin);
		return;
	}

	if(motor == MOTOR_RECUA) {
		off(RELE1_GPIO_Port, RELE1_Pin);
		on(RELE2_GPIO_Port, RELE2_Pin);
		return;
	}

	off(RELE1_GPIO_Port, RELE1_Pin);
	off(RELE2_GPIO_Port, RELE2_Pin);
}
/*=============================================================================
CONTROLE POSICAO
==============================================================================*/
void controlePosicao() {
	static uint8_t whileEntradaPulso = false;

	if(whileEntradaPulso) {
		if(!flagEntradaPulso) {
			whileEntradaPulso = false;
		}
	}

	if(operacao == OPERACAO_HOME) {
		if(flagEntradaHome) {
			acionamentoMotor(MOTOR_DESLIGADO);
			return;
		}
		acionamentoMotor(MOTOR_RECUA);
		return;
	}

	if(operacao == OPERACAO_POSICIONA) {
		if(flagEntradaHome) {
			acionamentoMotor(MOTOR_AVANCA);
			contadorPulsos = 0; //garante que a quantidade de pulsos é zerada
			return;
		}

		if(!whileEntradaPulso) {
			if(flagEntradaPulso) {
				whileEntradaPulso = true;
				contadorPulsos ++;
			}
		}

		if(flagEntradaFimCurso) {
			contadorPulsos = quantidadePulsosCalibrado; //garante que quantidade de pulsos é a calibrada
		}

		if(contadorPulsos > setpointPulsos) { //ainda não chegou no setpoint
			acionamentoMotor(MOTOR_RECUA);
			return;
		}

		if(contadorPulsos < setpointPulsos) { //passou do setpoint
			acionamentoMotor(MOTOR_AVANCA);
			return;
		}

		if(contadorPulsos == setpointPulsos) { //está exatamente no setpoint, para
			acionamentoMotor(MOTOR_DESLIGADO);
			return;
		}

		if(contadorPulsos >= quantidadePulsosCalibrado) { //proteção
			acionamentoMotor(MOTOR_DESLIGADO);
			return;
		}
	}

	if(operacao == OPERACAO_CALIBRACAO) {
		if(flagEntradaHome) {
			acionamentoMotor(MOTOR_AVANCA);
			contadorPulsos = 0; //garante que a quantidade de pulsos é zerada
			return;
		}

		if(!whileEntradaPulso) {
			if(flagEntradaPulso) {
				whileEntradaPulso = true;
				contadorPulsos ++;
			}
		}

		if(flagEntradaFimCurso) {
			acionamentoMotor(MOTOR_RECUA);
			quantidadePulsosCalibrado = contadorPulsos + 1;
			//TODO: SALVAR
			operacao = OPERACAO_HOME;
		}
	}
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
