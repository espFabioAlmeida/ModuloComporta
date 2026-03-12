# Modulo Comporta
Projeto Automasensor: Módulo Comporta

# Pinagem Conector
1: GND <br>
2: D+ OU CAN H <br>
3: D- OU CAN L <br>
4: NC <br>
5: FIM DE LINHA (FECHAR COM O PINO 2) <br>
6: SAIDA MOTOR 2 <br>
7: SAIDA MOTOR 1 <br>
8: VCC <br>
9: GND <br>
10: POTENCIÔMETRO (1K PARA O GND) <br>
11: NC <br>
12: IN4 <br>
13: IN5 <br>
14: SAIDA MOTOR 2 <br>
15: SAIDA MOTOR 1 <br>
16: VCC <br>
17: GND <br>
18: IN6 <br>
19: IN1 <br>
20: IN2 <br>
21: IN3 <br>
22: SAIDA MOTOR 2 <br>
23: SAIDA MOTOR 1 <br>
24: VCC <br>


# Entradas Digitais
IN1: Fim de Curso Abrir Comporta <br>
IN2: Fim de Curso Fechar Comporta<br>
IN3: LIVRE <br>
IN4: LIVRE <br>
IN5: LIVRE <br>
IN6: LIVRE <br>

# Relés
K1: Motor abrir <br>
K2: Motor fechar <br>

# Escopo
Recebe pela CAN o comando para abrir, parar ou fechar a comporta. <br>
Ao receber um comando de abertura ou fechamento, somente para em caso de receber um comando contrário ou por acionamento de fim de curso.

# Protocolo CAN
A ECU possui um endereço para cada tipo de pacote. <br>
Endereço ECU Pacote 1: 0x1BB81A01 <br>
Endereço ECU Pacote 2: 0x1BB81A02 <br>
Endereço ECU Pacote 3: 0x1BB81A03 <br>
Para esse equipamento somente o pacote 3 é relevante <br>
<br>
Pacote 3:
BYTE 0: COMANDO HASTE - 0=PARAR, 1=SUBIR, 2=DESCER, 3=SUBIR(RETORNO POR FIRMWARE) <br>
BYTE 1: COMANDO COMPORTAS - 0=PARAR, 1=FECHAR, 2=ABRIR <br>
BYTE 2: Livre <br>
BYTE 3: Livre <br>
BYTE 4: Livre <br>
BYTE 5: Livre <br>
BYTE 6: Livre <br>
BYTE 7: Livre <br>
<br>
Resposta: Por enquanto módulo apenas monitora a rede CAN <br>