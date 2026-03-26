# Atividade: "Cão de Guarda" da Nuvem Industrial com ESP32

Este repositório contém o projeto de um sistema de monitoramento de conectividade (Watchdog) desenvolvido para a plataforma **ESP32**. O dispositivo atua como um supervisor de rede para a fábrica TechMec Automação, garantindo que os operadores sejam avisados visualmente em caso de queda do servidor ou falha de internet.

VIDEO: [WATCHDOG](https://youtube.com/shorts/cJtogY26bFw)

---

## Descrição do Projeto
O ESP32 realiza requisições seguras (HTTPS GET) a cada 15 segundos para uma URL de *Health Check*. O projeto atende aos seguintes requisitos:
- **Resiliência de Rede:** Reconecta-se automaticamente caso o Wi-Fi caia.
- **Prevenção de Memory Leak:** Gerenciamento adequado da memória do cliente seguro (`WiFiClientSecure`) a cada ciclo de repetição.
- **Sinalização Física:**
  - **LED Verde/Laranja (Sucesso):** Acende APENAS se o servidor retornar o código HTTP `200`.
  - **LED Vermelho (Alerta):** Acende imediatamente se o Wi-Fi for desconectado ou se o servidor retornar qualquer falha ou código de erro.

## Hardware Necessário
| Componente | Quantidade |
| :--- | :---: |
| Placa ESP32 (ex: DevKit V1) | 1 |
| LED Verde (ou Laranja) | 1 |
| LED Vermelho | 1 |
| Resistor (200Ω) | 2 |
| Protoboard | 1 |
| Jumpers | 4 |

## Esquema de Ligação
1. **LED Verde/Laranja (Sucesso):** O Anodo (perna longa) deve ser conectado ao pino **GPIO 18**.
2. **LED Vermelho (Falha/Desconectado):** O Anodo deve ser conectado ao pino **GPIO 19**.
3. **Resistores e GND:** Os resistores devem ser conectados entre o Catodo (perna curta) de cada LED e a linha de **GND** da protoboard, que por sua vez vai ao pino GND do ESP32.

## Configuração do Ambiente (Arduino IDE)
1. Instale a **Arduino IDE**.
2. Adicione a URL das placas ESP32 em `Preferências`:
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. No `Gerenciador de Placas`, instale o pacote **esp32 by Espressif Systems**.
4. Selecione o modelo da sua placa em `Ferramentas > Placa`.
5. Lembre-se de alterar as variáveis `ssid` e `password` no código fonte para os dados da sua rede local (ex: roteador do celular).

## Autor
- **Vitor Miguel**
