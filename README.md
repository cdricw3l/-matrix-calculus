# Implementation en c de calcules matriciel

## parsing

### input EBNF gramar

# Non terminal symbole
* EXPRESSION := MATRICE {(PLUS | MOINS) MATRICE}
* MATRICE := BRACKET_LEFT SPACE M SPACE N SPACE BRACKET_LEFT C {SPACE C} BRACKET_RIGHT BRACKET_RIGHT 
* M := UNSIGNED_INT (* M > 0 *)
* N := UNSIGNED_INT (* N > 0 *)
* C := FLOAT
* UNSIGNED_INT := [ PLUS ] INT 
* SIGNED_INT := [ PLUS | MOINS ] INT
* FLOAT:= SIGNED_INT ( DOT | COMMA ) DECIMAL 
* INT := CHIFFRE {CHIFFRE}  (* >= INT_MIN <= INT_MAX *) 
* DECIMAL := CHIFFRE {CHIFFRE}  (* max len 8 CHIFFRE *) 

# Terminal symbole
* CHIFFRE := "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
* PLUS := "+"
* MOINS := "-"
* BRACKET_LEFT := [
* BRACKET_RIGHT := ]
* SPACE := " "
* DOT := '.'
* COMMA := ','

# contrainte
* (* total C = M * N *)
* (* M > 0 *)
* (* N > 0 *)
* INT_MIN := -2147483648
* INT_MAX := 2147483647


# execution




# Ressources

https://www.unilim.fr/pages_perso/jean.debord/math/matrices/matrices.htm
https://fr.wikipedia.org/wiki/Matrice_(math%C3%A9matiques)