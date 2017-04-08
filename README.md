I am trying to make a project on reducing the size of a file. For that, I have used Huffman coding. The Project contains following code files:-

Huffman_part1.cpp
Huffman_part1 is the source code for counting the occurrence of  all the character in the sting(including spaces). It also rearranges the output in ascending order of frequency of characters. 

Sample input- 
abcde abde

Sample output- 
  1
c 1
a 2
b 2
d 2
e 2

Huffman_part2.cpp
Huffman coding is implemented in Huffman_part2. It creates a tree and give the lowest number of terms to most occurred character in list.
Sample input-
a 1
b 2
c 3
d 4
e 5
f 6

Sample output-
d 00
e 01
c 100
a 1010
b 1011
f 11
