# v0.1 ir v0.1vector

Įvedamas studentų skaičius, jų vardai, pavardės, nd pažymiai (galima pasirinkti, kiek nd_paz įvesti) ir egz pažymiai.  
Pažymius galima vesti "ranka" arba sugeneruoti automatiškai.  
Pagal įvestus pažymius apskaičiuojamas galutinis pažymys.

Programa vardą, pavardę leidžia įvesti tik iš raidžių; pažymius tik iš skaičių.

const int arrs ir const int defsize - v0.1 ir v0.1vector nd_paz array/vektoriaus dydžiai atitinkamai.   

# v0.2
Eilutės iš "studentai10000 (with errors).txt" kaip string'ai įrašomi i "lineread".  
Sukuriamas Student struct'ų vektorius, kiekvienam Student objektui priskiriamas string'as iš "lineread"; string'as išskaidomas į Student struct'o kintamiuosius (vardas, pavardė, nd_paz, egz_paz).  

const int columncount - "studentai10000 (with errors).txt" stulpelių skaičius.  
nd_paz - int vektorius iš (columncount - 3) skaičių.

# v0.3
Eilutės iš "studentai10000 (with errors).txt" kaip string'ai įrašomi i "lineread".  
Sukuriamas Student struct'ų vektorius, kiekvienam Student objektui priskiriamas string'as iš "lineread"; string'as išskaidomas į Student struct'o kintamiuosius (vardas, pavardė, nd_paz, egz_paz).  

Jei "studentai10000 (with errors).txt" neegzistuoja/programa negali jo atidaryti - išmeta "ERROR: missing file"  
Jei nuskaitytoje eilutėje elementų kiekis nelygus columncount - išmeta "ERROR: corrupt data on line (blogos eilutės numeris .txt faile)"
Jei nuskaitytoje eilutėje nd_paz arba egz_paz nėra skaičius - išmeta "ERROR: bad int on line (blogos eilutės numeris .txt faile)"

const int columncount - "studentai10000 (with errors).txt" stulpelių skaičius.  
nd_paz - int vektorius iš (columncount - 3) skaičių.

# v0.4  

Programa sugeneruoja studentų txt failą, kiekvieną eilutę iš sugeneruoto failo irašo kaip string'ą į "lineread" string vektorių.  
Sukuriamas Student struct'ų vektorius, kiekvienam Student objektui priskiriamas string'as iš "lineread"; string'as išskaidomas į Student struct'o kintamiuosius (vardas, pavardė, nd_paz, egz_paz).  
Apskaičiuojamas galutinis_paz; studentai irašomi į du failus priklausomai nuo pažymio.

const int columncount - nustato, iš kiek stulpelių sugeneruoti failą (mažiausias galimas - 4).  
const int size - nustato, iš kiek eilučių (t.y studentų) sugeneruoti failą.  
nd_paz - int vektorius iš (columncount - 3) skaičių.

# v0.5

Programa sugeneruoja studentų txt failą, kiekvieną eilutę iš sugeneruoto failo irašo kaip string'ą į "lineread" string vektorių.  

Sukuriamas Student struct'ų vektorius, kiekvienam Student objektui priskiriamas string'as iš "lineread"; string'as išskaidomas į Student struct'o kintamiuosius (vardas, pavardė, nd_paz, egz_paz).  
Apskaičiuojamas galutinis_paz; studentai irašomi į du failus priklausomai nuo pažymio.

Sukuriamas Student struct'ų list'as, kiekvienam Student objektui priskiriamas string'as iš "lineread"; string'as išskaidomas į Student struct'o kintamiuosius (vardas, pavardė, nd_paz, egz_paz).  
Apskaičiuojamas galutinis_paz; studentai irašomi į du failus priklausomai nuo pažymio.

const int columncount - nustato, iš kiek stulpelių sugeneruoti failą (mažiausias galimas - 4).  
const int size - nustato, iš kiek eilučių (t.y studentų) sugeneruoti failą.  
nd_paz - int vektorius iš (columncount - 3) skaičių.

v0.5 greičio testavimas (8 stulpeliai)  
---------------------------
eilučių kiekis failo pavadinime ".txt"  

1000.txt generation: 0.0025759s  
1000.txt list handle: 0.00333949s  
1000.txt list sort + write: 0.000334884s  
1000.txt vector handle: 0.00498309s  
1000.txt vector sort + write: 0.000275388s  
1000.txt list total: 0.0037018s  
1000.txt vector total: 0.00528237s  

10000.txt generation: 0.0145677s  
10000.txt list handle: 0.0256634s  
10000.txt list sort + write: 0.00150192s  
10000.txt vector handle: 0.0335922s  
10000.txt vector sort + write: 0.00134411s  
10000.txt list total: 0.0271965s  
10000.txt vector total: 0.0349738s  

100000.txt generation: 0.131122s  
100000.txt list handle: 0.192991s  
100000.txt list sort + write: 0.015439s  
100000.txt vector handle: 0.318138s  
100000.txt vector sort + write: 0.010181s  
100000.txt list total: 0.208464s  
100000.txt vector total: 0.328353s  

1000000.txt generation: 1.4676s  
1000000.txt list handle: 1.87934s  
1000000.txt list sort + write: 0.205019s  
1000000.txt vector handle: 3.18454s  
1000000.txt vector sort + write: 0.16509s  
1000000.txt list total: 2.08442s  
1000000.txt vector total: 3.34967s  

10000000.txt generation: 15.8615s  
10000000.txt list handle: 18.5522s  
10000000.txt list sort + write: 2.20148s  
10000000.txt vector handle: 35.328s  
10000000.txt vector sort + write: 1.48s  
10000000.txt list total: 20.7537s  
10000000.txt vector total: 36.808s  

CPU:	Intel(R) Core(TM) i5-8265U CPU @ 1.60GHz  
RAM:	16GB ddr4 (2x8GB)  
SSD:	nvme  

# v1.0 

nuskaitomas sugeneruotas failas į list ir vector Student struct'us.  
str 1 - pirmoji strategija. Pradinis Student struct'as išskirstomas į du naujus list/vector Student struct'us, priklausomai nuo galutinio pažymio, ir išvedamas į failus.  
str 2 - antroji strategija. Iš pradinio Student struct'o į vieną naują list/vector Student struct'ą išvedami studentai, priklausomai nuo galutinio pažymio, ir ištrinami iš pradinio Student struct'o.  
erase(remove) - vektorius išrušiuojamas pagal galutinį pažymį; iš eilės ištrinami studentai kurių pažymys mažesnis už 5.  

v1.0 greičio testavimas
----------------------
10000.txt list handle: 0.0206259s  
list str 1 : 0.0107971s  
list str 2 : 0.0322819s  

10000.txt vector handle: 0.0249182s  
vector str 1 : 0.0126982s  
vector str 2 : 5.18823s  

10000.txt list total: 0.0637561s  
10000.txt vector total: 5.22589s  

10000.txt vector erase(remove) : 0.00854434s  
