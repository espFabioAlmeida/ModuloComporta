///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasCAN
//AUTOR:      Fábio Almeida
//CRIADO:     19/09/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
PROTOCOLO CAN
==============================================================================*/
void protocoloCAN() {

	switch(canRxBuffer[0]) {
		case OPERACAO_HOME:
			operacao = OPERACAO_HOME;
			setpointPulsos = 0;
			break;

		case OPERACAO_POSICIONA:
			operacao = OPERACAO_POSICIONA;
			setpointPulsos = canRxBuffer[1];
			break;

		case OPERACAO_CALIBRACAO:
			if(flagEntradaHome) {
				operacao = OPERACAO_CALIBRACAO;
			}
			break;
	}

	if(setpointPulsos > 100) {
		setpointPulsos = 100;
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
