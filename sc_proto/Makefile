INC := -I/home/zjq/deep_learning/anaconda3/include/python3.6m
LIB := -L/home/zjq/deep_learning/anaconda3/lib -lpython3.6m

main: sc_proto.o main.o
	gcc -o main main.o sc_proto.o ${INC} ${LIB}
sc_proto.o: sc_proto.c
	gcc -c sc_proto.c ${INC}
main.o : main.c
	gcc -c main.c ${INC}
clean:
	rm main *.o -rf
