'''
Project   :- PICO 1.14 inch lcd HAT
Developed :- SB-COMPONENTS
Date      :- 11/05/2021
Firmware  :- Demo code  for 1.14inch LCD
'''
import Lcd1_14driver
from machine import Pin,PWM
import time
LCD = Lcd1_14driver.Lcd1_14()

#------joystck pin declaration----- 
joyRight = Pin(17,Pin.IN)
joyDown  = Pin(18,Pin.IN)
joySel   = Pin(19,Pin.IN)
joyLeft  = Pin(20,Pin.IN)
joyUp    = Pin(21,Pin.IN)


BL = 13   # lcd back light pin declaration

if __name__=='__main__':
    pwm = PWM(Pin(BL))
    pwm.freq(100)
    pwm.duty_u16(32768)    #max value is 65535
    LCD.fill(LCD.white)
 
    LCD.lcd_show()
    LCD.text("SB-COMPONENTS",60,40,LCD.red)
    LCD.text("Pico WIFI",60,60,LCD.red)
    LCD.text("Pico-LCD-1.14",60,80,LCD.red)
    
    
    
    LCD.hline(10,10,220,LCD.blue)
    LCD.hline(10,125,220,LCD.blue)
    LCD.vline(10,10,115,LCD.blue)
    LCD.vline(230,10,115,LCD.blue)
        
    LCD.lcd_show()
    
    while(1):
        
        if(joyRight.value() == 0):
            print("joyRight press")
            LCD.fill(0x00f0)     #0x00ff for red color 
            LCD.lcd_show()
                  
        elif(joyDown.value() == 0):
            print("joyDown press")
            LCD.fill(0x0f00)     #0x00ff for blue color 
            LCD.lcd_show()

        elif(joySel.value() == 0):
            print("joySel press")
            LCD.fill(0x000f)      #0x00ff for green color 
            LCD.lcd_show()
            
        elif(joyLeft.value() == 0):
            print("joyLeft press")
            LCD.fill(0x00ff)      #0x00ff for yellow color 
            LCD.lcd_show()
       
        elif(joyUp.value() == 0):
            print("joyUp press")
            LCD.fill(0xfff0)      #0x00ff for pink color 
            LCD.lcd_show()
        
            
            
    LCD.lcd_show()
    time.sleep(1)
    #LCD.fill(0xFFFF)
