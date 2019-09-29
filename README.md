# Program3_work_play

A program to change one word into another, such as converting work into play.  At each step only a single letter can be changed at a time, and each word must be a word found in the dictionary.  This is inspired by Robert Frost's poem "Two Tramps in Mud Time" where the last stanza is:

    But yield who will to their separation,
    My object in living is to unite
    My avocation and my vocation
    As my two eyes make one in sight.
    Only where love and need are one,
    And the work is play for mortal stakes,
    Is the deed ever really done
    For heaven and the future’s sakes.


Using dictionary.txt of 235,886 words.  Running the program should look like the following, where user input is shown in bold (though your program when run will not display that in bold):

    Program #3: Work Play
    Author: Karan Singh Kochar and Lilly C
    Lab: Tues 8am
    System:  Codio

    Total number of words in dictionary file: 235886

    Word lengths where there are more than 1400 words:
    Length  How Many
    ------  --------
        3      1420
        4      5272
        5     10230
        6     17706
        7     23869
        8     29989
        9     32403
       10     30878
       11     26013
       12     20462
       13     14939
       14      9765
       15      5925
       16      3377
       17      1813

    Currently we have 1420 words of length 3 in the dictionary.
    Changing from 'dog' to 'cat'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 4

     1. Previous word is 'dog'.  Next word: cog
     2. Previous word is 'cog'.  Next word: cot
     3. Previous word is 'cot'.  Next word: cat
    Congratulations, you did it!

    Currently we have 1420 words of length 3 in the dictionary.
    Changing from 'dog' to 'cat'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 8

    Exiting the program

Running your program again could look like the following:

    Program #3: Work Play
    Author: Dale Reed
    Lab: Tues 8am
    System:  Codio

    Total number of words in dictionary file: 235886

    Word lengths where there are more than 1400 words:
    Length  How Many
    ------  --------
        3      1420
        4      5272
        5     10230
        6     17706
        7     23869
        8     29989
        9     32403
       10     30878
       11     26013
       12     20462
       13     14939
       14      9765
       15      5925
       16      3377
       17      1813

    Currently we have 1420 words of length 3 in the dictionary.
    Changing from 'dog' to 'cat'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 5

    0. dog:   1:bog 2:cog 3:fog 4:gog 5:hog 6:jog 7:log 8:mog 9:nog 10:rog 11:sog 12:tog 13:vog 14:wog 15:dag 16:deg 17:dig 18:dug 19:dob 20
    :doc 21:dod 22:doe 23:dol 24:dom 25:don 26:dop 27:dor 28:dos 29:dot 30:dow
    1. bog:   31:bag 32:beg 33:big 34:bug 35:boa 36:bob 37:bod 38:bom 39:bon 40:boo 41:bop 42:bor 43:bos 44:bot 45:bow 46:boy
    2. cog:   47:cag 48:cig 49:cob 50:cod 51:coe 52:col 53:con 54:coo 55:cop 56:cor 57:cos 58:cot 59:cow 60:cox 61:coy 62:coz
    3. fog:   63:fag 64:fig 65:fob 66:fod 67:foe 68:fon 69:foo 70:fop 71:for 72:fot 73:fou 74:fow 75:fox 76:foy
    4. gog:   77:gag 78:gig 79:goa 80:gob 81:god 82:goi 83:gol 84:gon 85:goo 86:gor 87:gos 88:got 89:goy
    5. hog:   90:hag 91:hug 92:hob 93:hod 94:hoe 95:hoi 96:hon 97:hop 98:hot 99:how 100:hox 101:hoy
    6. jog:   102:jag 103:jig 104:jug 105:job 106:joe 107:jon 108:jos 109:jot 110:jow 111:joy
    7. log:   112:lag 113:leg 114:lug 115:loa 116:lob 117:lod 118:lof 119:loo 120:lop 121:lot 122:lou 123:low 124:lox 125:loy
    8. mog:   126:mag 127:meg 128:mig 129:mug 130:mob 131:mod 132:moe 133:moi 134:mon 135:moo 136:mop 137:mor 138:mot 139:mou 140:mow 141:mo
    y
    9. nog:   142:nag 143:nig 144:noa 145:nob 146:nod 147:non 148:nor 149:not 150:nou 151:now 152:noy
    10. rog:   153:rag 154:reg 155:rig 156:rug 157:rob 158:roc 159:rod 160:roe 161:roi 162:rok 163:ron 164:rot 165:row 166:rox 167:roy
    11. sog:   168:sag 169:seg 170:sig 171:sob 172:soc 173:sod 174:soe 175:soh 176:sok 177:sol 178:son 179:sop 180:sot 181:sou 182:sov 183:s
    ow 184:soy
    12. tog:   185:tag 186:teg 187:tig 188:tug 189:tyg 190:toa 191:tod 192:toe 193:toi 194:tol 195:tom 196:ton 197:too 198:top 199:tor 200:t
    ot 201:tou 202:tow 203:tox 204:toy
    13. vog:   205:vag 206:vug 207:vod 208:voe 209:vol 210:vow
    14. wog:   211:wag 212:wig 213:wob 214:wod 215:woe 216:won 217:woo 218:wop 219:wot 220:wow 221:woy
    15. dag:   222:zag 223:dab 224:dad 225:dae 226:dah 227:dak 228:dal 229:dam 230:dan 231:dao 232:dap 233:dar 234:das 235:daw 236:day
    16. deg:   237:keg 238:peg 239:deb 240:dee 241:del 242:den 243:dev 244:dew 245:dey
    17. dig:   246:pig 247:zig 248:dib 249:did 250:die 251:dim 252:din 253:dip 254:dis 255:dit 256:div
    18. dug:   257:pug 258:dub 259:dud 260:due 261:dum 262:dun 263:duo 264:dup 265:dux
    19. dob:   266:kob 267:pob
    20. doc:
    21. dod:   268:pod
    22. doe:   269:poe 270:yoe 271:dye
    23. dol:   272:kol 273:pol
    24. dom:   274:pom 275:yom
    25. don:   276:eon 277:ion 278:kon 279:pon 280:yon
    26. dop:   281:kop 282:pop
    27. dor:   283:kor 284:yor
    28. dos:   285:kos
    29. dot:   286:pot 287:yot
    30. dow:   288:pow 289:yow
    31. bag:   290:baa 291:bab 292:bac 293:bad 294:bae 295:bah 296:bal 297:bam 298:ban 299:bap 300:bar 301:bas 302:bat 303:baw 304:bay
    32. beg:   305:bea 306:bed 307:bee 308:bel 309:ben 310:ber 311:bes 312:bet 313:bey
    33. big:   314:bib 315:bid 316:bim 317:bin 318:bis 319:bit 320:biz
    34. bug:   321:bub 322:bud 323:bum 324:bun 325:bur 326:bus 327:but 328:buy
    35. boa:   329:koa 330:poa 331:zoa 332:bra
    36. bob:
    37. bod:
    38. bom:
    39. bon:
    40. boo:   333:zoo 334:blo
    41. bop:
    42. bor:
    43. bos:
    44. bot:
    45. bow:
    46. boy:   335:poy 336:yoy
    47. cag:   337:cab 338:cad 339:cal 340:cam 341:can 342:cap 343:car 344:cat

    Winning sequence was found!

    Currently we have 1420 words of length 3 in the dictionary.
    Changing from 'dog' to 'cat'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 7

    Winning sequence in reverse order is:
      344. cat
       47. cag
        2. cog
        0. dog


    Currently we have 1420 words of length 3 in the dictionary.
    Changing from 'dog' to 'cat'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 8

    Exiting the program


