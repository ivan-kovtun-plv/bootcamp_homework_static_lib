objects := main.o DefineOperation.o SimpleMemoryControl.o
libcalc := libcalc/libcalc.a
libcalcpath := libcalc
libcalcinc := -Ilibcalc/inc
inc := -I.

simplecalc: $(objects) $(libcalc)
	gcc -o simplecalc $(objects) -lcalc -L$(libcalcpath) $(libcalcinc) $(inc) -lm

main.o:
	gcc -c main.c $(inc) $(libcalcinc)

DefineOperation.o:
	gcc -c DefineOperation.c $(inc)

SimpleMemoryControl.o:
	gcc -c SimpleMemoryControl.c $(inc)

$(libcalc):
	cd libcalc && $(MAKE)

clean:
	rm -f *.o simplecalc
	cd libcalc && $(MAKE) clean



