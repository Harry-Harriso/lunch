.SUFFIXES: .c.o

TARGET = lunch
OBJS = main.o
SRCS = $(OBJS:.o=.c)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o lunch $(OBJS)

.c.o:
	$(CC) -c $<

clean: 
	rm -f $(TARGET) $(OBJS)
