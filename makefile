signalcompile: signals.c
	gcc signals.c
run: signalcompile
	./a.out
clean:
	rm a.out
	rm log
