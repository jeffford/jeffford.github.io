CC = icpc
CFLAGS = -O0
OFLAGS = -openmp
 
all:    clean L1S L1SDC L1SSPMD L2S L3S L4 L5

L1S: L1_Serial.cpp
	$(CC) L1_Serial.cpp $(CFLAGS)  -o L1S

L1SDC: L1_SerialDivideConquer.cpp
	$(CC) L1_SerialDivideConquer.cpp $(CFLAGS) -oL1SDC

L1SSPMD: L1_SerialSPMD.cpp
	$(CC) L1_SerialSPMD.cpp $(CFLAGS) -o L1SSPMD

L2S: L2_Serial.cpp
	$(CC) L2_Serial.cpp $(CFLAGS)  -o L2S

L3S: L3_Serial.cpp
	$(CC) L3_Serial.cpp $(CFLAGS)  -o L3S

L4: L4.cpp
	$(CC) L4.cpp $(CFLAGS) $(OFLAGS)  -o L4

L5: L5.cpp
	$(CC) L5.cpp $(CFLAGS) $(OFLAGS)  -o L5


clean:
	rm -f L1S L1SDC L1SSPMD L2S L3C L3S L4 L5 a.out
