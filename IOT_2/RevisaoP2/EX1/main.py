import machine
import utime
potentiometer = machine.ADC(26)
led_amarelo = machine.Pin(15, machine.Pin.OUT)
conversion_factor = 1023 / (65535)
while True:
    voltage = potentiometer.read_u16() * conversion_factor
    print(voltage)
    utime.sleep(2)
    if voltage > 550:
        led_amarelo.value(1)
    else:
        led_amarelo.value(0)
