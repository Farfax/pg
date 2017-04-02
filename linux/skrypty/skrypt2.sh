#!/bin/bash
CMD=0


while [ $CMD -ne 7 ];do
echo "1. Nazwa pliku: $PLIK
2. Sciezka do pliku: $KATALOG
3. Min rozmiar: $MIN
4. Max rozmiar: $MAX
5. Zawartosc: $ZAW
6. Szukaj
7. Koniec"

	read CMD

	if [ $CMD -eq 1 ];then
	read PLIK
	CMD=0

	elif [ $CMD -eq 2 ];then
	read KATALOG
	CMD=0

	elif [ $CMD -eq 3 ];then
	echo "c/k/M/G (rozmiar):"
	read MIN
	CMD=0
	
	elif [ $CMD -eq 4 ];then
	echo "c/k/M/G (rozmiar):"
	read MAX
	CMD=0

	elif [ $CMD -eq 5 ];then
	read ZAW
	CMD=0

	elif [ $CMD -eq 6 ];then
	WYNIK=$(find $KATALOG -name $PLIK -size "+$MIN" -size "-$MAX" -exec grep -l $ZAW {} \; |& grep -v "Brak dost�pu" | wc -l)

		if [ $WYNIK -gt 0 ];then
		echo "plik istnieje"
		else
		echo "plik nie istnieje"
		fi
	CMD=0

	else echo "-----------------"
	fi
	done