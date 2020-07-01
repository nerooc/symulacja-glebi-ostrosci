#### Projekt nr  37


# Symulator głębi ostrości

Autorzy: Piotr Harmuszkiewicz, Kamil Szczepanek, Tomasz Gajda



## 1. Opis Projektu

Projekt zakłada stworzenie programu, pozwalającego na symulowanie głębi ostrości.  Oznacza to, że jeśli ustawimy ostrość na obiekt znajdujący się trzy metry od “obiektywu” to obiekty bliższe oraz dalsze będą rozmyte - ma symulować działanie rzeczywistych obiektywów. Efekt ten wykorzystywany głównie przez branżę kreatywną, często stosowany jest w celu skupienia uwagi widza na jakimś obiekcie - wskazania co na zdjęciu jest najważniejsze. W celu symulacji głębi, skorzystać będziemy musieli z tzw. map głębokości - są to obrazy o nieskończonej głębi ostrości specjalnie przygotowane dla danych obrazów.



## 2. **Założenia wstępne przyjęte w realizacji projektu**

Program powinien pozwolić użytkownikowi na ustawienie parametrów mapy głębokości jakimi są ogniskowa obiektywu i przysłona. W każdej chwili mamy opcję resetowania naszych ustawień mapy poprzez kliknięcie przycisku. Możemy również porównać nasze zdjęcie z mapą głębokości ze zdjęciem oryginalnym. Możliwe ma być też wczytywanie zdjęć z pliku oraz zapisywanie ich do pliku.  Praca nad projektem miała potrwać miesiąc. Uzgodniliśmy wygląd interfejsu.


