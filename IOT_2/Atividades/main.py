# Bibliotecas para pinos e tempo
import machine
import utime

# Declaração dos LEDs e configuração como saída
button = machine.Pin(9, machine.Pin.IN, machine.Pin.PULL_UP)
led_vermc = machine.Pin(13, machine.Pin.OUT)  
led_amarc = machine.Pin(14, machine.Pin.OUT)  
led_verdc = machine.Pin(15, machine.Pin.OUT) 
led_verdp = machine.Pin(12, machine.Pin.OUT)  
led_vermp = machine.Pin(11, machine.Pin.OUT)  

while True:
    if button.value() == 1:  
        print("Pedestre não pode atravessar!")
        led_vermc.value(0)
        led_amarc.value(0)
        led_verdc.value(1)
        led_vermp.value(1)
        led_verdp.value(0)
        utime.sleep(5)
        
        led_verdc.value(0)  
        for _ in range(3):
            led_amarc.value(1)
            utime.sleep(0.5)
            led_amarc.value(0)
            utime.sleep(0.5)

        led_vermc.value(1)
        utime.sleep(5)
        led_vermc.value(0)
        
    else: 
        print("Pedestre pode atravessar")
        led_amarc.value(1)
        utime.sleep(1)
        led_amarc.value(0)
        
        led_vermc.value(1)
        led_verdp.value(1)
        led_vermp.value(0)
        utime.sleep(5)
        led_vermc.value(0)
        led_verdp.value(0)
        
        print("Pedestre não pode atravessar")
        led_vermp.value(1)
        led_verdc.value(1)
        utime.sleep(5)
        led_vermp.value(0)
        led_verdc.value(0)
