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

rpi2_exp500_gpio: rpi2_exp500_gpio.o tcomptesmembres.o tgestion.o thistorique.o tlecteur.o tmateriel.o trs232.o main.o
	$(Linkeur) $(OptionsLinkeur) rpi2_exp500_gpio.o tcomptesmembres.o tgestion.o main.o thistorique.o tlecteur.o tmateriel.o trs232.o -o Tennis

rpi2_exp500_gpio.o: rpi2_exp500_gpio.cpp
	$(Compilateur) $(OptionsCompilateur) rpi2_exp500_gpio.cpp -o rpi2_exp500_gpio.o

tcomptesmembres.o: tcomptesmembres.cpp
	$(Compilateur) $(OptionsCompilateur) tcomptesmembres.cpp -o tcomptesmembres.o

tgestion.o: tgestion.cpp
	$(Compilateur) $(OptionsCompilateur) tgestion.cpp -o tgestion.o

thistorique.o: thistorique.cpp
	$(Compilateur) $(OptionsCompilateur) thistorique.cpp -o thistorique.o

tlecteur.o: tlecteur.cpp
	$(Compilateur) $(OptionsCompilateur) tlecteur.cpp -o tlecteur.o

tmateriel.o: tmateriel.cpp
	$(Compilateur) $(OptionsCompilateur) tmateriel.cpp -o tmateriel.o

trs232.o: trs232.cpp
	$(Compilateur) $(OptionsCompilateur) trs232.cpp -o trs232.o

main.o: main.cpp
	$(Compilateur) $(OptionsCompilateur) main.cpp -o main.o
	
