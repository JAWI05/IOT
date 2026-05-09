# Bibliotecas para pinos e tempo
# Bibliotecas para pinos e tempo
import machine
import utime

# Declarar button como entrada e ativar pull-up
button = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP)
# Declaração led e configuração como saída
led = machine.Pin(15, machine.Pin.OUT)

# Enquanto for verdadeiro (loop infinito)
while True:
    # Se valor de button for 0
    if button.value() == 1:
        # Envia 1 para led
        led.value(1)
        # Aguarda 2s
        utime.sleep(2)
    else:
        # Desliga LED
        led.value(0)
