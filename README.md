# DONE
### Input/output
- Input mesinkata
- Status
- Output color
  
### Load/Save
- Write kondisi game ke file (baca notes)
  
### Command
- Attack
- Move
- End turn (kurang update shield)
- Level Up

# BELUM
### Command
- Load/save
  
### Skill
- Cara dapetin (perlu ADT State)

# NOTES
## Urutan penulisan status game di save.sdat
1. Peta (matrix)
2. Graph (adjacency matrix)
3. Current State:
    
    Urutan penulisan state
   1. Array of building:
      1. Ukuran array
      2. info tiap building
         1. Owner Type Level Troop Regen MaxCap Defense Row Col (posisinya) HasAttacked
   2. Informasi kedua player
      1. Username
         1. Panjang usernamenya
         2. String usernamenya
      2. List building
         1. Panjang list
         2. Isi list nya
      3. Queue skills
         1. Banyaknya isi skill (dari front ke back)
         2. isi skill (dalam kata)
            1. panjang kata
            2. string kata
      4. Status shield
      5. Banyaknya extra turn
      6. Punya attack up ga
      7. Punya critical hit ga
   3. ID player yang lagi main
4. Stack of state
   1. Ukuran stack
   2. State nya (urutannya dari awal sampai yg terakhir di push)
5. EOP (#)

(di file nya ga ada komen gini ya)
```
// PETA
10 15
0 0 0 0 0 0 0 0 3 0 0 0 4 0 2
0 0 5 0 0 0 0 0 0 0 0 0 0 0 0
6 0 0 0 0 0 0 7 0 0 0 0 0 8 0
0 0 0 0 9 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 10 0 0 0
0 0 11 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 12 0 0 0 0 0
0 13 0 0 0 14 0 0 0 0 0 0 0 0 15
0 0 0 0 0 0 0 0 0 0 0 0 16 0 0
1 0 17 0 0 0 0 0 0 0 0 0 0 0 0
// GRAPH
17 17
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0
0 0 1 0 1 0 0 1 1 1 0 0 0 0 0 0 0
0 1 1 1 0 0 1 0 0 1 0 0 0 0 1 0 0
0 0 0 0 1 1 1 0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 0 1 1 1 0 0 1 0 0 1 0 0
0 0 0 0 0 1 0 0 1 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 1 1 1 0 0 1 0 1 0
1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1
0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 1
0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0
1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0
// CURRENT STATE
// Array of building
17
1 C 1 40 10 40 0 10 1 0
2 C 1 40 10 40 0 1 15 0
0 V 1 20 5 20 0 1 9 0
0 T 1 30 5 20 1 1 13 0
0 C 1 40 10 40 0 2 3 0
0 T 1 30 5 20 1 3 1 0
0 V 1 20 5 20 0 3 8 0
0 C 1 40 10 40 0 3 14 0
0 F 1 80 10 20 0 4 5 0
0 F 1 80 10 20 0 5 12 0
0 T 1 30 5 20 1 6 3 0
0 T 1 30 5 20 1 7 10 0
0 C 1 40 10 40 0 8 2 0
0 V 1 20 5 20 0 8 6 0
0 T 1 30 5 20 1 8 15 0
0 C 1 40 10 40 0 9 13 0
0 T 1 30 5 20 1 10 3 0
// PLAYER 1
// Username
4
user
// List of building
1
1
// Skills
1
2
IU
// Status player seperti critical hit, dll
0
0
0
0
// PLAYER 2 
4
name
1
2
1
2
IU
0
0
0
0
// Current player ID
1
// STACK OF STATE
1 // banyaknya element stack
// STATE
17
1 C 1 40 10 40 0 10 1 0
2 C 1 40 10 40 0 1 15 0
0 V 1 20 5 20 0 1 9 0
0 T 1 30 5 20 1 1 13 0
0 C 1 40 10 40 0 2 3 0
0 T 1 30 5 20 1 3 1 0
0 V 1 20 5 20 0 3 8 0
0 C 1 40 10 40 0 3 14 0
0 F 1 80 10 20 0 4 5 0
0 F 1 80 10 20 0 5 12 0
0 T 1 30 5 20 1 6 3 0
0 T 1 30 5 20 1 7 10 0
0 C 1 40 10 40 0 8 2 0
0 V 1 20 5 20 0 8 6 0
0 T 1 30 5 20 1 8 15 0
0 C 1 40 10 40 0 9 13 0
0 T 1 30 5 20 1 10 3 0
4
user
1
1
1
2
IU
0
0
0
0
4
name
1
2
1
2
IU
0
0
0
0
id 1
# // EOP
```