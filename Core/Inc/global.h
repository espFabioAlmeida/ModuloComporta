/*
 * global.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

enum BOOL {
	false,
	true
};

enum OPERACAO {
	OPERACAO_HOME,
	OPERACAO_POSICIONA,
	OPERACAO_CALIBRACAO
};

enum MOTOR {
	MOTOR_DESLIGADO,
	MOTOR_RECUA,
	MOTOR_AVANCA
};

#define TEMPO_SW_CALIBRACAO 30

extern CAN_HandleTypeDef hcan;
extern I2C_HandleTypeDef hi2c1;

extern uint8_t
	flagEntradaHome,
	flagEntradaFimCurso,
	flagEntradaPulso,

	flagLedCPU,
	flagLedCOM;

extern uint8_t
	operacao,
	contadorTempoSwCalibracao;

extern uint16_t
	contadorPulsos,
	quantidadePulsosCalibrado,
	setpointPulsos;
#endif /* INC_GLOBAL_H_ */
