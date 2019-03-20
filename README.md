# Die-Comparison
A simple program to generate dice and compare their win/loss to a sample die

Author: Nathan Sheely

Date: 3/20/2019

History: version 1.0

Summary:

  This program takes a sample die (d6 with sides 1,2,3,4,5,6 by default)
  generates die with up to a given number of pips (21 by defauly)
  and compares the win loss rate of each to the sample die.
  
  A die wins when it rolls a higher number, loses when it rolls lower, and ties re-roll.
  
Usage: ./die_comp [-pips #pips][-faces *faces][-die {number on each side}]

  -p (-pips) #pips -- change max number of pips on generated die to #pips
  -f (-faces) #faces -- change the number of faces on the die, without -die will default sides to 1 - #faces
  -d (-die) {number on each side} -- type in, space seperated, numbers for each die on the die you want to sample against
