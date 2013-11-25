Assigment6
==========

Prove You can use github

Step 1. Clone this repo

Step 1.5 
	run if using snowball:
```
git remote set-url origin https://<Your username here>@github.com/CSC-3320-Fall/Assignment6.git
unset SSH_ASKPASS
```


Step 2. Make a new directory with you CAMPUSID username.

Step 3. Write a short hello world C language program in YOUR directory.

Step 4. Use "git add" to add your program.

Step 5. Commit your changes ("write a good commit message!")

Step 6. Push your commit to github.

Step 7. Get a good grade.
=======
Assignment-7
============
# RWH
# CSc 3320 2013 Due November 5 2013
# Abstract

Your task is to write some computer tools to break a simple and not
quite as simple cipher system. Perform this successfully and you will be
at the state of the art (ca 1900). You will also have done better than
anyone from the Confederate States of America did during the American
Civil War.


The task in this assignment is to solve a very simple cipher and a somewhat
more complicated version of it. Ceaser ciphers, named after the emperor Julius,
consist of replacing each letter in a message with the letter n places down (mod
26 for English). With the key of 10, a would be replaced by a+10 or j. Each
key has an inverse which is simply 26 - key, so that applying the Ceaser cipher
with that inverse will result in the plain text. ((a+k)mod26+26-k)mod26 =
(a + k - k)mod26 = a.


A more complex version of this, Vigenere systems, involves using several keys
one after another. For example with the keys 10,11,12 the rst letter would be
encoded with 10, the second with 11, the third with 12, and then the fourth
with 10, and so on. The full Vignere system uses general substitution, but even
this system with Ceaser ciphers was considered unbreakable in the early 1900's.
While tedious to solve with paper and pencil these ciphers are very easy to
solve by machines. Since we know that 'e' is the most common English letter,
we can nd the most common letter in the Ceaser cipher and work out what
was added to 'e' to get that letter. With the Vigenere system, we need to rst
estimate the period (number of keys used) and then can break the individual
Ceaser ciphers by nding the most common letter in them.


The incidence of co-incidence, Kasiski or kappa test is a fairly easy way to
nd the period. Since each individual cipher always converts letters to the same
letter, and letters are not uniformly distributed in English (E is a lot more
common than X), if we slide the cipher along itself and count the number of
times the same letters appear, then we will get maximums at 0 (D'Oh - ignore
this one), the length of the key, two times the length of the key, three times the
length of the key and so on.


Once the period is known, solving the individual Ceaser ciphers is rather
trivial.


Following current conventions, the algorithm and encryption methods are
available for your perusal (ceaser.c, vigenere.c)


As usual, writing the code is more important than the answers - so please
check your code and answers into the class github. Files are in a tarle on
desire to learn or Dr. Harrison's account on snowball (look in the directory
assignment7).


1. Find the key for the le 'text.one.encrypted'.
2. Find the period for the le 'text.two.encrypted' using the incidence of co-incidence test.
3. Find the key for text.two.encrypted


Hints: Write out the pseudocode if you are confused what to do. A little
forethought in designing the counting/maximum parts of finding the first problem 
(i.e. using C functions for them) will make the problem easy. fgets() is
probably the best way to read each line in.
