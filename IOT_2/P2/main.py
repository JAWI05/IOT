import machine
import machine
import utime
potentiometer = machine.ADC(26)
led_verde = machine.Pin(15, machine.Pin.OUT)
led_vermelho = machine.Pin(14, machine.Pin.OUT)
conversion_factor = 1023 / (65535)
while True:
    voltage = potentiometer.read_u16() * conversion_factor
    print(voltage)
    utime.sleep(2)
    if voltage > 635:
        led_verde.value(0)
        led_vermelho.value(1)
    else:
        led_vermelho.value(0)
        led_verde.value(1)
