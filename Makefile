CC = gcc


TARGET = program

#recursively find all .c files 
SRCS := $(shell find . -name '*.c')


#object files have the same name as c files but with .o
OBJS := $(SRCS:.c=.o)


all: $(TARGET)
	$(shell find . -name '*.o' -delete)

# compile all .o files to one binary file ^ all prerequisites
$(TARGET): $(OBJS)
	$(CC) -lcurl -o  $@ $^ 
	

# compile all .c files  to .o files of same name, one at a time < first prerequisite
%.o: %.c
	$(CC) -c $< -o $@

clean: 
	