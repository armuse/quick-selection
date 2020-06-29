C++ = g++
C_FLAGS = -g

ROOTCFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs) -lRooFit -lRooFitCore -lMinuit -lTMVA

all nTupReader

clean: 
	rm NtupleReader

nTupReader: EZTree.cpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) EZTree.cpp -o NtupleREader $(ROOTLIBS)
