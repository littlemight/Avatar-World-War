# HELP
## BANTU BIKIN DRIVER YAA
Bikin driver untuk tiap adt yang ada di folder "src/adt", tolong bantu bikinin ya
1. Bikin driver nya di dalam folder adt/<nama adt>, terus namanya <b>HARUS</b> driver.c
Contoh  
```
--bin
--src
----adt
------point
--------point.c
--------point.h
--------driver.c
```
Terus tambahin STARTKATA(0); di dalam blok program main kalian
```
#include "<nama adt>.h"
int main() {
  STARTKATA(0);
  
  // program driver
  return 0; 
}
```

Biar gampang kalian nge run nya, jalaninnya kaya gini
```
> rundriver <nama adt>
```
## Contoh
```
> rundriver point
Compiling driver for point...
Compilation done 
Press any key to continue . . . 

Masukkin 2 angka: 12 23
(12,23)
```

<b>SCRIPT NYA CUMAN BISA DI WINDOWS YA SEKARANG</b>

<b>Kalo ga bikin driver, bantuin laporan ya, pls</b>
https://docs.google.com/document/d/1rRFfV6kpo0Hjq70rqqjELmAHR6aPr-9_whHb9z-5UhY/edit
