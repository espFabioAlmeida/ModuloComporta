# Modulo Comporta
Projeto Automasensor: Módulo Comporta

# Entradas Digitais
IN1: Home <br>
IN2: Fim de Curso <br>
IN3: Entrada de Pulsos <br>
IN4: LIVRE <br>
IN5: LIVRE <br>
IN6: LIVRE <br>

# Relés
K1: Motor avança <br>
K2: Motor recua <br>

# Escopo
Recebe pela CAN o comando para posicionar em determinado local. Entre 0 e 100%. <br>
Pela quantidade de pulsos sabe onde deve posicionar conforme o percentual. <br>
Possui comando para calibração. <br>

# Protocolo CAN
Endereço CPU: 0x1D57683D <br>
<br>
BYTE 0: Operação <br>
BYTE 1: Posição <br>
BYTE 2: Livre <br>
BYTE 3: Livre <br>
BYTE 4: Livre <br>
BYTE 5: Livre <br>
BYTE 6: Livre <br>
BYTE 7: Livre <br>
<br>
Operação: 0=HOME, 1=POSICIONA e 2=CALIBRAÇÃO <br>
Posição: Valor percentual entre 0-100% da posição, sendo 100% = FIM DE CURSO <br>