![alt text](https://github.com/nerooc/symulacja-glebi-ostrosci/blob/master/dokumentacja-materialy/mapy.png)


Rys. 1 Zdjęcia wraz z przygotowanymi mapami głębokości



## 3. **Analiza projektu**

### **Specyfikacja interfejsu użytkownika**

Interfejs powstał przy użyciu programu wxFormBuilder.

![alt text](https://github.com/nerooc/symulacja-glebi-ostrosci/blob/master/dokumentacja-materialy/interfejs.png)

Rys. 2 Interfejs programu

Składa się on z 4 przycisków, 1 checkboxa oraz 5 sliderów.  
**Przyciski** służą głównie do kontroli nad plikami:



*   **Wczytaj obraz** - Przycisk pozwala na otwarcie okna dialogowego i wczytanie wybranego przez nas pliku do programu jako zdjęcie główne
*   **Wczytaj mapę głębokości** - Przycisk pozwala na otwarcie okna dialogowego i wczytanie wybranego przez nas pliku do programu jako mapę głębokości
*   **Reset** - Przycisk pozwala na zresetowanie ustawień zmienionych na sliderach obsługujących mapę głębokości
*   **Zapis do pliku** - Przycisk pozwala na zapisanie naszego zmodyfikowanego zdjęcia do pliku

**Checkbox** daje nam możliwość decydowania o tym czy chcemy nałożyć mapę głębokości na obraz czy też chcemy widzieć oryginał. 

**Slidery** służą do kontrolowania zmian efektów nałożonych na obraz. Znajdujące się po lewej stronie służą do kontroli związanej ściśle z symulacją głębi ostrości: 



*   **Obiektyw** - Pozwala nam zmieniać wartość ogniskowej obiektywu, decyduje “na jakiej głębokości”  zdjęcie zacznie się rozmazywać
*   **Przysłona** - Pozwala nam obsługiwać przysłonę, decyduje jak bardzo będzie rozmazywać się zdjęcie pod wpływem mapy głębokości

Te znajdujące się prawej natomiast, służą do wprowadzania innych, niezwiązanych z symulacją poprawek wizualnych:



*   **Korekcja Gamma** - Pozwala nam zmieniać wartość korekcji gamma
*   **Kontrast** - Pozwala nam zmieniać wartość kontrastu na naszym zdjęciu
*   **Jasność** - Pozwala nam zmieniać jasność naszego zdjęcia

### **Decyzja o wyborze narzędzi programistycznych**

Zadecydowaliśmy, że program zostanie stworzony z wykorzystaniem biblioteki **WxWidgets**, ponieważ jest ona wspierana przez pomocny i wygodny przy budowaniu interfejsów program **wxFormBuilder**. \
 \
Wszyscy korzystaliśmy z **Visual Studio 2019** jako że poprzez wykonywanie laboratoriów przez pierwszą połowę semestru wszyscy nabraliśmy doświadczenia z tym środowiskiem i mieliśmy je już poprawnie skonfigurowane do współpracy z biblioteką WxWidgets.

Do przechowywania okresowych postępów korzystaliśmy z platformy **GitHub**, na której stworzyliśmy repozytorium gdzie przesyłaliśmy rzeczy, które aktualnie robiliśmy. Było to bardzo wydajne rozwiązanie, które nie powodowało żadnych problemów, a wszyscy członkowie grupy mieli najnowsze wersje programu cały czas w pełni dostępne.




## 4. **Opracowanie i opis niezbędnych algorytmów**

Liczyliśmy średni kolor wokół każdego pixela, w obszarze zależnym od odległości. Im pixel na mapie głębokości dalej, tym większy obszar z którego liczymy średnią (pixel ten, przyjmuje kolor średniej). W jaki sposób to uzyskaliśmy? \
 \
Mamy nasz obraz - każdy pixel ma 3 parametry: r, g, b typu unsigned char czyli 1 bajt (0-255)   

1. **Liczymy summed area table:**  \
(tj. tablica sum prefiksowych lub tablica zsumowanego obszaru). Jest to tablica w której każdy kolejny element jest sumą poprzednich, czyli dla tablicy 1D:  


t[0] = 2, t[1] = 4, t[2] = 8, t[3] = 13, t[4] = 17, t[5] = 20 

Summed area table (SAT) będzie wyglądała następująco: 


                SAT[0] = t[0] = 2,0 


                SAT[1] = t[0] + t[1] = 6, 


                SAT[2] = t[0] + t[1] + t[2] = SAT[1] + t[2] = 14 


                SAT[3] = SAT[2] + t[3] = 27 


                SAT[4] = Sat[3] + t[4] 

Co nam to daje? - W ten sposób możemy szybko policzyć sumę elementów od t[a] do t[b], wystarczy odjąć t[b] - t[a] i mamy sumę od a do b. A jak mamy sumę to mamy też średnią: 

t[b] - t[a] / (b-a) 

Jednak nasz obraz jest 2D - wszystko działa bardzo podobnie: do policzenia SAT najpierw zsumujemy wiersze a potem kolumny (w rzeczywistości jednak nie ma znaczenia co najpierw zsumujemy - wiersze czy kolumny).

Otrzymujemy tablice SAT 2D i chcemy obliczyć sume obszaru a potem średnią: 

![alt text](https://github.com/nerooc/symulacja-glebi-ostrosci/blob/master/dokumentacja-materialy/sat.png)

Suma obszaru ABCD będzie wynosić:  **sum = C + A - B - D** \
4 + 9 + 1 + 8 = 22 = 20 + 74 - 33 - 39 

a średnia to **sum / ((B - A) * (D - A))**

W ten sposób liczymy średnią dla każdego pixela. Pamiętamy, że pixel ma 3 wartości **(r, g, b)** i każdy element tablicy to tak naprawdę 3 liczby (wartości w SAT na końcu tablicy będą bardzo duże więc SAT jest typu **unsigned int**).



**2. GŁÓWNA PĘTLA FOR dla każdego pixela (i , j):**

a) Liczymy promień filtra (w programie float r) ten promień to tak naprawdę kwadrat, r tworzy kwadrat o boku 2r i środku w naszym pixelu (i,j) z tego kwadratu będziemy liczyć średnią 

![alt text](https://github.com/nerooc/symulacja-glebi-ostrosci/blob/master/dokumentacja-materialy/px.png)

**r = |(depthMap[i][j] - focus) / 255 * max|**

gdzie:

**focus** - odległość w której obraz jest ostry (w zakresie 0-255) 

**max** - maksymalna wielkość r (im większe tym obraz szybciej/bardziej się rozmazuje w odległości) 

b) Liczymy sumę obszaru ABCD, a potem średnią: 


                    A = SAT[i - m][j - m] 


                    B = SAT[i + m][j - m] 


                    C = SAT[i - m][j + m] 


                    D = SAT[i + m][j + m] 


                    sum = A - B - C + D 


                    średnia = sum/(2*m)<sup>2</sup> 

kolorem naszego pixela będzie ta średnia - tak samo postępujemy dla **każdego** pixela. 



## 5. **Kodowanie**

**Klasy:**


- **MyApp** jest to klasa aplikacji, która jest konieczna by uruchomić nasz program, dziedziczy po klasie wxApp z biblioteki wxWidgets i nadpisuje dwie funkcje OnInit() oraz OnExit(), które po włączeniu programu tworzą nowy obiekt klasy SimGOSymulatorGO, a po wyłączeniu zwracają zero.


- **GUI** to klasa stworzona i wygenerowana przez program wxFormBuilder. Znaleźć tam możemy wszystkie elementy interfejsu, czyli przyciski, suwaki oraz panel.


- **SimGOSymulatorGO** jest to klasa zawierająca wszystkie metody obsługujące elementy interfejsu - metody które włączamy w razie korzystania z przycisków/slider’ów.


- **DOF** jest to klasa odpowiadająca za działanie samej symulacji, zawiera zmienne i metody potrzebne do poprawnego funkcjonowania programu. 


**Zmienne:**

*   zmienne posiadające w nazwie **Height** opisują wysokość poszczególnych elementów
*   zmienne posiadające w nazwie **Width** opisują szerokość poszczególnych elementów
*   **translationX** oraz **translationY** opisują przesunięcie zdjęcia względem punktu (0,0) na panelu, pozwala na wycentrowanie wczytanego zdjęcia
*   **depthMapOn** to zmienna typu bool, która mówi nam o tym czy jest włączone nakładanie mapy głębokości
*   **mainImage** oraz **depthMap** to obiekty klasy wxImage, przechowujące oryginalne obrazki, odpowiednio obrazek główny oraz jego mapę głębokości
*   **mainScaledImage** oraz **depthScaledMap** to obiekty klasy wxImage, przechowujące przeskalowane obrazki, odpowiednio obrazek główny oraz jego mapę głębokości
*   **original, depth, blurred, final** to obiekty klasy wxImage opisujące poszczególne elementy składające się na otrzymanie zdjęcia objętego symulacją
*   **(\*\*\*SAT)** - trójwymiarowa tablica SAT z opisanego wcześniej algorytmu
*   **sizeX** - szerokość oryginalnego zdjęcia
*   **sizeY** - wysokość oryginalnego zdjęcia
*   **focal_distance** - ogniskowa, odległość w jakiej należy ustawić obiekt, aby był ostry
*   **focal_depth** - głębia ogniskowa, szybkość z jaką obiekty przestają być ostre wraz z oddalaniem się od ogniskowej
*   **max_focal_depth** - maksymalna głębia ostrości

**Funkcje:**

*   **loadImage( wxCommandEvent& event )** - funkcja pozwalająca na wczytanie głównego zdjęcia
*   **loadDepthMap( wxCommandEvent& event )** - funkcja pozwalająca na wczytanie mapy głębokości
*   **mapOn( wxCommandEvent& event )** - funkcja obsługująca checkBox, od którego zależy czy włączona jest mapa głębokości
*   **lensOnScroll( wxScrollEvent& event )** - funkcja obsługująca slider ustalający wartość zmiennej focal_distance
*   **apertureOnScroll( wxScrollEvent& event )** - funkcja obsługująca slider ustalający wartość zmiennej focal_depth
*   **resetImage( wxCommandEvent& event )** - funkcja pozwalająca użytkownikowi na reset obrazka do domyślnych wartości ustawień programu
*   **saveImage( wxCommandEvent& event )** - funkcja pozwalająca na zapis obrazka do pliku
*   **windowResized( wxSizeEvent& event )** - funkcja aktualizująca obrazek w momencie zmiany rozmiaru programu
*   **updateUI( wxUpdateUIEvent& event )** - funkcja aktualizująca obrazek
*   **gammaCorrection( wxScrollEvent& event )** - slider pozwalający na korzystanie z korekcji gamma na obrazku
*   **setContrast( wxScrollEvent& event )** - slider pozwalający na korzystanie ze zmiany kontrastu  obrazka
*   **setBrightness( wxScrollEvent& event )** - slider pozwalający na korzystanie ze zmiany jasności obrazka
*   **Repaint()** - funkcja “rysująca” zdjęcie na panelu, wykorzystywana w każdej funkcji aktualizującej
*   **calculate_SAT_DOF()** - przelicza SAT a potem wywoluje calculateDOF()
*   **calculateDOF()** - aktualizuje obraz final (ale nie przelicza SAT)
*   **allocateSAT(unsigned int x, unsigned int y)** - zajmuje miejsce dla tablicy SAT
*   **freeSAT()** - zwalnia miejsce zajmowane przez tablicę SAT
*   **calculateSAT()** - funkcja obliczająca tablicę SAT opisaną w algorytmie
*   **gettery, settery** - seria funkcji pozwalających na dostęp do zmiennych prywatnych klasy DOF

## 6. Wdrożenie, raport i wnioski

Udało nam się spełnić wszystkie wymagania podstawowe - program wczytuje dwa pliki, obraz oraz mapę głębokości. Użytkownik ma możliwość wyboru parametrów odległości ostrej jak i wyboru jak mocno obraz ma się rozmywać. Obraz jest wyświetlany na ekranie i jest możliwe zapisanie obrazu na dysk. Udało nam się zrobić również część wymagań rozszerzonych - użytkownik może manipulować wartościami korekcji gamma, kontrastem czy też jasnością. Stworzyliśmy również dwie mapy głębokości które służą jako przykłady działania programu. Niestety różne manipulacje nie mogą być stosowane jednocześnie, co zdecydowanie jest główną rzeczą, którą należałoby poprawić. 
