#DO NOT EDIT THIS FILE WITHOUT CONSULTING THE GROUP.
all: underseainvaders

underseainvaders: underseainvaders.o Model.o Controller.o View.o
  g++ -std=c++11 -Wall -o $@ $^

underseainvaders.o: underseainvaders.cpp Model.h Controller.h View.h
	g++ -c -std=c++11 -Wall -O2 -o $@ $<

Model.o: Model.cpp Model.h
	g++ -c -std=c++11 -Wall -O2 -o $@ $<

Controller.o: Controller.cpp Controller.h Model.h View.h
	g++ -c -std=c++11 -Wall -O2 -o $@ $<

View.o: View.cpp View.h
  g++ -c -std=c++11 -Wall -O2 -o $@ $<

clean:
	rm -f underseainvaders underseainvaders.o Model.o Controller.o View.o
