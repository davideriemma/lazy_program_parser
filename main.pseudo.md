# Pseudocodice

## Main:
**NOTE:**

1. apri i file e tutto il resto
2. trova il carattere '@', scrivi i caratteri se non lo trovi
3. se lo trovi, scrivi "#ifndef ...."
4. leggi la stringa successiva
5. continene il carattere '"'?  
	- se sì: toggle il valore del flag `in_string`  [0 -> 1]
		- finquando il valore del flag non è 0
		- stampa la stringa nel file
		- leggi la stringa dal file