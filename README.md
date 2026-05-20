# 🌐 Introdução à Internet das Coisas (IoT 1 & IoT 2)

Bem-vindo ao repositório central das disciplinas de **Introdução à Internet das Coisas (IoT 1 e IoT 2)**. Este espaço foi criado para centralizar todos os códigos, esquemáticos, relatórios e aprendizados desenvolvidos ao longo da jornada pelo universo dos sistemas embarcados e da automação conectada.

---

## 📚 Estrutura do Curso & Conteúdo Programático

### 🤖 IoT 1: Fundamentos e Eletrônica Básica
O foco inicial é entender como o hardware interage com o mundo físico através de lógica de programação e circuitos eletrônicos.
* **Introdução ao Arduino** e plataformas equivalentes.
* **Eletrônica Prática:** Montagem em protoboard, análise de circuitos elétricos e operação de multímetro.
* **Programação Básica:** Lógica em C/C++ (Wiring).
* **Periféricos:** Manipulação de sensores (leitura de dados) e atuadores (ação física).
* **🏎️ Projeto Prático Final:** Desenvolvimento de um **Robô Seguidor de Linha**.

### ☁️ IoT 2: Conectividade e Sistemas em Nuvem
A evolução do hardware foca em comunicação sem fio, protocolos de rede e integração com ecossistemas web.
* **Revisão e Transição:** Upgrade do ecossistema Arduino para **ESP8266 / ESP32**.
* **Redes e Protocolos:** Uso de redes Wi-Fi e conceitos estruturais de **Servidor e Cliente**.
* **Mensageria:** Implementação e uso do protocolo **MQTT** para comunicação IoT eficiente.
* **Sensores Avançados:** Coleta de dados integrados à rede.
* **🌱 Projeto Prático Final:** Desenvolvimento de uma **Horta Conectada**.

---

## 🚀 Destaque dos Projetos Práticos

### 1. Robô Seguidor de Linha (IoT 1)
Um veículo autônomo capaz de detectar e seguir uma linha demarcada no chão.
* **Hardware:** Arduino Uno/Nano, sensores infravermelhos (TCRT5000), ponte H (L298N ou similar) e motores DC.
* **Lógica:** Algoritmo de leitura analógica/digital com controle de direção e velocidade dos motores.

### 2. Horta Conectada (IoT 2)
Um ecossistema inteligente de monitoramento ambiental e automação de irrigação à distância.
* **Conectividade:** Comandos via Wi-Fi e monitoramento em tempo real através de aplicativo ou navegador web.
* **Telemetria:** Monitoramento de pelo menos duas grandezas (Ex: Temperatura/Umidade Ambiente e Umidade do Solo).
* **Tecnologia base:** ESP8266 ou ESP32 programados em *Wiring (C++)* ou *MicroPython*.
* **Estrutura Física:** Chassi modular cortado em MDF ou impresso em 3D.

---

## 🛠️ Tecnologias, Ferramentas e Componentes

* **Microcontroladores:** Arduino, NodeMCU (ESP8266), ESP32.
* **Linguagens:** C/C++ (Wiring), MicroPython.
* **Protocolos & Redes:** Wi-Fi, MQTT, HTTP.
* **Softwares & IDEs:** Arduino IDE, VS Code (PlatformIO / Thonny), Fritzing (para esquemáticos).
* **Instrumentação:** Multímetro digital, Protoboard, Cabos Jumpers.

---

## 📖 Referências Bibliográficas

Este projeto e os códigos aqui presentes foram baseados e guiados pela seguinte literatura:

1.  **STEVAN JR, S.L.** *Internet das Coisas: Fundamentos e aplicações em Arduino e NodeMCU.* São Paulo: Érica, 2018.
2.  **KENSHIMA, G.** *Nas linhas do Arduino – Programação Wiring para não programadores.* São Paulo: Novatec, 2020.
3.  **OLIVEIRA, C. L. V; ZANETTI, H.A.P.** *IoT com MicroPython e NodeMCU.* 1ª ed. São Paulo: Novatec, 2021.
4.  **OLIVEIRA, S.** *Internet das Coisas com ESP8266, Arduino e Raspberry Pi.* 2ª ed. Atualizado para ESP32. São Paulo: Novatec, 2021.
