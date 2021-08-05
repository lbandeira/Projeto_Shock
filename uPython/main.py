
# ###################################################
#            AUTECLA PROJETO SHOCK    V1.0.0       #
#                                                  # 
# Para excucao do codigo no picocom, utilize:      #
#                                                  #
#       exec(open("main.py").read())               #
#                                                  #
# ###################################################


import time
from machine import Pin
from machine import ADC

pinS = [Pin(26,Pin.OUT), Pin(25,Pin.OUT), Pin(33,Pin.OUT), Pin(32,Pin.OUT)]

def main():
#
# VERSAO DO CODIGO
#

    print('\033[33m'+'\n=============== VERSAO 1.0.0 ===============\n'+'\033[0;0m')

#
# Inicialização dos pinos 
#
    for i in range(3):
        pinS[i].value(1)

    pinSignal = Pin(34, Pin.IN)
    adc2 = ADC(pinSignal)
    adc2.atten(ADC.ATTN_11DB)

    print('\033[33m'+'\n============== LEITURAS =============='+'\033[0;0m')
    print('---\t---\t---\t---\t---\t---\t---\t---')
    while(1):  
        for pin in range(11):
            for i in range(3):
                pinS[i].value(1 if pin & (1 << i) else 0)
            Signal = adc2.read()
            print(Signal)
        print('\n')
        time.sleep(1)

main()