Note that the defaults are to work with words of size 3, with the default starting word being "dog" and the default end word being "cat".  Running the program again might look like the following:

    Program #3: Work Play
    Author: Dale Reed
    Lab: Tues 8am
    System:  Codio

    Total number of words in dictionary file: 235886

    Word lengths where there are more than 1400 words:
    Length  How Many
    ------  --------
        3      1420
        4      5272
        5     10230
        6     17706
        7     23869
        8     29989
        9     32403
       10     30878
       11     26013
       12     20462
       13     14939
       14      9765
       15      5925
       16      3377
       17      1813

    Currently we have 1420 words of length 3 in the dictionary.
    Changing from 'dog' to 'cat'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 2

    Enter the start and end index values of words to display: 0 5

    About to display dictionary words from 0 to 5
        0 aal
        1 aam
        2 aba
        3 abb
        4 abe
        5 abo

    Currently we have 1420 words of length 3 in the dictionary.
    Changing from 'dog' to 'cat'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 1

    What length words do you want to use? 4
    Currently we have 5272 words of length 4 in the dictionary.
    Changing from '' to ''

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 3

    Enter starting word, or 'r' for a random word: work

    Enter ending word, or 'r' for a random word: play
    Currently we have 5272 words of length 4 in the dictionary.
    Changing from 'work' to 'play'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 6



    Winning sequence was found!

    Currently we have 5272 words of length 4 in the dictionary.
    Changing from 'work' to 'play'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 7

    Winning sequence in reverse order is:
     3067. play
     1247. plak
      270. peak
       37. perk
        3. pork
        0. work


    Currently we have 5272 words of length 4 in the dictionary.
    Changing from 'work' to 'play'

    Choose from the following options:
       1. Change the word length
       2. Display some dictionary words
       3. Get start and end words
       4. Play the word change game
       5. Find the end word with debug
       6. Find the end word
       7. Display an answer sequence
       8. Exit the program
    Your choice -> 8

    Exiting the program


