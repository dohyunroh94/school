CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Proj4.o

LIBS =

TARGET =	Proj4.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
