# ChessTournament

Książę Bitomruk jest zapalonym szachistą. Aby uczcić jego pasję przed koronacją postanowiono przeprowadzić wielki turniej szachowy. Turniej ma polegać na tym, że każdy zawodnik zagra z każdym innym i ten, który pokona najwięcej osób zwycięży (formalnie każda potyczka składa się z serii gier, żeby każdy w parze zagrał tyle samo razy białymi co czarnymi, ale to nie znaczenia dla naszego zadania). Oczywiście organizatorzy turnieju założyli, że Bitomruk wygra, ale oszacowane wyniki gier wskazują, że najwyraźniej książe ma w sobie więcej pasji niż talentu. Jako że Wielki Turniej Koronacyjny został już ogłoszony, organizatorzy postanowili przekupić część graczy, żeby Bitomruk jednak wygrał. Na podstawie analizy poprzednich gier wyznaczyli dla każdych dwóch graczy kto zapewne wygra oraz ustalili cenę za odwrócenie tego wyniki. Niestety mają już dość ograniczony budżet i chcą na łapówki wydać jak najmniej pieniędzy. Twoim zdaniem jest napisać program, który sprawdzi, czy przy ich budżecie możliwe jest zapewnienie Bitomrukowi zwycięstwa. Na szczęście zasady zostały ustalone tak, że jeśli turniej zakończy się remisem (czyli kilku zawodników wygra tyle samo gier) i wśród remisujących znajdzie się Bitomruk, to i tak on właśnie wygrywa.

## Dane wejściowe
Plik wejściowy (który ma być wczytywany ze standardowego wejścia) w pierwszej linii zawiera liczbę T mówiącą ile jest zestawów danych (każdy pojedynczy zestaw opisuje jeden turniej). W kolejnych linijkach znajdują się opisy turniejów w następującym formacie:

- W pierwszej linii znajduje się liczba B, będąca budżetem organizatorów turnieju.

- W drugiej linii znajduje się liczba n zawodników. Zawodnicy są numerowani od 0 do n-1, książe Bitomruk ma numer 0 (co według niektórych dobrze odpowiada jego osobowości).

- W kolejnych n*(n-1)/2 liniach znajdują się czwórki liczb x, y, w, b, oznaczające, że gdy x gra przeciwko y to zwycięża w (gdzie w jest albo równe x albo y), ale płacąc b można wynik tego spotkania odwrócić. Każda para x, y występuje w opisie turnieju dokładnie raz.
