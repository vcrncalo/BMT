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
Sve komponente su povezane u sistem sa **Arduino Mega2560** i dodatnim modulom. **DHT11 senzor** za mjerenje temperature i vlažnosti povezan je tako da su njegov **VCC i GND** priključeni na **5V i GND** pinove Arduina, dok je **DATA** pin povezan na jedan od digitalnih pinova. **HC-05 Bluetooth modul** povezan je tako da je njegov **VCC** spojen na **5V**, **GND** na **GND Arduina**, dok su **TX i RX** pinovi modula povezani na **RX i TX** pinove Arduina. **OLED ekran** koristi **I2C komunikaciju**, pa su **SDA i SCL** pinovi ekrana povezani na **SDA i SCL** pinove Arduina. **Jedna LED dioda** povezana je preko otpornika od **27Ω** na jedan od digitalnih pinova Arduina, dok je njena katoda spojena na **GND**.

**Wi-Fi modul (ESP8266)** i **fotorezistor** s otpornikom od **10kΩ** nisu direktno povezani na **Arduino Mega**. Ove komponente čine nezavisni podsistem koji je povezan na laptop radi napajanja i komunikacije. **Fotorezistor** je spojen u seriji s otpornikom od **10kΩ**, pri čemu je spoj između fotorezistora i otpornika vjerovatno povezan na analogni ulaz Wi-Fi modula za očitavanje vrijednosti osvjetljenja. Napajanje i komunikacija za Wi-Fi modul osigurani su putem **USB veze s laptopom**. Za svrhu izrade naše sheme u programu **Fritzing**, korišten je drugi model **OLED displeja**. Nažalost, nije bilo moguće koristiti OLED displej koji je konkretno predviđen za stvarni projekat, jer taj model nije bio dostupan u biblioteci programa **Fritzing** koji se koristio za kreiranje sheme.


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
