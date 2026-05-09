import machine
import utime

led_amarelo = machine.Pin(15, machine.Pin.OUT)
led_vermelho = machine.Pin(14, machine.Pin.OUT)
led_verde = machine.Pin(13, machine.Pin.OUT)

sensor_temp = machine.ADC(26) 
conversion_factor = 3.3 / (65535)  

while True:
    leitura = sensor_temp.read_u16()  
    reading = leitura * conversion_factor  
    temperatura = 27 - (reading - 0.706) / 0.001721 

    print(f"Leitura bruta do ADC: {leitura}")
    print(f"Tensão lida: {reading:.4f} V")
    print(f"Temperatura calculada: {temperatura:.2f} °C")

    if temperatura >= 30:
        led_vermelho.value(1)
        led_amarelo.value(0)
        led_verde.value(0)
    elif 20 <= temperatura < 30:
        led_vermelho.value(0)
        led_amarelo.value(1)
        led_verde.value(0)
    else:  
        led_vermelho.value(0)
        led_amarelo.value(0)
        led_verde.value(1)
    
    utime.sleep(2) 
