# Comoara-Faraonului
Un proiect bazat pe Greedy, programare dinamica si backtraking


Un faraon foarte bogat voia să-şi ascundă comorile, aşa că a cerut să i se construiască un seif în forma unei piramide. 
El a mai cerut ca acesta să aibă o singură intrare (prin vârful piramidei), adică să se poată intra numai urcând pe trepte,
şi anumite secvenţe de paşi să blocheze calea de acces (din vârf).

Peste ceva timp, după ce piramida este gata, faraonul vrea să-şi verifice comorile, dar nu-şi mai aminteste pe care trepte 
trebuie să calce. Faraonul e bătrân şi s-a gândit că va avea problema aceasta, aşa că a cerut următoarele pentru a-i fi mai
uşor să găsească drumul:

    să existe cel puţin un drum pe care el poate merge în siguranţă, plecând dintr-un colţ al bazei piramidei
    acest drum să arate la fel, indiferent din ce colţ al bazei pleacă
    să primească o hartă care include un colţ al bazei şi care să-l ajute să găsească drumul

Harta:

    conţine un desen cu o parte din piramidă(atât cât îi trebuie faraonului), pe fiecare treaptă este trecut un număr, iar 
    harta este însoţită de un număr ce va reprezenta o sumă (maximă admisă).

Indicaţii

    desenul de pe hartă poate fi reprezentat folosind o matrice bidimensională pătratică de latură n.
    Pentru fiecare drum, colţul stânga-sus din matrice va fi punctul destinaţie(vârful) şi colţul dreapta-jos din matrice va 
    fi punct de plecare.
    faraonul poate „merge“, în matrice, doar în stânga(câte o coloană) sau în sus(câte o linie) la fiecare pas.
    Excepţie: atunci când, în urma unui pas, ajunge pe o „margine“ din matrice, faraonul poate merge, pentru restul drumului, 
    doar într-un sens: dacă ajunge pe prima linie, mai poate merge doar în stânga(respectiv de pe prima coloană, mai poate merge 
    doar în sus).
    numim drum valid un drum pe care poate „merge“ faraonul (în matrice).
    numim cost al unui drum suma tuturor valorilor din matrice de la poziţiile incluse în acel drum.
    un drum va fi sigur dacă are un cost mai mic decât (sau egal cu) suma maximă admisă.

Cerințe

    Aflaţi costul drumului valid ales după optimul local (la fiecare pas unde are de ales dintre stânga şi sus, alege
    treapta cu costul mai mic; preferă SUS când costurile sunt egale);
    Aflaţi costul drumului valid ales după optimul global (drumul cu cea mai mică sumă dintre cele posibile);
    Simulaţi un număr de drumuri valide ca încercări pentru a găsi un drum sigur
    (vă opriţi la primul drum sigur găsit), unde fiecare pas este ales “la întâmplare”(excepţie atunci când există o
    singură variantă pentru următorul pas - când am ajuns deja pe prima linie sau pe prima coloană)
    (bonus) Aflaţi numărul de drumuri valide sigure.
