CC     = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC    = main.c recherche.c conjugaison_1er_groupe.c conjugaison_2eme_groupe.c

conjugaison: $(SRC) conjugaison.h
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f conjugaison conjugaison.exe resultats.txt
