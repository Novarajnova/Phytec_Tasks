CFLAGS += -Wall

SRCS = app.c add.c mul.c div.c sub.c
OBJS = $(SRCS:.c=.o)
TARGET = mycalci

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c myheader.h
	$(CC) $(CFLAGS) -c $< -o $@

install:
	install -d $(DESTDIR)/usr/bin
	install -m 0755 $(TARGET) $(DESTDIR)/usr/bin

clean:
	rm -f $(OBJS) $(TARGET)
