# U4C7
Repositório para a atividade da unidade 4 e capítulo 7: PWM

__Aluno:__
Lucas Carneiro de Araújo Lima

## ATIVIDADE 
__Descrição:__
O exercício propõe o controle de um servomotor por meio de um sinal PWM, ajustando a posição do braço para 180°, 90° e 0° com tempos de espera de 5 segundos em cada posição. Para isso, define-se um ciclo ativo de 2400 µs (180°), 1470 µs (90°) e 500 µs (0°), correspondendo a _duty cycles_ de 12%, 7.35% e 2.5%, respectivamente. Após esses ajustes, deve-se implementar uma rotina para movimentação periódica e suave do servo entre 0° e 180°, utilizando incrementos de ±5 µs e um atraso de 10 ms para cada ajuste.

<div align="center">
  <img src="https://github.com/user-attachments/assets/a921a2e0-cf9f-4356-bb28-dfe01573f0b4" alt="GIF demonstrativo" width="400"/>
</div>

__Para este trabalho, os seguintes componentes e ferramentas se fazem necessários:__
1) Microcontrolador Raspberry Pi Pico W.
2) Ambiente de trabalho VSCode.
3) Simulador Wokwi
4) 1 Servomotor
5) 1 LED
6) Ferramenta educacional BitDogLab.

__O resultado do projeto pode ser assistido através deste link: [U4C7 - PWM](https://youtu.be/YymSxwrFUKg).__

## Instruções de Uso

### 1. Clone o repositório
Abra o terminal e execute o comando abaixo para clonar o repositório em sua máquina:
```bash
git clone https://github.com/LucasCarneiro3301/U4C7.git
```

### 2. Configure o ambiente de desenvolvimento
Certifique-se de que o [SDK do Raspberry Pi Pico](https://github.com/raspberrypi/pico-sdk) esteja instalado e configurado corretamente no seu sistema.

### 3. Configure a extensão do simulador Wokwi
Certifique-se de que a extensão [Wokwi para VS Code](https://docs.wokwi.com/pt-BR/vscode/getting-started) esteja instalada e configurada corretamente em seu ambiente VS Code.

### 4. Conexão com a Rapberry Pico
1. Conecte o Raspberry Pi Pico ao seu computador via USB.
2. Inicie o modo de gravação pressionando o botão **BOOTSEL** e **RESTART**.
3. O Pico será montado como um dispositivo de armazenamento USB.
4. Execute através do comando **RUN** a fim de copiar o arquivo `U4C7.uf2` para o Pico.
5. O Pico reiniciará automaticamente e executará o programa.

### 5. Observações (IMPORTANTE !!!)
1. O projeto é compatível **tanto** no Wokwi (servomotor) **quanto** na placa BitDogLab (LED)
2. Manuseie a placa com cuidado.

## Recursos e Funcionalidades

### 1. PWM

O programa implementa modulação por largura de pulso para controlar a posição de um servomotor.

### 2. Servomotor

Define três posições do servo baseadas no ciclo ativo do PWM:
  - 0° → 500 µs (2,5% de _duty cycle_)
  - 90° → 1470 µs (7,35% de _duty cycle_)
  - 180° → 2400 µs (12% de _duty cycle_)

Após isso, o servo permanece na rotina de movimentação periódica entre 0° e 180°, aumentando ou diminuindo o ciclo ativo em 5 µs por vez.

### 3. LED

O LED azul (GPIO 12) recebe o mesmo nível de PWM do servo, variando sua intensidade na mesma medida que a movimentação do servo. 

## Requisito 6: O que o discente observou no comportamento da iluminação do referido LED?

Quando o PWM tem um _duty cycle_ alto, ou seja, a fração correspondente ao nível lógico alto é maior que a fração de nível lógico baixo,  o LED azul permanece aceso por mais tempo dentro de cada período, tornando-se mais brilhante aos olhos humanos. Já com um _duty cycle_ baixo, ele passa mais tempo apagado, parecendo menos intenso. Portanto, à medida que o servomotor se move entre 0° e 180°, o LED azul também muda de brilho de acordo com a largura do pulso aplicado.













