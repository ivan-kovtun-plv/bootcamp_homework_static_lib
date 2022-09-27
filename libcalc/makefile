OUT := libcalc.a
INC := -Iinc
ODIR := obj
SDIR := src
_OBJS := div.o fact.o mul.o sqrt.o sub.o sum.o
OBJS := $(patsubst %,$(ODIR)/%,$(_OBJS))

$(OUT): $(OBJS)
	ar -rcs libcalc.a $^

$(ODIR)/%.o: $(SDIR)/%.c $(ODIR)
	gcc -c $(INC) -o $@ $<

$(ODIR):
	mkdir -p obj

clean:
	rm -rf $(ODIR) $(OUT)

