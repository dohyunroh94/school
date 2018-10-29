all: TrafficSim.o IntersectionFlowRate.o Vehicle.o LinkedList.o Node.o driver.o
	g++ -Wall driver.o TrafficSim.o IntersectionFlowRate.o Vehicle.o LinkedList.o Node.o  -o output.out

Node.o: Node.cpp
	g++ -Wall -c Node.cpp
	
LinkedList.o: LinkedList.cpp
	g++ -Wall -c LinkedList.cpp
	
Vehicle.o: Vehicle.cpp
	g++ -Wall -c Vehicle.cpp -D$(clearset)
	
IntersectionFlowRate.o: IntersectionFlowRate.cpp
	g++ -Wall -c IntersectionFlowRate.cpp

TrafficSim.o: TrafficSim.cpp
	g++ -Wall -c TrafficSim.cpp
	
driver.o: driver.cpp
	g++ -Wall -c driver.cpp

# -f removes any error messages if the file is not present
clean:
        rm -rf *.o
        rm -f *.out
        rm -f *~ *.h.gch *#
run:
	./output.out $(file)

