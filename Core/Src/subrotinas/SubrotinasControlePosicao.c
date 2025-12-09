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
		sentidoMotor = MOTOR_DESLIGADO;
		return;
	}

	if(motor == MOTOR_AVANCA) {
		off(RELE2_GPIO_Port, RELE2_Pin);
		on(RELE1_GPIO_Port, RELE1_Pin);
		sentidoMotor = MOTOR_AVANCA;
		return;
	}

	if(motor == MOTOR_RECUA) {
		off(RELE1_GPIO_Port, RELE1_Pin);
		on(RELE2_GPIO_Port, RELE2_Pin);
		sentidoMotor = MOTOR_RECUA;
		return;
	}

	off(RELE1_GPIO_Port, RELE1_Pin);
	off(RELE2_GPIO_Port, RELE2_Pin);
	sentidoMotor = MOTOR_DESLIGADO;
}
/*=============================================================================
INTERPRETACAO ENTRADA PULSOS
==============================================================================*/
void interpretacaoEntradaPulsos(){

	if(sentidoMotor == MOTOR_AVANCA) {
		if(contadorPulsos < quantidadePulsosCalibrado) {
			contadorPulsos ++;
		}
		return;
	}

	if(sentidoMotor == MOTOR_RECUA) {
		if(contadorPulsos) {
			contadorPulsos --;
		}
		return;
	}
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
				interpretacaoEntradaPulsos();
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
				interpretacaoEntradaPulsos();
			}
		}

		if(flagEntradaFimCurso) {
			acionamentoMotor(MOTOR_RECUA);
			quantidadePulsosCalibrado = contadorPulsos + 1;
			salvaQuantidadePulsos();
			flagLedCPU = true;
			operacao = OPERACAO_HOME;
		}
	}
}
/*=============================================================================
BOTAO DE CALIBRACAO
==============================================================================*/
void botaoCalibracao() {
	if(debounce(SW_CAL_GPIO_Port, SW_CAL_Pin)) {
		contadorTempoSwCalibracao = 1;
		while(!input(SW_CAL_GPIO_Port, SW_CAL_Pin)) {
			if(contadorTempoSwCalibracao > TEMPO_SW_CALIBRACAO) {
				flagLedCPU = true;
			}
		}
	}

	if(contadorTempoSwCalibracao > TEMPO_SW_CALIBRACAO) {
		operacao = OPERACAO_CALIBRACAO;
	}

	contadorTempoSwCalibracao = 0;
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
