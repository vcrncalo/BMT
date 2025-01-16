# Implementacija bežične komunikacije za prenos senzorskih podataka

## Opis projekta
Ovaj projekat istražuje implementaciju bežične komunikacije za prenos senzorskih podataka koristeći **Arduino Mega 2560**, **Bluetooth HC-05 modul**, i **DHT11 senzor** za mjerenje temperature i vlage. Cilj projekta je razvoj **efikasnog, troškovno prihvatljivog i energetski štedljivog** sistema za real-time praćenje parametara okruženja.

## Ključne komponente
- **Arduino Mega 2560** – mikroprocesorska ploča sa većim brojem I/O pinova.
- **DHT11 senzor** – mjeri temperaturu i vlažnost okruženja.
- **Bluetooth HC-05 modul** – omogućava bežičnu komunikaciju između senzora i mobilnog uređaja.
- **OLED displej** – prikazuje očitane vrijednosti u realnom vremenu.
- **WEMOS D1 Mini (ESP8266)** – koristi se za dodatnu Wi-Fi komunikaciju i prenos podataka putem e-maila.

## Implementacija
1. **Mjerenje podataka** – DHT11 senzor prikuplja podatke o temperaturi i vlažnosti.
2. **Prenos podataka** – očitane vrijednosti se šalju putem Bluetootha na mobilni uređaj ili e-mail koristeći Wi-Fi modul.
3. **Prikaz podataka** – rezultati se prikazuju na OLED displeju.
4. **Dodatne funkcionalnosti** – implementirana je LED indikacija uspješnog prenosa podataka.

## Korištene tehnologije
- **Bluetooth (IEEE 802.15.1)** – za kratkodometnu bežičnu komunikaciju.
- **Wi-Fi (IEEE 802.11)** – omogućava slanje podataka putem e-maila (SMTP protokol).
- **Visible Light Communication (VLC)** – eksperimentalna metoda prenosa podataka putem svjetlosti.
- **SMTP (Simple Mail Transfer Protocol)** – koristi se za slanje podataka putem e-maila, omogućava komunikaciju između klijentskih i serverskih aplikacija.
- **Dvofaktorska autentifikacija (2FA)** – dodatna sigurnosna mjera koja zahtijeva potvrdu identiteta pomoću drugog faktora (npr. mobilni uređaj ili e-mail kod).

## Povezivanje komponenti
Sve komponente su povezane u sistem sa **Arduino Mega2560** kao centralnim kontrolerom:
- **DHT11 senzor**: VCC na 5V, GND na GND, DATA na digitalni pin Arduina.
- **HC-05 Bluetooth modul**: VCC na 5V, GND na GND, TX na RX Arduina, RX na TX Arduina.
- **OLED displej**: Koristi I2C komunikaciju – SDA na SDA Arduina, SCL na SCL Arduina.
- **LED dioda**: Anoda povezana na digitalni pin, katoda na GND kroz otpornik od 220Ω.
- **Wi-Fi modul (ESP8266)** i **fotorezistor**: Povezani su nezavisno na laptop putem USB-a, gdje se fotorezistor spaja na analogni ulaz modula.

## Potencijalna poboljšanja
- Zamjena **DHT11** sa **DHT22** senzorom radi preciznijih mjerenja.
- Optimizacija koda za stabilniju Bluetooth komunikaciju.
- Korištenje naprednijih bežičnih tehnologija poput **LoRa** za veći domet.

## Instalacija i pokretanje
### 1. Potrebni alati:
- Arduino IDE
- Serial Bluetooth Terminal aplikacija (Android/iOS)

### 2. Koraci za pokretanje sistema:
1. Povežite komponente prema šemi iz projekta.
2. Učitajte **Arduino skicu** u Arduino Mega 2560 putem **Arduino IDE**.
3. Pokrenite Bluetooth aplikaciju na mobilnom uređaju i povežite se sa HC-05 modulom.
4. Podaci će se prikazivati na OLED displeju i slati putem Bluetootha ili e-maila korištenjem SMTP protokola sa dvofaktorskom autentifikacijom.
