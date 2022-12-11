CC = icpc
CFLAGS = -O0
OFLAGS = -openmp
 
all:    clean L1TDC L1TBB L1S L1SDC L1SSPMD L1CF L1CDC L1OF L1ODC L2S L2OF L2ODC L2CF L2CDC L2TBB L3S L3C L4 L5

L1S: L1_Serial.cpp
	$(CC) L1_Serial.cpp $(CFLAGS)  -o L1S

L1SDC: L1_SerialDivideConquer.cpp
	$(CC) L1_SerialDivideConquer.cpp $(CFLAGS) -oL1SDC

L1SSPMD: L1_SerialSPMD.cpp
	$(CC) L1_SerialSPMD.cpp $(CFLAGS) -o L1SSPMD

L1CF: L1_Cilkfor.cpp
	$(CC) L1_Cilkfor.cpp  $(CFLAGS) -o L1CF

L1CDC: L1_CilkDivideConquer.cpp
	$(CC) L1_CilkDivideConquer.cpp $(CFLAGS) -o L1CDC

L1OF: L1_OMPfor.cpp
	$(CC) L1_OMPfor.cpp $(CFLAGS) $(OFLAGS) -o L1OF

L1ODC: L1_OMPDivideConquer.cpp
	$(CC) L1_OMPDivideConquer.cpp $(CFLAGS) $(OFLAGS) -o L1ODC

L2S: L2_Serial.cpp
	$(CC) L2_Serial.cpp $(CFLAGS)  -o L2S

L2CF: L2_Cilkfor.cpp
	$(CC) L2_Cilkfor.cpp  $(CFLAGS) -o L2CF

L2CDC: L2_CilkDivideConquer.cpp
	$(CC) L2_CilkDivideConquer.cpp $(CFLAGS) -o L2CDC

L2OF: L2_OMPfor.cpp
	$(CC) L2_OMPfor.cpp $(CFLAGS) $(OFLAGS) -o L2OF

L2ODC: L2_OMPDivideConquer.cpp
	$(CC) L2_OMPDivideConquer.cpp $(CFLAGS) $(OFLAGS) -o L2ODC

L3S: L3_Serial.cpp
	$(CC) L3_Serial.cpp $(CFLAGS)  -o L3S

L3C: L3_Cilk.cpp
	$(CC) L3_Cilk.cpp  $(CFLAGS) -o L3C

L4: L4.cpp
	$(CC) L4.cpp $(CFLAGS) $(OFLAGS)  -o L4

L5: L5.cpp
	$(CC) L5.cpp $(CFLAGS) $(OFLAGS)  -o L5

L1TBB: L1_TBBReduce.cpp
	$(CC) L1_TBBReduce.cpp $(CFLAGS)  -o L1TBB -ltbb

L1TDC: L1_TBBDivideConquer.cpp
	$(CC) L1_TBBDivideConquer.cpp $(CFLAGS)  -std=c++0x -o L1TDC -ltbb

L2TBB: L2_TBBfor.cpp
	$(CC) L2_TBBfor.cpp $(CFLAGS) -std=c++0x  -o L2TBB -ltbb


clean:
	rm -f L1TDC L1TBB L1CDC L1CF L1ODC L1OF L1S L1SDC L1SSPMD L2CDC L2OF L2S L2CF L2ODC L2TBB L3C L3S L4 L5 a.out
