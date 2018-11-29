################################################################################
# @brief		makefile
# @author		HoYa <hoya128@gmail.com>
#	@version	v1.0.0
# @history
#		- 2018.11.28	Created.
################################################################################

.PHONY: clean

include tool.mk

TARGET	= full

OBJS		= main.o file_a.o file_b.o file_c.o

vpath %.c sub_b sub_c

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $@ $^

clean:
	rm -rf full $(OBJS)
	rm -rf full $(TARGET)
