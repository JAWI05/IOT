# Bibliotecas para pinos e tempo
import machine
import utime

# Declaração dos LEDs e configuração como saída
led_verm = machine.Pin(15, machine.Pin.OUT)
led_amar = machine.Pin(14, machine.Pin.OUT)
led_verd = machine.Pin(13, machine.Pin.OUT)

# Enquanto for verdadeiro (loop infinito)
while True:
    utime.sleep(1)
    # Acende o LED verde e garante que os outros LEDs estão apagados
    led_verm.value(0)
    led_amar.value(0)
    led_verd.value(1)
    utime.sleep(5)
    led_verd.value(0)

    # Faz o LED amarelo piscar três vezes
    for _ in range(3):
        led_amar.value(1)
        utime.sleep(0.5)
        led_amar.value(0)
        utime.sleep(0.5)

    # Acende o LED vermelho
    led_verm.value(1)
    utime.sleep(5)
    led_verm.value(0)

