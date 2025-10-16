Compilateur=g++
OptionsCompilateur=-c 
Linkeur=g++
OptionsLinkeur=

all: rpi2_exp500_gpio
	

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf rpi2_gpio

archive: clean
	tar czvf ../Rpi2_gpio.tgz *

rpi2_exp500_gpio: rpi2_exp500_gpio.o main.o
	$(Linkeur) $(OptionsLinkeur) rpi2_exp500_gpio.o main.o -o rpi2_exp500_gpio

rpi2_exp500_gpio.o: rpi2_exp500_gpio.cpp
	$(Compilateur) $(OptionsCompilateur) rpi2_exp500_gpio.cpp -o rpi2_exp500_gpio.o

main.o: main.cpp
	$(Compilateur) $(OptionsCompilateur) main.cpp -o main.o
	

